// C standard headers
#include <stdio.h>
#include <stdlib.h>
// Local headers
#include <arbint.h>

int main(void) {
	ArbInt *myInt = arb_create(false, 2, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFF0);
	char *myHex = arb_print_hex(myInt);
	char *myDigi = arb_print_base10(myInt);
	printf("The num in hex is: %s\nIn base 10 is %s\n", myHex, myDigi);
	free(myHex);
	free(myDigi);
	return 0;
}
