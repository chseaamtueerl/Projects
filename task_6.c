#include <superkarel.h>
#define SPEED 40
void go_to_said_direction();
void turn_six_thirty();

void game_scene(){
    //game cycle start
    while(no_beepers_present()){
        //go until beepers will be here
        step();
        turn_six_thirty();

        //turn based on number of beepers
        if(beepers_present()){
            go_to_said_direction();

            // if 5 beepers here end game
            if(beepers_present()){
                pick_beeper();
                break;
            }
        }
    }
}

int main (){
    turn_on("task_6.kw");
    set_step_delay(SPEED);

    //game process
    game_scene();

    turn_off();
    return 0;
}

void go_to_said_direction(){    
    if(beepers_present()){
        pick_beeper();
        turn_six_thirty();
        while(not_facing_north()){
            turn_left();
        }
    }
    if(beepers_present()){
        pick_beeper();
        turn_six_thirty();
        while(not_facing_west()){
            turn_left();
        }
    }
    if(beepers_present()){
        pick_beeper();
        turn_six_thirty();
        while(not_facing_south()){
            turn_left();
        }
    }
    if(beepers_present() && 1){
        pick_beeper();
        turn_six_thirty();
        while(not_facing_east()){
            turn_left();
        }
    }
}

void turn_six_thirty(){
    set_step_delay(0);
    turn_left();
    turn_left();
    turn_left();
    turn_left();
    set_step_delay(SPEED);   
}
