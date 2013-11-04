#ifndef HAT2_H_
#define HAT2_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <avr/pgmspace.h>
 
#define HAT2_NUM_CELLS 1339
#define HAT2_SAMPLERATE 16384
 
const char __attribute__((section(".progmem.data"))) HAT2_DATA [] = {7, -8, 5,
-1, -3, 0, 3, -6, -3, 4, 10, -17, 5, 3, -7, 12, -11, 8, -5, 6, -7, 10, -28, 14,
18, -14, -16, 42, -24, -16, 35, -28, 15, -23, 13, 11, -11, -29, 44, -6, -31, 34,
-5, -23, 8, 10, -4, 0, -20, 12, 8, -11, 1, -3, -3, 2, -1, 17, -16, -7, 10, 3,
-11, -17, 20, 8, -14, 4, -10, 1, 0, -4, 13, -7, -8, 2, 18, -19, -5, 16, -8, 5,
-5, 2, 7, -14, 4, 14, -9, -8, 6, 0, 6, -9, 1, 15, -21, 11, 0, -6, 6, -9, 6, 4,
-3, -5, 2, -2, 1, 9, -17, 13, -15, 8, 40, -75, 1, 25, -2, 12, -14, 5, 7, 0, 29,
-48, -36, 110, -64, -50, 111, -47, -37, 39, -12, -12, 19, 11, -31, 3, 2, 19, -6,
-6, -20, 25, 33, -79, 19, 45, -19, -26, 31, -5, -33, -14, 30, 18, -31, 16, -26,
60, -13, -85, 61, -1, -12, 15, -15, 9, 16, -46, 21, 46, -64, 24, -11, 13, -41,
19, 59, -75, 31, -12, -9, -1, 28, -35, -1, 10, 9, 7, -45, 36, 5, 6, -17, 5, -11,
13, -11, -8, 5, 8, 18, -34, 4, 39, -37, -13, 22, -16, 40, -65, 14, 7, -6, 23,
-25, 13, -20, 0, 1, 28, -8, -18, 18, -7, -12, 8, -17, 29, 17, -31, 0, -8, 3,
-23, 14, 24, -5, -12, 11, -2, -21, 24, -7, 14, -12, 1, -14, -23, 28, -2, 3, -1,
-9, -12, 19, 2, 7, -12, 9, 13, -7, -26, 22, 14, -32, 33, -24, -4, 19, 7, -34, 4,
9, 10, -10, -9, 34, -21, -7, -6, 18, -13, 4, -11, 2, 14, -22, 34, -17, -7, -9,
16, 8, -34, 23, 25, -16, -32, 35, -3, -20, 33, -25, -1, 20, -31, 17, -9, 26,
-26, -18, 32, -41, 22, 12, 4, -31, 19, -3, 4, 6, -28, 11, 0, -2, -6, 9, -23, 35,
-19, 13, 5, -21, 7, -5, 20, -7, 1, -22, 27, 3, -11, -11, -4, 27, -15, -32, 11,
5, -8, -7, 20, 9, -36, 22, 8, -18, -4, 22, -5, -9, 9, -3, 9, -7, -16, 11, -2,
-16, 14, 5, 13, -34, -3, 39, -29, 11, -10, 11, 2, -26, 44, -20, -32, 20, 25,
-19, -36, 32, 10, -2, -16, -18, 29, -3, 3, -7, 13, -15, -14, 22, -10, -4, -1,
19, -13, -8, 16, -10, -22, 6, 27, -22, -17, 10, 11, -2, -2, 19, -20, -6, 15, -2,
-20, 16, -1, -5, -12, -3, 19, -5, -5, -3, 24, -31, 9, 11, -15, -6, 5, 10, -12,
-9, 7, 19, -19, 10, -9, -6, 15, -14, -13, 21, -2, -17, 22, -22, 19, -4, -9, -3,
3, -1, -5, 7, -21, 34, -13, 0, -5, -1, 1, -8, -1, 7, 4, 4, -19, 0, 33, -31, 3,
-1, 19, 2, -18, -6, 14, 10, -6, -5, -16, 10, 5, 1, 13, -40, 30, 11, -25, 11,
-16, 22, -8, -11, -6, 27, -33, 17, 15, -32, 30, -24, 16, -3, -17, 12, 2, 6, -9,
7, -10, -10, 14, 9, 9, -35, 17, 16, -25, 3, -13, 38, -9, -27, 4, -3, 6, -11, 28,
-12, -5, -9, 12, -3, -23, 25, 1, -2, -9, 10, -5, 7, -9, 8, -9, -13, 25, 4, -22,
5, 18, -22, -3, -5, 5, -2, -7, 14, -3, -10, -1, 1, 12, -8, -10, 13, -4, -4, 14,
-11, 6, 2, -13, -2, -17, 26, -8, -11, 8, 10, -4, -13, 9, -18, 22, -10, -7, -1,
1, 10, -18, 7, 0, -4, 2, -3, -8, -5, 11, 16, -24, 13, 1, -13, -2, 4, 8, -10, 16,
-15, 7, -1, -14, 1, 6, 5, -17, -7, 9, 16, -18, 10, -2, -1, -5, 4, -4, -21, 28,
-3, -19, 10, 10, -28, 22, 6, -9, -4, -4, 6, 5, -5, -6, 8, -4, -4, -6, 6, -6, 5,
0, 1, 8, -7, 1, 5, -8, -1, 1, 10, -10, 0, 3, 3, -7, -4, 12, -5, -9, -13, 28, 7,
-8, -14, 9, 9, -18, -10, 13, 8, -9, -8, -4, 8, 10, 5, -18, 5, -2, 1, -8, -3, 23,
-14, 1, -5, -5, 14, 0, -9, -12, 23, -12, -3, 8, -16, 28, -12, -19, 10, 8, -6,
-5, 1, -2, 8, -15, 7, 7, -15, -4, 9, 9, -13, 2, 5, 2, -13, 14, -3, -17, 18, -15,
15, -11, -12, 16, -12, 7, 11, -10, -10, -3, 8, 7, -4, -5, -2, 10, -5, -4, 6, -1,
0, 1, 4, -22, 4, 32, -36, 0, 15, 0, -3, -22, 29, 9, -16, 1, -1, -4, -10, 6, 4,
-3, 12, -11, 0, 4, 0, -7, -14, 18, 2, -7, -2, -6, 7, 8, -13, 2, 4, -9, 2, 11,
-10, -6, 8, -1, 3, -12, 3, -10, 10, 9, -14, 5, -8, 1, 3, -5, 1, -1, -6, 13, -12,
-4, 16, 1, -17, -4, 20, -15, 3, -7, 5, 5, -5, -1, -7, 9, 1, 3, -20, 3, -2, 5, 3,
-5, 0, 0, -7, 11, -3, -23, 28, -14, -7, 8, 8, -14, 0, 8, -2, -10, 2, 4, -12, 16,
-4, 0, -8, -2, 7, 1, -12, 9, 9, -22, 7, 7, -7, -2, 8, -6, 5, 3, -23, 24, -5, -3,
2, 2, -7, -10, 17, -7, -10, 12, -6, -4, 19, -12, 9, -18, 9, -3, 3, -2, -7, 8,
-12, 10, -9, 14, -6, -5, 3, -2, 5, 2, -16, 13, 4, -10, 6, -5, 0, -1, 9, -10, 5,
-1, -8, 11, 0, -7, 1, 1, 1, -6, 0, 6, -4, -2, -6, 16, -8, -8, 6, 0, 3, -10, 7,
-2, -5, 2, 3, 3, -7, 6, 1, -9, 5, -2, 2, 4, -2, 0, -10, 7, -2, 3, 1, -12, 7, -5,
6, 0, -8, -2, -7, 15, 1, -9, 4, -2, 9, -14, -4, 6, 2, 0, 0, -2, -7, 11, -14, 10,
0, -9, -1, 2, 8, -4, -7, 3, 7, -9, -5, -5, 7, -4, 3, -7, -1, 10, -10, 5, -4, 8,
-9, -2, 5, -1, 1, -6, 4, -2, 4, -10, 5, 3, -5, -6, 5, 1, -6, 3, -1, 5, -8, 3,
-6, 4, 2, -4, 4, -7, -2, -3, 9, -8, 0, 8, -9, 4, 0, -2, 0, -4, 5, -2, -4, 0, -3,
7, -3, -2, -4, 1, 5, -6, -1, -1, 4, -1, -1, -5, -1, 7, -4, -1, -3, 2, 5, -11, 1,
7, -4, -1, -2, 1, -1, -3, 2, 2, -1, -6, 0, 0, 4, -2, -5, 5, -3, -3, 5, -6, -1,
4, 0, -4, -1, 2, -1, 1, -4, 7, -11, 5, 3, -5, 1, -4, 5, -5, 0, -1, 1, -3, 4, -2,
-2, 1, 2, 0, -6, 6, -3, 0, 1, -1, -2, 0, 2, -3, 1, -2, -2, 2, 0, -2, 5, -2, -2,
1, -6, 5, -1, -3, 1, 1, 0, -4, 2, 1, -1, 0, 0, -2, 2, -2, -2, 2, -1, 0, -2, 1,
0, -3, 1, 3, -2, -3, 3, -4, -2, 5, -4, -1, 3, -2, -2, 1, -2, 0, 2, -1, -1, -2,
0, 0, 1, -2, 0, -1, -1, 0, 0, 0, -2, 1, 1, -3, -1, -1, 2, -1, -1, 1, -3, 1, 1,
-1, -4, 1, 1, -2, -2, -2, 2, -1, -2, 0, -2, 1, 0, -1, -1, 0, 0, 0, 0, -2, 0, 0,
-1, 0, -1, -2, 1, 1, -3, 0, 1, -2, 1, -1, 0, 0, -2, -1, 0, -1, -1, -1, -1, 0,
-1, 0, -1, -1, 0, 1, -2, 0, 0, -2, 0, -1, -1, -1, -1, 0, 0, -1, -1, 0, -1, -1,
0, 0, -1, -2, 1, 0, -2, 0, 0, -1, 0, -1, -1, 0, -1, 0, -1, -1, 0, -1, -1, -1, 0,
-1, -1, 0, 0, -1, 0, 0, -1, 0, -1, -1, 0, -1, -1, 0, -1, -1, 0, -1, 0, };

#endif /* HAT2_H_ */
