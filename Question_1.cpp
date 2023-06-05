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