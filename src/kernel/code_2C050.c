#include <uv_sched.h>

#define VIDEO_MSG       666
#define RSP_DONE_MSG    667
#define RDP_DONE_MSG    668
#define PRE_NMI_MSG     669

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/func_8022B0A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/_uvScDoneGfx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/_uvScDoneAud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/_uvScRunAud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/_uvScRunGfx.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/_uvScDlistRecover.s")

extern u8 D_802B9C69;
extern u8 D_802B9C6A;
extern OSMesgQueue D_802C38E8;

void _uvScDlistRecover(void) {
    _uvDebugPrintf("Recovered from a bad display list\n");
    IO_WRITE(SP_STATUS_REG, 0x2902);
    if (D_802B9C69 != 0) {
        osSendMesg(&D_802C38E8, (void *)0x29B, 0);
    }
    if (D_802B9C6A != 0) {
        osSendMesg(&D_802C38E8, (void *)0x29C, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/_uvScCreateScheduler.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/func_8022B8A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/osScGetCmdQ.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/_uvScMain.s")
void _uvScMain(void* arg0) {
    OSMesg msg;
    msg = NULL;

    while (1) {
        osRecvMesg(&D_802C38E8, &msg, 1);

        switch ((int)msg) {
        case VIDEO_MSG:
            _uvScHandleRetrace();
            break;
        case RSP_DONE_MSG:
            _uvScHandleRSP();
            break;
        case RDP_DONE_MSG:
            _uvScHandleRDP();
            break;
        case PRE_NMI_MSG:
            _uvScHandleNMI();
            break;
        default:
            _uvDebugPrintf("unknown sched interrupt mesg: 0x%x\n", msg);
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/_uvScHandleRetrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/_uvScHandleRSP.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/_uvScHandleRDP.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/_uvScHandleNMI.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/func_8022BEB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/_uvScLogCpuEvent.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/_uvScLogIntoRing.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/func_8022C34C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2C050/func_8022C3C0.s")
