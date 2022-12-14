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
    if(in[i] == 'i' && in[i+1] == 'f' && !inQuotes){
        while(true){
            printf("%i%c%c", inQuotes, in[i], '\n');
            if(in[i] == NULL){
                error("Missing a '{'");
                return;
            }
            out.push_back(in[i]);
            q(in[i]);
            if(in[i] == '{'){
            if(!inQuotes){
                out.pop_back();
                break;
             }
            }
            
            i++;
        }
            i++;

            while(in[i] != '\n'){
            if(in[i] == NULL){
                error("Missing a newline");
                return;
            }
            q(in[i]);
            i++;
            }
        i++;
            out.push_back(':');
            out.push_back('\n');
                i2 = 0;
                printf("%i", indent);

    while(i2<indent){
        out.push_back(' ');
        i2++;
    }
    printf("hd\n%i\n", inQuotes);
                while(true){
            if(in[i] == NULL){
                error("Missing a '}'");
                return;
            }
                           out.push_back(in[i]);
                         q(in[i]);
            if(in[i] == '}'){
              if(!inQuotes){
                indent--;
                 out.pop_back();
                break;
            }
            }

                
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