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

    int i=0;
    Xil_Out32(0x41210000, 0x0a000000);
    Xil_Out32(0x41210008, 0x50505050);


    init_transfer_d();
    Xil_Out32(0x41210000, 0x0b000000);
    Xil_Out32(0x41210008, 0x10101010);



        init_transfer_d();
    while(1)
    {
    	xil_printf("0x0a's\t%x\t%x\t%x\t%x\n\r",Xil_In32(0x0a000000),Xil_In32(0x0a000004),Xil_In32(0x0a000008),Xil_In32(0x0a00000c));
    	xil_printf("0x0b's\t%x\t%x\t%x\t%x\n\r",Xil_In32(0x0b000000),Xil_In32(0x0b000004),Xil_In32(0x0b000008),Xil_In32(0x0b00000c));
    	sleep(1);

    }
    cleanup_platform();
    return 0;
}
