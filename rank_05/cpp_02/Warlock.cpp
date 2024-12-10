#include "Warlock.hpp"

Warlock::Warlock() {

}

Warlock::Warlock(std::string name, std::string title) {

    _name = name;
    _title = title;
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {

    std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock & Warlock::operator=(Warlock const& obj) {

    _name = obj._name;
    _title = obj._title;
    return *this;
}

Warlock::Warlock(Warlock const& obj) {

    *this = obj;
}

std::string const& Warlock::getName() const {

    return _name;
}

std::string const& Warlock::getTitle() const {

    return _title;
}

void Warlock::setTitle(std::string const& str) {

    _title = str;
}

void Warlock::introduce() const {

    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* obj) {

    _SpellBook.learnSpell(obj);
}

void Warlock::forgetSpell(std::string str) {

    _SpellBook.forgetSpell(str);
}

void Warlock::launchSpell(std::string str, ATarget const& obj) {

    _SpellBook.createSpell(str)->launch(obj);
}