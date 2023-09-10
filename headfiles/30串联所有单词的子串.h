
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

		// ��׼��
		for (const auto& word : words)
			addValueForMap(solution, word);

		// ��ʼ���������ڣ�i��ʾ��i�����ڣ�j��ʾ�ô��ڵĵ�j������
		for (int i = 0; i < wordSize; i++) {
			for (int j = 0; j < wordsSize; j++) {
				// ��������δ����s��ĩβ
				if (wordSize * (j + 1) + i <= sSize)
				{
					string word = s.substr(wordSize * j + i, wordSize);
					if (solution.find(word) != solution.end()) {
						addValueForMap(maps[i], word);
						// ���������׵���
						if (j == 0)
							nowBeginWords[i] = word;
					}
				}
			}
			// ��ʹ���ͬ
			if (maps[i] == solution)
				result.push_back(i);
		}

		// ������������
		for (int i = length; i <= sSize - wordSize; i++) {
			string word = s.substr(i, wordSize);
			string beginWord = nowBeginWords[i % wordSize];
			// ����ĩβ��һ������
			if (solution.find(word) != solution.end())
				addValueForMap(maps[i % wordSize], word);
			// ȥ�������׵���
			if (nowBeginWords[i % wordSize] != "")
				subValueForMap(maps[i % wordSize], nowBeginWords[i % wordSize]);
			// ���´����׵���
			beginWord = s.substr(i - length + wordSize, wordSize);
			if (solution.find(beginWord) != solution.end())
				nowBeginWords[i % wordSize] = beginWord;
			else
				nowBeginWords[i % wordSize] = "";
			// ��
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