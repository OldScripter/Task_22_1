#include <iostream>
#include <map>
#include <vector>

std::map<std::string, std::string> phoneBook;
std::map<std::string, std::vector<std::string>> ownersBook;

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

/**
 * @function Register new number and its owner in book, or set new owner for the number.
 * @requires [global] phoneBook map and [global] ownersBook map
 * @param [in] number string to be registered.
 * @param [in] name string to be registered.
 */
void addPhone(std::string& number, std::string& name)
{
    //Add to phone book:
    std::map<std::string, std::string>::iterator phoneIt = phoneBook.find(number);
    if (phoneIt != phoneBook.end())
    {
        std::cout << "Setting the number " << number << " to the owner " << name << ".\n";
        phoneIt->second = name;
    }
    else
    {
        std::cout << "Adding the number " << number << " for the owner " << name << ".\n";
        phoneBook.insert(std::make_pair(number, name));
    }

    //Add to owners book:
    std::map<std::string, std::vector<std::string>>::iterator ownerIt = ownersBook.find(name);
    if (ownerIt != ownersBook.end())
    {
        ownerIt->second.push_back(number);
    }
    else
    {
        std::vector<std::string> numbers = {number};
        ownersBook.insert(std::make_pair(name, numbers));
    }
}

/**
 * @function Get the owner of phone number.
 * @requires [global] phoneBook map
 * @param [in] number owner for which is looking for.
 */
void getOwner(std::string& number)
{
    std::map<std::string, std::string>::iterator it = phoneBook.find(number);
    if (it != phoneBook.end())
    {
        std::cout << "The owner of number " << number << " is " << it->second << ".\n";
    }
    else
    {
        std::cout << "The owner of number " << number << " is not found.\n";
    }
}

/**
 * @function Return all numbers of the owner.
 * @requires [global] ownersBook map
 * @param [in] name of the owner for whom numbers are looking for.
 */
void getNumbers(std::string& name)
{
    std::map<std::string, std::vector<std::string>>::iterator it = ownersBook.find(name);
    if (it != ownersBook.end())
    {
        std::cout << "For " << name << " following numbers are registered:\n";
        for (std::string number : it->second)
        {
            std::cout << number << " ";
        }
        std::cout << '\n';
    }
    else
    {
        std::cout << "Person " << name << " is not found.\n";
    }

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
        else if (buffer.length() == 0 || buffer[0] == ' ')
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
            if (secondPart != "none")
            {
                addPhone(firstPart, secondPart);
            }
            else
            {
                getOwner(firstPart);
            }
        }
        else
        {
            getNumbers(firstPart);
        }
    }
    while(true);

    std::cout << "Program is finished.\n";

    return 0;
}