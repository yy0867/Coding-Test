#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

typedef pair<string, string> cut;

const char OPEN = '(';
const char CLOSE = ')';

bool is_balance(string p)
{
	int left = 0, right = 0;

	for (int i = 0; i < p.length(); i++) {
		if (p[i] == OPEN) left++;
		else right++;
	}

	return left == right ? true : false;
}

bool is_perfect(string p)
{
	if (!is_balance(p)) return false;
	if (p[0] == CLOSE || p[p.length() - 1] == OPEN) return false;

	int cnt = 0;

	for (int i = 0; i < p.length(); i++) {
		if (p[i] == OPEN) cnt++;
		else cnt--;
		if (cnt < 0) return false;
	}

	return true;
}

cut cutting(string p)
{
	int i;
	string r1 = "", r2 = "";
	bool is_fin = false;

	for (i = 0; i < p.length(); i++) {
		if (is_fin == false) r1 += p[i];
		else r2 += p[i];

		if (is_balance(r1)) is_fin = true;
	}

	return make_pair(r1, r2);
}

string solution(string p)
{
	if (p == "" || is_perfect(p)) return p;
	string answer = "";

	cut t = cutting(p);
	string u = t.first, v = t.second;

	if (is_perfect(u)) return u + solution(v);
	else {
		string w = "(";
		w += solution(v);
		w += ")";
		for (int i = 1; i < u.length() - 1; i++) {
			if (u[i] == OPEN) w += ")";
			else w += "(";
		}
		return w;
	}

	return answer;
}

int main()
{
	string s;
	cin >> s;
	cout << solution(s);
	return 0;
}