/*
 * UART_int.h
 *
 *  Created on: Jul 11, 2019
 *      Author: hosam
 */

#ifndef UART_INT_H_
#define UART_INT_H_

void UART_init(long UART_BAUDRATE);
int UART_RxChar();
void UART_TxChar(char ch);
void UART_SendString(char *str);
int *UART_ReturnString();


#endif /* UART_INT_H_ */
