#include <stdio.h>
#include <stdlib.h>


// Enum for ALU operations 
typedef enum {
	ALU_NOP, 
	ALU_ADD,
	ALU_SUB,
	ALU_AND,
	ALU_OR,
	ALU_XOR,
	ALU_NOT,
	ALU_SHR
} ALUOP;


unsigned char alu(ALUOP opcode, unsigned char acc, unsigned char aux) {
	// Returns next value of accumulator  
	switch (opcode) {
	case ALU_NOP:
		return acc;
	case ALU_ADD:
		return acc + aux;
	case ALU_SUB:
		return acc - aux;
	case ALU_AND: 
		return acc & aux;
	case ALU_OR:
		return acc | aux;
	case ALU_XOR:
		return acc ^ aux;
	case ALU_NOT: 
		return ~acc;
	case ALU_SHR: 
		return acc >> 1;
	default:
		return acc;
	}
}


void load(unsigned char * acc, unsigned char * reg, unsigned char address) {
	// Copy value at register address into accumulator
	*acc = *(reg + address);
}


void store(unsigned char * acc, unsigned char * reg, unsigned char address) {
	// Copy value from accumulator to value at register address
	// Pointer to acc is not necessary but is pointer instead of value for consistency
	*(reg + address) = *acc;
}

int main() {
	unsigned char acc = 0;
	unsigned char * reg = calloc(255, sizeof(unsigned short));

	return 0;
}
