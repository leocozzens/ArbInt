// C standard headers
#include <stdio.h>
// Local headers
#include <arbint.h>

int main(void) {
	ArbInt *myInt = arb_create(true, 1, 0x0);
	printf("The num in hex is: %s\nIn base 10 is _\n", arb_print_hex(myInt));
	return 0;
}
