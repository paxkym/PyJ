#include <stdio.h>
#include <stdlib.h>
#include<list>
 std::list<char> out; 
char inputFile[] = "/Users/cosikym/Desktop/Developer/Projects/Open_projects/PyJ/main.py";
char outputFile[] = "/Users/cosikym/Desktop/Developer/Projects/Open_projects/PyJ/out.py";
bool inQuotes = false;
void error(char msg[]){
    printf("PyJ Error: ");
    printf("%s", msg);
}
void q(char in){
     if(in == '"'){
    inQuotes = !inQuotes;
    // printf("%c", in);
    }
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

unsigned int i = 0;
unsigned int i2 = 0;
unsigned int indent = 1;
while(in[i] != NULL){

 q(in[i]);


    if(in[i] == '\n'){
        if(in[i+1] == 'v' && in[i+2] == 'a' && in[i+3] == 'r' && in[i+4] == ' '){
            
        }

    }
    out.push_back(in[i]);
    if(in[i] == '\n'){
                    i2 = 0;
    while(i2<indent){
        out.push_back(' ');
        i2++;
    }
    }
        

        if(in[i] == '{' && !inQuotes){
            out.pop_back();
            out.push_back(':');
        indent++;
        
    }
    if(in[i] == '}' && !inQuotes){
                out.pop_back();
        indent--;
            printf("%i", indent);
}
i++;
}

i = 0;
char output[1000];
       for (char x : out) {
output[i] = x;
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