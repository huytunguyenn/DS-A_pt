#include "Node.h"

Node& Node::operator=(Node* a)
{
	
	this->data.LOAI = a->data.LOAI;
	this->data.MAso = a->data.MAso;
	this->data.setCAN(a->data.getCAN());
	this->data.setTINHtrang(a->data.getTINHtrang());
	return *this;
}