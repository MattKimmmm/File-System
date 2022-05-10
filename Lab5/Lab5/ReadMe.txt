Lab 5 Readme

Jinfeng Chen (c.jinfeng@wustl.edu) , Daniel Ryu, Matthew Kim

1. Jinfeng Chen, Daniel Ryu
2-3. Jinfeng Chen


Errors and Warnings:

	Logical Mistake:	
		Using cin >> insteand of getline(), so there is an unnecesary printout following password prompt with touch <file_name> -p
		Command

		Memory access violation---caused by different lifetime of PasswordProxy object and ImageFile objects. Solved by dynamically		
		allocating PasswordProxy objects.