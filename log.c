#include "log.h"
#include <stdio.h>
#include "timer.h"

FILE *log_file; // file pointer

int getTimeInText() {
    int level;
    char format[] = "%d\t%s\t%s\n" ; // format of the time in string to print in the file
    char *time_lvl0;
    char *time_all_levels;
    log_file = fopen("log.txt", "a"); // opening the file, append mode, to avoid overwriting
    time_all_levels = getTimeAsString();
    fprintf(log_file,format,level,time_lvl0, time_all_levels); // print in the file
    time_lvl0 = getTimeAsString();
    fclose(log_file); // close the file
    return 0;
}