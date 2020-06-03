#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"

void init_transfer_d(void)
{
	Xil_Out32(0x41200000, 0x0);
	usleep(100);
	Xil_Out32(0x41200000, 0x1);
	usleep(100);
	Xil_Out32(0x41200000, 0x0);
}
int main()
{
	enable_caches();
	init_uart();

    xil_printf("Hello World\n\r");


    u32 mem_loc, write_val;
    mem_loc = 0xE0001000 + 0x30;
    write_val = 0x12345678;
    Xil_Out32(0x41210000, mem_loc);

    while(1)
    {
    	xil_printf("mem_loc:\t%x\n\r", Xil_In32(mem_loc));
    	   Xil_Out32(0x41210008, 0x61);



    //	init_transfer_d();

    	sleep(1);

    }
    cleanup_platform();
    return 0;
}
