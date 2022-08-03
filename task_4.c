#include <superkarel.h>
#define SPEED 40

void turn();
void turn_six_thirty();
void column_repairs();
bool find_true_column();

void run_map(){
    while(front_is_clear() && right_is_blocked()){
        if (find_true_column()){
            column_repairs();
            
            if(front_is_clear()){
                step();
                turn_six_thirty();
            }
        }
        else{
            step();
            turn_six_thirty();
        }
    }
}

void column_repairs(){
    turn_left();
    turn_six_thirty();
    while(front_is_clear()){
        if(no_beepers_present()){
            put_beeper();
        }
        else{
            step();
            turn_six_thirty();
        }
    }
    if (no_beepers_present()){
        put_beeper();
    }
    turn();
    turn_six_thirty();
    while(front_is_clear()){
        step();
        turn_six_thirty();
    }
    turn_left();
}

bool find_true_column(){
    turn_left();
    while (front_is_clear()){
        step();
        if (beepers_present()){
            turn();
            while (front_is_clear()){
                step();
            }
            turn_left();
            
            return true;
        }
    }
    turn();
    while(front_is_clear()){
        step();
        turn_six_thirty();
    }
    turn_left();
    return false;
}

int main(){
    turn_on("task_4.kw");
    set_step_delay(SPEED);

    //repairing columns
    run_map();

    //last repair possible
    if (find_true_column()){
        column_repairs();
    }
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
