
#pragma once

import std;
using namespace std;

class Solution49 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<map<char, int>, int> maps;
		vector<vector<string>> result;
		int size = 0;
		for (const string& str : strs) {
			map<char, int> temp;
			for (const char ch : str) {
				addValueForMap(temp, ch);
			}
			if (maps.find(temp) != maps.end()) {
				int i = maps[temp];
				// 相同的词也要输出
				// if(find(result[i].begin(),result[i].end(), str) == result[i].end())
				result[i].push_back(string{ str });
			}
			else {
				addValueForMap(maps, temp, size);
				size++;
				result.push_back(vector<string>({ str }));
			}
		}
		return result;
	}
	template<typename Key>
	void addValueForMap(map<Key, int>& m, Key key, int value = 1) {
		if (m.find(key) != m.end())
			m[key]++;
		else
			m[key] = value;
	}
};