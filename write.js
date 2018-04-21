var portName = process.argv[2];
var chosenPin = process.argv[3];

var SerialPort = require("serialport");
var serialport = new SerialPort(portName, {
   baudRate: 9600,
   // Look for return and newline at the end of each data packet
   parser: SerialPort.parsers.readline("\n")
});

serialport.on('open', function(err) {
    console.log('Serial Port open.');
    console.log('Chosen pin: ' + chosenPin + '.');
    // A timeout is necessary to wait the port to open (if not working, try to increase the milliseconds value)
    setTimeout(function() {
		serialport.write(chosenPin);
	}, 2000);
    if(err) {
		console.log('Error when trying to open:' + err);
	}
    serialport.on('data', function(data) {
        console.log(data);
    });
});


