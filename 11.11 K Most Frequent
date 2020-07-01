#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>

std::vector<int> kMostFrequent(std::vector<int> & nums, int k) {
    // Your code goes here
    std::vector<int> numCount {0,0,0,0,0,0,0,0,0,0};

    for(int i = 0; i < nums.size(); i++)
    {
        numCount[nums[i]]++;
    }

    std::vector<int> kMost;

    for(int i = 0; i < k; i++)
    {
        kMost.push_back(0);
        for(int j = 1; j < numCount.size(); j++)
        {
            if(numCount[j] > numCount[kMost[i]])
            {
                kMost[i] = j;
            }
        }
        numCount[kMost[i]] = -1;
    }

    return kMost;
}

int main() {
    // Nothing goes in main
    std::vector<int> nums {1, 2, 3, 5, 2, 4, 0, 3, 9, 8, 5, 6, 3, 7, 2, 4, 8, 9, 3, 4, 7, 2, 1, 8};

    kMostFrequent(nums, 2);

    return 0;
}
