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

    u32 mem_loc;
    mem_loc = 0xe0001000 + 0x30;
    Xil_Out32(0x41210000, mem_loc);



  //  init_transfer_d();

    while(1)
    {
    	xil_printf("mem_loc:\t%x\t\tread_loc:\t%x\n\r", Xil_In32(mem_loc), Xil_In32(0x41210008));
    	sleep(1);

    }
    cleanup_platform();
    return 0;
}
