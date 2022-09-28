/*****************************************************/
/*  Title       : EXTI peripheral interface file     */
/* Author      : Yahia Ahmed                        */
/* Release     : 1.0                               */
/* Last Update : Aug 23, 2021                     */
/*************************************************/

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

void EXT_voidInit(u8 Copy_u8_EXTPin );
void EXTI_vid_SetCallBack_0(void (*Copy_ptr)(void));
void EXTI_vid_SetCallBack_1(void (*Copy_ptr)(void));
void EXTI_vid_SetCallBack_2(void (*Copy_ptr)(void));
void EXTI_vid_Enable(u8 Copy_u8_EXTPin);
void EXTI_vid_Disable(u8 Copy_u8_EXTPin);
#define EXTI_u8_INT0 	0
#define EXTI_u8_INT1 	1
#define EXTI_u8_INT2 	2
#endif
