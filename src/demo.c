// C standard headers
#include <stdio.h>
#include <stdlib.h>
// Local headers
#include <arbint.h>

int main(void) {
	ArbInt *myInt = arb_create(true, 2, 0xFFFFFFFFFFFFFFFF, 0x0000000000000080);
	char *myHex = arb_print_hex(myInt);
	printf("The num in hex is: %s\nIn base 10 is _\n", myHex);
	free(myHex);
	return 0;
}
