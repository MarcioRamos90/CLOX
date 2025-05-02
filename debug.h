#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"

void disassemblyChunk(Chunk* chunk, const char * name);
int disassemblyInstruction(Chunk* chunk, int offset);

#endif