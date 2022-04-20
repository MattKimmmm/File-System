studio 19 answers here

Daneial Ryu, Jinfeng Chen

2. We ran two tests. We created a TextFile object and ImageFile object. Then, we called read() on both objects and wrote a vector
	of char stored on the main data frame to it. After compilation, through print statements, we confirmed the files have been 
	successfully edited using updated read() and write() methods.

3. At first, the accept method is called on a pointer to AbstractFile type. Then, the dynamical binding happens, and the corresponding 
	accept method is called. At the concrete file type class, visit_<file_type> method is called on the AbstractFileVisitor, passing 
	along the pointer to that specific file class back to AbstractFileVisitor. This allows the visitor object to change the state of
	the concrete file object. The second dynamic binding happens at the accept method at the concrete file class.