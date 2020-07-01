#include <iostream>
#include <vector>

const int MAX_INT = 2147483647;

// You are not using c++ pairs when you return your result. You are to use a vector where { 1, 2} is a "pair"
std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    //initialize holding array
    int resultArray [k][3] {MAX_INT}; //[x][0] value of sum, [x][1] num1, [x][2] num2

    //initialize result vector
    std::vector<std::vector<int>> resultVector;

    int highestMinSum = 0;

    //iterate over nums 1
    for(int i = 0; i < nums1.size(); i++)
    {
        //iterate over nums 2
        for(int j = 0; j < nums2.size(); j++)
        {
            //iterate over holding array
            for(int x = 0; x < k; x++)
            {
                int numSum = nums1[i] + nums2[j];
                if(numSum < resultArray[x][0])
                {
                    resultArray[x][0] = numSum;
                    resultArray[x][1] = nums1[i];
                    resultArray[x][2] = nums2[j];
                }
            }
        }
    }

    //temporary output
    for(int x = 0; x < k; x++)
    {
        std::cout << resultArray[x][1] << ' ' << resultArray[x][2] << " | ";
    }


    return resultVector;
}

int main(){
    // Nothing goes in main
    std::vector<int> nums1 {1, 2, 3, 4};
    std::vector<int> nums2 {5, 6, 7, 8};
    int k = 3;

    kSmallestPairs(nums1, nums2, k);

    return 0;
}
