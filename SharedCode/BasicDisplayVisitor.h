#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFileVisitor.h"
class ImageFile;
class TextFile;

class BasicDisplayVisitor: public AbstractFileVisitor {

public :

	virtual void visit_TextFile(TextFile* filePtr) override;
	virtual void visit_ImageFile(ImageFile* filePtr) override;

};