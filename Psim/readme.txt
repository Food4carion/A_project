*************************************************
*						*
*	PROJECTILE SIMULATOR V1.0		*
*	by Food4carion				*
*						*
*************************************************

INSTRUCTIONS:
- Make sure the gfx library is installed within the same directory as "main.c"
- Simply compile using gcc via the terminal and run.
To compile:
- Open Terminal and open the directory that contains the main file and gfx

- type to compile:
	gcc main.c gfx.c -o "NAME".o -lX11 -lm

-There shouldnt be any error and there should be "NAME".o within the directory, if not try again.

-To run:
	./"NAME.o

Description:
Simulates a projectile that neglects air resistance.

-Uses Constant acceleration kinematics equations
-Initial velocity calculated based on string displacement
-Velocity of x-y component calculated using trigonometry func


Note:
Projectile will only travel towards the right side of the screen(fix in-progress).

Requirements:
gfx library for c (included within repository).
gcc compiler if you wanna edit


Coming updates:
Targets that will has a score if hit by projectile
(-ve)velocity thus projectile may displace towards the left
Scoring system


Any feedback regarding the simulator Im all ears :D
