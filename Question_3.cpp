/*
Question 3**

Given an array of integers arr, return *true if and only if it is a valid mountain array*.

Recall that arr is a mountain array if and only if:

- arr.length >= 3
- There exists some i with 0 < i < arr.length - 1 such that:
    - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

*/
#include <bits/stdc++.h>
using namespace std;

bool isMountainArray(vector<int>& arr)
{
    if (arr.size() < 3)
        return false;
    int flag = 0, i = 0;
    for (i = 1; i < arr.size(); i++)
        if (arr[i] <= arr[i - 1])
            break;
 
    if (i == arr.size() || i == 1)
        return false;
 
    for (; i < arr.size(); i++)
        if (arr[i] >= arr[i - 1])
            break;
    return i == arr.size();
}

int main()
{
    vector<int> arr
        = { 1, 2, 3, 4, 9,
            8, 7, 6, 5 };
    cout << (isMountainArray(arr)
                 ? "true"
                 : "false");
    return 0;
}