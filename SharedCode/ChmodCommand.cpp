
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "ChmodProxy.h"
#include "ChmodCommand.h"
#include <iostream>

using namespace std;

int ChmodCommand::execute(std::string input) {


};


void ChmodCommand::displayInfo() {
	cout << "chmod changes the file to and from read-only, chmod <file_name> - makes the file read-only, " <<
		" and chmod <file_name> + makes the file writable again" << endl;
};

ChmodCommand::ChmodCommand(AbstractFileSystem* sys):fileSys(sys) {
};