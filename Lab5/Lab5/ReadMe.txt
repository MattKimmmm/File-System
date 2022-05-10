Lab 5 Readme

Jinfeng Chen (c.jinfeng@wustl.edu) , Daniel Ryu, Matthew Kim

1. Jinfeng Chen, Daniel Ryu
2. Jinfeng Chen
3. Jinfeng Cheng
4. Daniel Ryu, Jinfeng Chen
5. Mugyeom Kim, Daniel Ryu, Jinfeng Chen
6. Daniel Ryu, Jinfeng Chen
7. Daniel Ryu
8. Daniel Ryu
9. Daniel Ryu
10. Jinfeng Chen, Daniel Ryu




10.
Implemented touch+cat. To invoke this command, you can either input toc <filename> or toc <filename> -p. With the -p, the user can create password protected 
file.

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
	Unable to get toc work with -p





Errors and Warnings:

	Logical Mistake:	
		Using cin >> insteand of getline(), so there is an unnecesary printout following password prompt with touch <file_name> -p
		Command

		Memory access violation---caused by different lifetime of PasswordProxy object and ImageFile objects. Solved by dynamically		
		allocating PasswordProxy objects.