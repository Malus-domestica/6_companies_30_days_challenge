#include <bits/stdc++.h>
using namespace std;
//could not solve all test cases
// brute force
int func(int n, int diff, vector<int> nums1, vector<int> nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int c = 0;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = i + 1; j < nums1.size(); j++)
        {
            if (nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff)
                c++;
        }
    }
    return c;
    // tc O(n^2)
}

void merge(vector<int> arr, int l, int mid, int r, int &ans, int diff)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];

    // before merging
    for (int j = 0; j < n2; j++)
    {
        int val = upper_bound(a, (a + n1), (b[j] + diff)) - a;
        ans += val;
    }

    int i = 0; // pointer for a
    int j = 0; // pointer for b
    int k = l; // pointer for arr
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

// nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
// nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff both are same
// if condition i<j were not there we could simply sort and find
// v1[i] = nums1[i] - nums2[i]
// v[i]<=v[j]+diff
// v[i]-v[j]<=diff

void mergeSort(vector<int> arr, int l, int r, int &ans, int diff)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid, ans, diff);
        mergeSort(arr, mid + 1, r, ans, diff);
        merge(arr, l, mid, r, ans, diff);
    }
}

int numOfPair(vector<int> nums1, vector<int> nums2, int diff)
{
    vector<int> v(nums1.size());
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = nums1[i] - nums2[i];
    }
    int ans = 0;
    mergeSort(v, 0, v.size() - 1, ans, diff);
    return ans;
}

// merge sort tech

int main(int argc, char const *argv[])
{
    int n, diff;
    cin >> n >> diff;
    vector<int> arr1(n), arr2(n);
    for (auto &i : arr1)
        cin >> i;
    for (auto &i : arr2)
        cin >> i;
    cout << numOfPair(arr1, arr2, diff) << endl;
    return 0;
}
