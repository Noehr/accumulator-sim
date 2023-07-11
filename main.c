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


unsigned short alu(ALUOP opcode, unsigned short acc, unsigned short aux) {
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


int main() {
	unsigned short acc;
	unsigned short * reg = calloc(255, sizeof(unsigned short));

	return 0;
}
