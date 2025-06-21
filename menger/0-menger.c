#include <stdio.h>
#include <math.h>
#include "menger.h"
/**
 * menger - Draws a 2D representation of the Menger sponge at a given level.
 * @level: The level of the Menger sponge to draw.
 *
 * If level is lower than 0, the function does nothing.
 */

void menger(int level) {
    int size = pow(3, level);
    
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            int x = row;
            int y = col;
            char print_char = '#';
            
            for (int lvl = 0; lvl < level; lvl++) {
                if (x % 3 == 1 && y % 3 == 1) {
                    print_char = ' ';
                    break;
                }
                x /= 3;
                y /= 3;
            }
            printf("%c", print_char);
        }
        printf("\n");
    }
}
