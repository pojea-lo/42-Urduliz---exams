#include "SpellBook.hpp"

SpellBook::SpellBook() {

}

SpellBook::~SpellBook() {

    for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it) {
        delete it->second;
    }
    _SpellBook.clear();

}

SpellBook & SpellBook::operator=(SpellBook const& obj) {

    _SpellBook = obj._SpellBook;
    return *this;
}

SpellBook::SpellBook(SpellBook const& obj) {

    *this = obj;
}

void SpellBook::learnSpell(ASpell* obj) {

    if (obj) {
        _SpellBook[obj->getName()] = obj->clone();
    }
}

void SpellBook::forgetSpell(std::string const& str) {

    std::map<std::string, ASpell*>::iterator it = _SpellBook.find(str);
    if (it != _SpellBook.end()) {
        delete it->second;
        _SpellBook.erase(it);
    }
}

ASpell* SpellBook::createSpell(std::string const& str) {

    ASpell* tmp = NULL;
    if (_SpellBook.find(str) != _SpellBook.end()) {
        tmp = _SpellBook[str];
    }
    return tmp;
}