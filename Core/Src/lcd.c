#include "lcd.h"
#include "spi.h"

void lcd_reset(){
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);
}

void lcd_cmd(uint8_t cmd){
	HAL_GPIO_WritePin(LCD_CE_GPIO_Port, LCD_CE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET);
	HAL_StatusTypeDef err_transmit;
	HAL_StatusTypeDef err_receive;
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	err_transmit = HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(LCD_CE_GPIO_Port, LCD_CE_Pin, GPIO_PIN_SET);
}

void lcd_data(const uint8_t** data, const uint8_t rows, const uint8_t columns)
{
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_CE_GPIO_Port, LCD_CE_Pin, GPIO_PIN_RESET);
	HAL_StatusTypeDef err_transmit;
	HAL_StatusTypeDef err_receive;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
			err_transmit = HAL_SPI_Transmit(&hspi1, *(data + i) + j, 1, HAL_MAX_DELAY);
		}

	}
	HAL_GPIO_WritePin(LCD_CE_GPIO_Port, LCD_CE_Pin, GPIO_PIN_SET);
}

void lcd_init(){
	lcd_reset();
	lcd_cmd(0x21);
	lcd_cmd(0xC0);
	lcd_cmd(0x20);
	lcd_cmd(0x0C);
}

void set_position(uint8_t* x, uint8_t* y){
	lcd_cmd(0x80 | *x);
	lcd_cmd(0x40 | (*y/8));
}

void set_point(uint8_t** data, uint8_t* x, uint8_t* y){
	*(*(data + (*y/8)) + *x) |= 0x1 << *y%8;
}

void clear_point(uint8_t** data, uint8_t* x, uint8_t* y){
	*(*(data + (*y/8)) + *x) &= ~(0x1 << *y%8);
}

void load_board_data(const uint8_t** data, const uint8_t rows, const uint8_t columns)
{
	lcd_data(data, rows, columns);
}
