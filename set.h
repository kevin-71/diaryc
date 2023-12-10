#ifndef DIARYC_SET_H
#define DIARYC_SET_H

typedef struct s_d_cell
{
    int value;
    struct s_d_cell *next_0;
    struct s_d_cell *next_1;
} t_d_cell;

typedef struct s_d_list
{
    t_d_cell *head_0;
    t_d_cell *head_1;
} t_d_list;

// structure representing a cell of the list
typedef struct s_level_cell{
    int value;             // value of the cell
    int level;             // level of the cell
    struct s_level_cell ** tab_next; // array of pointers to the next cells
}t_level_cell;

// structure representing the list
typedef struct s_level_list{
    t_level_cell ** heads; // array of pointers to the heads of the lists
    int max_levels;        // maximum level of the list
}t_level_list;

t_level_cell * createCell(int value, int level);
t_level_list * createEmptyLevelList(int);
void displayCell(t_level_cell*);
void displayList(t_level_list);
void addCellToList(t_level_list*, t_level_cell*);
t_level_list *createLevelList(int n);


#endif //DIARYC_SET_H
