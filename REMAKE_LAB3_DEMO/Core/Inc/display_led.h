/*
 * display_led.h
 *
 *  Created on: Nov 15, 2022
 *      Author: duchu
 */

#ifndef INC_DISPLAY_LED_H_
#define INC_DISPLAY_LED_H_

#define LED_RED		0
#define LED_AMBER	1
#define LED_GREEN	2

#define DISP_INIT	202
#define DISP_RED 	203
#define DISP_GREEN 	204
#define DISP_AMBER 	205

void clear();
void debug_led();
void clear_debug_led();
void blinky_led(int index);
void display_7_seg(int num);
void enable_7_seg(int index);
void display_light(int index, int type);
void display_time_7seg();
void display_led(int index);

#endif /* INC_DISPLAY_LED_H_ */
