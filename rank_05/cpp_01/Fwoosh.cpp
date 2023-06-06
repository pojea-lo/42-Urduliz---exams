#include "Fwoosh.hpp"

//metodos canonicos
Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh() {}

//metodos
ASpell*		Fwoosh::clone() {

	return (new Fwoosh());
}