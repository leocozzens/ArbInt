// C standard library
#include <stdio.h>
#include <stdarg.h> 
#include <stdint.h>
#include <stdlib.h>
// Local headers
#include <arbint.h>
#include <string.h>

#define UINT64_HEX_SIZE 16
typedef unsigned char byte;

ArbInt *arb_create(bool sign, unsigned int size, ...) {
	byte *data = malloc(sizeof(ArbInt) + sizeof(uint64_t) * size);
	ArbInt *newInt = data;
	newInt->sign = sign;
	newInt->size = size;
	newInt->set = data + sizeof(ArbInt);
	va_list blocks;
	va_start(blocks, size);
	
	for(int i = 0; i < size; i++) newInt->set[i] = va_arg(blocks, uint64_t);
	return newInt;
}

void arb_destroy(ArbInt **target) {
	free((*target)->set);
	free(*target);
	*target = NULL;
}


ArbInt *arb_add(ArbInt *x, ArbInt *y);
ArbInt *arb_sub(ArbInt *x, ArbInt *y);
ArbInt *arb_div(ArbInt *x, ArbInt *y);
ArbInt *arb_mult(ArbInt *x, ArbInt *y);

char *arb_print_hex(ArbInt *target) {
	char *hexVal;
	{
		char tmp[UINT64_HEX_SIZE + 1];
		sprintf(tmp, "%lX", target->set[0]);
		hexVal = malloc(target->size * UINT64_HEX_SIZE + 1 - (UINT64_HEX_SIZE - strlen(tmp)));
		strcpy(hexVal, tmp);
	}
	for(size_t i = 1; i < target->size; i++) {
		char tmp[UINT64_HEX_SIZE + 1];
		sprintf(tmp, "%016lX", target->set[i]);
		strcat(hexVal, tmp);
	}

	return hexVal;
}
char *arb_print_base10(ArbInt *target) {
	return NULL;
}
