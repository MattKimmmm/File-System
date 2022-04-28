// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* filePtr) {
	cout << filePtr->getName();
	cout << "text";
	cout << filePtr->getSize() << endl;
	
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* filePtr) {
	cout << filePtr->getName() ;
	cout << "image" ;
	cout << filePtr->getSize() << endl;
	
}