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
    for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it) {
        delete it->second;
    }
    _SpellBook.clear();
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

    if (obj) {
        if (_SpellBook.find(obj->getName()) == _SpellBook.end()) {
            _SpellBook[obj->getName()] = obj->clone();
        }
    }
}

void Warlock::forgetSpell(std::string str) {

    if (_SpellBook.find(str) != _SpellBook.end()) {
        delete _SpellBook[str];
        _SpellBook.erase(str);
    }
}

void Warlock::launchSpell(std::string str, ATarget const& obj) {

    if (_SpellBook.find(str) != _SpellBook.end()) {
        _SpellBook[str]->launch(obj);
    }
}