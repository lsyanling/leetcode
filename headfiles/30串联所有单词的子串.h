
#pragma once

import std;
using namespace std;

class Solution30 {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		int sSize = s.size();
		int wordsSize = words.size();
		int wordSize = words[0].size();
		int length = wordsSize * wordSize;
		if (sSize < length)
			return result;

		vector<map<string, int>> maps(wordSize, map<string, int>());
		map<string, int> solution;
		vector<string> nowBeginWords(wordSize);

		// 标准答案
		for (const auto& word : words)
			addValueForMap(solution, word);

		// 初始化滑动窗口，i表示第i个窗口，j表示该窗口的第j个单词
		for (int i = 0; i < wordSize; i++) {
			for (int j = 0; j < wordsSize; j++) {
				// 滑动窗口未到达s的末尾
				if (wordSize * (j + 1) + i <= sSize)
				{
					string word = s.substr(wordSize * j + i, wordSize);
					if (solution.find(word) != solution.end()) {
						addValueForMap(maps[i], word);
						// 滑动窗口首单词
						if (j == 0)
							nowBeginWords[i] = word;
					}
				}
			}
			// 解和答案相同
			if (maps[i] == solution)
				result.push_back(i);
		}

		// 滑动窗口右移
		for (int i = length; i <= sSize - wordSize; i++) {
			string word = s.substr(i, wordSize);
			string beginWord = nowBeginWords[i % wordSize];
			// 窗口末尾是一个单词
			if (solution.find(word) != solution.end())
				addValueForMap(maps[i % wordSize], word);
			// 去掉窗口首单词
			if (nowBeginWords[i % wordSize] != "")
				subValueForMap(maps[i % wordSize], nowBeginWords[i % wordSize]);
			// 更新窗口首单词
			beginWord = s.substr(i - length + wordSize, wordSize);
			if (solution.find(beginWord) != solution.end())
				nowBeginWords[i % wordSize] = beginWord;
			else
				nowBeginWords[i % wordSize] = "";
			// 解
			if (maps[i % wordSize] == solution)
				result.push_back(i - length + wordSize);
		}
		return result;
	}

	void addValueForMap(map<string, int>& m, const string& str) {
		if (m.find(str) != m.end())
			m[str]++;
		else
			m[str] = 1;
	}
	void subValueForMap(map<string, int>& m, const string& str) {
		if (m.find(str) != m.end())
			m[str]--;
	}
};