#ifndef LOGGER_H
#define LOGGER_H

#include "config.h"
#include "Singleton.h"
#include "engineString.h"

#ifndef COMPILE_PSP
#include <iostream>
#endif


namespace psp {

class ILogger : public TSingletonVirtual<ILogger, true>
{
public :
    //! Log a message (C format)
    static void Log(const char* parFormat, ...);
#ifdef COMPILE_PC
    //! Log a message (C++ format)
    static ILogger& Log();
    template <class T> ILogger& operator <<(const T& parToLog);
#endif
	//! Close the output buffer
	virtual void Close() = 0;

private :
	//! Register a message in the output buffer
    virtual void Write(const engine::core::stringc & parMsg) = 0;
};

// C++ format
#define LOG				::psp::ILogger::Log()
// C format
// TODO : verify if its work on PC now
#ifndef WIN32
# define LOGC			::psp::ILogger::Log
#else
# define LOGC			
#endif
#define LOGCLOSE		::psp::ILogger::Instance().Close();

#define LOGINSTANCE(LOGGER)	if(::psp::ILogger::HasInstance())						\
							{														\
								LOGCLOSE											\
								::psp::ILogger::Destroy();							\
							}														\
							::psp::ILogger::SetInstance(new ::psp::LOGGER());

#define REPORTLEAKS if(::psp::ILogger::HasInstance())						\
					{														\
						LOGCLOSE											\
						::psp::ILogger::Destroy();							\
					}														\
					::psp::ILogger::SetInstance(new ::psp::TLoggerFile("ms0:/PSP/GAME/Hide-And-Seek/Log/leaks.log", false)); \
					::psp::TMemoryDomain::ReportLeaks();

#define HasLoggerInstance() ::psp::ILogger::HasInstance()

#ifdef IA_LOG
# define LOGC_IA LOGC
#else
# define LOGC_IA DoNothingLog
#endif

#ifdef MEM_LOG
# define LOGC_MEM LOGC
#else
# define LOGC_MEM DoNothingLog
#endif

#ifdef _3D_LOG
# define LOGC_3D LOGC
#else
# define LOGC_3D DoNothingLog
#endif

#ifdef LOAD_LOG
# define LOGC_LOAD LOGC
#else
# define LOGC_LOAD DoNothingLog
#endif

#ifdef CORE_LOG
# define LOGC_CORE LOGC
#else
# define LOGC_CORE DoNothingLog
#endif

#ifdef SOUND_LOG
# define LOGC_SOUND LOGC
#else
# define LOGC_SOUND DoNothingLog
#endif

} // psp namespace

#endif
