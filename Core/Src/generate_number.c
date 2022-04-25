#include "generate_number.h"
#include "usart.h"
#include "rtc.h"
#include <stdlib.h>
#include <stdio.h>

void generate_position(uint8_t* x, uint8_t* y){
	RTC_TimeTypeDef time;
	RTC_DateTypeDef date;

	HAL_RTC_GetTime(&hrtc, &time, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &date, RTC_FORMAT_BIN);
	srand(time.Seconds);
	*x = (uint8_t)rand()%83;
	*y = (uint8_t)rand()%48;
}

