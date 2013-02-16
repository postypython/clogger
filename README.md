Clogger 0.0.1
===============================
C++ Node.js module implementing simple coloured console (stdout) logging.

## Installation
Using node package manager, run the following:

```bash
npm install clogger
```

From your Node.js application import clogger as per code below and then you are ready to go.


```javasacript
clogger = require('clogger');
```

## Sample usage
Colors available are: blue, red and green.
For each log message you can specify level or category.

```javasacript
// no colors applied nor level or category
clogger.log("Your log message");

// displays green message without defining level or category
clogger.log("Your first green message",,,"green");

// displays a red message with both level and category
clogger.log("This is an error","error","system.application","red");
```



