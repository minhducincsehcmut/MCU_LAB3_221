/*
 * button.c
 *
 *  Created on: Nov 15, 2022
 *      Author: duchu
 */


#include "button.h"
#include "main.h"
#define IS_PRESSED		GPIO_PIN_RESET
#define IS_RELEASED		GPIO_PIN_SET
//Store button state to debouncing
int KeyReg0[NO_OF_BUTTONS] = {IS_RELEASED};
int KeyReg1[NO_OF_BUTTONS] = {IS_RELEASED};
int KeyReg2[NO_OF_BUTTONS] = {IS_RELEASED};
int KeyReg3[NO_OF_BUTTONS] = {IS_RELEASED};
int TimeOutForKeyPress[NO_OF_BUTTONS] = {500};
int flag[NO_OF_BUTTONS];

void button_reading(void){
	for (int i = 0; i < NO_OF_BUTTONS; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		switch (i){                                           // button is being read
		case NO_1:
			KeyReg0[i] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2);
			break;
		case NO_2:
			KeyReg0[i] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
			break;
		case NO_3:
			KeyReg0[i] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
			break;
		default:
			break;
		}
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];

				if (KeyReg3[i] == IS_PRESSED){
					TimeOutForKeyPress[i] = 500;
					subKeyProcess(i);
				}
			} else {
				TimeOutForKeyPress[i] --;
				if (TimeOutForKeyPress[i] == 0){
				  KeyReg3[i] = IS_RELEASED;
				}
			}
		}
	}
}

void subKeyProcess(int index){
	flag[index] = 1;
}

int checkPressed(int index){
	if (flag[index] == 1){
		flag[index] = 0;
		return 1;
	}
	return 0;
}

