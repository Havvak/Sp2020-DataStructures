#include <iostream>
#include <map>



bool validAnagram( std::string first, std::string second ) {
    // Your code goes here
    int letterCountFirst[26] = {0};
    int letterCountSecond[26] = {0};

    for (int i = 0; i < first.length(); i++)
    {
        letterCountFirst[first[i] - 'a']++;
    }

    for (int i = 0; i < second.length(); i++)
    {
        letterCountSecond[second[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if(letterCountFirst[i] != letterCountSecond[i])
        {
            return false;
        }
    }

    return true;
}

int main() {
    // Nothing goes in main
    std::string first = "aaabaaa";
    std::string second = "abaabaa";

    if(validAnagram(first, second))
        std::cout << "true";
    else
        std::cout << "false";

    return 0;
}
