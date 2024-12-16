
#include <stdio.h>

typedef enum {
    STATE_IDLE,
    STATE_RUNNING,
    STATE_PAUSED,
    STATE_STOPPED
} State;

typedef struct {
    State current_state;
} StateMachine;

void initialize_state_machine(StateMachine* sm) {
    sm->current_state = STATE_IDLE;
}

void transition_to(StateMachine* sm, State new_state) {
    printf("Transitioning from %d to %d\n", sm->current_state, new_state);
    sm->current_state = new_state;
}

void handle_event(StateMachine* sm, int event) {
    switch (sm->current_state) {
        case STATE_IDLE:
            if (event == 1) {
                transition_to(sm, STATE_RUNNING);
            }
            break;
        case STATE_RUNNING:
            if (event == 2) {
                transition_to(sm, STATE_PAUSED);
            } else if (event == 3) {
                transition_to(sm, STATE_STOPPED);
            }
            break;
        case STATE_PAUSED:
            if (event == 1) {
                transition_to(sm, STATE_RUNNING);
            } else if (event == 3) {
                transition_to(sm, STATE_STOPPED);
            }
            break;
        case STATE_STOPPED:
            if (event == 1) {
                transition_to(sm, STATE_IDLE);
            }
            break;
    }
}

int main() {
    StateMachine sm;
    initialize_state_machine(&sm);

    handle_event(&sm, 1);  // IDLE -> RUNNING
    handle_event(&sm, 2);  // RUNNING -> PAUSED
    handle_event(&sm, 1);  // PAUSED -> RUNNING
    handle_event(&sm, 3);  // RUNNING -> STOPPED
    handle_event(&sm, 1);  // STOPPED -> IDLE

    return 0;
}
