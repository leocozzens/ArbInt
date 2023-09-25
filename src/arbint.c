// C standard library
#include <stdio.h>
#include <stdarg.h> 
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
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
	char tmp[UINT64_HEX_SIZE + 1];
	sprintf(tmp, "%lX", target->set[0]);

	char *hexVal = malloc(target->size * UINT64_HEX_SIZE + 1 - (UINT64_HEX_SIZE - strlen(tmp)));
	char *nextVal = stpcpy(hexVal, tmp);

	for(uint64_t i = 1; i < target->size; i++) {
		sprintf(tmp, "%016lX", target->set[i]);
		nextVal = stpcpy(nextVal, tmp);
	}

	return hexVal;
}
char *arb_print_base10(ArbInt *target) {
	char buffer[(target->size * 64) / 3 + 2];
	char *result = buffer + sizeof(buffer) - 1;

	*result = '\0';
	uint64_t num;
	for(int i = 0; i < target->size; i++) {
		num = target->set[i];
		do {
			*--result = '0' + (num % 10);
			num /= 10;
		} while(num != 0);
	}
	char *digiVal = malloc(strlen(result));
	strcpy(digiVal, result);
	return digiVal;
}
