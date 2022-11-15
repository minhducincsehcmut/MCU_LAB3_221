/*
 * button.h
 *
 *  Created on: Nov 15, 2022
 *      Author: duchu
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NO_OF_BUTTONS 	3

#define NO_1	0
#define NO_2	1
#define NO_3	2

void button_reading(void);
int checkPressed(int index);
void subKeyProcess(int index);

#endif /* INC_BUTTON_H_ */
