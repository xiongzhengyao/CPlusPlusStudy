#define C_TO_F(degc) ((degc) * (9.0 / 5.0) + 32.0)
    
#define SQUARE(x) ((x) * (x))

// Function to return the square of a number
double square(double num) {
    return SQUARE(num);
}


#include <stdint.h>

void swapbit(uint8_t* b)
{
    *b = (*b & 0xF0) >> 4 | (*b & 0x0F) << 4;
}

int main()
{

}