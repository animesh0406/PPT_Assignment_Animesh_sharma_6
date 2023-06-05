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