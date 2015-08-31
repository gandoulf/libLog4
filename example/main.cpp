/*
 * Copyright (C) 2012 All Right Reserved, Diotasoft 
 *
 * Author: Sebastian Knödel
 * Date: January 2014
 * Summary: Selltic OpenGL Demo
 *
 */

#include "log4.hpp"

int main(int argc, char **argv)
{
	Log4 log("try lib");
	std::string message("something append");
	std::string log1("logger");

	log.initLogger();
	log.initXML("");
	log.addLogger(log1);
	log.addLogger("foo");
	log.addLogger("foo.bar");
	log.useLogger("", message, FATAL);
	log.useLogger( "", "", 9);
	log.useLogger("logger", "", 9);
	log.useLogger(log1, message, WARN);
	log.useLogger("foo", "just a warning output created by foo", WARN);
	log.useLogger("foo.bar", "nothing happenning", TRACE);
	log.useLogger("foo.bar", "warning append", WARN);
	LOG4CXX_FATAL(log.getLogger("foo"), "yoloooooooo");
	return (0);
}
