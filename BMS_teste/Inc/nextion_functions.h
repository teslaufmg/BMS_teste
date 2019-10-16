/*
 * nextion_functions.h
 *
 *  Created on: 13 de ago de 2019
 *      Author: Rodolfo Lessa
 */

#ifndef NEXTION_FUNCTIONS_H_
#define NEXTION_FUNCTIONS_H_

#include "BMS.h"
#include "DMA_USART.h"

// NEXTION PAGES DEFINES
#define N_PAGE0 0
#define N_PAGE1 1
#define N_PAGE2 2
#define N_PAGE3 3
#define N_PAGE4 4
#define N_PAGE5 5
#define N_PAGE6 6
#define N_PAGE7 7

// NEXTION VARIABLES DEFINES
#define Cell_01 0
#define Cell_02 1
#define Cell_03 2
#define Cell_04 3
#define Cell_05 4
#define Cell_06 5
#define Cell_07 6
#define Cell_08 7
#define Cell_09 8
#define Cell_10 9
#define Cell_11 10
#define Cell_12 11

uint8_t actual_page;

void uart3MessageReceived(void);
uint8_t nexSetPageError(BMS_struct *BMS);
void nexLoop(BMS_struct *BMS);

#endif /* NEXTION_FUNCTIONS_H_ */
