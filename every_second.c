#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *fps = fopen(argv[1], "r");
    FILE *fpd = fopen(argv[2], "w");
    char ch = fgetc(fps);
    if (ch == EOF || fps == NULL)
    {
        fclose(fps);
        fclose(fpd);
        return 0;
    }
    
    char array[2048];
    int counter = 0;
    while (ch != EOF)
    {
        array[counter] = ch;
        ch = fgetc(fps);
        counter++;
    }
    array[counter] = '\0';    
    fclose(fps);
    counter = 0;
    while (array[counter] != '\0')
    {
        if (array[counter] == 'S' && array[counter+1] == 'T' && array[counter+2] == 'A' && array[counter+3] == 'R' && array[counter+4] == 'T')
        {
            break;
        }
        counter++;
    }
    //printf("%c ", array[counter]);
    counter = counter + 6;
    int a = -2;
    int first = 1;
    while (array[counter] != '\0')
    {   
        if (array[counter+1] == 'S' && array[counter+2] == 'T' && array[counter+3] == 'O' && array[counter+4] == 'P')
        {
            break;
        }
        
        
        if (a > 0 && first == 1)
        {
            first = 0;
        }
        else if (a > 0)
        {
            fputc(array[counter], fpd);
        }
        counter++;
        if (array[counter] == ' ')
        {
            a = -1*a;
        }
    }
    fclose(fpd);
    return 0;
}

