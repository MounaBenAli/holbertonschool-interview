#!/usr/bin/python3

import requests
import json


def count_words(subreddit, word_list, after=None):
    # Send a GET request to the Reddit API
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    params = {"limit": 100}
    if after:
        params["after"] = after
    response = requests.get(url, params=params, allow_redirects=False)
    if response.status_code != 200:
        return

    # Parse the JSON response
    data = json.loads(response.text)

    # Count the occurrences of each keyword in the titles
    count = {}
    for word in word_list:
        count[word] = 0
    for child in data["data"]["children"]:
        title = child["data"]["title"].lower()
        for word in word_list:
            if word in title:
                count[word] += 1

    # Print the results in descending order
    for word, c in sorted(count.items(), key=lambda x: (-x[1], x[0])):
        if c > 0:
            print(f"{word}: {c}")

    # Call the function recursively with the "after" parameter
    after = data["data"]["after"]
    if after:
        count_words(subreddit, word_list, after)
