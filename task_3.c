#include <superkarel.h>
#define SPEED 40
void turn_right();
void turn_back();
void turn_six_thirty();


void first_row(){
    turn_six_thirty();
    while (front_is_clear()){
        step();
        turn_six_thirty();
        if(beepers_present()){
            pick_beeper();
        }
    }
    turn_back();
    while(front_is_clear()){
        if (beepers_in_bag() && right_is_blocked()){
            put_beeper();
        }
        step();
        turn_six_thirty();
    }
    turn_back();
}

bool control_right_beep(){
    set_step_delay(0);
    turn_right();
    step();
    turn_six_thirty();
    if(beepers_present()){
        turn_back();
        step();
        turn_right();
        set_step_delay(SPEED);
        return true;
    }
    else{
        turn_back();
        step();
        turn_right();
        set_step_delay(SPEED);
        return false;
    }
}

void clear_our_bag(){
    while(front_is_clear()){
        if(beepers_in_bag()&& control_right_beep()){
            put_beeper();
        }
        step();
        turn_six_thirty();
    }
}

void collect_whole_row(){
    while(front_is_clear()){
        if(beepers_present()){
            pick_beeper();
        }
        turn_six_thirty();
        step();
    }
    if(beepers_present()){
        pick_beeper();
        turn_six_thirty();
    }
}

void whole_sorting(){
    	while(right_is_clear() && front_is_clear()){
        //control beeper in right position
        turn_right();
        if(front_is_clear()){
            step();
        }
        turn_left();

        collect_whole_row();
        turn_back();
        clear_our_bag();
        turn_back();
        
    }
}

void find_end_position_for_karel(){
    step();
    turn_left();
    while(front_is_clear()){
        step();
        //.
        if(front_is_clear()){
            step();
            turn_six_thirty();
        }
    }
    turn_left();
    while(front_is_clear()){
        step();
        //.
        if(front_is_clear()){
            step();
            turn_six_thirty();
        }
    }
    turn_back();
}




int main (){
	turn_on("task_3.kw");
    set_step_delay(SPEED);
    //first run
    first_row();

    //sorting beepers
    whole_sorting();

    //find end position
    find_end_position_for_karel();

	turn_off();
    return 0;
}

void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    turn_left();
    set_step_delay(SPEED);
}

void turn_back(){
    set_step_delay(0);
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
