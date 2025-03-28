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

// Middleware za parsiranje URL-encoded podataka
app.post('/submit', async (req, res) => {
  const {
    ime, adresa, telefon, svrha_doznake, primalac, mjesto, datum_uplate,
    potpis_nalogodavca, pecat_banke, potpis_ovlastenog_lica, racun_posiljaoca,
    racun_primaoca, iznos, hitno, broj_poreskog_obveznika, vrsta_prihoda,
    opcina, poziv_na_broj, porezni_period_od, porezni_period_do, budzetska_organizacija
  } = req.body;

  try {
    const result = await pool.query(
      `INSERT INTO uplatnica (
        ime, adresa, telefon, svrha_doznake, primalac, mjesto, datum_uplate,
        potpis_nalogodavca, pecat_banke, potpis_ovlastenog_lica, racun_posiljaoca,
        racun_primaoca, iznos, hitno, broj_poreskog_obveznika, vrsta_prihoda,
        opcina, poziv_na_broj, porezni_period_od, porezni_period_do, budzetska_organizacija
      ) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15, $16, $17, $18, $19, $20, $21) RETURNING *`,
      [
        ime, adresa, telefon, svrha_doznake, primalac, mjesto, datum_uplate,
        potpis_nalogodavca, pecat_banke, potpis_ovlastenog_lica, racun_posiljaoca,
        racun_primaoca, iznos, hitno, broj_poreskog_obveznika, vrsta_prihoda,
        opcina, poziv_na_broj, porezni_period_od, porezni_period_do, budzetska_organizacija
      ]
    );
    res.status(201).json(result.rows[0]);
  } catch (error) {
    console.error('Error saving data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

app.listen(port, () => {
  console.log(`Server running on http://localhost:${port}`);
});
