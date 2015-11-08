//Pengcheng Sun <pengches@andrew.cmu.edu>

#ifndef SWIHANDLER_H
#define SWIHANDLER_H

#include <exports.h>
#include <bits/errno.h>
#include <bits/fileno.h>
#include <bits/swi.h>
#include "utility.h"






int swi_handler(int swi_number);

ssize_t read_handler(int fd, void *buf, size_t count);

ssize_t write_handler(int fd, const void* buf, size_t count);

unsigned long time_handler(void);

void sleep_handler(unsigned long millis);

#endif


