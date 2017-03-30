var portName = process.argv[2];

var SerialPort = require("serialport");
var serialport = new SerialPort(portName, {
   baudRate: 9600,
   // Look for return and newline at the end of each data packet
   parser: SerialPort.parsers.readline("\n")
});

serialport.on('open', function() {
    console.log('Serial Port Opened.');
    serialport.on('data', function(data) {
        console.log(data);
    });
});
