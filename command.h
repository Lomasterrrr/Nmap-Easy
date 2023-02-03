#pragma once
#include <iostream>

class command
{
public:
    std::string sudo = "sudo ";
    std::string run = "nmap ";
    std::string scan;
    std::string arg;
    std::string target;
    std::string commandInit();
};
