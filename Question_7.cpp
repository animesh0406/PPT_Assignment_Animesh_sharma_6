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