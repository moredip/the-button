require('./config');

const express = require('express');
const bodyParser = require('body-parser');

const app = express();
app.use(bodyParser.text({type:'*/*'}));

app.set('port', (process.env.PORT || 5000));

app.get('/', function (req, res) {
  res.send(`
    <h1>the-button server</h1>
  `);
});

app.post('/device/heartbeat', function (req, res) {
  const deviceUid = req.body;
  console.log('received a heartbeat from:', deviceUid);
  res.send('OK');
});

app.post('/device/button', function (req, res) {
  const deviceUid = req.body;
  console.log('received a button press from:', deviceUid);
  res.send('OK');
});

app.listen(app.get('port'), function() {
  console.log('server running on port', app.get('port'));
});
