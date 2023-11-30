#ifndef LOGGER_H
#define LOGGER_H

#include <sstream>
#include <iostream>
#include "Singleton.hpp"

enum class LogLevel
{
	NO = 0,
	ERROR = 1,
	INFO = 2,
	DEBUG = 3
};

class Logger : public Singleton<Logger>
{
public:
	void setLogLevel(const LogLevel& logLevel);

	void log(const LogLevel& messageLevel, const std::string& message);

private:

	void setPrefix(const LogLevel& messageLevel);

	std::string logPrefix_;
	LogLevel currentLogLevel_ = LogLevel::NO;
	LogLevel messageLevel_ = LogLevel::NO;
};

#endif
