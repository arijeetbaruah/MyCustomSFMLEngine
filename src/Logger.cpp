#include "../include/Logger.hpp"

void Logger::setPrefix(const LogLevel& messageLevel)
{
	switch (messageLevel)
	{
	case LogLevel::DEBUG:
		logPrefix_ = "[DEBUG] ";
		break;
	case LogLevel::INFO:
		logPrefix_ = "[INFO] ";
		break;
	case LogLevel::ERROR:
		logPrefix_ = "[ERROR] ";
		break;
	default:
		break;
	}
}

void Logger::setLogLevel(const LogLevel& logLevel)
{
	currentLogLevel_ = logLevel;
}


void Logger::log(const LogLevel& messageLevel, const std::string& message)
{
	if (messageLevel == LogLevel::NO)
		return;
	if (currentLogLevel_ != LogLevel::DEBUG)
	{
		if (messageLevel == LogLevel::ERROR && currentLogLevel_ !=
			LogLevel::ERROR)
			return;
		if (messageLevel == LogLevel::INFO && currentLogLevel_ !=
			LogLevel::INFO)
			return;
	}

	setPrefix(messageLevel);

	std::cout << logPrefix_ << message << std::endl;
}
