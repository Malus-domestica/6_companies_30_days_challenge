class Solution {
public:
    void findSum(int last, vector<bool> &viz, vector<int> &sub_vector, vector<vector<int>> &output, int n, int k)
{
    if (n == 0 && k == 0)
    {
        output.push_back(sub_vector);
        return;
    }
    if (k == 0 && n != 0)
        return;

    for (int i = last; i <= 9; i++)
    {
        if (!viz[i])
        {
            viz[i] = true;
            sub_vector.push_back(i);
            findSum(i + 1, viz, sub_vector, output, n - i, k - 1);
            sub_vector.pop_back();
            viz[i] = false;
        }
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool> viz(9, false);
        vector<int> sub_vector;
        vector<vector<int>> output;
        findSum(1, viz, sub_vector, output, n, k);
        return output;
    }
};