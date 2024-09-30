/*
 ******************************************************************************
 * Created On     : Sep 26,2024
 * File           : HAL_LCD_Private.h
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

#ifndef INC_HAL_LCD_PRIVATE_H_
#define INC_HAL_LCD_PRIVATE_H_


#define LCD_8_BIT_2_LINE_DOT_5_7 							0x38
#define LCD_4_BIT_2_LINE_DOT_5_7 							0x28
#define Entry_Mode 											0x06

#define Display_OFF_Cursor_OFF								0x08
#define Display_ON_Cursor_ON								0x0E
#define Display_ON_Cursor_oFF								0x0C
#define Display_ON_Cursor_BLINKING							0x0F

#define Shift_Entire_Display_Left 							0x18
#define Shift_Entire_Display_RIGHT 							0x1C
#define Move_Cursor_Left_by_One_Character 					0x10
#define Move_Cursor_RIGHT_by_One_Characterr 				0x14
#define Clear_Display 										0x01

#define LCD_BEGIN_AT_Line_1									0x80
#define LCD_BEGIN_AT_Line_2									0xC0

#endif /* INC_HAL_LCD_PRIVATE_H_ */
