#include "ASpell.hpp"

//metodos canonicos
ASpell::ASpell() {

	this->name = "";
	this->effects = "";

	return;
}

ASpell::ASpell(std::string const _name, std::string _effects) {

	this->name = _name;
	this->effects = _effects;

	return;
}

ASpell::ASpell(const ASpell &obj) {

	*this = obj;

	return;
}

ASpell::~ASpell() {

	return;
}

ASpell	&ASpell::operator=(const ASpell &obj) {

	this->name = obj.name;
	this->effects = obj.effects;

	return *this;
}

//getters & setters
std::string		ASpell::getName() const {

	return this->name;
}

std::string		ASpell::getEffects() const {

	return this->effects;
}

//metodos
void	ASpell::launch(const ATarget &obj) const {

	obj.getHitBySpell(*this);
	return;
}