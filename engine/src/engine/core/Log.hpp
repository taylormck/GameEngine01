/**
 * @file Default logger for the engine
 */

#ifndef ENGINE_LOGGER_HPP
#define ENGINE_LOGGER_HPP

#include <memory>

// Forward declaration of our logger class.
// Using a forward declaration allows us to avoid requiring the client
// to link the spdlog library.
namespace spdlog {
class logger;
};

namespace Engine {
class Logger {
private:
	std::shared_ptr<spdlog::logger> _logger;

	Logger(std::string name);
	~Logger();

public:
	void trace(const char *msg...);
	void info(const char *msg...);
	void warn(const char *msg...);
	void error(const char *msg...);
	void critical(const char *msg...);

	static Logger &GetCoreLogger();
	static Logger &GetAppLogger();

}; // class Logger
}; // namespace Engine

#ifdef DISABLE_LOGGING

#define ENGINE_LOG_TRACE(...)
#define ENGINE_LOG_INFO(...)
#define ENGINE_LOG_WARN(...)
#define ENGINE_LOG_ERROR(...)
#define ENGINE_LOG_CRITICAL(...)

#define APP_LOG_TRACE(...)
#define APP_LOG_INFO(...)
#define APP_LOG_WARN(...)
#define APP_LOG_ERROR(...)
#define APP_LOG_CRITICAL(...)

#else

#define ENGINE_LOG_TRACE(...) ::Engine::Logger::GetCoreLogger().trace(__VA_ARGS__)
#define ENGINE_LOG_INFO(...) ::Engine::Logger::GetCoreLogger().info(__VA_ARGS__)
#define ENGINE_LOG_WARN(...) ::Engine::Logger::GetCoreLogger().warn(__VA_ARGS__)
#define ENGINE_LOG_ERROR(...) ::Engine::Logger::GetCoreLogger().error(__VA_ARGS__)
#define ENGINE_LOG_CRITICAL(...) ::Engine::Logger::GetCoreLogger().critical(__VA_ARGS__)

#define APP_LOG_TRACE(...) ::Engine::Logger::GetAppLogger().trace(__VA_ARGS__)
#define APP_LOG_INFO(...) ::Engine::Logger::GetAppLogger().info(__VA_ARGS__)
#define APP_LOG_WARN(...) ::Engine::Logger::GetAppLogger().warn(__VA_ARGS__)
#define APP_LOG_ERROR(...) ::Engine::Logger::GetAppLogger().error(__VA_ARGS__)
#define APP_LOG_CRITICAL(...) ::Engine::Logger::GetAppLogger().critical(__VA_ARGS__)

#endif // DISABLE_LOGGING

#endif // ENGINE_LOGGER_HPP
