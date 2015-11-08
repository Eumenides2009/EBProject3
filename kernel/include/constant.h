#ifndef CONSTANT_H
#define CONSTANT_H

#define user_stack_top 0xa3000000
#define irq_stack_top 0xa2000000 
#define user_entry 0xa0000000
#define load_inc_ins 0xe59ff000
#define load_dec_ins 0xe51ff000
#define swi_mask 0x00ffffff
#define error_status 0x0badc0de
#define ram_upper_bound 0xa3ffffff
#define ram_lower_bound 0xa0000000
#define rom_upper_bound 0x00ffffff
#define rom_low_bound   0x00000000
#define read_swi_return  0x3
#define write_swi_return 0x4
#define exit_swi_return  0x1
#define time_swi_return  0x6
#define sleep_swi_return 0x7
#define irq_elapse_time 10
#define irq_elapse_count 32500

#endif



