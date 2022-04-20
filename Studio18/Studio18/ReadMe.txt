studio 18 answers here

2. The method that we need to change in order to create a new concrete file type is createFile() in SimpleFileSystem. Our group concluded that it would not be difficult to implement creating a new file type assuming the concrete classes are defined already. 
However, it would be hard to create a new concrete file type since we would need to define all the interfaces and methods that access and control the new filetype.

3. Advantage: Allows us to take away responsibility of creating file from the simple file system class. One class could have one purpose. 
Disadvantage: More difficult to understand relationship between classes.
We concluded that new concrete file factory class must be created when we want to interact differently with the file. 
The concrete file factory would be modified if new file type is introduced. Same factory can be used to create files for both files of the same type. If the 
file types are different, same concrete factory implementation cannot be used.