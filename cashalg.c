#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    float f;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    do {
        f = get_float("Change owed: \n");
    }
    while (f < 0);

    int coins[4] = {25, 10, 5, 1};

    if (f == 0.00) {
        printf("Usage: Enter amount in float (decimal) form greater than 0.");
    }

    int change = (int)round(f*100);
    int counter = 0;
    while (change > 0) {
        for (int i = 0; i < ((int)sizeof(coins) / 4); i++) {
            while (change % coins[i] != change) {
                change -= coins[i];
                counter++;
                printf("%i cents removed. %i cents left\n", coins[i], change);
            }
        }
    }
    printf("Total of %i coins required.\n", counter);
}
