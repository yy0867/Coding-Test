#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Dir { UP, LEFT, DOWN, RIGHT };

int max_cost;
vector<vector<int>> field;

bool is_inside(int r, int c) 
{
	if ((0 <= r && r < field.size()) && (0 <= c && c < field.size())) return true;
	return false;
}

bool is_finish(int r, int c)
{
	return (r == field.size() - 1 && c == field.size() - 1);
}

void tracking(Dir dir, int r, int c, int cost)
{
	if (!is_inside(r, c)) return;
	if (is_finish(r, c)) {
		max_cost = cost > max_cost ? cost : max_cost;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if ((i + 2) % 4 == dir % 4) continue;
		else if (i == dir) {
			if (dir == UP) tracking(UP, r - 1, c, cost + 100);
			else if (dir == DOWN) tracking(DOWN, r + 1, c, cost + 100);
			else if (dir == LEFT)tracking(LEFT, r, c - 1, cost + 100);
			else tracking(RIGHT, r, c + 1, cost + 100);
		}
		else {
			if (dir == UP) tracking(UP, r - 1, c, cost + 600);
			else if (dir == DOWN) tracking(DOWN, r + 1, c, cost + 600);
			else if (dir == LEFT)tracking(LEFT, r, c - 1, cost + 600);
			else tracking(RIGHT, r, c + 1, cost + 600);
		}
	}
}

int solution(vector<vector<int>> board)
{
	int answer = 0;
	field = board;

	tracking(RIGHT, 0, 1, 100);

	answer = max_cost;
	return answer;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	cout << solution(board) << endl;

	return 0;
}