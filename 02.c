// 2) Function Debug (5 points)
// The following function should compute and return the square of the value 
// pointed to by x.  Correct any mistakes in the implementation.

#include <stdint.h>

uint8_t computeSquareADC(volatile uint8_t *x)
{
    uint16_t temp = (uint16_t)(*x) * (*x);
    return (uint8_t)(temp > 255 ? 255 : temp);
}