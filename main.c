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


void jump(unsigned int * pc, unsigned int new_pc) {
	// Set program counter to new instruction number. 
	*pc = new_pc;
}

void branch_zero(unsigned char acc, unsigned int * pc, unsigned int new_pc) {
	// Jump to instruction if accumulator is zero
	if (acc == 0) {
		jump(pc, new_pc);
	}
}

void branch_positive(unsigned char acc, unsigned int * pc, unsigned int new_pc) {
	// Jump to instruction if accumulator is positive (>0)
	// Assumes accumulator is non zero integer. Handling negative number must be implemented in program.
	if (acc > 0) {
		jump(pc, new_pc);
	}
}

int main() {
	// Initialise accumulator, registers and program counter. 
	unsigned char acc = 0;
	unsigned char * reg = calloc(255, sizeof(unsigned char));
	unsigned int pc = 0;
	

	return 0;
}
