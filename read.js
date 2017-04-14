var portName = process.argv[2];

var SerialPort = require("serialport");
var serialport = new SerialPort(portName, {
   baudRate: 9600,
   // Look for return and newline at the end of each data packet
   parser: SerialPort.parsers.readline("\n")
});

serialport.on('open', function(err) {
    console.log('Serial Port open.');
    serialport.on('data', function(data) {
        console.log(data);
    });
    if(err) {
		console.log('Error when trying to open:' + err);
	}
});
