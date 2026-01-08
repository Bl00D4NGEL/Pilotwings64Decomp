#ifndef PILOTWINGS64_UV_SCHED
#define PILOTWINGS64_UV_SCHED

#include <ultra64.h>
#include <PR/sched.h>
#include <uv_util.h>

void _uvScDlistRecover(void);
void _uvScCreateScheduler(OSSched* sc, void* stack, s32 priority, u8 mode, u8 numFields);
void _uvScAddClient(OSSched *s, OSScClient *c, OSMesgQueue *msgQ);
OSMesgQueue* _uvScGetCmdQ(OSSched *s);
void _uvScMain(void* arg);
void _uvScHandleRetrace(void);
void _uvScHandleRSP(void);
void _uvScHandleRDP(void);
void _uvScHandleNMI(void);

#endif // PILOTWINGS64_UV_SCHED

