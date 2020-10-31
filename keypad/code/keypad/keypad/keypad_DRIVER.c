/*
 * keypad_DRIVER.c
 *
 * Created: 27/04/2020 01:59:01 PM
 *  Author: BOB
 */ 



/******************** method 1 **********************
#include "keypad_DRIVER.h"

int keypadRow[]={R0,R1,R2,R3};// rows input
int keypadCol[]={C0,C1,C2,C3};// coulms output
		
void keypad_init()
{
	keypad_DDR &=~(1<<R0)|(1<<R1)|(1<<R2)|(1<<R3); //set upper of port as input (ROWS)
	keypad_DDR |= ((1<<C0)|(1<<C1)|(1<<C2)|(1<<C3)); //set lower of port as output (COULMS)
	keypad_PORT=0xFF;
}

char keypad_getchar()
{
	int i;
	int j;
	
	for (i=0;i<4;i++)
	{
		keypad_PORT |=( (1<<keypadCol[0]) | (1<<keypadCol[1]) | (1<<keypadCol[2]) | (1<<keypadCol[3]) );
		keypad_PORT &= ~(1<<keypadCol[i]);
		
		for (j=0;j<4;j++)
		{
			if (!(keypad_PIN & (1<<keypadRow[j]))) //if key pressed
			{
				while (!(keypad_PIN & (1<<keypadRow[j]))); //wait until key released
				
				switch(i)
				{
					case 0:
						if (j==0) return '1';
						else if (j==1) return '2'; 
						else if (j==2) return '3';
						else if (j==3) return 'a';
						break;
					
					case 1:
						if (j==0) return '4';
						else if (j==1) return '5';
						else if (j==2) return '6';
						else if (j==3) return 'o';
						break;
					
					case 2:
						if (j==0) return '7';
						else if (j==1) return '8';
						else if (j==2) return '9';
						else if (j==3) return 'i';
						break;
					
					case 3:
						if (j==0) return 'M';
						else if (j==1) return '0';
						else if (j==2) return 'C';
						else if (j==3) return 'E';
						break;
								
				}
			}
		}
	}
	
	
	return 'A'; //if no key was pressed
}

*/

/******************* method 2 **********************/

#include "keypad_DRIVER.h"
unsigned char keypad[4][4] = {	{'1','2','3','A'},
								{'4','5','6','O'},
								{'7','8','9','I'},
								{'M','0','C','E'}};

unsigned char colloc, rowloc;

char keyfind()
{
	while(1)
	{
		KEY_DDR = 0xF0;           /* set port direction as input-output */
		KEY_PRT = 0xFF;

		do
		{
			KEY_PRT &= 0x0F;      /* mask PORT for column read only */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F); /* read status of column */
		}while(colloc != 0x0F);
		
		do
		{
			do
			{
				_delay_ms(20);             /* 20ms key debounce time */
				colloc = (KEY_PIN & 0x0F); /* read status of column */
				}while(colloc == 0x0F);        /* check for any key press */
				
				_delay_ms (40);	            /* 20 ms key debounce time */
				colloc = (KEY_PIN & 0x0F);
			}while(colloc == 0x0F);

			/* now check for rows */
			KEY_PRT = 0xEF;            /* check for pressed key in 1st row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 0;
				break;
			}

			KEY_PRT = 0xDF;		/* check for pressed key in 2nd row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 1;
				break;
			}
			
			KEY_PRT = 0xBF;		/* check for pressed key in 3rd row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 2;
				break;
			}

			KEY_PRT = 0x7F;		/* check for pressed key in 4th row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 3;
				break;
			}
		}

		if(colloc == 0x0E)
		return(keypad[rowloc][0]);
		else if(colloc == 0x0D)
		return(keypad[rowloc][1]);
		else if(colloc == 0x0B)
		return(keypad[rowloc][2]);
		else
		return(keypad[rowloc][3]);
	}
