#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        map<int, int> cnt;
        long long cost = 0;
        for (int i = 0; i < basket1.size(); i++)
        {
            if (cnt.count(basket1[i]))
            {
                cnt[basket1[i]] += 1;
            }
            else
            {
                cnt[basket1[i]] = 1;
            }
        }
        for (int i = 0; i < basket2.size(); i++)
        {
            if (cnt.count(basket2[i]))
            {
                cnt[basket2[i]] -= 1;
            }
            else
            {
                cnt[basket2[i]] = -1;
            }
        }

        vector<int> num;
        int min = cnt.begin()->first * 2;
        for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
        {
            if (abs(it->second) % 2 != 0)
            {
                return -1;
            }
            for (int i = 0; i < abs(it->second) / 2; i++)
            {
                num.push_back(it->first);
            }
        }
        for (int i = 0; i < num.size() / 2; i++)
        {
            cost += (min > num[i]) ? num[i] : min;
        }
        return cost;
    }
};