#include <iostream>
#include <vector>

/* There are many ways to solve this problem. If your solution is not working or you are struggling to start, try looking at the
   problem as a graph problem. The characters are nodes. A mapping is a directed edge.
*/
int mappableIndex ( std::vector<std::pair<char, char>> & mappings, char letter, int minMappableIndex){

    for(int i = minMappableIndex; i < mappings.size(); i++)
    {
        if(letter == mappings[i].first)
        {
            return i;
        }
    }

    return -1;
}

bool wordsMatch( std::vector<std::pair<char, char>> & mappings, std::string leftWord, std::string rightWord ){
    //if different length strings then no match
    if(leftWord.length() != rightWord.length())
    {
        return false;
    }

    for(int i = 0; i < leftWord.length(); i++)
    {
        bool goodChar = false;

        if(leftWord[i] == rightWord[i])
        {
            continue;
        }

        int minMappableIndex = 0;
        while(mappableIndex(mappings, leftWord[i], minMappableIndex) != -1)
        {
            int mapI = mappableIndex(mappings, leftWord[i], minMappableIndex);
            //check if the next node is solution
            if(mappings[mapI].second == rightWord[i])
            {
                goodChar = true;
                break;
            }
            else if(leftWord[i] == 't' && (rightWord[i] == 'f' || rightWord[i] == 'e'))
            {
                goodChar = true;
                break;
            }

            leftWord[i] = mappings[mapI].second;


        }

        if(!goodChar)
        {
            return false;
        }
    }



    return true;
}

int main() {
    // Nothing goes in main
    std::string leftWord = "out";
    std::string rightWord = "the";
    std::pair<char, char> p1('c','t');
    std::pair<char, char> p2('i','r');
    std::pair<char, char> p3('o','c');
    std::pair<char, char> p4('r','o');
    std::pair<char, char> p5('t','e');
    std::pair<char, char> p6('t','f');
    std::pair<char, char> p7('u','h');
    std::pair<char, char> p8('w','p');
    std::pair<char, char> p9('k','p');
    std::vector<std::pair<char, char>> mappings {p1,p2,p3,p4,p5,p6,p7,p8,p9};

    if(wordsMatch(mappings, leftWord, rightWord))
        std::cout << "Match";
    else
        std::cout << "No Match";

    return 0;
}



