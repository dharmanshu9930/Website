const mongoose = require('mongoose');
const { stringify } = require('querystring');

const iterationschema = new mongoose.Schema({
    name: {
        type: String,
        required: true
    },
    wins: {
        type: String,
        required: true
    },
})

const Iteration = mongoose.model('val' , iterationschema);

module.exports = Iteration;