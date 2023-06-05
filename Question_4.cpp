/*
*Question 4**

Given a binary array nums, return *the maximum length of a contiguous subarray with an equal number of* 0 *and* 1.

**Example 1:**

**Input:** nums = [0,1]

**Output:** 2

**Explanation:**

[0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

*/
#include <bits/stdc++.h>
 
using namespace std;
 

 
int findSubArray(int arr[], int n)
{
    int sum = 0;
    int maxsize = -1, startindex;
 
    
    for (int i = 0; i < n - 1; i++) {
        sum = (arr[i] == 0) ? -1 : 1;
 
        
        for (int j = i + 1; j < n; j++) {
            (arr[j] == 0) ? (sum += -1) : (sum += 1);
 
           
            if (sum == 0 && maxsize < j - i + 1) {
                maxsize = j - i + 1;
                startindex = i;
            }
        }
    }
    if (maxsize == -1)
        cout << "No such subarray";
    else
        cout << startindex << " to "
             << startindex + maxsize - 1;
 
    return maxsize;
}

int main()
{
    int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
 
    findSubArray(arr, size);
    return 0;
}