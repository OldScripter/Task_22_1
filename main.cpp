#include <iostream>
#include <map>

/**
 * @function Get the input from keyboard.
 * @return line of std::string
 */
std::string getInput()
{
    std::cout << "Please enter the command (or 'exit' to stop):\n";
    std::string buffer;
    std::getline(std::cin, buffer);

    return buffer;
}

int main()
{
    std::map<std::string, std::string> phoneNumbers;
    do
    {
        std::string buffer = getInput();
        if (buffer == "exit")
        {
            break;
        }
        else if (buffer.length() == 0 || (buffer.length() != 0 && buffer[0] == ' '))
        {
            std::cerr << "Bad input! Try again.\n";
            continue;
        }

        //Process the input:
        std::size_t space = buffer.std::string::find(' ');
        std::string firstPart = "none";
        std::string secondPart = "none";
        if (space != std::string::npos)
        {
            firstPart = buffer.substr(0, space);
            secondPart = buffer.substr(space + 1, buffer.length());
        }
        else
        {
            firstPart = buffer;
        }
        if (firstPart[0] >= '0' && firstPart[0] <= '9')
        {
            std::map<std::string, std::string>::iterator it = phoneNumbers.find(firstPart);
            if (secondPart != "none")
            {
                if (it != phoneNumbers.end())
                {
                    std::cout << "Setting the number " << firstPart << " to the owner " << secondPart << ".\n";
                    it->second = secondPart;
                }
                else
                {
                    std::cout << "Adding the number " << firstPart << " for the owner " << secondPart << ".\n";
                    phoneNumbers.insert(std::make_pair(firstPart, secondPart));
                }
            }
            else
            {
                std::cout << "Looking for owner of '" << firstPart << "'.\n";
                it = phoneNumbers.find(firstPart);
                if (it != phoneNumbers.end())
                {
                    std::cout << "The owner is: " << it->second << "\n";
                }
                else
                {
                    std::cout << "Owner not found.\n";
                }
            }
        }
        else
        {
            std::cout << "Looking for numbers for owner '" << firstPart << "'.\n";
            int counter = 0;
            for (std::map<std::string, std::string>::iterator it = phoneNumbers.begin();
                 it != phoneNumbers.end(); ++it)
            {
                if (it->second == firstPart)
                {
                    std::cout << it->first << " ";
                    ++counter;
                }
            }
            std::cout << "\n";
            if (counter == 0) std::cout << "No numbers found.\n";
        }
    }
    while(true);

    std::cout << "Program is finished.\n";

    return 0;
}
