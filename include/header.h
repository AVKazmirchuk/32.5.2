#pragma once

#include <vector>



struct Moonshiners
{
    std::string country;
    std::string date;
    std::string studio;
    std::string scriptwriter;
    std::string director;
    std::string producer;
    std::vector<std::pair<std::string, std::string>> actorAndRole;
};