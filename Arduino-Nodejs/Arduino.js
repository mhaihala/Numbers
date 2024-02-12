var http = require('http');
var fs = require('fs');
var index = fs.readFileSync( 'index.html');


var SerialPort = require("serialport");
const parsers = SerialPort.parsers;

const parser = new parsers.Readline({
    delimiter: '\r\n'
});

var port = new SerialPort('COM5',{                  // Port Parameters
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false
});

port.pipe(parser);

var app = http.createServer(function(req, res){

    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end(index);
});

var io = require('socket.io').listen(app);

io.on('connection', function(data){

    console.log('Node.js is listening');            // When connected inform user

});

parser.on('data', function(data){

    console.log(data);                              // Read serialport and output to socket.io
    io.emit('data', data);

})

    

app.listen(3000);
