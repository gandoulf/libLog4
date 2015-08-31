#include "log4.hpp"
#include <stdlib.h>
#include <iostream>


Log4::Log4(char *name): log4Name(name)
{
  for (int i = 0; i <= 4; ++i)
    logCall[i] = 0;
  for (int i = 0; i < 6; ++i)
    logCall[i] = 0;
  report[0] = &Log4::logTrace;
  report[1] = &Log4::logDebug;
  report[2] = &Log4::logInfo;
  report[3] = &Log4::logWarn;
  report[4] = &Log4::logError;
  report[5] = &Log4::logFatal;
}

Log4::Log4()
{
  for (int i = 0; i <= 4; ++i)
    logCall[i] = 0;
  for (int i = 0; i < 6; ++i)
    logCall[i] = 0;
  report[0] = &Log4::logTrace;
  report[1] = &Log4::logDebug;
  report[2] = &Log4::logInfo;
  report[3] = &Log4::logWarn;
  report[4] = &Log4::logError;
  report[5] = &Log4::logFatal;
}

Log4::~Log4()
{
  int			i = 0;
  std::stringstream	name; name << "loggerReport " << log4Name;
  LoggerPtr		loggerReport(Logger::getLogger(name.str()));
  std::stringstream	sstm;


  while (logger[i] != NULL)
    {
      free(logger[i]);
      free(loggerName[i]);
      ++i;
    }
  free(logger);
  free(loggerName);
  sstm << "Trace: " << logCall[0] << ",Debug: " << logCall[1] << ",Info: " << logCall[2] << ",Warn: " << logCall[3] << ",Error: " << logCall[4] << ",Fatal: " << logCall[5];
  LOG4CXX_INFO(loggerReport, sstm.str());
}

/* public function */

int	Log4::initLogger()
{
  if ((logger = (LoggerPtr **)malloc(sizeof(LoggerPtr *) * 2)) == 0)
    return (-1);
  if ((loggerName = (std::string **)malloc(sizeof( std::string *) * 2)) == 0)
    return (-1);
  logger[0] = new LoggerPtr(Logger::getLogger( "root"));
  loggerName[0] = new std::string("root");
  logger[1] = NULL;
  loggerName[1] = NULL;
}

void	Log4::initXML(std::string *file)
{
  if (file == NULL)
	 DOMConfigurator::configure("log4/Log4cxxConfig.xml");
  else
    DOMConfigurator::configure(*file);
}

void	Log4::initLogFile(std::string *file)
{
  if (file == NULL)
	 PropertyConfigurator::configure("C:/document/log4ex/lp-log4cxx-master/examples/CinderProject/assets/log4j.properties");
  else
    PropertyConfigurator::configure(*file);
}
int	Log4::addLogger(std::string *logName)
{
  int	i;

  if (logName == NULL)
    return (0);
  i = getLoggerNbr();
  if ((logger = (LoggerPtr **)realloc(logger, sizeof(LoggerPtr *) * (i + 1))) == 0)
    return (-1);
  if ((loggerName = (std::string **)realloc(loggerName, sizeof( std::string *) * (i+ 1))) == 0)
    return (-1);
  logger[i - 1] = new LoggerPtr(Logger::getLogger(*logName));
  loggerName[i - 1] = new std::string(*logName);
  logger[i] = NULL;
  loggerName[i] = NULL;
  return (1);
}

void	Log4::useLogger(std::string *logName, std::string *message, int force)
{
  int	i;
  
  if (force < 0 || force > 5)
    force = 0;
  if (logName != NULL && message == NULL)
    {
      i = searchLogger(logName);
      (*this.*report[force])(i, &(std::string ("no message to display")));
    }
  else if (logName == NULL && message == NULL)
    {
      (*this.*report[force])(0, &(std::string ("no logger and no message to display")));
    }
  else if (logName == NULL)
    {
      (*this.*report[force])(0, message);
    }
  else
    {
      i = searchLogger(logName);
      (*this.*report[force])(i, message);
    }
}

LoggerPtr	*Log4::getLogger(std::string *Name)
{
  return (logger[searchLogger(Name)]);
}

/* private function */

int	Log4::getLoggerNbr()
{
  int	i = 0;

  while (logger[i] != NULL)
    ++i;
  return (i + 1);
}

int	Log4::searchLogger(std::string *logName)
{
  int	i = 0;

  while (loggerName[i] != NULL)
    {
      if (loggerName[i][0] == *logName)
	return (i);
      ++i;
    }
  return (0);
}

 void          Log4::logTrace(int i, std::string *message)
{
  if (logger[i][0]->isTraceEnabled())
    {
      logCall[0] += 1;
      LOG4CXX_TRACE(logger[i][0], *message);
    }
}

 void          Log4::logDebug(int i, std::string *message)
{
  if (logger[i][0]->isDebugEnabled())
    {
      logCall[1] +=1;
      LOG4CXX_DEBUG(logger[i][0], *message);
    }
}
 void          Log4::logInfo(int i, std::string *message)
{
  if (logger[i][0]->isInfoEnabled())
    {
      logCall[2] +=1;
      LOG4CXX_INFO(logger[i][0], *message);
    }
}

 void          Log4::logWarn(int i, std::string *message)
{
  if (logger[i][0]->isWarnEnabled())
    {
      logCall[3] +=1;
      LOG4CXX_WARN(logger[i][0], *message);
    }
}
 void          Log4::logError(int i, std::string *message)
{
  if (logger[i][0]->isErrorEnabled())
    {
      logCall[4] +=1;
      LOG4CXX_ERROR(logger[i][0], *message);
    }
}

 void          Log4::logFatal(int i, std::string *message)
{
  if (logger[i][0]->isFatalEnabled())
    {
      logCall[5] +=1;
      LOG4CXX_FATAL(logger[i][0], *message);
    }
}
