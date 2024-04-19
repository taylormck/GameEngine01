/**
 * @file Default logger for the engine
 */

#ifndef ENGINE_LOGGER_HPP
#define ENGINE_LOGGER_HPP

#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Engine {
class Logger {
public:
	static std::shared_ptr<spdlog::logger> GetCoreLogger();

}; // class Logger
}; // namespace Engine

#ifndef DISABLE_LOGGING

#define ENGINE_LOG_TRACE(...) ::Engine::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define ENGINE_LOG_INFO(...) ::Engine::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define ENGINE_LOG_WARN(...) ::Engine::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define ENGINE_LOG_ERROR(...) ::Engine::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define ENGINE_LOG_CRITICAL(...) ::Engine::Logger::GetCoreLogger()->critical(__VA_ARGS__)

#endif // DISABLE_LOGGING

#endif // ENGINE_LOGGER_HPP
