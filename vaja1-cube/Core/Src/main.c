#include "main.h"
#include <stdint.h>

struct vector {
    int32_t x;
    int32_t y;
    float length;
};

uint32_t reset_bit(uint32_t x, uint8_t p) {
	x = x & ~(1 << p);
	return x;
}

uint32_t reset_two_bits(uint32_t x, uint8_t p) {
	x = x & ~(1 << p);
	x = x & ~(1 << (p+1));
	return x;
}

uint32_t set_bit(uint32_t x, uint8_t p) {
	x = x | (1 << p);
	return x;
}

uint32_t set_two_bits_to(uint32_t x, uint8_t p, uint8_t n) {
	x = x & ~(3u << p);
	x = x | (n << p);
	return x;
}

void set_vector_length(struct vector *a) {
	a->length = sqrt((a->x)*(a->x)+(a->y)*(a->y));
}

int main(void) {
	uint32_t a;
	uint32_t b;

	a = 0xf;
	b = reset_bit(a, 2); // 0xB
	a = 0xA;
	b = reset_bit(a, 0); // 0xA

	a = 0xFF;
	b = reset_two_bits(a, 3); // 0xE7
	a = 0xB7;
	b = reset_two_bits(a, 3); // 0xA7

	a = 0xB;
	b = set_bit(a, 0); // 0xB
	a = 0xE;
	b = set_bit(a, 2); // 0xE

	a = 0xEF;
	b = set_two_bits_to(a, 3, 1); // 0xEF
	a = 0xB7;
	b = set_two_bits_to(a, 3, 2); // 0xB7

	struct vector c;
	c.x = 4;
	c.y = -2;
	set_vector_length(&c);
	// c.length = 4.47
}
