
#pragma once

import std;
using namespace std;

class Solution48 {
public:
	void rotate(vector<vector<int>>& matrix)
	{
		int n = matrix.size();
		// 左右对称
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n / 2; j++) {
				swap(matrix[i][j], matrix[i][n - 1 - j]);
			}
		}
		// y=x对称
		for (int i = 0, j = 0; i < n; i++) {
			for (j = 0; i + j < n; j++) {
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
			}
		}
	}
};