#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int max = 0;
        int length = 0;
        int maxlength = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (max < nums[i])
            {
                max = nums[i];
                maxlength = 1;
                length = 1;
            }
            else if (max == nums[i])
            {
                length += 1;
            }
            else
            {
                maxlength = (maxlength > length) ? maxlength : length;
                length = 0;
            }
        }
        return (maxlength > length) ? maxlength : length;
    }
};