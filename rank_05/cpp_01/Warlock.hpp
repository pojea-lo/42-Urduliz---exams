#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string.h>

class Warlock {

	private:
		std::string     name;
		std::string		title;
		Warlock ();
		Warlock (Warlock const &obj);
		Warlock		&operator=(Warlock const &obj);

	public:
		Warlock (const std::string _name, const std::string _title);
		~Warlock();

		std::string	const & getName() const;
		std::string	const & getTitle() const;

		void	setTitle(std::string const &_title);

		void	introduce() const;

};

#endif