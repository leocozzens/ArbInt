#ifndef ARBINT_H
#define ARBINT_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint64_t *set;
    unsigned int size;
    bool sign;
} ArbInt;

ArbInt *arb_create(bool sign, unsigned int size, ...);
void arb_destroy(ArbInt **target);

ArbInt *arb_add(ArbInt *x, ArbInt *y);
ArbInt *arb_sub(ArbInt *x, ArbInt *y);
ArbInt *arb_div(ArbInt *x, ArbInt *y);
ArbInt *arb_mult(ArbInt *x, ArbInt *y);

ArbInt *arb_add_replace(ArbInt **x, ArbInt *y);
ArbInt *arb_sub_replace(ArbInt **x, ArbInt **y, bool which);
ArbInt *arb_div_replace(ArbInt **x, ArbInt **y, bool which);
ArbInt *arb_mult_replace(ArbInt **x, ArbInt *y);

char *arb_print_hex(ArbInt *target);
char *arb_print_base10(ArbInt *target);

#endif
