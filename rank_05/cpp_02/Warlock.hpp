#pragma once

#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock {

    private:
        std::string _name;
        std::string _title;
        SpellBook   _SpellBook;
        Warlock();
        Warlock & operator=(Warlock const& obj);
        Warlock(Warlock const& obj);

    public:
        Warlock(std::string name, std::string title);
        ~Warlock();
        std::string const& getName() const;
        std::string const& getTitle() const;
        void setTitle(std::string const& str);
        void introduce() const;
        void learnSpell(ASpell* obj);
        void forgetSpell(std::string str);
        void launchSpell(std::string str, ATarget const& obj);
};