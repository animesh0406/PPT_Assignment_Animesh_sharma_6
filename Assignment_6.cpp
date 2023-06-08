/*
Question 1

A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

- s[i] == 'I' if perm[i] < perm[i + 1], and
- s[i] == 'D' if perm[i] > perm[i + 1].

Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return **any of them**.

Example 1:

Input:s = "IDID"

Output:

[0,4,1,3,2]

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> dimatch(string s) {
        int n = s.length();
        vector<int>v;
        int j = n;
        int k = 0;
        for(int i = 0;i<n+1;i++){
           if(s[i]=='I'){
               v.push_back(k);
               k++;
           }
           else if(s[i]=='D'){
               v.push_back(j);
               j--;}
        }
       v.push_back(k);
        return v;}



/*
Question 2**

You are given an m x n integer matrix matrix with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true *if* target *is in* matrix *or* false *otherwise*.

You must write a solution in O(log(m * n)) time complexity.

*/
#include<bits/stdc++.h>
using namespace std;
 
#define M 3
#define N 4
bool binarySearch1D(int arr[], int K)
{
    int low = 0;
    int high = N - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == K)
            return true;

        if (arr[mid] < K)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

bool searchMatrix(int matrix[M][N], int K)
{
    int low = 0;
    int high = M - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
 
      
        if (K >= matrix[mid][0]
            && K <= matrix[mid][N - 1])
            return binarySearch1D(matrix[mid], K);
 
        if (K < matrix[mid][0])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return false;
}

int main()
{
    int matrix[M][N] = { { 1, 3, 5, 7 },
                         { 10, 11, 16, 20 },
                         { 23, 30, 34, 50 } };
    int K = 3;
    if (searchMatrix(matrix, K))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
}


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


/*
<aside>
💡 **Question 5**

The **product sum** of two equal-length arrays a and b is equal to the sum of a[i] * b[i] for all 0 <= i < a.length (**0-indexed**).

- For example, if a = [1,2,3,4] and b = [5,2,3,1], the **product sum** would be 1*5 + 2*2 + 3*3 + 4*1 = 22.

Given two arrays nums1 and nums2 of length n, return *the **minimum product sum** if you are allowed to **rearrange** the **order** of the elements in* nums1.

**Example 1:**

**Input:** nums1 = [5,3,4,2], nums2 = [4,2,2,5]

**Output:** 40

**Explanation:**

We can rearrange nums1 to become [3,5,4,2]. The product sum of [3,5,4,2] and [4,2,2,5] is 3*4 + 5*2 + 4*2 + 2*5 = 40.

</aside>
*/
#include <bits/stdc++.h>
using namespace std;

long long int minValue(int A[], int B[], int n)
{
  
    sort(A, A + n);
    sort(B, B + n);
   
 
    long long int result = 0;
    for (int i = 0; i < n; i++)
        result += (A[i] * B[n - i - 1]);
   
    return result;
}
   

int main()
{
    int A[] = { 3, 1, 1 };
    int B[] = { 6, 5, 4 };
    int n = sizeof(A) / sizeof(A[0]);
    cout << minValue(A, B, n) << endl;
    return 0;
}



/*
<aside>
💡 **Question 6**

An integer array original is transformed into a **doubled** array changed by appending **twice the value** of every element in original, and then randomly **shuffling** the resulting array.

Given an array changed, return original *if* changed *is a **doubled** array. If* changed *is not a **doubled** array, return an empty array. The elements in* original *may be returned in **any** order*.

**Example 1:**

**Input:** changed = [1,3,4,2,6,8]

**Output:** [1,3,4]

**Explanation:** One possible original array could be [1,3,4]:

- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.

Other original arrays could be [4,3,1] or [3,1,4].

</aside>
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() & 1) return {};
        int n=changed.size();
        int cnt=0;
        vector<int >v;
        sort(changed.begin(),changed.end());
        unordered_map<int,int> mp;
        for(auto it:changed)
        {
                mp[it]++;
        }
        
        for(auto it:changed){
            int x=it;
            if(mp[x]%2==0 && x==0 && mp[x]>=2) // for 0 we are checking it even no of time of occurrance because mp[x]==mp[2*x]
            {
                v.push_back(x);
                cout<<x<<endl;
                mp[x]-=2;
            }
            if(mp.find(2*x)!=mp.end() && x!=0)
            {                
                if(mp[x]>0 && mp[2 * x] > 0)
                {
                    v.push_back(x);
                    mp[x]--;                    
                    mp[2*x]--;                   
                }   
            }
        }
        if(v.size()==n/2) return v;
        v.clear();
        return v;
    }



/*

**Question 7**

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.


*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    fillMatrix(matrix, 0, n - 1, 0, n - 1, 1);
    return matrix;
}

void fillMatrix(vector<vector<int>>& matrix, int top, int bottom, int left, int right, int num) {
    if (top > bottom || left > right) {
        return;
    }
    for (int i = left; i <= right; i++) {
        matrix[top][i] = num;
        num++;
    }
    for (int i = top + 1; i <= bottom; i++) {
        matrix[i][right] = num;
        num++;
    }
    if (top < bottom && left < right) {
        for (int i = right - 1; i >= left; i--) {
            matrix[bottom][i] = num;
            num++;
        }
        for (int i = bottom - 1; i > top; i--) {
            matrix[i][left] = num;
            num++;
        }
    }
    fillMatrix(matrix, top + 1, bottom - 1, left + 1, right - 1, num);
}


/*
Question 8**

Given two  mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2. You may assume that multiplication is always possible.

</aside>
*/
#include<bits/stdc++.h>
using namespace std;
  vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int r1 = mat1.size(), c1 = mat1[0].size(), c2 = mat2[0].size();
        vector<vector<int>> res(r1, vector<int>(c2));
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c1; ++j) {
                if (mat1[i][j] != 0) mp[i].push_back(j);
            }
        }
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c2; ++j) {
                for (int k : mp[i]) res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
        return res;
    }