/**
 * @file Default logger for the engine
 */

#ifndef ENGINE_LOGGER_HPP
#define ENGINE_LOGGER_HPP

#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <utility>

namespace Engine {
class Log {
private:
	std::shared_ptr<spdlog::logger> _logger;

	Log(std::string name) : _logger(spdlog::stdout_color_mt(name)) {}

	~Log() = default;

public:
	template <typename... Args> void Info(fmt::format_string<Args...> fmt, Args &&...args) {
		_logger->info(fmt, std::forward<Args>(args)...);
	}

	static Log &GetCoreLogger() {
		static Log coreLogger = Log("Engine Core");

		return coreLogger;
	}

	static Log &GetAppLogger() {
		static Log appLogger = Log("Application");

		return appLogger;
	}

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

#define ENGINE_LOG_TRACE(...) ::Engine::Log::GetCoreLogger().Trace(__VA_ARGS__)
#define ENGINE_LOG_INFO(...) ::Engine::Log::GetCoreLogger().Info(__VA_ARGS__)
#define ENGINE_LOG_WARN(...) ::Engine::Log::GetCoreLogger().Warn(__VA_ARGS__)
#define ENGINE_LOG_ERROR(...) ::Engine::Log::GetCoreLogger().Error(__VA_ARGS__)
#define ENGINE_LOG_CRITICAL(...) ::Engine::Log::GetCoreLogger().Critical(__VA_ARGS__)

#define APP_LOG_TRACE(...) ::Engine::Log::GetAppLogger().Trace(__VA_ARGS__)
#define APP_LOG_INFO(...) ::Engine::Log::GetAppLogger().Info(__VA_ARGS__)
#define APP_LOG_WARN(...) ::Engine::Log::GetAppLogger().Warn(__VA_ARGS__)
#define APP_LOG_ERROR(...) ::Engine::Log::GetAppLogger().Error(__VA_ARGS__)
#define APP_LOG_CRITICAL(...) ::Engine::Log::GetAppLogger().Critical(__VA_ARGS__)

#endif // DISABLE_LOGGING

#endif // ENGINE_LOGGER_HPP
