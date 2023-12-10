#include "search.h"
#include "set.h"
#include <stdlib.h>

int classicalSearch(t_level_list *myList, int value) {
    t_level_cell *curr = myList->heads[0]; // set the current cell to the head of the first level (level 0)

    while (curr != NULL && curr->value < value) {
        curr = curr->tab_next[0]; // going through the list
    }

    if (curr != NULL && curr->value == value) {
        return 1;  // value found
    }
    return 0; // not found
}


int efficientSearch(t_level_list* list, int value, t_level_cell* begin, int level, t_level_cell* temp)
{
    if (level < 0) {
        return 0; // check if the level is valid
    }
    if (begin->value == value){
        return 1; // value found
    }
    if (value < begin->value) // case where the value is inferior to the value of the cell
    {
        if (begin == list->heads[level]) // if it's at the head of the list
        {
            return efficientSearch(list, value,  list->heads[level - 1], level-1,temp);
        }
        else
        {
            t_level_cell* temp2 = temp;
            if(temp2->tab_next[level - 1] != begin) { // if the next cell is not the cell we are looking for
                temp2 = temp2->tab_next[level - 1]; // going to the next cell
                return efficientSearch(list,value,temp2,level - 1,temp);
            }
        }
    }
    else
    {
        return efficientSearch(list, value,  begin->tab_next[level - 1], level - 1,begin); // calling with the good parameters
    }
    return 0; // double check
}
