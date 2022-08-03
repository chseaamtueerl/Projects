#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "r");
    char ch = fgetc(fp);
    char array[2048];
    int counter = 0;
    while (ch != EOF)
    {
        array[counter] = ch;
        ch = fgetc(fp);
        counter++;
    }
    array[counter] = '\0';
    fclose(fp);
    counter = 0;
    while (array[counter] != '\0')
    {
        if (array[counter] < 97 && array[counter] > 64){
            array[counter] = array[counter] + 32;
        }
        counter++;
    }
    counter = 5;
    int ananases = 0;
    while (array[counter] != '\0')
    {
        if (array[counter] == 's' && array[counter - 1] == 'a' && array[counter-2] == 'n' && array[counter - 3] == 'a' && array[counter-4] == 'n' && array[counter-5] == 'a')
        {
            ananases++;
        }
        counter++;
    }
    fp = fopen(argv[1], "w");
    if (ananases>9)
    {
        
        fputc((char)48+(ananases / 10), fp);
        fputc((char)48+(ananases % 10), fp);

    }
    else
    {
        fputc((char)48+ananases, fp);
    }
    fclose(fp);
    return 0;
}