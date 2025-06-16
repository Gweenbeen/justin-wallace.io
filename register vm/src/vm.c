#include "vm.h"

static uint16_t program[] = {
	WRITE_BIT(CONST, R0, 12),
	WRITE_BIT(CONST, R1, 15),
	WRITE_BIT(MULT, R1, R0),
	WRITE_BIT(HALT, 0, 0),
};

void runVM(VM* vm) {
	int count = 0;
	int capacity = 0;

	vm->reg[IP] = 0;

	int running = 1;
	while(running) {


		uint16_t instruction = program[vm->reg[IP]++];
		uint8_t op = READ_OPCODE(instruction);
		uint8_t arg1 = READ_ARG1(instruction);
		uint8_t arg2 = READ_ARG2(instruction);

		switch(op) {
		// arithmetic
		case CONST:
			printf("Writing %d to register %d\n", arg2, arg1);
			vm->reg[arg1] = arg2;
			break;

		case ADD:
			printf("Adding from register %d to register %d... ", arg1, arg2);
			vm->reg[arg1] += vm->reg[arg2];
			printf("result is %d\n", vm->reg[arg1]);
			break;

		case SUB:
			printf("Subtracting from register %d to register %d... ", arg1, arg2);
			vm->reg[arg1] -= vm->reg[arg2];
			printf("result is %d\n", vm->reg[arg1]);
			break;

		case MULT:
			printf("Multiplying from register %d to register %d... ", arg1, arg2);
			vm->reg[arg1] *= vm->reg[arg2];
			printf("result is %d\n", vm->reg[arg1]);
			break;

		case DIV:
			printf("Dividing from register %d to register %d... ", arg1, arg2);
			vm->reg[arg1] /= vm->reg[arg2];
			printf("result is %d\n", vm->reg[arg1]);
			break;

		// bitwise
		case AND:
			printf("Bitshift AND from register %d to register %d... ", arg1, arg2);
			vm->reg[arg1] &= vm->reg[arg2];
			printf("result is %d\n", vm->reg[arg1]);
			break;

		case OR:
			printf("Bitshift OR from register %d to register %d... ", arg1, arg2);
			vm->reg[arg1] |= vm->reg[arg2];
			printf("result is %d\n", vm->reg[arg1]);
			break;

		case NOT:
			printf("Bitshift NOT from register %d to register %d... ", arg1, arg2);
			vm->reg[arg1] = ~vm->reg[arg2];
			printf("result is %d\n", vm->reg[arg1]);
			break;

		// control
		case JUMP:
			printf("Jumping to instruction %d\n", arg2);
			vm->reg[IP] = arg2;
			break;

		case HALT:
			printf("Halting program");
			running = 0;
			break;

		case CALL: // todo
			break;

		case RET: // todo
			break;

		case PUSH:
			printf("Pushing %d onto the stack\n", arg1);
			vm->stack[vm->reg[SP]++] = vm->reg[arg1];
			break;

		case POP:
			printf("Popping %d from the stack\n", arg1);
			vm->reg[arg1] = vm->stack[--vm->reg[SP]];
			break;

		// memory (unused)
		case LOAD:
			break;
		case STORE:
			break;

		default:
			printf("Unknown opcode: %d", vm->reg[IP]);
			exit(1);
		}
	}
}