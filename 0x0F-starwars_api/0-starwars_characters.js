#!/usr/bin/node
const request = require('request');

const Args = process.argv.slice(2);
const MovieID = Args[0];

const options = {
  url: `https://swapi-api.hbtn.io/api/films/${MovieID}/`,
  json: true,
  transform (body, response) {
    if (response.headers['content-type'] === 'application/json') {
      response.body = JSON.parse(body);
    }
    return response;
  }
};

request(options, async (error, response, body) => {
  if (error) {
    throw new Error(`HTTP error: ${response.status}`);
  }
  for (const characterURL of response.body.characters) {
    await new Promise((resolve, reject) => {
      request(characterURL, (err, res, body1) => {
        if (err) {
          reject(new Error(`HTTP error: ${res.status}`));
        }
        console.log(JSON.parse(body1).name);
        resolve();
      });
    });
  }
});
