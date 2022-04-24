Studio 21 ReadMe.txt 

Jinfeng Chen, Daniel Ryu

2. We declare a virutal destructor in the base class so that all calls to delete a pointer to base class objects will
	be directed to call delete on the derived class too, so the actual underlying reousrce will be deleted.

3.