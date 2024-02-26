#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>

namespace Fern {
	class FERN_API Log{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros

#define FN_CORE_TRACE(...)     ::Fern::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FN_CORE_INFO(...)      ::Fern::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FN_CORE_WARN(...)      ::Fern::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FN_CORE_ERROR(...)     ::Fern::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FN_CORE_CRITICAL(...)  ::Fern::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros

#define FN_TRACE(...)     ::Fern::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FN_INFO(...)      ::Fern::Log::GetClientLogger()->info(__VA_ARGS__)
#define FN_WARN(...)      ::Fern::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FN_ERROR(...)     ::Fern::Log::GetClientLogger()->error(__VA_ARGS__)
#define FN_CRITICAL(...)  ::Fern::Log::GetClientLogger()->critical(__VA_ARGS__)