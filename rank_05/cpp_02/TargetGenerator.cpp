#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {

}

TargetGenerator::~TargetGenerator() {

    for (std::map<std::string, ATarget*>::iterator it = _TargetBook.begin(); it != _TargetBook.end(); ++it) {
        delete it->second;
    }
    _TargetBook.clear();
}

TargetGenerator & TargetGenerator::operator=(TargetGenerator const& obj) {

    _TargetBook = obj._TargetBook;
    return *this;
}

TargetGenerator::TargetGenerator(TargetGenerator const& obj) {

    *this = obj;
}

void TargetGenerator::learnTargetType(ATarget* obj) {

    if (obj) {
        _TargetBook[obj->getType()] = obj->clone();
    }
}

void TargetGenerator::forgetTargetType(std::string const& str) {

    std::map<std::string, ATarget*>::iterator it = _TargetBook.find(str);
    if (it != _TargetBook.end()) {
        delete it->second;
        _TargetBook.erase(it);
    }
}

ATarget* TargetGenerator::createTarget(std::string const& str) {

    ATarget* tmp = NULL;
    if (_TargetBook.find(str) != _TargetBook.end()) {
        tmp = _TargetBook[str];
    }
    return tmp;
}