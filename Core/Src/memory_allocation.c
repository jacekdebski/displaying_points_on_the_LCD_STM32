#include "memory_allocation.h"

void allocate_memory(uint8_t*** data, const int rows, const int columns)
{
	  *data = (uint8_t**)calloc(rows, sizeof(uint8_t*));
	  for (int i = 0; i < rows; i++) {
		  *(*data + i) = (uint8_t*)calloc(columns, sizeof(uint8_t));
	  }
}

