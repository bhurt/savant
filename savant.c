#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int stayWins = 0;
int switchWins = 0;
int carsShown = 0;

#define SWAP(a, b) do { temp = a; a = b; b = temp; } while (0)

static void runTest() {
    // We start with three doors.
    int choice = 1, // The door initially selected by the contestant
        goat = 2,   // The door opened to show a goat
        alt = 3,    // The door the contestant can switch to
        car,        // The door that hides the car
        temp;       // Used in the SWAP macro.

    // The car exists behind one of the three doors.
    car = 1 + (rand() % 3);

    // The contestant picks a random door.
    // The contestant's choice limits the goat and alt choices.
    switch (rand() % 3) {
        case 0:
            break;
        case 1:
            SWAP(choice, goat);
            break;
        case 2:
            SWAP(choice, alt);
            break;
        default:
            assert(0);
            break;
    }

    // We randomly swap the goat and alt doors.
    if ((rand() % 2) == 0) {
        SWAP(goat, alt);
    }

    // Except if this makes goat the door with the car, we swap (we never
    // show the car).
    // Comment out this if statement to allow Monty to open a door to show
    // the car, not a goat.
    if (goat == car) {
        SWAP(goat, alt);
    }

    if (car == choice) {
        stayWins += 1;
    } else if (car == alt) {
        switchWins += 1;
    } else {
        assert(car == goat);
        carsShown += 1;
    }
}

int main(void) {
    int i;
    time_t now;

    // Seed our random number generator.
    now = time(NULL);
    srand((unsigned int) now);

    for (i = 0; i < 1000000; ++i) {
        runTest();
    }

    printf(
        "Number of times sticking with our initial choice would have won: %d\n",
        stayWins);
    printf(
        "Number of times switching our choice would have won:             %d\n",
        switchWins);
    printf(
        "Number of times we showed a car and not a goat:                  %d\n",
        carsShown);
    return 0;
}

