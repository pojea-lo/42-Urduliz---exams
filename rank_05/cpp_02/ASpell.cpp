#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) {

    _name = name;
    _effects = effects;
}

ASpell::~ASpell() {

}

ASpell & ASpell::operator=(ASpell const& obj) {

    _name = obj._name;
    _effects = obj._effects;
    return *this;
}

ASpell::ASpell(ASpell const& obj) {

    *this = obj;
}

std::string ASpell::getName() const {

    return _name;
}

std::string ASpell::getEffects() const {

    return _effects;
}

void ASpell::launch(ATarget const& obj) const {

    obj.getHitBySpell(*this);
}