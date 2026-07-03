#pragma once

#include "XenoniumAPI.hpp"

#include <string>
#include <unordered_map>

namespace Xenonium {
	enum class LoggerLevel : int {
		FATAL = -3,
		ERROR = -2,
		WARN = -1,
		INFO = 0,
		SUCCESS = 1
	};

	
	// Logger format:
	// [HH:MM:SS][LoggerLevel] <Xenonium | Game>: [Message]
	namespace Logger {
		XENONIUM_API void Log(LoggerLevel level, const std::string& message);

		XENONIUM_API inline void Fatal(const std::string& message) {
			Log(LoggerLevel::FATAL, message);
		}
		XENONIUM_API inline void Error(const std::string& message) {
			Log(LoggerLevel::ERROR, message);
		}
		XENONIUM_API inline void Warn(const std::string& message) {
			Log(LoggerLevel::WARN, message);
		}
		XENONIUM_API inline void Info(const std::string& message) {
			Log(LoggerLevel::INFO, message);
		}
		XENONIUM_API inline void Success(const std::string& message) {
			Log(LoggerLevel::SUCCESS, message);
		}
	}
}