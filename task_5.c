#include <superkarel.h>
#define SPEED 40

void turn();
void turn_six_thirty();


void find_start_position(){
    while (not_facing_south()){
        turn_left();
        turn_six_thirty();
    }
    while(front_is_clear()){
        step();
    }
    turn_left();
    while(front_is_clear()){
        step();
    }
    turn_left();
    turn_six_thirty();
}

void fill_bottoms(){
    while(no_beepers_present()){
        put_beeper();
        if (front_is_blocked()){
            turn_left();
            step();
        }
        else{
            step();
            turn_six_thirty();
        }
    }
}

void recursion_m(){
    if (front_is_blocked()){
        turn();
        turn_six_thirty();
        return;
    }
    step();
    step();
    recursion_m();
    step();
}

void go_mid(){
    while(not_facing_west()){
        turn_left();
    }
    recursion_m();
    turn_six_thirty();
    while(not_facing_north()){
        turn_left();
    }
    recursion_m();
    turn_six_thirty();
}

void rotate(){
    while(not_facing_north()){
        turn_left();
        turn_six_thirty();
    }
}

int main (){
    turn_on("task_5.kw");
    set_step_delay(SPEED);

    //go to the right down bottom of the map
    find_start_position();
    turn_six_thirty();

    //fill bottoms sides
    fill_bottoms();
    
    //find mid with recursion call
    go_mid();

    //turn to end position
    rotate();

    turn_off();
    return 0;
}

void turn(){
    turn_left();
    turn_left();
}

void turn_six_thirty(){
    set_step_delay(0);
    turn_left();
    turn_left();
    turn_left();
    turn_left();
    set_step_delay(SPEED);   
}
