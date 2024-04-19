/**
 * @file implementation of the engine logger
 */

#include "./Log.hpp"
#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Engine {
std::shared_ptr<spdlog::logger> Logger::GetCoreLogger() {
	static std::shared_ptr<spdlog::logger> coreLogger = spdlog::stdout_color_mt("Engine Core");

	return coreLogger;
}
}; // namespace Engine
