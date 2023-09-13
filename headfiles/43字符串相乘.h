
#pragma once

import std;
using namespace std;

class Solution43 {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		if (num1 == "1")
			return num2;
		if (num2 == "1")
			return num1;
		int n1 = num1.size(), n2 = num2.size();
		string result(n1 + n2, '0');
		for (int i = n1 - 1; i >= 0; i--) {
			for (int j = n2 - 1; j >= 0; j--) {
				// һλ��һλ
				int temp = multiply(num1[i], num2[j]);
				string accumulation = intToString(temp);
				addString(result, accumulation, n1 - 1 - i + n2 - 1 - j);
			}
		}
		// ȥ��ǰ��0
		auto i = result.rbegin();
		while (i != result.rend() && *i == '0')
			i++;
		// ���������
		return string(i, result.rend());
	}
	int multiply(char c1, char c2) {
		return (c1 - '0') * (c2 - '0');
	}
	string intToString(int value) {
		string result = "0";
		if (value < 10)
			result[0] = value + '0';
		else
		{
			result[0] = ((value / 10) + '0');
			result += ((value % 10) + '0');
		}
		return result;
	}
	void addString(string& s1, string& s2, int digit) {
		// s2��һλ����λ��
		if (s2.size() == 1) s2 = "0" + s2;
		s1[digit] += s2[1] - '0';
		s1[digit + 1] += s2[0] - '0';
		// ��λ
		if (s1[digit] > '9') {
			s1[digit] -= 10;
			s1[digit + 1]++;
		}
		for (int i = digit + 1; i < s1.size(); i++) {
			if (s1[i] > '9') {
				s1[i] -= 10;
				s1[i + 1]++;
			}
			else return;
		}
	}
};