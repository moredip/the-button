global.DEV_MODE = ((process.env.NODE_ENV||'development') === 'development');

if( DEV_MODE ){
  require('dotenv').config({path: __dirname+"/.env"});
}
