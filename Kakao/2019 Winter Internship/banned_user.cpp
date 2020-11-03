#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<string>> vvs;

vvs list;

bool is_correct(string user_id, string banned_id)
{
	if (user_id.length() != banned_id.length()) return false;

	for (int i = 0; i < user_id.length(); i++) {
		if (banned_id[i] == '*') continue;
		if (user_id[i] != banned_id[i]) return false;
	}

	return true;
}

bool is_exist(string s, vector<string> list)
{
	if (list.size() == 0) return false;

	for (auto i : list) {
		if (s == i) return true;
	}
	return false;
}

void make_list(vector<string> t, vvs banned_list, int n)
{
	if (t.size() == banned_list.size()) {
		list.push_back(t);
		return;
	}

	for (int i = 0; i < banned_list[n].size(); i++) {
		if (!is_exist(banned_list[n][i], t)) {
			t.push_back(banned_list[n][i]);
			make_list(t, banned_list, n + 1);
			t.pop_back();
		}
	}
}

bool compare(vector<string> a, vector<string> b)
{
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) continue;
		else if (a[i] > b[i]) return true;
		else return false;
	}
}

int solution(vector<string> user_id, vector<string> banned_id)
{
	int answer = 0;
	vvs banned_list;
	vector<string> t;

	for (int i = 0; i < banned_id.size(); i++) {
		t.clear();
		for (int j = 0; j < user_id.size(); j++) {
			if (is_correct(user_id[j], banned_id[i])) {
				t.push_back(user_id[j]);
			}
		}
		banned_list.push_back(t);
	}

	t.clear();

	make_list(t, banned_list, 0);

	for (int i = 0; i < list.size(); i++) {
		sort(list[i].begin(), list[i].end());
	}
	sort(list.begin(), list.end(), compare);

	list.erase(unique(list.begin(), list.end()), list.end());

	answer = list.size();
	return answer;
}