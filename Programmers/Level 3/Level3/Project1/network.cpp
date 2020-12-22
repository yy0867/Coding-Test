//bfs

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;
	vector<int> network(n);
	queue<int> next;

	for (int i = 0; i < n; i++) {
		if (network[i] == 0)
			answer++;
		else {
			continue;
		}
		next.push(i);
		network[i] = answer;

		while (!next.empty()) {
			int cur = next.front();
			next.pop();

			for (int j = 0; j < n; j++) {
				if (computers[cur][j] == 1 && network[j] == 0) {
					next.push(j);
					network[j] = answer;
				}
			}
		}
	}

	return answer;
}

/*int main() 
{
	int n;
	cin >> n;

	vector<vector<int>> computers(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> computers[i][j];

	cout << solution(n, computers) << endl;

	return 0;
}*/