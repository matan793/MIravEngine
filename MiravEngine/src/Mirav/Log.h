#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
namespace Mirav {
	class Mirav_API Log
	{
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
#define MV_CORE_TRACE(...)    ::Mirav::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MV_CORE_INFO(...)     ::Mirav::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MV_CORE_WARN(...)     ::Mirav::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MV_CORE_ERROR(...)    ::Mirav::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MV_CORE_FATAL(...)    ::Mirav::Log::GetCoreLogger()->fatal(__VA_ARGS__)
							
// Client log macros		
#define MV_TRACE(...)	      ::Mirav::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MV_INFO(...)	      ::Mirav::Log::GetClientLogger()->info(__VA_ARGS__)
#define MV_WARN(...)	      ::Mirav::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MV_ERROR(...)	      ::Mirav::Log::GetClientLogger()->error(__VA_ARGS__)
#define MV_CRITICAL(...)	      ::Mirav::Log::GetClientLogger()->critical(__VA_ARGS__)
