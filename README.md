##This is the README.md for the last project (An agricultural irrigation system)
We added 8 files to our project.
4 header files: fsm.h, global.h, scheduler.h, software_timer.h
4 source files: fsm.c, global.c, scheduler.c, software_timer.c

#Uses of 4 header files:
fsm.h: interface for the state machine.
global.h: define the status for the state machine.
scheduler.h: interface for the scheduler.
software_timer.h: interface for the timer interrupt.

#Uses of 4 source files:
fsm.c: we implement to state machine with 7 states.
global.c: we define the status variable.
scheduler.c: we implement the cooperative scheduler with complexity is O(1).
software_timer.c: this is the same from the file the teacher give us.
