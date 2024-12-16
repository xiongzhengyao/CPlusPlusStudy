////////////////////////////////////////////////////////////////////////////////
// 4) State Machine (20 points)
//
//    Complete the function below to implement the state machine shown in the
//    diagram below for an electronic gumball vending machine.
//     * The initial state of the state machine should be IDLE
//     * The state machine should maintain and manage its state
//     * The function should return the current state of the state machine
//     * Unexpected or invalid input should not cause a state transition
//     * GENERIC_FAULT may be received in any state and should put the machine
//       into the FAULT state
//
//
//          COIN      +---------+
//   +--------------->|         |   BUTTON
//   |                |  READY  | ---------+       
//   |    COIN_RETURN |         |          |
//   |   +----------- +---------+          |
//   |   |                                 |
//   |   V                                 V
// +---------+                        +---------+
// |         |     VEND_COMPLETE      |         |
// |  IDLE   |<-----------------------| VENDING |
// |         |                        |         |
// +---------+                        +---------+
//
//                                 +---------+
//                                 |         |
//                GENERIC_FAULT    |  FAULT  |
//             +------------------>|         |
//                                 +---------+
//
 
typedef enum
{
    IDLE,
    READY,
    VENDING,
    FAULT
} state_E;
 
typedef enum
{
    COIN,
    COIN_RETURN,
    BUTTON,
    VEND_COMPLETE,
    GENERIC_FAULT
} input_E;
 
static state_E current_state = IDLE;

state_E updateStateMachine(input_E input)
{
    switch (current_state)
    {
        case IDLE:
            if (input == COIN)
            {
                current_state = READY;
            }
            break;
        
        case READY:
            if (input == COIN_RETURN)
            {
                current_state = IDLE;
            }
            else if (input == BUTTON)
            {
                current_state = VENDING;
            }
            break;
        
        case VENDING:
            if (input == VEND_COMPLETE)
            {
                current_state = IDLE;
            }
            break;
        
        case FAULT:
            // No transitions from FAULT state
            break;
    }

    // Handle GENERIC_FAULT in any state
    if (input == GENERIC_FAULT)
    {
        current_state = FAULT;
    }

    return current_state;
}