/*****************************************************/
/* Title       : EXTI peripheral Configuration file */
/* Author      : Yahia Ahmed                       */
/* Release     : 1.0                              */
/* Last Update : Aug 23, 2021                    */
/************************************************/
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

//There are four triggering options for EXTI_u8_TRIGGER_MODE :
/*
	EXTI_u8_MODE_LOW_Level 		
	EXTL_u8_Mode_Logical_Change 
	EXTI_u8_MODE_Falling_Edge	
    EXTI_u8_MODE_Rising_Edge	
*/
/***note that if you use interrupt INT2 You can choose only***/
/***********Either Falling_Edge or Rising_Edge mode*********/
#define EXTI_u8_TRIGGER_MODE		EXTI_u8_MODE_Falling_Edge

//there are three external interrupts..For EXTI_u8_INTX_MODE:
/*
EXTI_u8_INT0 
EXTI_u8_INT1 
EXTI_u8_INT2 
*/
/*this Configuration is optional and I don't use it in my APIS*/
#define EXTI_u8_INTX_MODE			EXTI_u8_INT0

#endif /* EEXTI_CONFIG_H_*/
