#pragma once

#include <iostream>

class Warlock {

    private:
        std::string _name;
        std::string _title;
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
};