// definitions of basic display visitor here

#include "BasicDisplayVisitor.h"
#include <iostream>
#include <math.h>

using namespace std;

void BasicDisplayVisitor::visit_ImageFile(ImageFile* filePtr) {

	int board_size = sqrt(filePtr->getSize());

	for (int i = 0; i < board_size; ++i) {

		for (int j = 0; j < board_size; j++) {

			int index = j * board_size + i;
			cout << filePtr->read()[index];
		}
		cout << endl;
	}
}

void BasicDisplayVisitor::visit_TextFile(TextFile* filePtr) {
	for (auto i : filePtr->read()) {
		std::cout << i;
	}
	std::cout << std::endl;

}

