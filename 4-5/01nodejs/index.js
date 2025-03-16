const http = require('http');

const hostname = 'localhost';

const port = 3000;

const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Zdravo svima\n');
}); 

server.listen(port, hostname, () => {
  console.log(`Server radi na http://${hostname}:${port}/`);
});