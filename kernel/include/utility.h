#ifndef UTILITY_H
#define UTILITY_H

#include <exports.h>

#include <arm/psr.h>
#include <arm/exception.h>
#include <arm/interrupt.h>
#include <arm/timer.h>
#include <arm/reg.h>

#include "constant.h"



int install_handler(unsigned *vector, unsigned *handler,unsigned *S_Handler, unsigned *original_1, unsigned *original_2);

void restore_handler(unsigned *handler,unsigned original_1, unsigned original_2);

void setup_peripheral_device(unsigned *ICMR, unsigned *ICLR, unsigned *OIER);

void restore_peripheral_device(unsigned ICMR, unsigned ICLR, unsigned OIER);


#endif


