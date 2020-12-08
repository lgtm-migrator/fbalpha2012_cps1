/* FM timers */

#define TIMER_TICKS_PER_SECOND (2048000000)
#define MAKE_TIMER_TICKS(n, m) ((INT64)(n) * TIMER_TICKS_PER_SECOND / (m))
#define MAKE_CPU_CYLES(n, m) ((INT64)(n) * (m) / TIMER_TICKS_PER_SECOND)

extern "C" double BurnTimerGetTime(void);

/* Callbacks for various sound chips */
/* period = cnt * stepTime in seconds */
void BurnOPNTimerCallback(INT32 n, INT32 c, INT32 cnt, double stepTime);	
/* period in seconds */
void BurnOPLTimerCallback(INT32 c, double period);
/* period in milliseconds */
void BurnYMFTimerCallback(INT32 n, INT32 c, double period);

/* Start / stop a timer */
/* period in seconds */
void BurnTimerSetRetrig(INT32 c, double period);
/* period in seconds */
void BurnTimerSetOneshot(INT32 c, double period);

extern double dTime;

void BurnTimerExit(void);
void BurnTimerReset(void);
INT32 BurnTimerInit(INT32 (*pOverCallback)(INT32, INT32), double (*pTimeCallback)());
INT32 BurnTimerAttachSek(INT32 nClockspeed);
INT32 BurnTimerAttachZet(INT32 nClockspeed);
INT32 BurnTimerAttachM6809(INT32 nClockspeed);
INT32 BurnTimerAttachHD6309(INT32 nClockspeed);
INT32 BurnTimerAttachM6800(INT32 nClockspeed);
INT32 BurnTimerAttachHD63701(INT32 nClockspeed);
INT32 BurnTimerAttachM6803(INT32 nClockspeed);
INT32 BurnTimerAttachM6502(INT32 nClockspeed);
INT32 BurnTimerAttachSh2(INT32 nClockspeed);
INT32 BurnTimerAttachH6280(INT32 nClockspeed);
void BurnTimerScan(INT32 nAction, INT32* pnMin);
INT32 BurnTimerUpdate(INT32 nCycles);
void BurnTimerUpdateEnd(void);
void BurnTimerEndFrame(INT32 nCycles);
