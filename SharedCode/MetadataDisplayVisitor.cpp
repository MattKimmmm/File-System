// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* filePtr) {
	cout << filePtr->getName() << endl;
	cout << filePtr->getSize() << endl;
	cout << "text" << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* filePtr) {
	cout << filePtr->getName() << endl;
	cout << filePtr->getSize() << endl;
	cout << "image" << endl;
}