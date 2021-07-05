#include <iostream>
#include <map>

std::string getInput()
{
    std::cout << "Please enter the command:";
    std::string buffer;
    std::getline(std::cin, buffer);
    return buffer;
}


int main() {

    std::map<std::string, std::string> phoneNumbers;
    std::string buffer = getInput();
    unsigned int space = buffer.std::string::find(' ');
    std::string firstPart = "none";
    std::string secondPart = "none";
    firstPart = buffer.substr(0, space);
    secondPart = buffer.substr(space + 1, buffer.length());

    if (firstPart[0] >= '0' || firstPart[0] <= '9')
    {
        if (secondPart != "none")
        {
            phoneNumbers.insert(std::make_pair(firstPart, secondPart));
        }
        else
        {
            std::cout << phoneNumbers.find(firstPart)->second << "\n";
        }
    }
    else
    {
        for (std::map<std::string, std::string>::iterator it = phoneNumbers.begin();
             it != phoneNumbers.end(); ++it)
        {
            if (it->second == secondPart)
            {
                std::cout << it->first << " ";
            }
            std::cout << "\n";
        }
    }


    return 0;
}
