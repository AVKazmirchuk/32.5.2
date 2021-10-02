#include <iostream>
#include <fstream>
#include <iomanip>

#include "nlohmann/json.hpp"

int main() {
    nlohmann::json j = {
            {"Moonshiners", {
                {"country", "USSR"},
                {"date", "1962"},
                {"studio", "Mosfilm"},
                {"scriptwriter", "Konstantin Brovin, Leonid Gaidai"},
                {"director", "Leonid Gaidai"},
                {"producer", "Peter Feller"},
                {"actorAndRole", {{"Evgeny Morgunov", "Experienced"},
                                  {"George Vitsin", "Coward"},
                                  {"Yuri Nikulin", "Idiot"}}}
            }},
            {"A friend among strangers, a stranger among his own", {
                {"country", "USSR"},
                {"date", "1974"},
                {"studio", "Mosfilm"},
                {"scriptwriter", "Nikita Mikhalkov, Eduard Volodarsky"},
                {"director", "Nikita Mikhalkov"},
                {"producer", "Vladimir Komarovsky"},
                {"actorAndRole", {{"Yuri Bogatyrev",  "Egor Petrovich Shilov, security officer"},
                                  {"Alexander Kaidanovsky", "Lemke, raider, former captain of the Kappel Division"},
                                  {"Nikita Mikhalkov", "Alexander Brylov, ataman, former esaul"}}}
            }},
            {"Ivan Vasilyevich is changing his profession", {
                {"country", "USSR"},
                {"date", "1973"},
                {"studio", "Mosfilm"},
                {"scriptwriter", "Vladlen Bakhnov, Leonid Gaidai"},
                {"director", "Leonid Gaidai"},
                {"producer", "Arkady Ashkinazi"},
                {"actorAndRole", {{"Yuri Yakovlev", "manager Ivan Vasilyevich Bunsha / Tsar Ivan Vasilyevich the Terrible"},
                                  {"Leonid Kuravlev", "Georges Miloslavsky, a recidivist apartment thief"},
                                  {"Alexander Demyanenko", "engineer-inventor Shurik (Alexander Sergeevich Timofeev)"}}}
            }},
            {"Moscow does not believe in tears", {
                {"country", "USSR"},
                {"date", "1979"},
                {"studio", "Mosfilm"},
                {"scriptwriter", "Valentin Chernykh"},
                {"director", "Vladimir Menshov"},
                {"producer", "Vitaly Boguslavsky"},
                {"actorAndRole", {{"Vera Alentova", "Katerina Aleksandrovna Tikhomirova, fitter, later - director of the chemical plant"},
                                  {"Alexey Batalov", "Georgy Ivanovich (aka Gosha, aka Goga, aka Zhora, aka Mountain, aka Yuri)"},
                                  {"Irina Muravyeva", "Lyudmila Sviridova, bakery worker, later - dry cleaning worker"}}}
            }},
            {"Diamond Hand", {
                {"country", "USSR"},
                {"date", "1969"},
                {"studio", "Mosfilm"},
                {"scriptwriter", "Leonid Gaidai, Yakov Kostyukovsky, Maurice Slobodskoy"},
                {"director", "Leonid Gaidai"},
                {"producer", "Arkady Ashkinazi"},
                {"actorAndRole", {{"Yuri Nikulin", "Semyon Semyonovich Gorbunkov"},
                                  {"Anatoly Papanov", "Lelik (Mechanic)"},
                                  {"Andrey Mironov", "Gennady Petrovich Kozodoev (Gesha, Count)"}}}
            }}};

    std::ofstream out("film.json");
    out << std::setw(4) << j;
    out.close();

    j.clear();

    std::ifstream in("film.json");

    if (!in.is_open()) std::cout << "File not found!";
    else
    {
        in >> j;
        in.close();

        std::cout << j.dump(4);

        while (true)
        {
            std::cout << "\n\nFirst or last name of the actor: ";
            std::string name;
            std::cin >> name;

            std::string Name {name};
            Name[0] = std::toupper(Name[0]);

            for (const auto &i : j.get<std::map<std::string, nlohmann::json>>())
                for (const auto &k : i.second["actorAndRole"].get<std::map<std::string, std::string>>())
                    if (k.first.find(name) != std::string::npos || k.first.find(Name) != std::string::npos)
                        std::cout << "\n\nFilm: " << i.first << "\nRole: " << k.second;
        }
    }
}
