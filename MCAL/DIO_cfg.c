
/*
 * DIO_cfg.c
 *
 * Created: 11/5/2022 12:21:11 AM
 *  Author: 20100
 */ 

#include "DIO_interface.h"
#include "STDTYPS.h"


extern const DIO_pin_status  pin_status[]={
	
	INFREE,/***********PORT A***********/
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	INFREE,
	INFREE,/***********PORT B***********/
	OUTPUT,
	OUTPUT,
	OUTPUT,
    OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT, /**********PORT C************/
	OUTPUT,
	OUTPUT,
	OUTPUT,  //ss
	OUTPUT,  //mosi
	OUTPUT,   //miso
	OUTPUT,   //clk
	OUTPUT,
	OUTPUT,/***********PORT D********/
	OUTPUT,
	INPULL,	
	OUTPUT,
	OUTPUT,
	OUTPUT,
	INFREE,
	OUTPUT
	
};

