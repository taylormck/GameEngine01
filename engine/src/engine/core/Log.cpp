/**
 * @file implementation of the engine logger
 */

#include "./Log.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Engine {

Logger::Logger(std::string name) : _logger(spdlog::stdout_color_mt(name)) {}

Logger::~Logger() {}

void Logger::trace(const char *msg...) { _logger->trace(msg); }

void Logger::info(const char *msg...) { _logger->info(msg); }

void Logger::warn(const char *msg...) { _logger->warn(msg); }

void Logger::error(const char *msg...) { _logger->error(msg); }

void Logger::critical(const char *msg...) { _logger->critical(msg); }

Logger &Logger::GetCoreLogger() {
	static Logger coreLogger = Logger("Engine Core");

	return coreLogger;
}

Logger &Logger::GetAppLogger() {
	static Logger appLogger = Logger("Application");

	return appLogger;
}
}; // namespace Engine
