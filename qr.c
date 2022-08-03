#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// task 1.1
void encode_char(const char character, bool bits[8]){
    // zeroing array
    for (int i = 0; i < 8; i++)
    {
        bits[i] = false;
    }
    // converting decimal => binary
    int decimal = (int)character;
    int i = 7;
    while (decimal > 0){
        bits[i] = decimal % 2;
        decimal = decimal / 2;
        i--;
    }
}
// task 1.2
char decode_byte(const bool bits[8]){
    // array of bits to one int
    int binary = 0;
    for (int i = 0; i < 8; i++){
        binary = 10 * binary + (int)bits[i];
    }
    // converting binary=>decimal
    int decimal = 0, i = 0, x;
    while (binary != 0) {
        x = binary % 10;
        binary /= 10;
        decimal += x * pow(2, i);
        ++i;
    }
    return (char)decimal;
}
// task 2.1
void encode_string(const char string[], bool bytes[strlen(string)+1][8]){
    int len = strlen(string)+1;
    for (int i = 0; i < len; i++){
        encode_char(string[i], bytes[i]);
    }
}
// task 2.2
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){
    for (int i = 0; i < rows; i++){
        string[i] = decode_byte(bytes[i]);
    }
}
// task 3.1
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    // zeroing blocks array
    for (int a = 0; a < (offset*8); a++)
    {
        for (int b = 0; b < cols; b++)
        {
            blocks[a][b] = false;
        }
        
    }
    
    int columns = 0;
    int row = 0;
    int shift_counter = 0;
    for (int i = 0; i < rows; i++)
    {   
        if (columns == cols)
        {
            columns = 0;
            shift_counter++;
        }
        row = (shift_counter * 8);
        for (int j = 0; j < 8; j++)
        {
            blocks[row][columns] = bytes[i][j];
            row++;
        }
        columns++;
    }
    
}
// task 3.2
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    int columns = 0;
    int row = 0;
    int shift_counter = 0;
    for (int i = 0; i < rows; i++)
    {   
        if (columns == cols)
        {
            columns = 0;
            shift_counter++;
        }
        row = (shift_counter * 8);
        for (int j = 0; j < 8; j++)
        {
            bytes[i][j] = blocks[row][columns];
            row++;
        }
        columns++;
    }
}
int main(){
    return 0;
}