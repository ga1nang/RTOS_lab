## This is the README.md for the last project (An agricultural irrigation system)

We added 8 files to our project:
- 4 header files: `fsm.h`, `global.h`, `scheduler.h`, `software_timer.h`
- 4 source files: `fsm.c`, `global.c`, `scheduler.c`, `software_timer.c`

### Uses of 4 header files:
- `fsm.h`: Interface for the state machine.
- `global.h`: Defines the status for the state machine.
- `scheduler.h`: Interface for the scheduler.
- `software_timer.h`: Interface for the timer interrupt.

### Uses of 4 source files:
- `fsm.c`: Implementation of the state machine with 7 states.
- `global.c`: Definition of the status variable.
- `scheduler.c`: Implementation of the cooperative scheduler with complexity O(1).
- `software_timer.c`: Same as the file provided by the teacher.
