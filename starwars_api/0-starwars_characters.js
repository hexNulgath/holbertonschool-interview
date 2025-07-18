#!/usr/bin/node
const request = require('request');
const filmId = process.argv[2];

if (!filmId) {
  console.error('Please provide a film ID as an argument');
  console.log('Usage: node script.js <film-id>');
  process.exit(1);
}

const url = `https://swapi-api.hbtn.io/api/films/${filmId}/`;

// Wrap request in a promise to use with async/await
function requestPromise(url) {
  return new Promise((resolve, reject) => {
    request(url, { json: true }, (error, response, body) => {
      if (error) {
        reject(error);
      } else if (response.statusCode !== 200) {
        reject(new Error(`API error: ${response.statusCode}`));
      } else {
        resolve(body);
      }
    });
  });
}

async function getCharacters() {
  try {
    const film = await requestPromise(url);
    const characterUrls = film.characters;
    
    // Process characters in order
    for (const characterUrl of characterUrls) {
      try {
        const character = await requestPromise(characterUrl);
        console.log(character.name);
      } catch (error) {
        console.error('Error fetching character:', error.message);
      }
    }
  } catch (error) {
    console.error('Error fetching film:', error.message);
  }
}

getCharacters();