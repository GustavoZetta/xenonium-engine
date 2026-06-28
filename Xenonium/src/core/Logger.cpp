#include "core/Logger.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

namespace Xenonium {
	namespace Logger {
		namespace {
			std::string GetTime() {
				auto now = std::chrono::system_clock::now();

				std::time_t c_time = std::chrono::system_clock::to_time_t(now);

				std::tm* local_time = std::localtime(&c_time);

				std::stringstream ss;
				ss << "[" << std::put_time(local_time, "%T") << "]";

				return ss.str();
			}
			std::string GetLoggerLevel(LoggerLevel l) {
				switch (l) {
				case LoggerLevel::FATAL:
					return "[FATAL]";
				case LoggerLevel::ERROR:
					return "[ERROR]";
				case LoggerLevel::WARN:
					return "[WARN]";
				case LoggerLevel::INFO:
					return "[INFO]";
				case LoggerLevel::SUCCESS:
					return "[SUCCESS]";
				default:
					return "[INFO]";
				}
			}
		}

		void Log(LoggerLevel level, const std::string& message) {
			std::string time = GetTime();
			std::string l = GetLoggerLevel(level);

			std::cout << time << l << " " << message << "\n";
		}

		void Fatal(const std::string& message) {
			Log(LoggerLevel::FATAL, message);
		}
		void Error(const std::string& message) {
			Log(LoggerLevel::ERROR, message);
		}
		void Warn(const std::string& message) {
			Log(LoggerLevel::WARN, message);
		}
		void Info(const std::string& message) {
			Log(LoggerLevel::INFO, message);
		}
		void Success(const std::string& message) {
			Log(LoggerLevel::SUCCESS, message);
		}
	}
}