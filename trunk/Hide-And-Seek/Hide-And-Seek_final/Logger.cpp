#include "Logger.h"

#include <cstdarg>
#include <sstream>

namespace psp {

void ILogger::Log(const char* parFormat, ...)
{
    // Formatage du message dans une chaîne de caractère
    char locBuffer[512];
    va_list Params;
    va_start(Params, parFormat);
#ifdef COMPILE_PC
    vsprintf_s(locBuffer, parFormat, Params);
#else
    vsprintf(locBuffer, parFormat, Params);
#endif
    va_end(Params);
	
    // Loggization
    Instance().Write(locBuffer);
}

#ifdef COMPILE_PC
ILogger& ILogger::Log()
{
    return Instance();
}


template <class T> ILogger& ILogger::operator <<(const T& parToLog)
{
    std::ostringstream locStream;
    locStream << parToLog;
    Write(locStream.str().c_str());

    return Instance();
}
#endif

}
