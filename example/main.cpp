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
	log.initXML(NULL);
	log.addLogger(&log1);
	log.addLogger(&(std::string ("foo")));
	log.addLogger(&(std::string ("foo.bar")));
	log.useLogger(NULL, &message, FATAL);
	log.useLogger(NULL, NULL, 9);
	log.useLogger(&(std::string("logger")), NULL, 9);
	log.useLogger(&log1, &message, WARN);
	log.useLogger(&(std::string ("foo")), &(std::string ("just a warning output created by foo")), WARN);
	log.useLogger(&(std::string ("foo.bar")), &(std::string ("nothing happenning")), TRACE);
	log.useLogger(&(std::string ("foo.bar")), &(std::string ("warning append")), WARN);
	return (0);
}
