Lab 5 Readme

Jinfeng Chen (c.jinfeng@wustl.edu) , Daniel Ryu, Matthew Kim

1. Jinfeng Chen, Daniel Ryu
2. Jinfeng Chen
3. Jinfeng Cheng
4. Daniel Ryu, Jinfeng Chen
5. Matthew Kim, Daniel Ryu, Jinfeng Chen
6. Daniel Ryu, Jinfeng Chen
7. Daniel Ryu
8. Daniel Ryu
9. Daniel Ryu
10. Jinfeng Chen, Daniel Ryu




Notes:

For part 9, we implemented touch+cat. To invoke this command, you can either input toc <filename> or toc <filename> -p. With the -p, 
	the user can create password protected file.

DisplayInfo() method for MacroCommand will print usage message all MacroCommands, independent of which MacroCommand is called

For all cat operations on password-protected files, the password prompt will occur only after the user tried to save the file.



TEST for cat:

	Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
	 $ cat img.img

	Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
	X XX2
	:wq

	Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
	 $ ds img.img
	X
	XX

TEST #1:
toc text.txt

	Enter data you would like to write to the file. Enter :wq to sace the file and
	exit, enter :q to exist without saving and without saving and without -a, 
	we don't append but overwrite the old contents

	hello
	:wq

TEST #2:
	toc text2.txt -p

	What is the password?
	hhh
	Please enter password to write to this file
	Input Password:
	hhh


	Enter data you would like to write to the file. Enter :wq to sace the file and
	exit, enter :q to exist without saving and without saving and without -a, 
	we don't append but overwrite the old contents
	heee
	:wq


BUGS TO KILL:
	

	ds <filename> -d for textFile: the SAME?

	Check memory leaks : close files after each open operation

	Test each command and record tests in Readme

	Extra credit chmod

Errors and Bugs:

	Logical Mistakes:	
		Using cin >> insteand of getline(), so there is an unnecesary printout following password prompt with touch <file_name> -p
		Command

		Memory access violation---caused by different lifetime of PasswordProxy object and ImageFile objects. Solved by dynamically		
		allocating PasswordProxy objects.

		toc file.txt -o ----leads to vector subscript out of range EXCEPTION
			Solved by including lines of code to handle this edge case

