/*
 * main.c
 *
 *  Created on: Jul 11, 2019
 *      Author: hosam
 */
#define F_CPU 8000000UL			/* Define frequency here its 8MHz */
#include <avr/io.h>
#include <util/delay.h>
#include"LIB/types.h"
#include"LIB/util.h"
#include"AVRD/DIO_int.h"
#include"AVRD/LCD_cfg.h"
#include"AVRD/LCD_int.h"
#include"UART_int.h"


int main(void)
{
	char Data_in;
	int pas,open;
	int pass[2]={'1','2','3'};
	int iterator;
	int flag=0;
	u8 user;


	UART_init(9600);	/* initialize USART with 9600 baud rate */
	DDRC=0xff;			/* make PORT as output port */
	PORTC=0;
	PORTC |= (1<<PC2);
	PORTC &=~ (1<<PC4);

	DIO_SetPortDirection(LCD_DATA_PORT,DIO_u8OUTPUT);
	DIO_SetPortDirection(LCD_CONTROL_PORT,DIO_u8OUTPUT);
	LCD_vidInit();
	LCD_vidSendCommand(LCD_CLR);


	while(1)
	{
		LCD_String("CONTROL HOME");
			_delay_ms(3000);
			LCD_vidSendCommand(LCD_CLR);
			LCD_String("user:");
			LCD_vidSendCommand(LCD_u8LINE2_LOC0);
			LCD_String("password:");
		user=UART_RxChar();
		switch(user)
		{
		/*********************************/
		case '1':

		for (iterator = 0; iterator <3; iterator++)
								   {

			pas=UART_RxChar();
			//pass=UART_RxChar();

				if(pas==pass){
					do{
					LCD_vidSendCommand(LCD_CLR);
							LCD_String("WEL MOH");
					open=UART_RxChar();
							if(open=='5')
							{
							PORTC |= (1<<PC4);
							//
							_delay_ms(500);
							PORTC &=~ (1<<PC4);
							 open='6';
							}
//							else
//								break;
							}

					while(open=='5');

	do{

		Data_in = UART_RxChar();	/* receive data from Bluetooth device*/
		if(Data_in=='3')
		{
			PORTC |= (1<<PC0);
		}
		else if(Data_in == '4')
					{
						PORTC &= ~ (1<<PC0);
					}
		else if(Data_in =='1')
		{
			PORTC |= (1<<PC1); 			/* Turn ON LED */
		//	UART_SendString("LED_ON");/* send status of LED i.e. LED ON */

		}

		else if(Data_in=='2')
		{
			PORTC &= ~ (1<<PC1);			/* Turn OFF LED */
			//UART_SendString("LED_OFF"); /* send status of LED i.e. LED OFF */
		}
		flag=1;


}


while(pas=='9');

	}
else if(iterator<2)
{
	LCD_vidSendCommand(LCD_CLR);
	LCD_String("WRONG PASS");
	_delay_ms(1000);
	LCD_vidSendCommand(LCD_CLR);
	LCD_String("TRY AGAIN");

	PORTC |= (1<<PC3);
	_delay_ms(3000);
	PORTC &= ~ (1<<PC3);

}
						   }
		break;


		/**********************/
		case '2':

		for (iterator = 0; iterator <3; iterator++)
		{

		    pas=UART_RxChar();
		    if(pas=='8'){
		    	do{
		    						LCD_vidSendCommand(LCD_CLR);
		    								LCD_String("WEL ABD");
		    						open=UART_RxChar();
		    								if(open=='5')
		    								{
		    								PORTC |= (1<<PC4);
		    								//
		    								_delay_ms(500);
		    								PORTC &=~ (1<<PC4);
		    								 open='6';
		    								}
		    	//							else
		    	//								break;
		    								}

		    						while(open=='5');
		        do{

		            Data_in = UART_RxChar();    /* receive data from Bluetooth device*/
		            if(Data_in=='3')
		            {
		                PORTC |= (1<<PC0);
		            }
		            else if(Data_in == '4')
		            {
		                PORTC &= ~ (1<<PC0);
		            }
		            else if(Data_in =='1')
		            {
		                PORTC |= (1<<PC1);
		                //    UART_SendString("LED_ON");/* send status of LED i.e. LED ON */

		            }

		            else if(Data_in=='2')
		            {
		                PORTC &= ~ (1<<PC1);
		                //UART_SendString("LED_OFF"); /* send status of LED i.e. LED OFF */
		            }
		            flag=1;


		        }


		        while(pas=='8');

		    }
		    else if(iterator<2)
		    {
		    	LCD_vidSendCommand(LCD_CLR);
		    		LCD_String("WRONG PASS");
		    		_delay_ms(1000);
		    		LCD_vidSendCommand(LCD_CLR);
		    		LCD_String("TRY AGAIN");

		    		PORTC |= (1<<PC3);
		    		_delay_ms(3000);
		    		PORTC &= ~ (1<<PC3);

		    }
		}
		break;


		/**********************************/
		case '3':
		for (iterator = 0; iterator <3; iterator++)
		{

		    pas=UART_RxChar();
		    if(pas=='7'){
		    	do{
		    						LCD_vidSendCommand(LCD_CLR);
		    								LCD_String("WEL ALI");
		    						open=UART_RxChar();
		    								if(open=='5')
		    								{
		    								PORTC |= (1<<PC4);
		    								//
		    								_delay_ms(500);
		    								PORTC &=~ (1<<PC4);
		    								 open='6';
		    								}
		    	//							else
		    	//								break;
		    								}

		    						while(open=='5');
		        do{


		            Data_in = UART_RxChar();    /* receive data from Bluetooth device*/
		            if(Data_in=='3')
		            {
		                PORTC |= (1<<PC0);
		            }
		            else if(Data_in == '4')
		            {
		                PORTC &= ~ (1<<PC0);
		            }
		            else if(Data_in =='1')
		            {
		                PORTC |= (1<<PC1);
		                //    UART_SendString("LED_ON");/* send status of LED i.e. LED ON */

		            }

		            else if(Data_in=='2')
		            {
		                PORTC &= ~ (1<<PC1);
		                //UART_SendString("LED_OFF"); /* send status of LED i.e. LED OFF */
		            }
		            flag=1;


		        }


		        while(pas=='7');

		    }
		    else if(iterator<2)
		    {
		    	LCD_vidSendCommand(LCD_CLR);
		    		LCD_String("WRONG PASS");
		    		_delay_ms(1000);
		    		LCD_vidSendCommand(LCD_CLR);
		    		LCD_String("TRY AGAIN");

		    		PORTC |= (1<<PC3);
		    		_delay_ms(3000);
		    		PORTC &= ~ (1<<PC3);

		    }
		}
		break;
/***************/
		case '4':

				for (iterator = 0; iterator <3; iterator++)
										   {

					pas=UART_RxChar();
						if(pas=='6'){
							do{
												LCD_vidSendCommand(LCD_CLR);
														LCD_String("WEL DIN");
												open=UART_RxChar();
														if(open=='5')
														{
														PORTC |= (1<<PC4);
														//
														_delay_ms(500);
														PORTC &=~ (1<<PC4);
														 open='6';
														}
							//							else
							//								break;
														}

												while(open=='5');
			do{

				Data_in = UART_RxChar();	/* receive data from Bluetooth device*/
				if(Data_in=='3')
				{
					PORTC |= (1<<PC0);
				}
				else if(Data_in == '4')
							{
								PORTC &= ~ (1<<PC0);
							}
				else if(Data_in =='1')
				{
					PORTC |= (1<<PC1); 			/* Turn ON LED */
				//	UART_SendString("LED_ON");/* send status of LED i.e. LED ON */

				}

				else if(Data_in=='2')
				{
					PORTC &= ~ (1<<PC1);			/* Turn OFF LED */
					//UART_SendString("LED_OFF"); /* send status of LED i.e. LED OFF */
				}
				flag=1;


		}


		while(pas=='6');

			}
		else if(iterator<2)
		{
			LCD_vidSendCommand(LCD_CLR);
			LCD_String("WRONG PASS");
			_delay_ms(1000);
			LCD_vidSendCommand(LCD_CLR);
			LCD_String("TRY AGAIN");

			PORTC |= (1<<PC3);
			_delay_ms(3000);
			PORTC &= ~ (1<<PC3);

		}
								   }
				break;
				/**********************/
		case '5':

				for (iterator = 0; iterator <3; iterator++)
										   {

					pas=UART_RxChar();
						if(pas=='5'){
							do{
												LCD_vidSendCommand(LCD_CLR);
														LCD_String("WEL HOSS");
												open=UART_RxChar();
														if(open=='5')
														{
														PORTC |= (1<<PC4);
														//
														_delay_ms(500);
														PORTC &=~ (1<<PC4);
														 open='6';
														}
							//							else
							//								break;
														}

												while(open=='5');
			do{

				Data_in = UART_RxChar();	/* receive data from Bluetooth device*/
				if(Data_in=='3')
				{
					PORTC |= (1<<PC0);
				}
				else if(Data_in == '4')
							{
								PORTC &= ~ (1<<PC0);
							}
				else if(Data_in =='1')
				{
					PORTC |= (1<<PC1); 			/* Turn ON LED */
				//	UART_SendString("LED_ON");/* send status of LED i.e. LED ON */

				}

				else if(Data_in=='2')
				{
					PORTC &= ~ (1<<PC1);			/* Turn OFF LED */
					//UART_SendString("LED_OFF"); /* send status of LED i.e. LED OFF */
				}
				flag=1;


		}


		while(pas=='5');

			}
		else if(iterator<2)
		{
			LCD_vidSendCommand(LCD_CLR);
			LCD_String("WRONG PASS");
			_delay_ms(1000);
			LCD_vidSendCommand(LCD_CLR);
			LCD_String("TRY AGAIN");

			PORTC |= (1<<PC3);
			_delay_ms(3000);
			PORTC &= ~ (1<<PC3);

		}
								   }
				break;
				/*******************************/
		case '6':

				for (iterator = 0; iterator <3; iterator++)
										   {

					pas=UART_RxChar();
						if(pas=='4'){
							do{
												LCD_vidSendCommand(LCD_CLR);
														LCD_String("WEL ANJ");
												open=UART_RxChar();
														if(open=='5')
														{
														PORTC |= (1<<PC4);
														//
														_delay_ms(500);
														PORTC &=~ (1<<PC4);
														 open='6';
														}
							//							else
							//								break;
														}

												while(open=='5');
			do{

				Data_in = UART_RxChar();	/* receive data from Bluetooth device*/
				if(Data_in=='3')
				{
					PORTC |= (1<<PC0);
				}
				else if(Data_in == '4')
							{
								PORTC &= ~ (1<<PC0);
							}
				else if(Data_in =='1')
				{
					PORTC |= (1<<PC1); 			/* Turn ON LED */
				//	UART_SendString("LED_ON");/* send status of LED i.e. LED ON */

				}

				else if(Data_in=='2')
				{
					PORTC &= ~ (1<<PC1);			/* Turn OFF LED */
					//UART_SendString("LED_OFF"); /* send status of LED i.e. LED OFF */
				}
				flag=1;


		}


		while(pas=='4');

			}
		else if(iterator<2)
		{
			LCD_vidSendCommand(LCD_CLR);
			LCD_String("WRONG PASS");
			_delay_ms(1000);
			LCD_vidSendCommand(LCD_CLR);
			LCD_String("TRY AGAIN");

			PORTC |= (1<<PC3);
			_delay_ms(3000);
			PORTC &= ~ (1<<PC3);

		}
								   }
				break;
/**********************************/

		default :
			LCD_vidSendCommand(LCD_CLR);
			LCD_String("NOT USER");
			_delay_ms(1000);
			LCD_vidSendCommand(LCD_CLR);
			LCD_String("TRY AGAIN");

			flag=2;
		}
		/****************************/
if(flag==0)
{
	LCD_vidSendCommand(LCD_CLR);
	LCD_String("NOT ALLAWED");
	PORTC &= ~ (1<<PC2);
	_delay_ms(2000);
	PORTC |=  (1<<PC2);
	break;
}
}
}
