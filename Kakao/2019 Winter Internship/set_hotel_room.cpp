#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> m;

long long next_room(long long num)
{
	if (m[num] == 0) return num;
	return m[num] = next_room(m[num]);
}

vector<long long> solution(long long k, vector<long long> room_number)
{
	vector<long long> answer;

	for (auto i : room_number) {
		long long num = next_room(i);
		answer.push_back(num);
		m[num] = num + 1;
	}

	return answer;
}