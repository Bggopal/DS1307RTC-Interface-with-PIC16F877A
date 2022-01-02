/*
 * File:   main.c
 * Author: Bala
 *
 * Created on 23 December, 2021, 5:46 PM
 */


#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 20000000 //We are running on 20MHz crystal 

//Define the LCD pins
#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7

/*Set the current value of date and time below*/
int sec = 00;
int min = 25;
int hour = 12;
int day = 04;
int date = 29;
int month = 12;
int year = 21;
/*Time and Date Set*/

#include <xc.h>
#include "LCD.h" //Header for using LCD module
#include "PIC_I2C.h" // Header for using I2C protocal
#include "DS1307.h" //Header for using DS3231 RTC module

void day_print(int);


int main()
{

    TRISD = 0x00; //Make Port D pins as output for LCD interfacing 
    
    Lcd_Start(); // Initialize LCD module
    
    I2C_Initialize(100); //Initialize I2C Master with 100KHz clock
        
    Set_Time_Date(); //set time and date on the RTC module
    
     //Give an intro message on the LCD
     Lcd_Clear();
     Lcd_Set_Cursor(1,1);
     Lcd_Print_String("DS1307RTC Interf");
     Lcd_Set_Cursor(2,7);
     Lcd_Print_String(" - BGGopal ");
     __delay_ms(1500); //display for 1.5sec

while(1)
  {
 
    Update_Current_Date_Time(); //Read the current date and time from RTC module
    
    //Split the into char to display on lcd
     char sec_0 = sec%10;
     char sec_1 = (sec/10);
     char min_0 = min%10;
     char min_1 = min/10;
     char hour_0 = hour%10;
     char hour_1 = hour/10;
     char date_0 = date%10;
     char date_1 = date/10;
     char month_0 = month%10;
     char month_1 = month/10;
     char year_0 = year%10;
     char year_1 = year/10;
    
       //Display the Time on the LCD screen
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        Lcd_Print_String(" TIME: ");
        Lcd_Print_Char(hour_1+'0');
        Lcd_Print_Char(hour_0+'0');
        Lcd_Print_Char(':');
        Lcd_Print_Char(min_1+'0');
        Lcd_Print_Char(min_0+'0');
        Lcd_Print_Char(':');
        Lcd_Print_Char(sec_1+'0');
        Lcd_Print_Char(sec_0+'0');
        Lcd_Set_Cursor(2,1);
        Lcd_Print_String("Have A Good  Day");
        __delay_ms(500); //refresh for every 0.5 sec
        
        //Display the Date on the LCD screen
        day_print(day);
        Lcd_Set_Cursor(2,1);
        Lcd_Print_String("DATE: ");
        Lcd_Print_Char(date_1+'0');
        Lcd_Print_Char(date_0+'0');
        Lcd_Print_Char('-');
        Lcd_Print_Char(month_1+'0');
        Lcd_Print_Char(month_0+'0');
        Lcd_Print_Char('-');
        Lcd_Print_Char(year_1+'0');
        Lcd_Print_Char(year_0+'0');
        __delay_ms(500); //refresh for every 0.5 sec
    
  }

    return 0;
}

void day_print(int disp)
{
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Print_String("DAY: ");
    switch(disp)
    {
	case 1:Lcd_Print_String("Sunday");
               break;
	case 2:Lcd_Print_String("Monday");
               break;
	case 3:Lcd_Print_String("Tuesday");
               break;
	case 4:Lcd_Print_String("Wednesday");
               break;
	case 5:Lcd_Print_String("Thursday");
               break;
	case 6:Lcd_Print_String("Friday");
               break;
	case 7:Lcd_Print_String("Saturday");
               break;
    }
}