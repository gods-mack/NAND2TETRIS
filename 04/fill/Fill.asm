// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

/*
* Logic:

* i=Screen
* i = screen
* while(1) {
* 	if(kbd) {
* 		RAM[i] = -1; // full black
* 		if(i < kbd){
* 			i++;
* 		}
* 	}
* 	else {
* 		RAM[i] = 0; // full white
* 		if(i > Screen) {
* 			i--;
* 		}
* 	}
* }
*
*/





@SCREEN
D=A
@i
M=D

(LOOP)
@KBD
D=M
@BLACK
D;JGT
@WHITE
0;JMP


(BLACK)
	@i
	A=M
	M=-1

	@i
	D=M
	@KBD
	D=D-A
	@LOOP
	D=D+1;JEQ

	@i
	M=M+1

	@LOOP
	0;JMP

(WHITE)
	@i
	A=M
	M=0
	
	@i
	D=M
	@SCREEN
	D=D-A
	@LOOP
	D;JEQ

	@i
	M=M-1

	@LOOP
	0;JMP
