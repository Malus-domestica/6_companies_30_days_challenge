#include <bits/stdc++.h>
using namespace std;

int findUnsortedSubarr(vector<int> &nums)
{
    int n = nums.size();
    int l, r, min, max, s;
    l = 0;
    r = nums.size() - 1;
    for (int i = 0; i < n; i++)
    {
        min = *min_element(nums.begin() + l, nums.end() - ((n - 1) - r));
        max = *max_element(nums.begin() + l, nums.end() - ((n - 1) - r));
        if (nums[l] != min && nums[r] != max)
            break;
        if (nums[l] == min)
            l++;
        if (nums[r] == max)
            r--;
        if (l >= r)
            break;
    }
    // size of array
    if (r > l)
        s = r - l + 1;
    else
        s = 0;
    return s;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,3,3};
    cout << findUnsortedSubarr(nums) << endl;
    return 0;
}
