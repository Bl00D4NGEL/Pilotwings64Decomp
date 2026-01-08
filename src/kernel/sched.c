#include <uv_sched.h>

#define VIDEO_MSG       666
#define RSP_DONE_MSG    667
#define RDP_DONE_MSG    668
#define PRE_NMI_MSG     669

extern u8 gSchedRspStatus;
extern u8 gSchedRdpStatus;
extern OSMesgQueue gSchedMsgQ;

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/func_8022B0A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScDoneGfx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScDoneAud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScRunAud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScRunGfx.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScDlistRecover.s")
void _uvScDlistRecover(void) {
    _uvDebugPrintf("Recovered from a bad display list\n");

    IO_WRITE(SP_STATUS_REG, 0x2902);
    if (gSchedRspStatus != 0) {
        osSendMesg(&gSchedMsgQ, (OSMesg)RSP_DONE_MSG, 0);
    }
    if (gSchedRdpStatus != 0) {
        osSendMesg(&gSchedMsgQ, (OSMesg)RDP_DONE_MSG, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScCreateScheduler.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScAddClient.s")
void _uvScAddClient(OSSched* sc, OSScClient* client, OSMesgQueue* mq) {
    client->msgQ = mq;
    client->next = sc->clientList;
    sc->clientList = (OSScClient* )client;
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScGetCmdQ.s")
OSMesgQueue *_uvScGetCmdQ(OSSched *s) {
    return &s->cmdQ;
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScMain.s")
void _uvScMain(void* arg0) {
    OSMesg msg;
    msg = NULL;

    while (1) {
        osRecvMesg(&gSchedMsgQ, &msg, 1);

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

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScHandleRetrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScHandleRSP.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScHandleRDP.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScHandleNMI.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/func_8022BEB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScLogCpuEvent.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/_uvScLogIntoRing.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/func_8022C34C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sched/func_8022C3C0.s")

