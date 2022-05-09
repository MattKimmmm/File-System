// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"
#include <iomanip>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* filePtr) {
	cout << setw(20) << filePtr->getName();
	cout << setw(10) << "text ";
	cout << filePtr->getSize() << endl;
	
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* filePtr) {
	cout << setw(20) << filePtr->getName() ;
	cout << setw(10) <<  "image " ;
	cout << filePtr->getSize() << endl;
	
}