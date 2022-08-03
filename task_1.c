#include <superkarel.h>
#define SPEED 40
void go_forward();
void go_rewerse();
void turn_right();
void turn();
void turn_six_thirty();



void start_1(){
    if (beepers_in_bag()){
        put_beeper();
    }
    turn_six_thirty();
}

void start_2(){
    if (front_is_clear() && right_is_blocked()){
        step();
    }
    //else if(front_is_clear()){
    //    step();
    //}
    else{
        turn_left();
        step();
    }
}

void go_on(){
    while(no_beepers_present()){
        while (front_is_clear() && right_is_blocked()){
            if (beepers_present()){
                break;
            }
            step();
            turn_six_thirty();
        }
        if (beepers_present()){
            break;
        }
        turn_six_thirty();
        go_forward();
    }
}

void go_back_olimpic(){
    while (no_beepers_present()){
        while(front_is_clear() && left_is_blocked()){
            if (beepers_present()){
                break;
            }
            turn_six_thirty();
            step();
        }
        go_rewerse();
    }
    while(beepers_present()){
        pick_beeper();
    }
    while(not_facing_west()){
        turn_left();
    }
}

int main (){
    turn_on("task_1.kw");
    set_step_delay(SPEED);
    //starting function
    start_1();
    start_2();

    //go forward
    go_on();
    
    //picking  beepers and turning
    pick_beeper();
    turn();
    turn_six_thirty();

    //go back to start
    go_back_olimpic();


    turn_off();
    return 0;
}

void go_forward(){
    if (right_is_clear()){
        turn_right();
        step();
    }
    else if (front_is_blocked() && left_is_clear()){
        turn_left();
        step();
    }
    else {
        turn();
    }
}

void go_rewerse(){
    if(beepers_present()){
        return;
    }
    else if(left_is_clear()){
        turn_left();
        step();
        turn_six_thirty();
    }
    else if(front_is_blocked() && right_is_clear()){
        turn_right();
        step();
        turn_six_thirty();
    }
    else {
        turn();
    }
}

void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    turn_left();
    set_step_delay(SPEED);
}

void turn(){
    set_step_delay(0);
    turn_left();
    turn_right();
    turn_left();
    turn_right();
    turn_left();
    turn_left();
    set_step_delay(SPEED);
}

void turn_six_thirty(){
    set_step_delay(0);
    turn_right();
    turn_right();
    turn_right();
    turn_right();
    set_step_delay(SPEED);   
}
