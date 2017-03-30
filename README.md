# About
Read an USB connected arduino's serial data using Node.js.

# How to run
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

Once knowing the arduino port, run:
```sh
$ node index.js 'port'
```
Where 'port' is your arduino USB port.
Example:
```sh
$ node index.js COM1
```

The arduino's serial data will be displayed in the Node.js console.

# Observations
- Note that "9600" is the chosen serial baud rate so dont't forget to match that on your arduino's code.
