#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int maxRotateFunction(vector<int>& nums) {
       int F, sum, mx;
    sum = 0, F = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        F += i * nums[i];
    }
    mx = F;
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--)
    {
        F = F + sum - (n * nums[i]);
        mx = max(mx, F);
    }

    return mx;
    }
};