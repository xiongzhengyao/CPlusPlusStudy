#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>

// 1/-4)-State-Machine-(26-points)
// 1/--- -Complete-the- function-below- to-implement- the- state-mechine-shown-in-the
// 1/----diagram-below-for-an-electronic-gumball-vending-machine.
// 1/……*.The-initial·state-of·the-state-machine-should-be-IDLE
// 1/……*.The-state-machine-should-maintain-and-manage-its-state
// 1/.….*.The-Function-should-return-the-current-state-of-the-state-machine
// 1/……*.Unexpected-or-invalid-input-should-not-cause-a-state-transition
// ....*-GENERIC_FAULT-may-be-received-in-any-state-and- should put-the-machine

// typedef-enum
// J0LE,NEADY,VENDINS,FAULT 3-state_E;
// typedef-enum
// COIN,
// COIN_RETURN,
// BUTTON,
// VEND_COMPLETE,GENERIC_FAULT J- ânput_Es

// 5) Interpolation (20 points)
// Given two arrays of n > 1 values arrX[] (sorted ascending) and arrY[]
// (sorted ascending), write an interpolation function that satisfies the
// following:
//
// * Interpolation(arrX[i]) returns arrY[i], for 0 <= i < n
// * Interpolation(val) returns the linearly interpolated value
//   of val if arrX[0] <= val <= arrX[n-1]. That is: val shall be found between
//   arrX[i-1] and arrX[i] and the return value shall be the interpolation of
//   arrY[i-1] and arrY[i].
// * Interpolation(val) returns -1 for any other case.
//
//           |                   /
//   arrY[i] |------------------+
//           |                / |
//           |              /   |
//    return |------------O     |
//           |          / |     |
//           |        /   |     |
//           |      /     |     |
// arrY[i-1] |----+       |     |
//           |  / |       |     |
//           |/___|_______|_____|______
//            arrX[i-1]  val   arrX[i]
 
#define ARR_SIZE 5 // Example size, can be adjusted as needed
float arrX[ARR_SIZE] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f}; // Example values
float arrY[ARR_SIZE] = {10.0f, 20.0f, 30.0f, 40.0f, 50.0f}; // Example values

float interpolate(float val)
{
    // Check if val is within the range of arrX
    if (val < arrX[0] || val > arrX[ARR_SIZE - 1]) {
        return -1.0f;
    }

    // Find the interval where val lies
    int i;
    for (i = 0; i < ARR_SIZE - 1; i++) {
        if (val <= arrX[i + 1]) {
            break;
        }
    }

    // If val exactly matches an arrX value, return corresponding arrY value
    if (val == arrX[i]) {
        return arrY[i];
    }

    // Perform linear interpolation
    float x0 = arrX[i];
    float x1 = arrX[i + 1];
    float y0 = arrY[i];
    float y1 = arrY[i + 1];

    return y0 + (val - x0) * (y1 - y0) / (x1 - x0);
}
float interpolate(float val)
{
    
    // Answer: TODO
    return 0.0f;
}