#ifndef INC_LCD_H_
#define INC_LCD_H_

#include <stdint.h>
#include "spi.h"

#define LCD_ROWS 6
#define LCD_COLUMNS 84
#define LCD_MAX_INDEX_X 83
#define LCD_MAX_INDEX_Y 47

void lcd_reset(void);

void lcd_cmd(uint8_t cmd);

void lcd_data(const uint8_t** data, const uint8_t rows, const uint8_t columns);

void lcd_init();

void set_position(uint8_t* x, uint8_t* y);

void set_point(uint8_t** data, uint8_t* x, uint8_t* y);

void clear_point(uint8_t** data, uint8_t* x, uint8_t* y);

void load_board_data(const uint8_t** data, const uint8_t rows, const uint8_t columns);

#endif /* INC_LCD_H_ */
