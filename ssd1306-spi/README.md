# ssd1306-spi
<br>
This library designed to work with ssd1306 OLED displays via 3- and 4-wire SPI.  

*Note:* the driver uses low layer soft-SPI so make sure you set GPIO maximum output speed to HIGH <i>(this needs more testing)</i>
 
### How to use this driver:
1. Initialize 4(5 for CS) GPIOs as Output Push-Pull in your CubeMX project
1. In **ssd1306-spi.h**:
    * Include your HAL library
    * Change RST, DC, SCL, SDA defines
    * If you use CS pin, then assign SSD1306_USE_CS to 1 and define CS pin
    * Change **SSD1306_HEIGHT** to 32, 64 or 128
1. Call **ssd1306_Init()** to initialize the display

_Note:_ that functions only change the buffer:
```c
// fill display buffer with chosen color
void ssd1306_Fill(SSD1306_COLOR color);
// fill rectangle with color
void ssd1306_FillRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, SSD1306_COLOR color);
// draw single pixel to display buffer
void ssd1306_DrawPixel(uint32_t x, uint32_t y, SSD1306_COLOR color);
// draw char symbol to display buffer
void ssd1306_WriteChar(char ch, FontDef Font, SSD1306_COLOR color);
// draw char  string to display buffer
void ssd1306_WriteString(char* str, FontDef Font, SSD1306_COLOR color);
// draw string of specified length to display buffer
void ssd1306_WriteStringLen(char* str, uint32_t length, FontDef Font, SSD1306_COLOR color);
// set cursor for drawing
void ssd1306_SetCursor(uint32_t x, uint32_t y);
// Bresenham algorithm for drawing lines
void ssd1306_DrawLine(int x1, int y1, int x2, int y2, SSD1306_COLOR color);
``` 

Call it to load data from buffer to display.
```c 
// update information on display
 void ssd1306_UpdateScreen(void);
 ```

##### That library refactored by [zhovtobruhd](https://github.com/zhovtobruhd/) with respect to [afiskon`s](https://github.com/afiskon/stm32-ssd1306) API. Original library provided by https://mcudev.taobao.com
