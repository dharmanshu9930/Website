const express = require('express');
const port = 8000;
const path = require('path');

const db = require('./config/mongoose')
const Iteration = require('./models/iteration')

const app = express();

app.set('view engine','ejs')
//to join main directry with views
app.set('views', path.join(__dirname, 'views'))
// //to encoded the data from browser
// app.set('view engine', 'ejs');
// app.set('views' , path.join(__dirname,'views'));
app.use(express.urlencoded())
app.use(express.static('assets'))

app.get('/game/start' , function(req, res){

    // Iteration.create({
    //     name: 
    // })
    return res.render('game');
});

app.listen(port , function(err){
    if(err){
        console.log('error in loading');
    }
    console.log('server is up for running');
})