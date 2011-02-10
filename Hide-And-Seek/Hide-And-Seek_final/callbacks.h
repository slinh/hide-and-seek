#ifndef common_callbacks_h
#define common_callbacks_h

#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef COMPILE_PSP

int running();
int setupCallbacks();

#endif

#ifdef __cplusplus
}
#endif

#endif
