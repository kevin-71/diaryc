#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "set.h"
#include <math.h>
#include "log.h"
#include "search.h"
#define MAX_LEVELS 18

int main() {
    srand(time(NULL));
    int nbLevel = 18;
    int iterations = 100000;
    if (nbLevel > MAX_LEVELS) {
        nbLevel = MAX_LEVELS;
    }
    t_level_list *myList;
    for (int j = 5; j < nbLevel; j++){
        printf("level list of %d levels\n", j);

        myList = createLevelList(j); // create a j levels list
        printf("List of %d levels created\n", j);
        startTimer();
        for (int i = 0; i < iterations; i++) {
            int numToSearch = rand() % (int)(pow(2, j) - 1);
            int isFoundClassical = classicalSearch(myList, numToSearch);
        }
        stopTimer();
        displayTime();

        startTimer();
        for (int i = 0; i < iterations; i++) {
            int numToSearch = rand() % (int)(pow(2, j) - 1);
            int isFoundEfficient = efficientSearch(myList, numToSearch, myList->heads[myList->max_levels - 1], j - 1, myList->heads[myList->max_levels - 1]); // calling with the right parameters
        }
        stopTimer();
        displayTime();
        printf("\n");
    }
}