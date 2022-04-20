#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFileVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"

class BasicDisplayVisitor: public AbstractFileVisitor {

public :

	virtual void visit_TextFile(TextFile* filePtr) override;
	virtual void visit_ImageFile(ImageFile* filePtr) override;

};