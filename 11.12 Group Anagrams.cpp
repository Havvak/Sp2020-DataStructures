#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

//From 11.10 Valid Anagram
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

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> & words) {
    // Your code goes here
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> newResult;

    std::queue<std::string> wordQueue;

    for(int i = 0; i < words.size(); i++)
    {
        wordQueue.push(words[i]);
    }

    std::string currWord = wordQueue.front();
    wordQueue.pop();

    result.push_back(newResult);
    result[0].push_back(currWord);

    while(!(wordQueue.empty()))
    {
        std::string currWord = wordQueue.front();
        wordQueue.pop();

        int i = 0;
        bool flag = true;

        for(i = 0; i < result.size(); i++)
        {
            if(validAnagram(currWord, result[i][0]))
            {
                result[i].push_back(currWord);
                flag = false;
            }
        }

        if(flag)
        {
            result.push_back(newResult);
            result[i].push_back(currWord);
        }
    }

    return result;
}

int main() {
    // Nothing goes in main
    std::vector<std::string> words {"eat", "tea", "tan", "ate", "nat", "bat"};

    groupAnagrams(words);

    return 0;
}
