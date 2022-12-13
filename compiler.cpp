#include <stdio.h>
#include <stdlib.h>
#include<list>

char inputFile[] = "/Users/cosikym/Desktop/Developer/Projects/Open_projects/PyJ/main.py";
char outputFile[] = "/Users/cosikym/Desktop/Developer/Projects/Open_projects/PyJ/out.py";
void error(char msg[]){
    printf("PyJ Error: ");
    printf("%s", msg);
}
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
  
 std::list<char> out; 
unsigned int i = 0;
bool inQuotes = false;
unsigned int indent = 0;
while(in[i] != NULL){
    if(in[i] == '"'){
        inQuotes == true;
    }
    if(in[i] == '\n'){
        if(in[i+1] == 'v' && in[i+2] == 'a' && in[i+3] == 'r' && in[i+4] == ' '){
            
        }
    }
    if(in[i] == 'i' && in[i+1] == 'f'){
        while(in[i] != '{'){
            if(in[i] == NULL){
                error("Missing a '{'");
                return;
            }
            out.push_back(in[i]);
            i++;
        }
                while(in[i] != '}'){
            if(in[i] == NULL){
                error("Missing a '}'");
                return;
            }
            out.push_back(in[i]);
            i++;
        }
    }

    i++;
}

i = 0;
char output[1000];
       for (char x : out) {
output[i] = x;
 printf("%c", x);
i++;
        }
write(output);
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