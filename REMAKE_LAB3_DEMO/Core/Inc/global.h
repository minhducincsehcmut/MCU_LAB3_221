/*
 * global.h
 *
 *  Created on: Nov 15, 2022
 *      Author: duchu
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "software_timer.h"
#include "button.h"
extern int flagTimer1;
extern int current_mode;
extern int traffic_duration[3];
extern int traffic_state[2];
extern int traffic_curr_time[2];
extern int traffic_time_buffer[2][2];

#endif /* INC_GLOBAL_H_ */
