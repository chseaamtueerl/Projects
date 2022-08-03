#include<superkarel.h>
#define SPEED 40

void back();
void turn_right();
void turn_six_thirty();


void go_forward(){
    while(front_is_clear() && no_beepers_present()){
        if (beepers_present()){
            break;
        }
        else{
            step();
            turn_six_thirty();
        }
    }
    if(front_is_blocked() && left_is_clear()){
            turn_left();
            turn_six_thirty();
    }
}

void go_rewerse(){
    while(front_is_clear()){
        step();
        turn_six_thirty();
    }
    if(front_is_blocked() && right_is_clear()){
        turn_right();
        turn_six_thirty();
    }

}

void find(){
    while(no_beepers_present()){
        while(front_is_clear() || left_is_clear()){
            if (beepers_present()){
                break;
            }
            go_forward();
        }
    }
    while (beepers_present()){
        pick_beeper();
    }
}

void find_spawn(){
    while(1){
        while(front_is_clear() || right_is_clear()){
            go_rewerse();
        }
        if(front_is_blocked() && right_is_blocked() && left_is_blocked()){
            break;
        }
    }
}

int main (){
    turn_on("task_2.kw");
    set_step_delay(SPEED);

    //find the beeper in our run
    find();

    //turn back
    back();
    turn_six_thirty();

    //go back to our spiral spawn
    find_spawn();
    
    turn_off();
    return 0;
}



void back(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(SPEED);
}

void turn_right(){
    set_step_delay(0);
    turn_left();
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
