#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

string getstd(string s, int st, int len)
{
	string std = "";
	if (st + len > s.length()) return "";
	for (int i = st; i < st + len; i++) std += s[i];
	return std;
}

string left_string(string s, int st)
{
	string t = "";
	for (int i = st; i < s.length(); i++) t += s[i];
	return t;
}

int cut(string s, int len)
{
	vector<pair<string, int>> cutlist;
	int cnt = 1;
	string curstd = getstd(s, 0, len);
	string newstd = "";

	for (int i = len; i < s.length(); i += len) {
		newstd = getstd(s, i, len);

		if (newstd == "") {
			cutlist.push_back(make_pair(curstd, cnt));
			curstd = left_string(s, i);
			cnt = 1;
		}
		else if (newstd != curstd) {
			cutlist.push_back(make_pair(curstd, cnt));
			curstd = newstd;
			cnt = 1;
		}
		else cnt++;
	}
	cutlist.push_back(make_pair(curstd, cnt));

	s = "";
	for (int i = 0; i < cutlist.size(); i++) {
		if (cutlist[i].second != 1) s += to_string(cutlist[i].second);
		s += cutlist[i].first;
	}

	return s.length();
}

int solution(string s)
{
	int answer = s.length();

	for (int i = 1; i <= s.length() / 2; i++) {
		int t = cut(s, i);
		answer = t < answer ? t : answer;
	}

	return answer;
}

int main()
{
	cin >> s;
	cout << solution(s);
	return 0;
}