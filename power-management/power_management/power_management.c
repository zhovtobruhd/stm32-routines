#include "power_management.h"

//void DebugON() {
//    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_13 | GPIO_PIN_14);
//
//    __HAL_RCC_GPIOA_CLK_ENABLE();
//    GPIO_AF0_SWJ;
//    __HAL_AFIO_REMAP_SWJ_NOJTAG();
//}
//
//void DebugOFF() {
//    __HAL_AFIO_REMAP_SWJ_DISABLE();
//    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_13 | GPIO_PIN_14);
//
//    GPIO_InitTypeDef GPIO_InitStruct = {0};
//    __HAL_RCC_GPIOA_CLK_ENABLE();
//
//    /*Configure GPIO pin : PA13, PA14 */
//    GPIO_InitStruct.Pin = GPIO_PIN_13 | GPIO_PIN_14;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//}

void SleepMode() {
    HAL_SuspendTick();
    __HAL_RCC_PWR_CLK_ENABLE();
    HAL_PWR_EnterSLEEPMode(0, PWR_SLEEPENTRY_WFI);
    HAL_ResumeTick();
}

void StopMode(void (*SystemClock_Config)()) {
    HAL_SuspendTick();
    HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
    SystemClock_Config();
    HAL_ResumeTick();
}

void StandbyMode(uint32_t WakeUpPinx) {
    // Enable WKUP pin
    // MX_GPIO_Deinit();
    __HAL_RCC_PWR_CLK_ENABLE();
    // HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);
    __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
    HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
    HAL_PWR_EnterSTANDBYMode();
}



