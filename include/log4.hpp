#ifndef LOG4_H_
# define LOG4_H_

#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/helpers/exception.h>

# define TRACE 0
# define DEBUG 1
# define INFO 2
# define WARN 3
# define ERROR 4
# define FATAL 5

using namespace log4cxx;
using namespace log4cxx::xml;
using namespace log4cxx::helpers;

class Log4
{
 public:
  
  Log4();
  Log4(char *);
  ~Log4();
  int	initLogger();
  void	initXML(std::string *);
  void	initLogFile(std::string *);
  int	addLogger(std::string *);
  void	useLogger(std::string *, std::string *, int);
  LoggerPtr	*getLogger(std::string *);
  
 private:

  int		getLoggerNbr();
  int		searchLogger(std::string *);
  void		logTrace(int, std::string *);
  void		logDebug(int, std::string *);
  void		logInfo(int, std::string *);
  void		logWarn(int, std::string *);
  void		logError(int, std::string *);
  void		logFatal(int, std::string *);

  LoggerPtr	**logger;
  std::string	**loggerName;
  std::string	log4Name;
  int		logCall[6];
  void		(Log4::*report[6])(int, std::string *);
};

#endif /* LOG_4_ */
