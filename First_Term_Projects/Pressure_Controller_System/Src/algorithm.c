/*
 ******************************************************************************
 * Created On     : Aug 25,2024
 * File           : algorithm.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************
*/

#include "algorithm.h"
#include "driver.h"

uint32_t Alg_pval = 0;         // the value takes from PS_pval
uint32_t Alg_pthreshold = 20;  // pressure threshold value= 20 bar

void (*Alg_state)();


/************************************Function Description***********************************/
/*void setPressureVal(int pval): IN signal receive value from the pressure sensor          */
/*******************************************************************************************/
void setPressureVal(int pval)
{
	Alg_pval = pval;
	Alg_state = State(Alg_HighPressureDetect);
}



/************************************Function Description***********************************/
/*void ST_Alg_HighPressureDetect(): This function performs operations (if) Alg_pval > Alg_pthreshold sending there are high pressure to alarm monitor then waiting the new value*/
/*******************************************************************************************/
State_define(Alg_HighPressureDetect)
{
	Alg_state_id = 	Alg_HighPressureDetect;

	if(Alg_pval > Alg_pthreshold)
	{
		alg_HighPressureDetect();
	}

	setPressureVal(Alg_pval);
	Alg_state= State(Alg_HighPressureDetect);

}
