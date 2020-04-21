/*
 * LCD_prog.c

 *
 *  Created on: Aug 17, 2018
 *      Author: seif
 */
/***********************Header file Inclusion******************************/
#include "LIB/types.h"
#include "util/delay.h"

#include "DIO_int.h"
#include "LCD_int.h"
#include "LCD_cfg.h"

void LCD_vidInit(void)
{
	/*Delay 30 ms to ensure the initialization of the LCD driver*/
	_delay_ms(30);
	/*Function set command*/
	LCD_vidSendCommand(LCD_FUNCSET_8BIT);
	_delay_ms(1);
	/* Display ON OFF control*/
	LCD_vidSendCommand(LCD_DISPON_CURSON);
	_delay_ms(1);
	/* Return Home  */
	LCD_vidSendCommand(LCD_HOME);
	_delay_ms(15);
	LCD_vidSendCommand(LCD_CLR);
	_delay_ms(15);
	/* Entry Mode Set  */
	LCD_vidSendCommand(LCD_ENTRYMODE);
	_delay_ms(2);

}

void LCD_vidSendCommand(u8 u8CmdCpy)
{
	/* Reset RS pin */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8LOW);
	/* Reset R/W pin*/
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8LOW);
	/* Set E to HIGH  */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8HIGH);
	/*Load command on data bus*/
	DIO_SetPortValue(LCD_DATA_PORT, u8CmdCpy);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8LOW);
	_delay_ms(5);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8HIGH);
	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);

}
void LCD_vidWriteData(u8 u8DataCpy)
{
	/* Reset RS pin */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8HIGH);
	/* Reset R/W pin*/
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8LOW);
	/* Set E to HIGH  */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8HIGH);
	/*Load command on data bus*/
	DIO_SetPortValue(LCD_DATA_PORT, u8DataCpy);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8LOW);
	_delay_ms(5);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8HIGH);
	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);
}

void LCD_String (char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)  /* send each char of string till the NULL */
	{
		LCD_vidWriteData (str[i]);  /* call LCD data write */
	}
}








