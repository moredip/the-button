require('./config');

const express = require('express');
const app = express();

app.set('port', (process.env.PORT || 5000));

app.get('/', function (req, res) {
  res.send(`
    <h1>the-button server</h1>
  `);
});

app.get('/device/heartbeat', function (req, res) {
  const deviceUid = req.body.toString();
  console.log('received a heartbeat from:', deviceUid);
  res.send('OK');
});

app.listen(app.get('port'), function() {
  console.log('server running on port', app.get('port'));
});
