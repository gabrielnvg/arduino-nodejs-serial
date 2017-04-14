# About
Read an USB connected arduino's serial data using Node.js.

# Usage
To get the project dependencies, run:
```sh
$ npm install
```

To find your arduino USB port, run:
```sh
$ node listPorts.js
```
This will list the USB ports. Find the arduino one.
An example on Linux: "/dev/tty.usbmodem1421".
An example on Windows: "COM1".

### Reading
Once knowing the arduino port, run:
```sh
$ node read.js 'port'
```
Where 'port' is your arduino USB port.
Example:
```sh
$ node read.js COM1
```

The arduino's serial data will be displayed in the Node.js console.

### Writing
To turn a pin on/off, you will use the same following command.

Once knowing the arduino port, run:
```sh
$ node write.js 'port' 'pin'
```
Where 'port' is your arduino USB port and 'pin' is the chosen pin. Please be aware that it only accepts values from 0 to 9 on current version. I'm still working on it :)
Example:
```sh
$ node write.js COM1 7

# Observations
- Note that "9600" is the chosen serial baud rate so dont't forget to match that on your arduino's code.
- The "ArduinoTest.ino" file inside the "arduino_test" folder is for you to test the read (using an ultrasonic sensor, don't forget to add it's library) and the write (using a led).
- The "write.js" file also reads the serial data from arduino after it writes.
- When you open the serial connection, the arduino will reset. So you will notice that a pin will change its state back to its default if you re-open the serial port connection.
