//bfs

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

void draw_graph(vector<list<int>>& graph, vector<vector<int>> edge)
{
	for (int i = 0; i < edge.size(); i++) {
		graph[edge[i][0]].push_back(edge[i][1]);
		graph[edge[i][1]].push_back(edge[i][0]);
	}
}

int solution(int n, vector<vector<int>> edge)
{
	int answer = 0;
	vector<list<int>> graph(n + 1);
	vector<bool> is_visited(n + 1, false);
	vector<int> distance(n + 1, 0);
	queue<int> next;

	draw_graph(graph, edge);
	
	next.push(1);
	is_visited[1] = true;
	distance[1] = 0;

	while (!next.empty()) {
		int cur = next.front();
		next.pop();

		for (int link : graph[cur]) {
			if (!is_visited[link]) {
				next.push(link);
				is_visited[link] = true;
				distance[link] = distance[cur] + 1;
			}
		}
	}

	sort(distance.begin() + 1, distance.end(), greater<int>());
	int base = distance[1];
	for (int i = 1; ; i++) {
		if (distance[i] != base) break;
		answer++;
	}

	return answer;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> edge(n + 1, vector<int>(2));

	for (int i = 0; i < 7; i++)
		cin >> edge[i][0] >> edge[i][1];

	cout << solution(n, edge) << endl;

	return 0;
}