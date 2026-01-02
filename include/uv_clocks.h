#ifndef PILOTWINGS64_UV_CLOCKS
#define PILOTWINGS64_UV_CLOCKS

#include <ultra64.h>

typedef struct uvClockState {
    s32 unk0;
    s32 unk4;
} uvClockState_t;

void func_80205FD0(void);
void func_80205FFC(void);
f64 uvClkGetSec(s32 clk_id);
void func_80206150(s32 arg0);

#endif // PILOTWINGS64_UV_CLOCKS

