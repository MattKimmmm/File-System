
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "ChmodProxy.h"
#include "ChmodCommand.h"

using namespace std;

int ChmodCommand::execute(std::string input) {


};


void ChmodCommand::displayInfo() {

};

ChmodCommand::ChmodCommand(AbstractFileSystem* sys):fileSys(sys) {
};