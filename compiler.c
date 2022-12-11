#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[] = "c";
int main(){
    printf("hi");
FILE* file;
    char c;
    // Opening file in reading mode
    file = fopen("/Users/cosikym/Desktop/Developer/Projects/Open_projects/PyJ/main.py", "r");
    do {
        c = fgetc(file);
        strncat(input,c, 1);
    } while (c != EOF);
    fclose(file);
    return 0;
}