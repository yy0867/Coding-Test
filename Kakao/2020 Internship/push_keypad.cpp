#include <string>
#include <utility>
#include <vector>

using namespace std;
enum HAND { LEFT, CENTER, RIGHT };

bool isDigit(char c)
{
	return ('0' <= c && c <= '9') ? true : false;
}

HAND getHand(int n)
{
	if (n == 0 || n % 3 == 2) return CENTER;
	else if (n % 3 == 0) return RIGHT;
	else return LEFT;
}

HAND getCloserHand(pair<int, HAND> left, pair<int, HAND> right, int n)
{
	int l_dist;
	int r_dist;

	if (n == 0) {
		l_dist = abs(3 - left.first);
		r_dist = abs(3 - right.first);
	}
	else {
		l_dist = abs((n / 3) - left.first);
		r_dist = abs((n / 3) - right.first);
	}

	if (left.second == LEFT) l_dist++;
	if (right.second == RIGHT) r_dist++;

	if (l_dist > r_dist) return RIGHT;
	else if (l_dist < r_dist) return LEFT;
	else return CENTER;
}

string solution(vector<int> numbers, string hand)
{
	string answer = "";
	hand = (hand == "right") ? "R" : "L";

	pair<int, HAND> pos_left = make_pair(3, LEFT);
	pair<int, HAND> pos_right = make_pair(3, RIGHT);

	for (int i = 0; i < numbers.size(); i++) {
		int t = numbers[i];
		switch (getHand(t)) {
		case LEFT:
			answer += "L";
			pos_left.first = t / 3;
			pos_left.second = LEFT;
			break;

		case RIGHT:
			answer += "R";
			pos_right.first = (t / 3) - 1;
			pos_right.second = RIGHT;
			break;

		case CENTER:
			HAND close = getCloserHand(pos_left, pos_right, t);
			if (close == LEFT) {
				answer += "L";
				pos_left.first = t == 0 ? 3 : t / 3;
				pos_left.second = CENTER;
			}
			else if (close == RIGHT) {
				answer += "R";
				pos_right.first = t == 0 ? 3 : t / 3;
				pos_right.second = CENTER;
			}
			else {
				answer += hand;
				if (hand == "R") {
					pos_right.first = t == 0 ? 3 : t / 3;
					pos_right.second = CENTER;
				}
				else {
					pos_left.first = t == 0 ? 3 : t / 3;
					pos_left.second = CENTER;
				}
			}

			break;
		}
	}

	return answer;
}

int main()
{
	int n, t;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}

	string s;
	cin >> s;

	cout << solution(v, s);
	return 0;
}