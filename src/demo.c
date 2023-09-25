// C standard headers
#include <stdio.h>
#include <stdlib.h>
// Local headers
#include <arbint.h>

int main(void) {
	ArbInt *myInt = arb_create(false, 3, 0x000000000F0F00C, 123, 0x000000000F0F00F);
	char *myHex = arb_print_hex(myInt);
	printf("The num in hex is: %s\nIn base 10 is _\n", myHex);
	free(myHex);
	return 0;
}
