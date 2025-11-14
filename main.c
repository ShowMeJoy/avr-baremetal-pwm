#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB |= (1 << PB1);     // Настраиваем PB5 как выход
    TCCR1A = (1 << COM1A1) | (1 << WGM10);  // Нормальный режим PWM на OC1A
    TCCR1B = (1 << WGM12) | (1 << CS10);    // Fast PWM, без предделителя

    

    while (1)
    {
        for (uint8_t i = 0; i < 255; ++i) {
            OCR1A = i;  // Скважность (0–255)
            _delay_ms(5);
        }
        for (uint8_t i = 255; i > 0; --i) {
            OCR1A = i;
            _delay_ms(5);
        }
    }
}
