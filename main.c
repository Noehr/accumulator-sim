#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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


uint8_t alu(ALUOP opcode, uint8_t acc, uint8_t aux) {
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


void load(uint8_t * acc, uint8_t * reg, uint8_t address) {
	// Copy value at register address into accumulator
	*acc = *(reg + address);
}


void store(uint8_t * acc, uint8_t * reg, uint8_t address) {
	// Copy value from accumulator to value at register address
	// Pointer to acc is not necessary but is pointer instead of value for consistency
	*(reg + address) = *acc;
}


void jump(uint16_t * pc, uint16_t new_pc) {
	// Set program counter to new instruction number. 
	*pc = new_pc;
}

void branch_zero(uint8_t acc, uint16_t * pc, uint16_t new_pc) {
	// Jump to instruction if accumulator is zero
	if (acc == 0) {
		jump(pc, new_pc);
	}
}

void branch_positive(uint8_t acc, uint16_t * pc, uint16_t new_pc) {
	// Jump to instruction if accumulator is positive (>0)
	// Assumes accumulator is non zero integer. Handling negative number must be implemented in program.
	if (acc > 0) {
		jump(pc, new_pc);
	}
}

int main() {
	// Initialise accumulator, registers and program counter. 

	uint8_t acc = 0;
	uint8_t * reg = calloc(255, sizeof(uint8_t));
	uint16_t pc = 0;

	// Initialise and load instruction memory
	uint16_t * instructions = calloc(4096, sizeof(uint16_t));
	
	FILE * file;
	file = fopen("instructions.bin", "rb");
	fread(instructions, sizeof(uint16_t), 4096, file);
	fclose(file);

	return 0;
}
