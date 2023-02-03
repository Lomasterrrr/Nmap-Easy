#include "command.h"

std::string command::commandInit()
{
    std::string command = run + scan + arg + target;
    return command;
}

