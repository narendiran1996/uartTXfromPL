#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"

void init_transact(void)
{
	Xil_Out32(0x41200000, 0x0);
	usleep(100);
	Xil_Out32(0x41200000, 0x1);
	usleep(100);
	Xil_Out32(0x41200000, 0x0);
}
int main()
{
//	enable_caches();
	init_uart();

    xil_printf("Hello World\n\r");
    u32 read_loc;
    //read_loc = 0xE0001000 + 0x00000010U;
    read_loc = 0x0a000000;
    Xil_Out32(0x41220000, read_loc);

    u32  write_loc;
    write_loc =  0xE0001000 + 0x0030U;
    Xil_Out32(0x41220008, write_loc);

    u32 write_val, read_val;
    write_val = 0x61;
    Xil_Out32(0x41210008, write_val);

   // init_write_transact();

    while(1)
    {
    	read_val = Xil_In32(0x41210000);
    	xil_printf("The value read is %x and the current val is %x \n\r",read_val, Xil_In32(read_loc));
	sleep(1);
	// to test use
	/* xsct% mwr 0x41200000 0
xsct% mwr 0x41200000 1
xsct% mwr 0x0a000000 0x12345678
xsct% mwr 0x41200000 0
xsct% mwr 0x41200000 1  */
    }

  // init_transfer_d();


    cleanup_platform();
    return 0;
}
