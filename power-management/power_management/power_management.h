#ifndef POWER_MANAGEMENT_H
#define POWER_MANAGEMENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f3xx_hal.h"

///**
// * @brief Enable SWD interface
// */
//void DebugON();
//
///**
// * @brief Disable SWD interface, remap PA13, PA14 to GPIO_MODE_OUTPUT_PP
// */
//void DebugOFF();

/**
 * @brief Enter Sleep Mode
 * @note Enable any interrupt to wake up from this mode
 */
void SleepMode();

/**
 * @brief Enter Stop Mode
 * @note Enable either EXTI or RTC interrupt to wake up from this mode
 * @param SystemClock_Config Pointer to function that reinitialize system clock
 */
void StopMode(void (*SystemClock_Config)());

/**
 * @brief Enter Standby Mode
 * @note This function enables WKUP pin as well
 * @param WakeUpPinx Wakeup Pin PWR_WAKEUP_PINx depending on MCU you use
 */
void StandbyMode(uint32_t WakeUpPinx);

#ifdef __cplusplus
}
#endif

#endif //POWER_MANAGEMENT_H
