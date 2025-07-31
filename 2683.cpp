#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int result = derived[0];
        for (int i = 1; i < derived.size(); i++)
        {
            result = result ^ derived[i];
        }
        if (result == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};