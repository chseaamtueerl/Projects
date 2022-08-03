#include <stdio.h>
#include <math.h>

// task_1
float lift_a_car(const int stick_length, const int human_weight, const int car_weight) {
    float length = ( (float)stick_length * (float)human_weight ) / ( (float)human_weight + (float)car_weight );
    length = length * 100;
    length = round(length);
    length = length / 100;
    return length;
}

// task_2
float unit_price(const float pack_price, const int rolls_count, const int pieces_count) {
    float pieces = rolls_count * pieces_count;
    float price = ( pack_price / pieces ) * 100;
    price = price * 100;
    price = round(price);
    price = price / 100;
    return price;
}

// task_3
int collatz(const int number) {
    int counter = 1;
    int number_1 = number;
    while(number_1 != 1) {
        if((number_1 % 2) == 0) {
            number_1 = number_1 / 2;
        }
        else {
            number_1 = (3 * number_1) + 1;
        }
        counter += 1;
    }
    return counter;
}

// task_4
int opposite_number(const int n, const int number){
    int number_count = n;
    int middle = number_count / 2;
    int opposite = 0;
    if (number < middle)
    {
        opposite = middle + number;
    }
    else if (number > middle)
    {
        opposite = number - middle;
    }
    else
    {
        opposite = 0;
    }
    
    
    

    return opposite;
}

// task_5
void counter(const int input_array[], const int array_size, int result_array[2]){
    result_array[0] = 0;
    result_array[1] = 0;
    for (int i = 0; i < (array_size); i++)
    {
        if ((i % 2) == 0)
        {
            result_array[0] += input_array[i];
        }
        else
        {
            result_array[1] += input_array[i];
        }
        
        
    }
    
}

// task_6
unsigned long sum_squared(const int line){
    unsigned long long sucet = 0;
    unsigned long long cislo = 1;
    int a = line;
    int b = 1;
    for (int i = 0; i < (line + 1); i++)
    {
        cislo = cislo * a / b;
        sucet = sucet + (cislo * cislo);
        a--;
        b++;
    }
    return sucet + 1;
    
}

// task_7 hh
int array_min(const int input_array[], const int array_size){
    if (input_array == NULL)
    {
        return -1;
    }
    
    int min = input_array[0];
    for (int i = 0; i < array_size; i++)
    {        
        if (min > input_array[i])
        {
            min = input_array[i];
        }
        
    }
    if (input_array == NULL)
    {
        return -1;
    }
    else
    {
        return min;
    } 
    
    
}

int array_max(const int input_array[], const int array_size){
    if (input_array == NULL)
    {
        return -1;
    }
    int max = input_array[0];
    for (int i = 0; i < array_size; i++)
    {
        if (max < input_array[i])
        {
            max = input_array[i];
        }
        
    }
    if (input_array == NULL)
    {
        return -1;
    }
    else
    {
        return max;
    } 
   
    
}

//task_8
unsigned long special_counter(const int input_array[], const int array_size) {
    int divny_sucet = 0;
    for (int i = 0; i < array_size; i++)
    {
        if ((i % 2) == 0)
        {
            divny_sucet += input_array[i];
        }
        else{
            divny_sucet += (input_array[i] * input_array[i]);
        }
        
    }
    return divny_sucet;
    
}

//task_9
int special_numbers(const int input_array[], const int array_size, int result_array[]){
    int x = 0;
    for (int i = 0; i < array_size; i++)
    {
        int actual_number = input_array[i];
        int sucet_vpravo = 0;
        for (int j = i + 1; j < array_size; j++)
        {
           sucet_vpravo += input_array[j]; 
        }
        if (actual_number > sucet_vpravo)
        {
            
            result_array[x] = actual_number;
            x++;
        }
        //printf("%d ", actual_number);
        //printf("%d \n", sucet_vpravo);
    }
    /*for(int i = 0; i < x; i++){
    printf("%d ", result_array[i]);
    }*/
    //printf("%d", x);
   return x;
}

int main() {
    return 0;
}