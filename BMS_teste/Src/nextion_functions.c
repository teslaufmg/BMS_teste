


#include "BMS.h"
#include <stdlib.h>
#include "nextion_functions.h"


extern uint8_t uart_user_message[DMA_RX_BUFFER_SIZE];	/* Buffer received for user access */


void uart3MessageReceived(void)
{
  /* If the message is to change the nextion page */
  if(uart_user_message[0] == 0x71 && uart_user_message[5] == 0xFF && uart_user_message[6] == 0xFF && uart_user_message[7] == 0xFF)
  {
    switch(uart_user_message[1])
    {
      case 0:
      actual_page = N_PAGE0;
      NexPageShow(N_PAGE0);
      break;

      case 1:
      actual_page = N_PAGE1;
      NexPageShow(N_PAGE1);
      break;

      case 2:
      actual_page = N_PAGE2;
      NexPageShow(N_PAGE2);
      break;

      case 3:
      actual_page = N_PAGE3;
      NexPageShow(N_PAGE3);
      break;

      case 4:
      actual_page = N_PAGE4;
      NexPageShow(N_PAGE4);
      break;

      case 5:
      actual_page = N_PAGE5;
      NexPageShow(N_PAGE5);
      break;

      case 6:
      actual_page = N_PAGE6;
      NexPageShow(N_PAGE6);
      break;

    }
  }
}


//uint8_t nexSetPageError(BMS_struct *BMS) {
//
//	uint8_t var01;
//
//	if(BMS->lowest_cell < 2800) {
//		var01 = ;
//	}
////	else if(BMS->highest_cell > 3600) {
////		var01 = nex_id[1];
////	}
////	else if(BMS->temperature_max > 600) {
////		var01 = nex_id[2];
////	}
//	else var01 = 0;
//
//	return var01;
//}

void nextLoop(BMS_struct *BMS)
{

		if(NextError[0] == 1){
			NexTextSetText(2, "Low Voltage");
		}
		else if(NextError[1] == 1){
			NexTextSetText(2, "High Voltage");
		}
		else if(NextError[2] == 1){
			NexTextSetText(2, "Over Temp");
		}
		else if(NextError[3] == 1){
			NexTextSetText(2, "Pack Error");
		}
		else if(NextError[4] == 1){
			NexTextSetText(2, "GLV Voltage");
		}
		else{
		NexTextGetText(2,"");
		}

	NexProgressBarSetValue(0, 0);

	   switch(actual_page) /*actual_nextion_page is used to not use NexPageShow() many times*/
		{
			case N_PAGE0:

     		   NexVariableSetValue(0, BMS->AIR);
			   NexNumberSetValue(0, 0);
			   NexXfloatSetValue(0, 0);
			   NexXfloatSetValue(1, BMS->lowest_cell);
			   NexXfloatSetValue(2, BMS->v_bank);
			   NexXfloatSetValue(3, 0);
			   break;

			case N_PAGE1:

				NexXfloatSetValue(0, BMS->sensor_v[actual_page - 1]->v_cell[0]);
				NexXfloatSetValue(1, BMS->sensor_v[actual_page - 1]->v_cell[1]);
				NexXfloatSetValue(2, BMS->sensor_v[actual_page - 1]->v_cell[2]);
				NexXfloatSetValue(3, BMS->sensor_v[actual_page - 1]->v_cell[3]);
				NexXfloatSetValue(4, BMS->sensor_v[actual_page - 1]->v_cell[4]);
				NexXfloatSetValue(5, BMS->sensor_v[actual_page - 1]->v_cell[5]);
				NexXfloatSetValue(6, BMS->sensor_v[actual_page - 1]->v_cell[6]);
				NexXfloatSetValue(7, BMS->sensor_v[actual_page - 1]->v_cell[7]);
				NexXfloatSetValue(8, BMS->sensor_v[actual_page - 1]->v_cell[8]);
				NexXfloatSetValue(9, BMS->sensor_v[actual_page - 1]->v_cell[9]);
				NexXfloatSetValue(10, BMS->sensor_v[actual_page - 1]->v_cell[10]);
				NexXfloatSetValue(11, BMS->sensor_v[actual_page - 1]->v_cell[11]);
				NexXfloatSetValue(12, 0);
				NexXfloatSetValue(13, 0);
				NexXfloatSetValue(14, 0);
				NexXfloatSetValue(15, 0);
				break;

			case N_PAGE2:

				NexXfloatSetValue(0, BMS->sensor_v[actual_page - 1]->v_cell[0]);
				NexXfloatSetValue(1, BMS->sensor_v[actual_page - 1]->v_cell[1]);
				NexXfloatSetValue(2, BMS->sensor_v[actual_page - 1]->v_cell[2]);
				NexXfloatSetValue(3, BMS->sensor_v[actual_page - 1]->v_cell[3]);
				NexXfloatSetValue(4, BMS->sensor_v[actual_page - 1]->v_cell[4]);
				NexXfloatSetValue(5, BMS->sensor_v[actual_page - 1]->v_cell[5]);
				NexXfloatSetValue(6, BMS->sensor_v[actual_page - 1]->v_cell[6]);
				NexXfloatSetValue(7, BMS->sensor_v[actual_page - 1]->v_cell[7]);
				NexXfloatSetValue(8, BMS->sensor_v[actual_page - 1]->v_cell[8]);
				NexXfloatSetValue(9, BMS->sensor_v[actual_page - 1]->v_cell[9]);
				NexXfloatSetValue(10, BMS->sensor_v[actual_page - 1]->v_cell[10]);
				NexXfloatSetValue(11, BMS->sensor_v[actual_page - 1]->v_cell[11]);
				NexXfloatSetValue(12, 0);
				NexXfloatSetValue(13, 0);
				NexXfloatSetValue(14, 0);
				NexXfloatSetValue(15, 0);
				break;

			case N_PAGE3:

				NexXfloatSetValue(0, BMS->sensor_v[actual_page - 1]->v_cell[0]);
				NexXfloatSetValue(1, BMS->sensor_v[actual_page - 1]->v_cell[1]);
				NexXfloatSetValue(2, BMS->sensor_v[actual_page - 1]->v_cell[2]);
				NexXfloatSetValue(3, BMS->sensor_v[actual_page - 1]->v_cell[3]);
				NexXfloatSetValue(4, BMS->sensor_v[actual_page - 1]->v_cell[4]);
				NexXfloatSetValue(5, BMS->sensor_v[actual_page - 1]->v_cell[5]);
				NexXfloatSetValue(6, BMS->sensor_v[actual_page - 1]->v_cell[6]);
				NexXfloatSetValue(7, BMS->sensor_v[actual_page - 1]->v_cell[7]);
				NexXfloatSetValue(8, BMS->sensor_v[actual_page - 1]->v_cell[8]);
				NexXfloatSetValue(9, BMS->sensor_v[actual_page - 1]->v_cell[9]);
				NexXfloatSetValue(10, BMS->sensor_v[actual_page - 1]->v_cell[10]);
				NexXfloatSetValue(11, BMS->sensor_v[actual_page - 1]->v_cell[11]);
				NexXfloatSetValue(12, 0);
				NexXfloatSetValue(13, 0);
				NexXfloatSetValue(14, 0);
				NexXfloatSet1Value(15, 0);
				break;

			case N_PAGE4:

				NexXfloatSetValue(0, BMS->sensor_v[actual_page - 1]->v_cell[0]);
				NexXfloatSetValue(1, BMS->sensor_v[actual_page - 1]->v_cell[1]);
				NexXfloatSetValue(2, BMS->sensor_v[actual_page - 1]->v_cell[2]);
				NexXfloatSetValue(3, BMS->sensor_v[actual_page - 1]->v_cell[3]);
				NexXfloatSetValue(4, BMS->sensor_v[actual_page - 1]->v_cell[4]);
				NexXfloatSetValue(5, BMS->sensor_v[actual_page - 1]->v_cell[5]);
				NexXfloatSetValue(6, BMS->sensor_v[actual_page - 1]->v_cell[6]);
				NexXfloatSetValue(7, BMS->sensor_v[actual_page - 1]->v_cell[7]);
				NexXfloatSetValue(8, BMS->sensor_v[actual_page - 1]->v_cell[8]);
				NexXfloatSetValue(9, BMS->sensor_v[actual_page - 1]->v_cell[9]);
				NexXfloatSetValue(10, BMS->sensor_v[actual_page - 1]->v_cell[10]);
				NexXfloatSetValue(11, BMS->sensor_v[actual_page - 1]->v_cell[11]);
				NexXfloatSetValue(12, 0);
				NexXfloatSetValue(13, 0);
				NexXfloatSetValue(14, 0);
				NexXfloatSetValue(15, 0);
				break;

			case N_PAGE5:

				NexXfloatSetValue(0, BMS->sensor_v[actual_page - 1]->v_cell[0]);
				NexXfloatSetValue(1, BMS->sensor_v[actual_page - 1]->v_cell[1]);
				NexXfloatSetValue(2, BMS->sensor_v[actual_page - 1]->v_cell[2]);
				NexXfloatSetValue(3, BMS->sensor_v[actual_page - 1]->v_cell[3]);
				NexXfloatSetValue(4, BMS->sensor_v[actual_page - 1]->v_cell[4]);
				NexXfloatSetValue(5, BMS->sensor_v[actual_page - 1]->v_cell[5]);
				NexXfloatSetValue(6, BMS->sensor_v[actual_page - 1]->v_cell[6]);
				NexXfloatSetValue(7, BMS->sensor_v[actual_page - 1]->v_cell[7]);
				NexXfloatSetValue(8, BMS->sensor_v[actual_page - 1]->v_cell[8]);
				NexXfloatSetValue(9, BMS->sensor_v[actual_page - 1]->v_cell[9]);
				NexXfloatSetValue(10, BMS->sensor_v[actual_page - 1]->v_cell[10]);
				NexXfloatSetValue(11, BMS->sensor_v[actual_page - 1]->v_cell[11]);
				NexXfloatSetValue(12, 0);
				NexXfloatSetValue(13, 0);
				NexXfloatSetValue(14, 0);
				NexXfloatSetValue(15, 0);
				break;

			case N_PAGE6:

				NexXfloatSetValue(0, BMS->sensor_v[actual_page - 1]->v_cell[0]);
				NexXfloatSetValue(1, BMS->sensor_v[actual_page - 1]->v_cell[1]);
				NexXfloatSetValue(2, BMS->sensor_v[actual_page - 1]->v_cell[2]);
				NexXfloatSetValue(3, BMS->sensor_v[actual_page - 1]->v_cell[3]);
				NexXfloatSetValue(4, BMS->sensor_v[actual_page - 1]->v_cell[4]);
				NexXfloatSetValue(5, BMS->sensor_v[actual_page - 1]->v_cell[5]);
				NexXfloatSetValue(6, BMS->sensor_v[actual_page - 1]->v_cell[6]);
				NexXfloatSetValue(7, BMS->sensor_v[actual_page - 1]->v_cell[7]);
				NexXfloatSetValue(8, BMS->sensor_v[actual_page - 1]->v_cell[8]);
				NexXfloatSetValue(9, BMS->sensor_v[actual_page - 1]->v_cell[9]);
				NexXfloatSetValue(10, BMS->sensor_v[actual_page - 1]->v_cell[10]);
				NexXfloatSetValue(11, BMS->sensor_v[actual_page - 1]->v_cell[11]);
				NexXfloatSetValue(12, 0);
				NexXfloatSetValue(13, 0);
				NexXfloatSetValue(14, 0);
				NexXfloatSetValue(15, 0);
				break;

			case N_PAGE7:
				break;
		}
}

void nexLoop(BMS_struct *BMS)
{


	NexProgressBarSetValue(0, 0);

	   switch(actual_page) /*actual_nextion_page is used to not use NexPageShow() many times*/
		{
			case N_PAGE0:

     		   NexVariableSetValue(0, BMS->AIR);
			   NexNumberSetValue(0, 0);
			   NexXfloatSetValue(0, 0);
			   NexXfloatSetValue(1, BMS->lowest_cell);
			   NexXfloatSetValue(2, BMS->v_bank);
			   NexXfloatSetValue(3, 0);
			   break;

			case N_PAGE1:

				NexXfloatSetValue(0, BMS->sensor_v[actual_page - 1]->v_cell[0]);
				NexXfloatSetValue(1, BMS->sensor_v[actual_page - 1]->v_cell[1]);
				NexXfloatSetValue(2, BMS->sensor_v[actual_page - 1]->v_cell[2]);
				NexXfloatSetValue(3, BMS->sensor_v[actual_page - 1]->v_cell[3]);
				NexXfloatSetValue(4, BMS->sensor_v[actual_page - 1]->v_cell[4]);
				NexXfloatSetValue(5, BMS->sensor_v[actual_page - 1]->v_cell[5]);
				NexXfloatSetValue(6, BMS->sensor_v[actual_page - 1]->v_cell[6]);
				NexXfloatSetValue(7, BMS->sensor_v[actual_page - 1]->v_cell[7]);
				NexXfloatSetValue(8, BMS->sensor_v[actual_page - 1]->v_cell[8]);
				NexXfloatSetValue(9, BMS->sensor_v[actual_page - 1]->v_cell[9]);
				NexXfloatSetValue(10, BMS->sensor_v[actual_page - 1]->v_cell[10]);
				NexXfloatSetValue(11, BMS->sensor_v[actual_page - 1]->v_cell[11]);
				NexXfloatSetValue(12, 0);
				NexXfloatSetValue(13, 0);
				NexXfloatSetValue(14, 0);
				NexXfloatSetValue(15, 0);
				break;

			case N_PAGE2:

				NexXfloatSetValue(0, BMS->sensor_v[actual_page - 1]->v_cell[0]);
				NexXfloatSetValue(1, BMS->sensor_v[actual_page - 1]->v_cell[1]);
				NexXfloatSetValue(2, BMS->sensor_v[actual_page - 1]->v_cell[2]);
				NexXfloatSetValue(3, BMS->sensor_v[actual_page - 1]->v_cell[3]);
				NexXfloatSetValue(4, BMS->sensor_v[actual_page - 1]->v_cell[4]);
				NexXfloatSetValue(5, BMS->sensor_v[actual_page - 1]->v_cell[5]);
				NexXfloatSetValue(6, BMS->sensor_v[actual_page - 1]->v_cell[6]);
				NexXfloatSetValue(7, BMS->sensor_v[actual_page - 1]->v_cell[7]);
				NexXfloatSetValue(8, BMS->sensor_v[actual_page - 1]->v_cell[8]);
				NexXfloatSetValue(9, BMS->sensor_v[actual_page - 1]->v_cell[9]);
				NexXfloatSetValue(10, BMS->sensor_v[actual_page - 1]->v_cell[10]);
				NexXfloatSetValue(11, BMS->sensor_v[actual_page - 1]->v_cell[11]);
				NexXfloatSetValue(12, 0);
				NexXfloatSetValue(13, 0);
				NexXfloatSetValue(14, 0);
				NexXfloatSetValue(15, 0);
				break;

			case N_PAGE3:

				NexXfloatSetValue(0, BMS->sensor_v[actual_page - 1]->v_cell[0]);
				NexXfloatSetValue(1, BMS->sensor_v[actual_page - 1]->v_cell[1]);
				NexXfloatSetValue(2, BMS->sensor_v[actual_page - 1]->v_cell[2]);
				NexXfloatSetValue(3, BMS->sensor_v[actual_page - 1]->v_cell[3]);
				NexXfloatSetValue(4, BMS->sensor_v[actual_page - 1]->v_cell[4]);
				NexXfloatSetValue(5, BMS->sensor_v[actual_page - 1]->v_cell[5]);
				NexXfloatSetValue(6, BMS->sensor_v[actual_page - 1]->v_cell[6]);
				NexXfloatSetValue(7, BMS->sensor_v[actual_page - 1]->v_cell[7]);
				NexXfloatSetValue(8, BMS->sensor_v[actual_page - 1]->v_cell[8]);
				NexXfloatSetValue(9, BMS->sensor_v[actual_page - 1]->v_cell[9]);
				NexXfloatSetValue(10, BMS->sensor_v[actual_page - 1]->v_cell[10]);
				NexXfloatSetValue(11, BMS->sensor_v[actual_page - 1]->v_cell[11]);
				NexXfloatSetValue(12, 0);
				NexXfloatSetValue(13, 0);
				NexXfloatSetValue(14, 0);
				NexXfloatSetValue(15, 0);
				break;

			case N_PAGE4:

				NexXfloatSetValue(0, BMS->sensor_v[actual_page - 1]->v_cell[0]);
				NexXfloatSetValue(1, BMS->sensor_v[actual_page - 1]->v_cell[1]);
				NexXfloatSetValue(2, BMS->sensor_v[actual_page - 1]->v_cell[2]);
				NexXfloatSetValue(3, BMS->sensor_v[actual_page - 1]->v_cell[3]);
				NexXfloatSetValue(4, BMS->sensor_v[actual_page - 1]->v_cell[4]);
				NexXfloatSetValue(5, BMS->sensor_v[actual_page - 1]->v_cell[5]);
				NexXfloatSetValue(6, BMS->sensor_v[actual_page - 1]->v_cell[6]);
				NexXfloatSetValue(7, BMS->sensor_v[actual_page - 1]->v_cell[7]);
				NexXfloatSetValue(8, BMS->sensor_v[actual_page - 1]->v_cell[8]);
				NexXfloatSetValue(9, BMS->sensor_v[actual_page - 1]->v_cell[9]);
				NexXfloatSetValue(10, BMS->sensor_v[actual_page - 1]->v_cell[10]);
				NexXfloatSetValue(11, BMS->sensor_v[actual_page - 1]->v_cell[11]);
				NexXfloatSetValue(12, 0);
				NexXfloatSetValue(13, 0);
				NexXfloatSetValue(14, 0);
				NexXfloatSetValue(15, 0);
				break;

			case N_PAGE5:

				NexXfloatSetValue(0, BMS->sensor_v[actual_page - 1]->v_cell[0]);
				NexXfloatSetValue(1, BMS->sensor_v[actual_page - 1]->v_cell[1]);
				NexXfloatSetValue(2, BMS->sensor_v[actual_page - 1]->v_cell[2]);
				NexXfloatSetValue(3, BMS->sensor_v[actual_page - 1]->v_cell[3]);
				NexXfloatSetValue(4, BMS->sensor_v[actual_page - 1]->v_cell[4]);
				NexXfloatSetValue(5, BMS->sensor_v[actual_page - 1]->v_cell[5]);
				NexXfloatSetValue(6, BMS->sensor_v[actual_page - 1]->v_cell[6]);
				NexXfloatSetValue(7, BMS->sensor_v[actual_page - 1]->v_cell[7]);
				NexXfloatSetValue(8, BMS->sensor_v[actual_page - 1]->v_cell[8]);
				NexXfloatSetValue(9, BMS->sensor_v[actual_page - 1]->v_cell[9]);
				NexXfloatSetValue(10, BMS->sensor_v[actual_page - 1]->v_cell[10]);
				NexXfloatSetValue(11, BMS->sensor_v[actual_page - 1]->v_cell[11]);
				NexXfloatSetValue(12, 0);
				NexXfloatSetValue(13, 0);
				NexXfloatSetValue(14, 0);
				NexXfloatSetValue(15, 0);
				break;

			case N_PAGE6:

				NexXfloatSetValue(0, BMS->sensor_v[actual_page - 1]->v_cell[0]);
				NexXfloatSetValue(1, BMS->sensor_v[actual_page - 1]->v_cell[1]);
				NexXfloatSetValue(2, BMS->sensor_v[actual_page - 1]->v_cell[2]);
				NexXfloatSetValue(3, BMS->sensor_v[actual_page - 1]->v_cell[3]);
				NexXfloatSetValue(4, BMS->sensor_v[actual_page - 1]->v_cell[4]);
				NexXfloatSetValue(5, BMS->sensor_v[actual_page - 1]->v_cell[5]);
				NexXfloatSetValue(6, BMS->sensor_v[actual_page - 1]->v_cell[6]);
				NexXfloatSetValue(7, BMS->sensor_v[actual_page - 1]->v_cell[7]);
				NexXfloatSetValue(8, BMS->sensor_v[actual_page - 1]->v_cell[8]);
				NexXfloatSetValue(9, BMS->sensor_v[actual_page - 1]->v_cell[9]);
				NexXfloatSetValue(10, BMS->sensor_v[actual_page - 1]->v_cell[10]);
				NexXfloatSetValue(11, BMS->sensor_v[actual_page - 1]->v_cell[11]);
				NexXfloatSetValue(12, 0);
				NexXfloatSetValue(13, 0);
				NexXfloatSetValue(14, 0);
				NexXfloatSetValue(15, 0);
				break;

			case N_PAGE7:
				break;
		}
}



void testnexLoop(void) {

int aux_ten = 0, aux_temp = 0, aux_corrente = 0, aux_ten_total = 0, percent = 0, air = 0, aux_ten1 = 0, aux_txt = 0;

   if(aux_ten>=5000) aux_ten = 0;
   else aux_ten = aux_ten + 50;

   if(aux_ten1>=500) aux_ten1 = 0;
   else aux_ten1 = aux_ten1 + 5;

   if(aux_temp>=1000) aux_temp = 0;
   else aux_temp = aux_temp + 10;

   if(aux_ten_total>=10000) aux_ten_total = 0;
	  else aux_ten_total = aux_ten_total + 100;

   if(aux_corrente>=1000) aux_corrente = 0;
   else aux_corrente = aux_corrente + 10;

   if(air != 1) air = 1;
   else air = 0;

   if(percent >= 100) percent = 0;
   else percent = percent + 1;

   if(aux_txt >= 6) aux_txt = 0;
   else aux_txt = aux_txt + 1;

	NexProgressBarSetValue(0,percent);
  	NexVariableSetValue(1,aux_txt);

  	switch(actual_page) /*actual_nextion_page is used to not use NexPageShow() many times*/
  		{
  			case N_PAGE0:

       		   NexVariableSetValue(2,air);
  			   NexNumberSetValue(0, aux_corrente);
  			   NexNumberSetValue(1, percent);
  			   NexXfloatSetValue(0, aux_ten1);
  			   NexXfloatSetValue(1, aux_ten1);
  			   NexXfloatSetValue(2, aux_ten_total);
  			   NexXfloatSetValue(3, aux_temp);

  			   break;

  			case N_PAGE1:

  				NexXfloatSetValue(0, 1);
  				NexXfloatSetValue(1, 1);
  				NexXfloatSetValue(2, 1);
  				NexXfloatSetValue(3, aux_ten);
  				NexXfloatSetValue(4, aux_ten);
  				NexXfloatSetValue(5, aux_ten);
  				NexXfloatSetValue(6, aux_ten);
  				NexXfloatSetValue(7, aux_ten);
  				NexXfloatSetValue(8, aux_ten);
  				NexXfloatSetValue(9, aux_ten);
  				NexXfloatSetValue(10, aux_ten);
  				NexXfloatSetValue(11, aux_ten);
  				NexXfloatSetValue(12, aux_temp);
  				NexXfloatSetValue(13, aux_temp);
  				NexXfloatSetValue(14, aux_temp);
  				NexXfloatSetValue(15, aux_temp);
  				break;

  			case N_PAGE2:

  				NexXfloatSetValue(0, 2);
  				NexXfloatSetValue(1, 2);
  				NexXfloatSetValue(2, 2);
  				NexXfloatSetValue(3, aux_ten);
  				NexXfloatSetValue(4, aux_ten);
  				NexXfloatSetValue(5, aux_ten);
  				NexXfloatSetValue(6, aux_ten);
  				NexXfloatSetValue(7, aux_ten);
  				NexXfloatSetValue(8, aux_ten);
  				NexXfloatSetValue(9, aux_ten);
  				NexXfloatSetValue(10, aux_ten);
  				NexXfloatSetValue(11, aux_ten);
  				NexXfloatSetValue(12, aux_temp);
  				NexXfloatSetValue(13, aux_temp);
  				NexXfloatSetValue(14, aux_temp);
  				NexXfloatSetValue(15, aux_temp);
  				break;

  			case N_PAGE3:

  				NexXfloatSetValue(0, 3);
  				NexXfloatSetValue(1, 3);
  				NexXfloatSetValue(2, 3);
  				NexXfloatSetValue(3, aux_ten);
  				NexXfloatSetValue(4, aux_ten);
  				NexXfloatSetValue(5, aux_ten);
  				NexXfloatSetValue(6, aux_ten);
  				NexXfloatSetValue(7, aux_ten);
  				NexXfloatSetValue(8, aux_ten);
  				NexXfloatSetValue(9, aux_ten);
  				NexXfloatSetValue(10, aux_ten);
  				NexXfloatSetValue(11, aux_ten);
  				NexXfloatSetValue(12, aux_temp);
  				NexXfloatSetValue(13, aux_temp);
  				NexXfloatSetValue(14, aux_temp);
  				NexXfloatSetValue(15, aux_temp);
  				break;

  			case N_PAGE4:

  				NexXfloatSetValue(0, 4);
  				NexXfloatSetValue(1, aux_ten);
  				NexXfloatSetValue(2, aux_ten);
  				NexXfloatSetValue(3, aux_ten);
  				NexXfloatSetValue(4, aux_ten);
  				NexXfloatSetValue(5, aux_ten);
  				NexXfloatSetValue(6, aux_ten);
  				NexXfloatSetValue(7, aux_ten);
  				NexXfloatSetValue(8, aux_ten);
  				NexXfloatSetValue(9, aux_ten);
  				NexXfloatSetValue(10, aux_ten);
  				NexXfloatSetValue(11, aux_ten);
  				NexXfloatSetValue(12, aux_temp);
  				NexXfloatSetValue(13, aux_temp);
  				NexXfloatSetValue(14, aux_temp);
  				NexXfloatSetValue(15, aux_temp);
  				break;

  			case N_PAGE5:

  				NexXfloatSetValue(0, 5);
  				NexXfloatSetValue(1, aux_ten);
  				NexXfloatSetValue(2, aux_ten);
  				NexXfloatSetValue(3, aux_ten);
  				NexXfloatSetValue(4, aux_ten);
  				NexXfloatSetValue(5, aux_ten);
  				NexXfloatSetValue(6, aux_ten);
  				NexXfloatSetValue(7, aux_ten);
  				NexXfloatSetValue(8, aux_ten);
  				NexXfloatSetValue(9, aux_ten);
  				NexXfloatSetValue(10, aux_ten);
  				NexXfloatSetValue(11, aux_ten);
  				NexXfloatSetValue(12, aux_temp);
  				NexXfloatSetValue(13, aux_temp);
  				NexXfloatSetValue(14, aux_temp);
  				NexXfloatSetValue(15, aux_temp);
  				break;

  			case N_PAGE6:

  				NexXfloatSetValue(0, 6);
  				NexXfloatSetValue(1, aux_ten);
  				NexXfloatSetValue(2, aux_ten);
  				NexXfloatSetValue(3, aux_ten);
  				NexXfloatSetValue(4, aux_ten);
  				NexXfloatSetValue(5, aux_ten);
  				NexXfloatSetValue(6, aux_ten);
  				NexXfloatSetValue(7, aux_ten);
  				NexXfloatSetValue(8, aux_ten);
  				NexXfloatSetValue(9, aux_ten);
  				NexXfloatSetValue(10, aux_ten);
  				NexXfloatSetValue(11, aux_ten);
  				NexXfloatSetValue(12, aux_temp);
  				NexXfloatSetValue(13, aux_temp);
  				NexXfloatSetValue(14, aux_temp);
  				NexXfloatSetValue(15, aux_temp);
  				break;

//  			case PAGE7:
//
//
//  				break;


  		}

  }


