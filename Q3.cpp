#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
      unordered_map<char, int> map1, map2;
    int bulls = 0, cows = 0;
    for (int i = 0; i < secret.size(); i++)
    {
        if (secret[i] == guess[i])
            bulls++;
        else
        {
            map1[secret[i]]++;
            map2[guess[i]]++;
        }
    }
    for (auto it : map1)
    {
        if (map2.find(it.first) != map2.end())
        {
            cows += min(it.second, map2[it.first]);
        }
    }
    string ans;
    ans = to_string(bulls) + "A" + to_string(cows) + "B";
    return ans;  
    }
};