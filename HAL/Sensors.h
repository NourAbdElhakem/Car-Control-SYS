


#include "STDTYPS.h"
#include "DIO_interface.h"
#include "ADC.h"

#ifndef SENSORS_H_
#define SENSORS_H_

/*******************confg******************/





#define LM_35  CH_7

#define SMOKE  CH_0


/************************************/



u16 MPX4115_GetPress(void);
u16 TEMP_Read(void);




#endif /* SENSORS_H_ */