#include "Section.h"


Section::Section() {
	sectionName = "";
	selectors = List<String>();
	declarations = List<Declaration>();
}


Section::Section(String sectionName) {
	this->sectionName = sectionName;
	selectors = List<String>();
	declarations = List<Declaration>();
}


void Section::print() {
	std::cerr << "Section: " << sectionName << std::endl;

	std::cerr << "Selectors:" << std::endl;
	for (int i = 0; i < selectors.getSize(); i++) {
		std::cerr << selectors[i] << std::endl;
	}

	std::cerr << "Declarations:" << std::endl;
	for (int i = 0; i < declarations.getSize(); i++) {
		std::cerr << declarations[i].getProperty() << ": " << declarations[i].getValue() << std::endl;
	}
}


void Section::setSelectors(List<String> selectors) {
	this->selectors = selectors;
}


void Section::setDeclarations(List<Declaration> declarations) {
	this->declarations = declarations;
}


String Section::getSectionName() {
	return sectionName;
}


List<String> Section::getSelectors() {
	return selectors;
}


List<Declaration> Section::getDeclarations() {
	return declarations;
}