var logger = require('../build/Release/clogger.node');

logger.log("This is a message");

logger.log("This is an info message", "info");

logger.log("This is an info message from application.main", "info", "application.main");

logger.log("This is a green message from application.main", "info", "application.main", "green");

logger.log("This is a blue message from application.main", "info", "application.main", "blue");
 
logger.log("This is a cyan message from application.main", "info", "application.main", "cyan");

logger.log("This is a purple message from application.main", "info", "application.main", "purple");
