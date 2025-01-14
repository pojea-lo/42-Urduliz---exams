#pragma once

#include <iostream>
#include <map>

#include "ATarget.hpp"

class TargetGenerator {

    private:
        std::map<std::string, ATarget*> _TargetBook;
        TargetGenerator & operator=(TargetGenerator const& obj);
        TargetGenerator(TargetGenerator const& obj);

    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget*);
        void forgetTargetType(std::string const &);
        ATarget* createTarget(std::string const &);
};