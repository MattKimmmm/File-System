#pragma once
// declaration of MetadataDisplayVisitor here
#include "AbstractFileVisitor.h"

#include <iostream>

class TextFile;
class ImageFile;

class MetadataDisplayVisitor :public AbstractFileVisitor {

public:

	virtual void visit_TextFile(TextFile* filePtr) override;
	virtual void visit_ImageFile(ImageFile* filePtr) override;


};