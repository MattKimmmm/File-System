Studio 20 ReadMe.txt


2. When the file system deletes the file, the proxy object associated with the file must also be deleted. 
	Or else, it would result in a memory leak.

4. We dynamically allocated an AbstractFile of TextFile type and created a PasswordProxy object with a password. We called write on
	the PasswordProxy object, and it asked for the password as expected. When incorrect password is entered, the code keeps prompting 
	as expected. Write action is successful with correct password, as confirmed by a password-protected read action.