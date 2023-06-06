#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <iostream>
#include <string.h>
#include "ATarget.hpp"

class ATarget;

class ASpell {

	protected:
		std::string		name;
		std::string		effects;

	public:
		ASpell();
		ASpell(std::string const _name, std::string const _effects);
		ASpell(const ASpell &obj);
		virtual ~ASpell();

		ASpell	&operator=(const ASpell &obj);

		std::string		getName() const;
		std::string		getEffects() const;

		virtual ASpell*	clone() = 0;

		void	launch(const ATarget &obj) const;		


};

#endif