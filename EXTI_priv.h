/**************************************************/
/* Title       : EXTI peripheral Private file    */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                           */
/* Last Update : Aug 22, 2021                 */
/*********************************************/

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

#define GICR   *((volatile u8*)0x5b)//General Interrupt Control Register(PIE)
#define GIFR   *((volatile u8*)0x5a)//General Interrupt Flag Register(PIF)
#define MCUCR  *((volatile u8*)0x55)//MCU Control Register(for INT0/INT1 trigger mode )
#define MCUCSR *((volatile u8*)0x54)//MCU Control and Status Register(for INT2 trigger mode)


/*************MCUCR triggered Mode Selection Bits*****************/
/*************************** INT0/INT1 **************************/
#define EXTI_u8_INT0_ISC00_BIT   0
#define EXTI_u8_INT0_ISC01_BIT   1
#define EXTI_u8_INT1_ISC10_BIT   2
#define EXTI_u8_INT1_ISC11_BIT   3
/*************MCUCSR triggered Mode Selection Bits*******************/
/***************************** INT2 ********************************/
#define EXTI_u8_INT2_ISC2_BIT    6

/********************GICR Bits For PIE Peripheral*******************/
#define EXTI_u8_INT0_PIE_BIT  	 6
#define EXTI_u8_INT1_PIE_BIT  	 7
#define EXTI_u8_INT2_PIE_BIT  	 5
/********************GIFR Bits For PIF *******************/
#define EXTI_u8_INTF0_PIF_BIT	 6
#define EXTI_u8_INTF1_PIF_BIT	 7
#define EXTI_u8_INTF2_PIF_BIT	 5


#define EXTI_u8_MODE_LOW_Level 				0
#define EXTL_u8_Mode_Logical_Change 		1
#define EXTI_u8_MODE_Falling_Edge			2
#define EXTI_u8_MODE_Rising_Edge			3

#endif/* EXTI_PRIV_H_*/
