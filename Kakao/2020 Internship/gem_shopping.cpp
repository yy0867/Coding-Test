#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> gem_list;

bool operator<(vector<int> v1, vector<int> v2)
{
	if (v1[1] - v1[0] < v2[1] - v2[0]) return true;
	else if (v1[1] - v1[0] == v2[1] - v2[0]) return v1[0] < v2[0] ? true : false;
	return false;
}

bool is_exist(vector<string> v, string k)
{
	for (string s : v) if (s == k) return true;
	return false;
}

void get_list(vector<string> gems)
{
	for (string s : gems) {
		if (!is_exist(gem_list, s)) gem_list.push_back(s);
	}
}

bool search(int start, int end, vector<string> gems)
{
	if (end - start < gem_list.size() - 1) return false;
	vector<string> t_list;
	for (int i = start; i <= end; i++) {
		if (!is_exist(t_list, gems[i])) t_list.push_back(gems[i]);
		if (t_list.size() == gem_list.size()) return true;
	}
	return false;
}

vector<int> solution(vector<string> gems)
{
	vector<int> answer, comp(2, 0);
	int start = 0, end = 0;

	answer.push_back(100010101);
	answer.push_back(201293421);
	get_list(gems);
	while (start < gems.size()) {
		if (search(start, end, gems)) {
			comp[0] = start + 1, comp[1] = end + 1;
			answer = comp < answer ? comp : answer;
			start++;
		}
		else {
			if (end == gems.size() - 1) start++;
			else end++;
		}
	}

	return answer;
}

int main()
{
	int n;
	cin >> n;
	string s;
	vector<string> gems;

	for (int i = 0; i < n; i++) {
		cin >> s;
		gems.push_back(s);
	}

	vector<int> t = solution(gems);
	cout << "[" << t[0] << ", " << t[1] << "]" << endl;

	return 0;
}

/*
8
DIA RUBY RUBY DIA DIA EMERALD SAPPHIRE DIA
*/