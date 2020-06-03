#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"


int main()
{
	enable_caches();
	init_uart();

    xil_printf("Hello World\n\r");





    cleanup_platform();
    return 0;
}
