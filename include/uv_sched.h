#ifndef PILOTWINGS64_UV_SCHED
#define PILOTWINGS64_UV_SCHED

#include <ultra64.h>
#include <uv_util.h>

void _uvScMain(void* arg);
void _uvScHandleRetrace(void);
void _uvScHandleRSP(void);
void _uvScHandleRDP(void);
void _uvScHandleNMI(void);

#endif // PILOTWINGS64_UV_SCHED

