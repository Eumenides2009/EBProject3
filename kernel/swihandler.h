//Pengcheng Sun <pengches@andrew.cmu.edu>

#ifndef SWIHANDLER_H
#define SWIHANDLER_H

#include <exports.h>
#include <bits/errno.h>
#include <bits/fileno.h>
#include <bits/swi.h>

#define vector_entry 0x08
#define user_stack_top 0xa3000000
#define user_entry 0xa2000000
#define load_inc_ins 0xe59ff000
#define load_dec_ins 0xe51ff000
#define error_status 0x0badc0de
#define ram_upper_bound 0xa3ffffff
#define ram_lower_bound 0xa0000000
#define rom_upper_bound 0x00ffffff
#define rom_low_bound   0x00000000


int install_swi_handler(unsigned *vector, unsigned *handler,unsigned *S_Handler, unsigned *original_1, unsigned *original_2);

void restore_handler(unsigned *handler,unsigned original_1, unsigned original_2);

int swi_handler(int swi_number);

ssize_t read_handler(int fd, void *buf, size_t count);

ssize_t write_handler(int fd, const void* buf, size_t count);


#endif


