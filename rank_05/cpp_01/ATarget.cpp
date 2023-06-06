#include "ATarget.hpp"

//metodos canónicos
ATarget::ATarget() {}

ATarget::ATarget(std::string const _type) {

	this->type = _type;
}

ATarget::ATarget(const ATarget &obj) {

	*this = obj;
}

ATarget::~ATarget() {}

ATarget	&ATarget::operator=(const ATarget &obj) {

	this->type = obj.type;

	return *this;
}

//getters
std::string const& ATarget::getType() const {

	return this->type;
}

//metodos
void	ATarget::getHitBySpell(const ASpell &obj) const{

	std::cout << this->type << " has been " << obj.getEffects() << std::endl;
	return;
}
