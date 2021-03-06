#ifndef _CTR_DEBUG_H__
#define _CTR_DEBUG_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
void wait_for_input(void);
void dump_result_value(Result val);
#ifdef __cplusplus
}
#endif

#define DEBUG_HOLD() do{printf("%s@%s:%d.\n",__FUNCTION__, __FILE__, __LINE__);fflush(stdout);wait_for_input();}while(0)
#define DEBUG_STR(X) printf( "%s: %s\n", #X, (char*)(X))
#define DEBUG_VAR(X) printf( "%-20s: 0x%08X\n", #X, (u32)(X))
#define DEBUG_VAR64(X) printf( #X"\r\t\t\t\t : 0x%016llX\n", (u64)(X))
#define DEBUG_ERROR(X) do{if(X)dump_result_value(X)}while(0)
#define PRINTFPOS(X,Y) "\x1b["#X";"#Y"H"
#define PRINTFPOS_STR(X,Y) "\x1b["X";"Y"H"

#endif //_CTR_DEBUG_H__
