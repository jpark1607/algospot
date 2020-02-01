#include <iostream>
using namespace std;

bool findRight(int x, int y);
bool findDown(int x, int y);
bool findWay(int x, int y);

int arr[100][100];
int N = 0, x = 0, y = 0;

int main(void) {
	int C = 0, c = 0;
	
	cin >> C;

	for (c = 0; c < C; c++) {
		
		cin >> N;

		for (x = 0; x < N; x++) {
			for (y = 0; y < N; y++) {
				cin >> arr[x][y];
			}
		}

		if (findWay(0, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}

bool findRight(int x, int y) {
	if (arr[x][y] == -1)
		return false;

	if (y + arr[x][y] > N - 1)
		return false;

	if (arr[x][y + arr[x][y]] == 0)
		return true;

	return findWay(x, y + arr[x][y]);
}

bool findDown(int x, int y) {
	if (arr[x][y] == -1)
		return false;

	if (x + arr[x][y] > N - 1)
		return false;

	if (arr[x + arr[x][y]][y] == 0)
		return true;

	return findWay(x + arr[x][y], y);
}

bool findWay(int x, int y) {
	bool found = false;

	found = findRight(x, y);
	if (found)
		return found;
	
	found = findDown(x, y);

	if (!found)
		arr[x][y] = -1;

	return found;
}


