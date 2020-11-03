#include <string>
#include <vector>

using namespace std;

int find(vector<vector<int>> board, int move)
{

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i][move] != 0) {
			return i;
		}
	}

	return -1;
}

bool is_remove(vector<int>& basket)
{
	if (basket.size() < 2) return false;

	int size = basket.size();

	if (basket[size - 1] == basket[size - 2]) {
		basket.pop_back();
		basket.pop_back();
		return true;
	}
	return false;
}

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;
	int res = 0;

	vector<int> basket;

	for (int i = 0; i < moves.size(); i++) {
		res = find(board, moves[i] - 1);

		if (res >= 0) {
			basket.push_back(board[res][moves[i] - 1]);
			board[res][moves[i] - 1] = 0;

			answer += is_remove(basket);
		}
	}

	return answer * 2;
}