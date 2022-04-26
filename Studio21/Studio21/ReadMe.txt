Studio 21 ReadMe.txt 

Jinfeng Chen, Daniel Ryu

2. We declare a virutal destructor in the base class so that all calls to delete a pointer to base class objects will
	be directed to call delete on the derived class too, so the actual underlying reousrce will be deleted.

3. By using interfaces like AbstactFileFactory and AbstractFileSystem, CommandPrompt is very flexible in adapting to
	changes in the real implementations to the file factory and file system because CommandPrompt does not depend on
	the actual implementations. Dependency interjection helps programmers to code in a way that makes codes extensible and adaptable.

4. Typed in "q", the program quits as expected. Asked for help on touch, returned help message (displayInfo) as expected. ( "help touch")