#include "manipulation.h"

void move(uint8_t** data, uint8_t* x, uint8_t* y, enum direction dir)
{
	clear_point(data, x, y);
	switch(dir)
	{
		case RIGHT:
			(*x)++;
			if (*x > LCD_MAX_INDEX_X)
			{
				*x = 0;
			}
			break;

		case LEFT:
			(*x)--;
			if (*x == 0xFF)
			{
				*x = LCD_MAX_INDEX_X;
			}
			break;

		case UP:
			(*y)--;
			if (*y == 0xFF)
			{
				*y = LCD_MAX_INDEX_Y;
			}
			break;

		case DOWN:
			(*y)++;
			if (*y > LCD_MAX_INDEX_Y)
			{
				*y = 0;
			}
			break;
	}
	set_point(data, x, y);
}
