/************************************************/
/* Title       : EXTI peripheral program file    */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 22, 2021                   */
/************************************************/
#include "BIT_math.h"
#include "STD_types.h"
#include "EXTI_int.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"

void (* CallBack_EXT0) (void);
void (* CallBack_EXT1) (void);
void (* CallBack_EXT2) (void);

void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	CallBack_EXT0();

}
void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	CallBack_EXT1();

}

void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{
	CallBack_EXT2();

}
 void EXT_voidInit(u8 Copy_u8_EXTPin )
{
////////////INT0/////////////
	if( Copy_u8_EXTPin==EXTI_u8_INT0)
	{
		switch(EXTI_u8_TRIGGER_MODE)
		{
			case EXTI_u8_MODE_LOW_Level :
				CLEAR_BIT(MCUCR,EXTI_u8_INT0_ISC00_BIT);
				CLEAR_BIT(MCUCR,EXTI_u8_INT0_ISC01_BIT);	break;
			case EXTL_u8_Mode_Logical_Change :
				SET_BIT(MCUCR,EXTI_u8_INT0_ISC00_BIT);
				CLEAR_BIT(MCUCR,EXTI_u8_INT0_ISC01_BIT);	break;
			case EXTI_u8_MODE_Falling_Edge :
				CLEAR_BIT(MCUCR,EXTI_u8_INT0_ISC00_BIT);
				SET_BIT(MCUCR,EXTI_u8_INT0_ISC01_BIT);		break;
			case EXTI_u8_MODE_Rising_Edge :
				SET_BIT(MCUCR,EXTI_u8_INT0_ISC00_BIT);
				SET_BIT(MCUCR,EXTI_u8_INT0_ISC01_BIT);		break;
		}
		CLEAR_BIT(GICR,EXTI_u8_INT0_PIE_BIT);
		SET_BIT(GIFR,EXTI_u8_INTF0_PIF_BIT);
	
	}
	else if( Copy_u8_EXTPin==EXTI_u8_INT1)
	{
		switch(EXTI_u8_TRIGGER_MODE)
		{
			case EXTI_u8_MODE_LOW_Level :
				CLEAR_BIT(MCUCR,EXTI_u8_INT1_ISC10_BIT);
				CLEAR_BIT(MCUCR,EXTI_u8_INT1_ISC11_BIT);	break;
			case EXTL_u8_Mode_Logical_Change :
				SET_BIT(MCUCR,EXTI_u8_INT1_ISC10_BIT);
				CLEAR_BIT(MCUCR,EXTI_u8_INT1_ISC11_BIT);	break;
			case EXTI_u8_MODE_Falling_Edge :
				CLEAR_BIT(MCUCR,EXTI_u8_INT1_ISC10_BIT);
				SET_BIT(MCUCR,EXTI_u8_INT1_ISC11_BIT);		break;
			case EXTI_u8_MODE_Rising_Edge :
				SET_BIT(MCUCR,EXTI_u8_INT1_ISC10_BIT);
				SET_BIT(MCUCR,EXTI_u8_INT1_ISC11_BIT);		break;
		}
	CLEAR_BIT(GICR,EXTI_u8_INT1_PIE_BIT);
	SET_BIT(GIFR,EXTI_u8_INTF1_PIF_BIT);
	}
	else if( Copy_u8_EXTPin==EXTI_u8_INT2)
	{
		if( EXTI_u8_TRIGGER_MODE ==EXTI_u8_MODE_Falling_Edge)
		CLEAR_BIT(MCUCSR,EXTI_u8_INT2_ISC2_BIT);
		else if(EXTI_u8_TRIGGER_MODE ==EXTI_u8_MODE_Rising_Edge)
		SET_BIT(MCUCSR,EXTI_u8_INT2_ISC2_BIT);

		CLEAR_BIT(GICR,EXTI_u8_INT2_PIE_BIT);
		SET_BIT(GIFR,EXTI_u8_INTF2_PIF_BIT);
	}

}

void EXTI_vid_SetCallBack_0(void (*Copy_ptr)(void))
{
	CallBack_EXT0 = Copy_ptr;
}
void EXTI_vid_SetCallBack_1(void (*Copy_ptr)(void))
{
	CallBack_EXT1 = Copy_ptr;
}
void EXTI_vid_SetCallBack_2(void (*Copy_ptr)(void))
{
	CallBack_EXT2 = Copy_ptr;
}

void EXTI_vid_Enable(u8 Copy_u8_EXTPin){
	switch(Copy_u8_EXTPin)
	{
		case EXTI_u8_INT0:
			SET_BIT(GICR,EXTI_u8_INT0_PIE_BIT); break;
		case EXTI_u8_INT1:
			SET_BIT(GICR,EXTI_u8_INT1_PIE_BIT); break;
		case EXTI_u8_INT2:
			SET_BIT(GICR,EXTI_u8_INT2_PIE_BIT); break;
	}

}

void EXTI_vid_Disable(u8 Copy_u8_EXTPin)
{
	switch(Copy_u8_EXTPin)
	{
		case EXTI_u8_INT0:
			CLEAR_BIT(GICR,EXTI_u8_INT0_PIE_BIT); break;
		case EXTI_u8_INT1:
			CLEAR_BIT(GICR,EXTI_u8_INT1_PIE_BIT); break;
		case EXTI_u8_INT2:
			CLEAR_BIT(GICR,EXTI_u8_INT2_PIE_BIT); break;
	}

}
