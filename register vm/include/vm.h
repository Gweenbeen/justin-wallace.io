#ifndef VM_H
#define VM_H

#include "common.h"

// each bytecode is 16 bits
// 4 instruction
// 4 register
// 8 value
#define WRITE_BIT(op, reg, val) (((op & 0xF) << 12 ) | ((reg & 0xF) << 8) | (val & 0xFF))
#define READ_OPCODE(x) (((x) >> 12) & 0xF)
#define READ_ARG1(x) (((x) >> 8) & 0xF)
#define READ_ARG2(x) ((x) & 0xFF)

// 16 instructions only, but may expand to 64 if i want to switch to 8 bit instructions
enum {
	CONST = 0,	// store constant
	ADD,	// add
	SUB,	// subtract
	MULT,	// multiply
	DIV,	// divide
	AND,	// bitwise and
	OR,		// bitwise or
	NOT,	// bitwise not
	JUMP,	// jump
	CALL,	// call stack
	RET,	// return stack
	PUSH,	// push register to stack
	POP,	// pop register from stack
	LOAD,	// load memory to reg (unused)
	STORE,	// store reg to memory (unused)
	HALT,	// halt program
};

// 13 general purpose reg
// 3 reserved reg (flag pointer, stack pointer, instruction pointer)
enum {
	R0 = 0,
	R1,
	R2,
	R3,
	R4,
	R5,
	R6,
	R7,
	R8,
	R9,
	R10,
	R11,
	R12,
	R13,
	FP,
	SP,
	IP
};

typedef struct {
	uint16_t reg[16];
	uint16_t stack[256];
} VM;


void runVM();

#endif