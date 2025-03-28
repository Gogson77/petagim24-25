const express = require('express');
const bodyParser = require('body-parser');
const { Pool } = require('pg');
const path = require('path'); // Dodano za rad sa putanjama

const app = express();
const port = 3000;

const pool = new Pool({
  user: 'postgres',
  host: 'localhost',
  database: 'postgres',
  password: '',
  port: 5432,
});

// Middleware za parsiranje JSON podataka
app.use(bodyParser.json());

// Middleware za posluživanje statičkih datoteka
app.use(express.static(path.join(__dirname))); // Poslužuje datoteke iz trenutnog direktorija

app.post('/submit', async (req, res) => {
  // ...existing code...
});

app.listen(port, () => {
  console.log(`Server running on http://localhost:${port}`);
});
