#include <superkarel.h>
#define SPEED 40
void turn_right();
void turn();
void turn_six_thirty();

void back_check(){
    if(beepers_present()){
        if(facing_south()){
            pick_beeper();
            turn();
            step();
            put_beeper();
            turn();
            step();
            turn_left();
            return;
        }
        else{
            pick_beeper();
            while(not_facing_east()){
                turn_left();
            }
            return;
        }
    }
}

void checking_street_openness(){
    turn_left();
    step();
    while(no_beepers_present()){
	    if(left_is_clear()){
            turn_left();
            step();
            turn_six_thirty();
        }
        else if(left_is_blocked()&& front_is_clear()){
            step();
            turn_six_thirty();
        }
        else{
            turn_right();
            turn_six_thirty();
        }
    }
    back_check();
}

void go_to_the_end(){
    while(not_facing_east()){
        turn_left();
    }
    while(front_is_clear()){
        step();
    }
}

int main (){
    turn_on("task_7.kw");
    set_step_delay(SPEED);

    //find every entry in the maze
    while(right_is_blocked()){
        //if entry here
        if(right_is_blocked() && left_is_clear()){
            put_beeper();
            checking_street_openness();
        }

        //we are in the end of width 
        if(front_is_blocked()){
           break;
        }
        step();
        turn_six_thirty();
    }
    
    //turn for puting and picking beepers
    turn();
    
    //in right aisle picking-puting beepers
    while(left_is_blocked()){
        if(right_is_clear()){
            turn_right();
            step();

            //collecting and picking based on beepers
            //if present pick, if no beeper put
            if(beepers_present()){
                pick_beeper();
                turn();
                step();
                turn_right();
                turn_six_thirty();
            }
            else{
                put_beeper();
                turn();
                step();
                turn_right();
                turn_six_thirty();
            }
        }

        //end x,y map
        if(front_is_blocked()){
            break;
        }
        
        step();
        turn_six_thirty();
    }

    //find end position
    go_to_the_end();

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

void turn(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(SPEED);
}

void turn_six_thirty(){
    set_step_delay(0);
    turn_left();
    turn_left();
    turn_left();
    turn_left();
    set_step_delay(SPEED);   
}
