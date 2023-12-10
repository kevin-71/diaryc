#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


t_level_cell *createCell(int value, int level) {
    t_level_cell *myCell;
    myCell = (t_level_cell *)malloc(sizeof(t_level_cell)); // allocate memory for the cell
    myCell->value = value; // set the value and the level
    myCell->level = level;

    if (level > 0) {
        myCell->tab_next = (t_level_cell **)malloc(level * sizeof(t_level_cell *)); // allocate memory for the pointers
        for (int i = 0; i < level; i++) {
            myCell->tab_next[i] = NULL; // set all the pointers to NULL
        }
    } else {
        myCell->tab_next = NULL;
    }

    return myCell;
}



t_level_list * createEmptyLevelList(int max_levels) {
    t_level_list *myList;
    myList = (t_level_list*) malloc(sizeof(t_level_list)); // allocate memory for the list
    myList->max_levels = max_levels;

    myList->heads = (t_level_cell **) malloc(max_levels * sizeof(t_level_cell *)); // two * : one for pointer, the other for dynamic list
    for (int i = 0; i < max_levels; i++){
        myList->heads[i] = NULL; // set all the heads to NULL
    }
    return myList;
}


void displayCell(t_level_cell *myCell){
    if (myCell == NULL){
        printf("NULL\n");
    }
    printf("-->[%d|@-]", myCell->value); // print the value of the cell with this format
}


void displayList(t_level_list myList){
    for (int i = 0; i < myList.max_levels; i++) {
        printf("[list head_%d @-]", i);

        t_level_cell *curr = myList.heads[i]; // set the current cell to the head of the list corresponding to the level

        while (curr != NULL) {
            displayCell(curr);
            curr = curr->tab_next[i]; // going through the list by going from one cell to the next cell
        }
        printf("-->NULL\n");
    }
}

void addCellToList(t_level_list *myList, t_level_cell *myCell){
    if (myCell->level < 0 || myCell->level > myList->max_levels){
        return;
    }
    for (int i = 0; i < myCell->level; i++){
        if (myList->heads[i] == NULL){
            myList->heads[i] = myCell; // if the head of the list is NULL, set the head to the cell
        }
        else{
            t_level_cell *curr = myList->heads[i]; // declarer a current cell
            while (curr->tab_next[i] != NULL && curr->tab_next[i]->value < myCell->value){
                curr = curr->tab_next[i]; // going through the list
            }
            myCell->tab_next[i] = curr->tab_next[i]; // set the next cell to the next cell of the current cell
            curr->tab_next[i] = myCell; // set the cell to the next cell
        }
    }
}

t_level_list *createLevelList(int n){
    int nbCell = (int) pow(2, n) - 1; // the number of cells is 2^n - 1
    t_level_list *myList = createEmptyLevelList(n); // create an empty list
    for (int i = 0; i < nbCell; i++){
        int level = 0;
        for (int j = 0; j < n; j++){
            if ((i + 1) % (int) pow(2, j) == 0){ // when the number of the cell is a power of 2, the level is incremented
                level++;
            }
        }
        t_level_cell *newCell = createCell(i, level); // create a cell with the corresponding value and level
        addCellToList(myList, newCell); // add it to the list
    }
    return myList;
}
