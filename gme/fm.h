/*
  File: fm.h -- header file for software emulation for FM sound generator

*/

#pragma once

#include "mamedef.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BUILD_YM2203  1
#define BUILD_YM2612  1

/* select bit size of output : 8 or 16 */
#define FM_SAMPLE_BITS 16

/* select timer system internal or external */
#define FM_INTERNAL_TIMER 1

/* --- speedup optimize --- */
/* busy flag enulation , The definition of FM_GET_TIME_NOW() is necessary. */
//#define FM_BUSY_FLAG_SUPPORT 1



typedef stream_sample_t FMSAMPLE;
/*
#if (FM_SAMPLE_BITS==16)
typedef INT16 FMSAMPLE;
#endif
#if (FM_SAMPLE_BITS==8)
typedef unsigned char  FMSAMPLE;
#endif
*/

/* FM_TIMERHANDLER : Stop or Start timer         */
/* int n          = chip number                  */
/* int c          = Channel 0=TimerA,1=TimerB    */
/* int count      = timer count (0=stop)         */
/* doube stepTime = step time of one count (sec.)*/

/* FM_IRQHHANDLER : IRQ level changing sense     */
/* int n       = chip number                     */
/* int irq     = IRQ level 0=OFF,1=ON            */

typedef struct _ssg_callbacks ssg_callbacks;
struct _ssg_callbacks
{
	void (*set_clock)(void *param, int clock);
	void (*write)(void *param, int address, int data);
	int (*read)(void *param);
	void (*reset)(void *param);
};

#if BUILD_YM2203
/* -------------------- YM2203(OPN) Interface -------------------- */

/*
** Initialize YM2203 emulator(s).
**
** 'num'           is the number of virtual YM2203's to allocate
** 'baseclock'
** 'rate'          is sampling rate
** 'TimerHandler'  timer callback handler when timer start and clear
** 'IRQHandler'    IRQ callback handler when changed IRQ level
** return      0 = success
*/
//void * ym2203_init(void *param, const device_config *device, int baseclock, int rate,
//               FM_TIMERHANDLER TimerHandler,FM_IRQHANDLER IRQHandler, const ssg_callbacks *ssg);
void * ym2203_init(void *param, int baseclock, int rate, const ssg_callbacks *ssg);

/*
** shutdown the YM2203 emulators
*/
void ym2203_shutdown(void *chip);

/*
** reset all chip registers for YM2203 number 'num'
*/
void ym2203_reset_chip(void *chip);

/*
** update one of chip
*/
void ym2203_update_one(void *chip, FMSAMPLE **buffer, int length);

/*
** Write
** return : InterruptLevel
*/
int ym2203_write(void *chip,int a,unsigned char v);

/*
** Read
** return : InterruptLevel
*/
unsigned char ym2203_read(void *chip,int a);

/*
**  Timer OverFlow
*/
int ym2203_timer_over(void *chip, int c);

/*
**  State Save
*/
void ym2203_postload(void *chip);

void ym2203_set_mutemask(void *chip, UINT32 MuteMask);
#endif /* BUILD_YM2203 */

#if (BUILD_YM2612||BUILD_YM3438)
//void * ym2612_init(void *param, const device_config *device, int baseclock, int rate,
//               FM_TIMERHANDLER TimerHandler,FM_IRQHANDLER IRQHandler);
void * ym2612_init(int baseclock, int rate);
void ym2612_shutdown(void *chip);
void ym2612_reset_chip(void *chip);
void ym2612_update_one(void *chip, FMSAMPLE **buffer, int length);

int ym2612_write(void *chip, int a,unsigned char v);
unsigned char ym2612_read(void *chip,int a);

void ym2612_set_mutemask(void *chip, UINT32 MuteMask);
void ym2612_setoptions(void *chip, UINT8 Flags);
#endif /* (BUILD_YM2612||BUILD_YM3438) */

#ifdef __cplusplus
};
#endif