#include "menu.h"
#include <iostream>
#include "command.h"

void menu::MainMenu()
{
    command c;

    while (true)
    {
        std::cout << "\e[8;15;100t";
        system("clear");
        HelpMenu();

        std::string what;
        std::cout << "  $ : ";
        std::cin >> what;

        // ScanCheck
        if (what == "1" || what == "-sT")
        {
            c.scan = "-sT ";
        }
        else if (what == "2" || what == "-sS")
        {
            c.scan = "-sS ";
        }
        else if (what == "3" || what == "-sP")
        {
            c.scan = "-sP ";
        }
        else if (what == "4" || what == "-sU")
        {
            c.scan = "-sU ";
        }

        // ArgCheck
        else if (what == "1a" || what == "1A" || what == "-sV")
        {
            c.arg += "-sV ";
        }
        else if (what == "2a" || what == "2A" || what == "-A")
        {
            c.arg += "-A ";
        }
        else if (what == "5a" || what == "5A" || what == "--open")
        {
            c.arg += "--open ";
        }
        else if (what == "6a" || what == "6A")
        {
            std::string whatP;
            std::cout << "  Format (txt,xml,all): ";
            std::cin >> whatP;
            if (whatP == "txt")
            {
                std::string FileName;
                std::cout << "  FileName: ";
                std::cin >> FileName;
                c.arg += "-oN " + FileName + "." + whatP + " ";
            }
            else if (whatP == "xml")
            {
                std::string FileName;
                std::cout << "  FileName: ";
                std::cin >> FileName;
                c.arg += "-oX " + FileName + "." + whatP + " ";
            }
            else if (whatP == "all")
            {
                std::string FileName;
                std::cout << "  FileName: ";
                std::cin >> FileName;
                c.arg += "-oA " + FileName + " ";
            }
        }
        else if (what == "7a" || what == "5A" || what == "--open")
        {
            std::string FileName;
            std::cout << "  FileName: ";
            std::cin >> FileName;
            c.arg += "-iL " + FileName + " ";
        }

        // ExampleCheck
        else if (what == "max" || what == "MAX")
        {
            c.scan = "";
            c.arg = "-n -T5 ";
        }
        else if (what == "info" || what == "INFO")
        {
            c.scan = "";
            c.arg = "-v -A -sV -p \"*\" ";
        }

        // CommandCheck
        else if (what == "run" || what == "RUN")
        {
            std::cout << "  \033[92mCreated by lomaster\033[0m";
            break;
        }
        else if (what == "clear" || what == "CLEAR")
        {
            c.scan = "";
            c.arg = "";
            c.target = "";
        }
        else if (what == "3a" || what == "3A" || what == "-p")
        {
            std::string whatP;
            std::cout << "  Ports: ";
            std::cin >> whatP;
            c.arg += "-p " + whatP + " ";
        }
        else if (what == "4a" || what == "4A" || what == "-T")
        {
            std::string whatP;
            std::cout << "  Count (1-5): ";
            std::cin >> whatP;
            c.arg += "-T" + whatP + " ";
        }
        else if (what == "sudo" || what == "SUDO")
        {
            c.run = c.sudo + c.run;
        }
        else
        {
            c.target = what;
        }

        std::cout << "\033[0;33m  Command:\033[92m " << c.commandInit();
    }
    std::cout << "\n";
    std::string result = c.commandInit();
    std::cout << "\e[8;40;100t";
    system(result.c_str());
    std::string resume;
    std::cout << "\n\033[0;33mEnter 1 to continue...\033[0m";
    std::cin >> resume;
    if (resume == "1"){
        MainMenu();
    }
}

void menu::HelpMenu()
{
    std::cout << "\n\n";
    std::cout << "  \033[0;33mScaning              Arguments                  Commands            Example\n ";
    std::cout << " \033[92m[1]\033[0m TCP scan: -sT    \033[92m[1a]\033[0m Software host: -sV    \033[92m[run]\033[0m StartScan     \033[92m[max]\033[0m MaxSpeed\n";
    std::cout << "  \033[92m[2]\033[0m SYN scan: -sS    \033[92m[2a]\033[0m Aggressive info: -A   \033[92m[sudo]\033[0m AdminScan    \033[92m[info]\033[0m MaxInfo\n";
    std::cout << "  \033[92m[3]\033[0m Ping scan: -sP   \033[92m[3a]\033[0m Insert ports: -p      \033[92m[clear]\033[0m Clear\n";
    std::cout << "  \033[92m[4]\033[0m UDP scan: -sU    \033[92m[4a]\033[0m Time sample: -T       \033[92m[ ]\033[0m SelectTarget\n";
    std::cout << "                       \033[92m[5a]\033[0m OnlyOpen: --open\n";
    std::cout << "                       \033[92m[6a]\033[0m FileSave: -oN,oX,oA\n";
    std::cout << "                       \033[92m[7a]\033[0m TargetsFromFile: -iL\n";
}


