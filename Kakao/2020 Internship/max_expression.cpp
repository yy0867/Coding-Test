#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<long long> num;
vector<char> op, op_list;
vector<vector<char>> op_order;
vector<long long> t_num;
vector<char> t_op;

bool is_exist(vector<char> v, char k)
{
	for (auto c : v) if (c == k) return true;
	return false;
}

void make_order(vector<char> op)
{
	if (op.size() == op_list.size()) {
		op_order.push_back(op);
		return;
	}
	for (char i : op_list) {
		if (!is_exist(op, i)) {
			op.push_back(i);
			make_order(op);
			op.pop_back();
		}
	}
}

void make_list(string exp)
{
	string t = "";
	for (auto i : exp) {
		if ('0' <= i && i <= '9') t += i;
		else {
			op.push_back(i);
			num.push_back(stoi(t));
			t = "";
		}
	}
	num.push_back(stoi(t));
	op_list = op;
	
	sort(op_list.begin(), op_list.end());
	op_list.erase(unique(op_list.begin(), op_list.end()), op_list.end());

	vector<char> v;
	make_order(v);
}

void calculate(int index)
{
	long long c1 = t_num[index], c2 = t_num[index + 1];

	if (t_op[index] == '+') c1 += c2;
	else if (t_op[index] == '-') c1 -= c2;
	else c1 *= c2;

	t_num[index] = c1;
	t_op.erase(t_op.begin() + index);
	t_num.erase(t_num.begin() + index + 1);
}

long long process(vector<char> op_order)
{
	t_num = num;
	t_op = op;
	for (int i = 0; i < op_order.size(); i++) {
		for (int j = 0; j < t_op.size(); j++) {
			if (op_order[i] == t_op[j]) {
				calculate(j);
				j--;
			}
		}
	}

	return t_num[0];
}

long long solution(string expression)
{
	long long answer = 0;

	make_list(expression);
	
	for (vector<char> c : op_order) {
		long long t = abs(process(c));
		answer = answer > t ? answer : t;
	}

	return answer;
}

int main()
{
	string s;
	cin >> s;

	cout << solution(s) << endl;

	return 0;
}