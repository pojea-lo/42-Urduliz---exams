#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include <string.h>
#include "ASpell.hpp"

class	ASpell;

class ATarget {

	private:
		std::string		type;

	public:
		ATarget();
		ATarget(std::string const _type);
		ATarget(const ATarget &obj);
		virtual ~ATarget();
		ATarget	&operator=(const ATarget &obj);

		std::string const& getType() const;

		virtual ATarget* clone() = 0;

		void	getHitBySpell(const ASpell &obj) const;
};

#endif