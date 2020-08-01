#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace oep
{
	class OEP_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr <spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr <spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr <spdlog::logger> s_ClientLogger;
		static std::shared_ptr <spdlog::logger> s_CoreLogger;
	};
};

//Core log errors
#define OEP_CORE_ERROR(...)		::oep::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OEP_CORE_WARN(...)		::oep::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OEP_CORE_INFO(...)		::oep::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OEP_CORE_TRACE(...)		::oep::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OEP_CORE_FATAL(...)		::oep::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log errors

#define OEP_ERROR(...)		::oep::Log::GetClientLogger()->error(__VA_ARGS__)
#define OEP_WARN(...)		::oep::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OEP_INFO(...)		::oep::Log::GetClientLogger()->info(__VA_ARGS__)
#define OEP_TRACE(...)		::oep::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OEP_FATAL(...)		::oep::Log::GetClientLogger()->fatal(__VA_ARGS__)


