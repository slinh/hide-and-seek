#ifndef LOGGERTYPES_H
#define LOGGERTYPES_H

#include "config.h"
#include "Logger.h"
#include "WriteFile.h"

namespace psp {

// Debug output stream
class TLoggerDebug : public ILogger
{
public :
	virtual void Close()
	{}

private :
    virtual void Write(const engine::core::stringc& parMsg)
    {
#if defined(COMPILE_PC)
		std::cout << parMsg.c_str();
#elif defined(COMPILE_PSP)
 		print("%s", parMsg.c_str());
#endif
    }
};

// Dialog output stream
class TLoggerMsgBox : public ILogger
{
public :
	virtual void Close()
	{}

private :
    virtual void Write(const engine::core::stringc& parMsg)
    {
		LAssertNotImplemented();
#if defined(COMPILE_PC)
		std::cout << parMsg.c_str();
#elif defined(COMPILE_PSP)
 		print("%s", parMsg.c_str());
#endif
    }
};

// Log file output stream
class TLoggerFile : public ILogger
{
public :
#ifdef COMPILE_PC
    TLoggerFile(const char* parFilename = "Log/output.log", bool parAppend = false) : FFile(parFilename, parAppend)
#elif defined(COMPILE_PSP)
	TLoggerFile(const char* parFilename = "ms0:/PSP/GAME/Hide-And-Seek/Log/output.log", bool parAppend = false) : FFile(parFilename, parAppend)
#endif
	{}

	virtual void Close()
	{
		FFile.Close();
	}

private :
    virtual void Write(const engine::core::stringc& parMessage)
    {
    	FFile.Write(parMessage.c_str(), parMessage.size());
    }

	engine::io::TWriteFile FFile;
};

} // psp namespace

#endif
