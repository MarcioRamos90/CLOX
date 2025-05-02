#include <stdio.h>

#include "debug.h"

void disassemblyChunk(Chunk* chunk, const char* name)
{
  printf("== %s == \n", name);

  for (int offset = 0; offset < chunk->count;) {
    offset = disassemblyInstruction(chunk, offset);
  }
}

static int simplestInstruction(const char* name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

int disassemblyInstruction(Chunk* chunk, int offset) {
  printf("%04d ", offset);

  uint8_t instruction = chunk->code[offset];
  switch(instruction) {
    case OP_RETURN:
      return simplestInstruction("OP_RETURN", offset);
    default:
      printf("Unknown opcode %d\n", instruction);
      return offset + 1;
  }
}