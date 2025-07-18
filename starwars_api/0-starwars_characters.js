#!/usr/bin/node
const request = require('request');
const filmId = process.argv[2];

if (!filmId) {
  console.error('Please provide a film ID as an argument');
  console.log('Usage: node script.js <film-id>');
  process.exit(1);
}

const url = `https://swapi-api.hbtn.io/api/films/${filmId}/`;

request(url, { json: true }, (error, response, body) => {
  if (error) {
    console.error('Request error:', error);
    return;
  }
  
  if (response.statusCode !== 200) {
    console.error('API error:', response.statusCode, body);
    return;
  }

  // The characters are listed as URLs in the film response
  const characterUrls = body.characters;
  
  // Fetch each character
  characterUrls.forEach(characterUrl => {
    request(characterUrl, { json: true }, (error, response, character) => {
      if (!error && response.statusCode === 200) {
        console.log(character.name);
      } else {
        console.error('Error fetching character:', error || response.statusCode);
      }
    });
  });
});