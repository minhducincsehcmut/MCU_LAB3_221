/*
 * fsm.c
 *
 *  Created on: Nov 15, 2022
 *      Author: duchu
 */


#include "fsm.h"
#include "main.h"
#include "global.h"
#include "button.h"
#include "display_led.h"
#include "duration.h"

void fsm_run(){
	switch(current_mode){
	case INIT:                      // INIT
		clear();
		current_mode = MODE_1;
		traffic_state[ROW] = DISP_INIT;      //ROW
		traffic_state[COL] = DISP_INIT;      //COLUMN
		setTimer(TIMER_7SEG, 250);
		break;
	case MODE_1:                            // switch from auto to manual mode
		display_led(ROW);
		display_led(COL);
		display_time_7seg();
		if (checkPressed(NO_1)){                   //pressing button 1 to change to next mode
			current_mode = MODE_2;
			change(MODE_2);
			setTimer(TIMER_LED, 500);
			clear();
		}
		break;


	case MODE_2:                             //RED
		blinky_led(LED_RED);
		display_time_7seg();


		if (checkPressed(NO_1)){                  //pressing button 1 to change to next mode
			current_mode = MODE_3;
			change(MODE_3);
			setTimer(TIMER_LED, 500);
			clear();
		}

		if (checkPressed(NO_2)) {
			increase_duration();
		}
		if (checkPressed(NO_3)) {
			update(LED_RED);
		}
		break;


	case MODE_3:                            // AMBER(YELLOW)

		blinky_led(LED_AMBER);
		display_time_7seg();
		if (checkPressed(NO_1)){                  //pressing button 1 to change to next mode
			current_mode = MODE_4;
			change(MODE_4);
			setTimer(TIMER_LED, 500);
			clear();
		}
		if (checkPressed(NO_2)){
			increase_duration();
		}
		if (checkPressed(NO_3)) {
			update(LED_AMBER);
		}
		break;
	case MODE_4:                         // GREEN
		blinky_led(LED_GREEN);
		display_time_7seg();
		if (checkPressed(NO_1)){                    //pressing button 1 to change to next mode
			current_mode = MODE_1;
			traffic_state[ROW] = DISP_INIT;
			traffic_state[COL] = DISP_INIT;
			clear();
		}
		if (checkPressed(NO_2)) {
			increase_duration();
		}
		if (checkPressed(NO_3)) {
			update(LED_GREEN);
		}
		break;
	default:
		break;
	}
}
