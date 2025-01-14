/*
* Copyright 2019 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "fsl_common.h"
#include "clock_config.h"
#include "system_JN5189.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* System clock frequency. */
extern uint32_t SystemCoreClock;

/*******************************************************************************
 * Code
 ******************************************************************************/
void BOARD_BootClockVLPR(void)
{
}

void BOARD_BootClockRUN(void)
{
    /* Set PMC FRO selection */
    CLOCK_EnableClock(kCLOCK_Fro48M);
    CLOCK_EnableClock(kCLOCK_Rtc);

    /* INMUX and IOCON are used by many apps, enable both INMUX and IOCON clock bits here. */
    //CLOCK_AttachClk(kOSC32M_to_FRG_CLK);
  
    CLOCK_SetClkDiv(kCLOCK_DivClkout, 1, false);

    CLOCK_EnableClock(kCLOCK_Xtal32M);
    CLOCK_EnableClock(kCLOCK_Xtal32k);
    CLOCK_AttachClk(kXTAL32K_to_OSC32K_CLK);

    /* Enable 48MHz CPU freq */
    CLOCK_AttachClk(kFRO48M_to_MAIN_CLK);

    /* WWDT clock config (32k oscillator, no division) */
    CLOCK_AttachClk(kOSC32K_to_WDT_CLK);
    CLOCK_SetClkDiv(kCLOCK_DivWdtClk, 1, true);

    /* enable the clocks for the cryto blocks */
    CLOCK_EnableClock(kCLOCK_Aes);

    SystemCoreClockUpdate();
}

void BOARD_BootClockHSRUN(void)
{
}
