#ifndef INC_LCD_H_
#define INC_LCD_H_

#include <stdint.h>

#define LCD_ROWS 5
#define LCD_COLUMNS 48

void lcd_reset(void);

void lcd_cmd(uint8_t cmd);

void lcd_data(const uint8_t** data, const uint8_t rows, const uint8_t columns);

void lcd_init();

void set_position(uint8_t* x, uint8_t* y);

void display_point(uint8_t* x, uint8_t* y);

void clear_point(uint8_t* x, uint8_t* y);

void load_board_data(const uint8_t** data, const uint8_t rows, const uint8_t columns);

#endif /* INC_LCD_H_ */
