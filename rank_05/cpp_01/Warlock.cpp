#include "Warlock.hpp"

//canonical functions
Warlock::Warlock() {

	std::cout << "Default Warlock constructor was called" << std::endl;

	return;
}

Warlock::Warlock (const std::string _name, const std::string _title) {

	this->name = _name;
	this->title = _title;
	std::cout << this->name << ": This looks like another boring day." << std::endl;

	return;
}

Warlock::Warlock (Warlock const &obj) {

	*this = obj;

	return;
}

Warlock::~Warlock() {

	std::cout << this->name << ": My job here is done!" << std::endl;

	return;
}

Warlock		&Warlock::operator=(Warlock const &obj) {

	this->name = obj.name;
	this->title = obj.title;

	return *this;
}

//getters & setters
std::string		const & Warlock::getName() const {

	return this->name;
}

std::string		const &Warlock::getTitle() const {

	return this->title;
}

void		Warlock::setTitle(std::string const &_title) {

	this->title = _title;

	return;
}

//methods
void		Warlock::introduce() const {

	std::cout << this->name << ": I am " << this->name << ", " << this->title << std::endl;

	return; 
}