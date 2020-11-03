#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int get_size(string s)
{
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '}') cnt++;
	}

	return cnt - 1;
}

int make_num(vector<int> v)
{
	int n = 0, t;
	for (int i = v.size() - 1, t = 1; i >= 0; i--, t *= 10) n = v[i] * t;

	return n;
}

vector<int> solution(string s)
{
	vector<int> answer;
	int n = get_size(s);
	vector<vector<int>> tuple(n);
	vector<int> t;
	string num = "";

	for (int i = 1; i < s.length() - 1; i++) {
		if (s[i] == '{') num = "";
		else if ('0' <= s[i] && s[i] <= '9') num += s[i];
		else if (s[i] == '}') {
			t.push_back(stoi(num));
			tuple[t.size() - 1] = t;
			t.clear();
		}
		else if (s[i] == ',' && s[i - 1] != '}') {
			t.push_back(stoi(num));
			num = "";
		}
	}

	for (int i = 0; i < tuple.size(); i++) {
		for (int j = 0; j < tuple[i].size(); j++) {
			vector<int>::iterator it = find(answer.begin(), answer.end(), tuple[i][j]);
			if (it == answer.end()) {
				answer.push_back(tuple[i][j]);
				break;
			}
		}
	}

	return answer;
}