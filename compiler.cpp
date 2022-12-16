#include <stdio.h>
#include <stdlib.h>
#include<list>
 std::list<char> out; 
char inputFile[] = "/Users/cosikym/Desktop/Developer/Projects/Open_projects/PyJ/main.py";
char outputFile[] = "/Users/cosikym/Desktop/Developer/Projects/Open_projects/PyJ/out.py";
bool inQuotes = false;
bool isScopeBrace = false;
bool isFree = true;
void error(char msg[]){
    printf("PyJ Error: ");
    printf("%s", msg);
}
// This function checks each character, to set flags designating their purpose.
void q(char in){
     if(in == '"'){
    inQuotes = !inQuotes;
    // printf("%c", in);
    }
    if(in == '{' && !inQuotes){
        isScopeBrace = true;
    }else
        if(in == '}' && !inQuotes){
        isScopeBrace = true;
    }else{
        isScopeBrace = false;
    }
    isFree = !inQuotes;
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

// The compiler does not check for errors while compiling, meaning that a function must check that the code is perfect
// before it gets compiled, or else is will not run properly.
void checkForErrors(char in[]){
unsigned int i = 0;
unsigned int i2 = 0;
unsigned int indent = 1;
while(in[i+1] != NULL){
    q(in[i]);
    if(in[i] == 'i' && in[i+1] == 'f'){
        while(true){
            if(in[i] == NULL){
                error("Missing a '{'");
                return;
            }
            if(in[i] == '{' && isFree){
                
            }
            q(in[i]);
            i++;
        }
    }
    if((in[i] == '{' || in[i] == '}') && isFree && !isScopeBrace){
        
    }
i++;
}
}

void compile(char in[]){
checkForErrors(in);
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
        

        if(in[i] == '{' && isFree){
            out.pop_back();
            out.push_back(':');
        indent++;
        
    }
    if(in[i] == '}' && isFree){
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