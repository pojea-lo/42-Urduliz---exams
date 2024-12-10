#include "ATarget.hpp"

ATarget::ATarget(std::string type) {

    _type = type;
}

ATarget::~ATarget() {

}

ATarget & ATarget::operator=(ATarget const& obj) {

    _type = obj._type;
    return *this;
}

ATarget::ATarget(ATarget const& obj) {

    *this = obj;
}

std::string const& ATarget::getType() const {

    return _type;
}

void ATarget::getHitBySpell(ASpell const& obj) const {

    std::cout << _type << " has been " << obj.getEffects() << "!" << std::endl;
}