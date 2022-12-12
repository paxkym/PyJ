#include <stdio.h>
#include <stdlib.h>

char inputFile[] = "/Users/cosikym/Desktop/Developer/Projects/Open_projects/PyJ/main.py";
char outputFile[] = "/Users/cosikym/Desktop/Developer/Projects/Open_projects/PyJ/out.py";

void write(char text[]){
    FILE *file;
    file = fopen(outputFile, "w");
    if (file == NULL) {
        printf("File does not exist, or is invalid");
        return;
    }
    fprintf(file, "%s", text);
    fclose(file);
}


void compile(char in[]){
    printf("\n");
  char h = "\n";
  
  bool t = true;

unsigned int i = 0;
while(i<sizeof(in)){
// if(in[i] == "\u000A"){
    
//     printf("ayo");
// }
    printf("%c", in[i]);
    i++;
}
write(in);
return;
}


int main(){

FILE* file;
    char c;
    int length = 0;

    file = fopen(inputFile, "r");
    while (c != EOF){
        c = fgetc(file);
        length++;
    };
    fclose(file);

    c = NULL;
    char out[length];

    int i = 0;

    file = fopen("/Users/cosikym/Desktop/Developer/Projects/Open_projects/PyJ/main.py", "r");
    while (c != EOF){
        c = fgetc(file);
        out[i] = c;
        i++;
    };
    fclose(file);

    compile(out);

    return 0;
}