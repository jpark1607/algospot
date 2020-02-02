#include <iostream>
#include <vector>
#include <list>
using namespace std;
int clocks[16] = { 0, };
int C = 0, c = 0;
int i = 0, j = 0;
int num = 0;
int bcnt;
vector<vector<int> > buttoncase;

int arr[10][5] = {
	{0, 1, 2, -1, -1},
	{3, 7, 9, 11, -1},
	{4, 10, 14, 15, -1},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
  {0, 2, 14, 15, -1},
  {3, 14, 15, -1, -1},
  {4, 5, 7, 14, 15},
  {1, 2, 3, 4, 5},
  {3, 4, 5, 9, 13}
};

bool pushButtonCase(int type, int cnt);
bool pushButtonLinear();
void initialize();
bool checkClocks();

int main(void) {
	
	cin >> C;

	initialize();

	for (c = 0; c < C; c++) {
		bcnt = 0;
		for (i = 0; i < 16; i++) {
			cin >> num;
			clocks[i] = num;
		}

		if (!pushButtonLinear()) {
			cout << -1 << endl;
			continue;
		}
		
		if (!checkClocks()) {
			cout << -1 << endl;
		}
		else
			cout << bcnt << endl;
	}

	return 0;
}

bool pushButtonLinear() {
	if (clocks[8] != clocks[12])
		return false;

	if (pushButtonCase(4, (12 - clocks[8])))
		return true;

	if (pushButtonCase(2, (12 - clocks[10])))
		return true;

	if (pushButtonCase(1, (12 - clocks[11])))
		return true;

	if (clocks[9] != clocks[13])
		return false;

	if (pushButtonCase(9, (12 - clocks[9])))
		return true;

	if (pushButtonCase(3, (12 - clocks[6])))
		return true;

	if (clocks[4] != clocks[5])
		return false;

	if (pushButtonCase(7, (12 - clocks[7])))
		return true;

	if (pushButtonCase(8, (12 - clocks[5])))
		return true;

	if (clocks[0] != clocks[2])
		return false;

	if (clocks[14] != clocks[15])
		return false;

	if (pushButtonCase(0, (12 - clocks[1])))
		return true;

	if (pushButtonCase(6, (12 - clocks[3])))
		return true;

	if (pushButtonCase(5, (12 - clocks[0])))
		return true;

	return true;
}

bool checkClocks() {
	for (i = 0; i < 16; i++) {
		if (clocks[i] == 12 || clocks[i] == 0)
			continue;
		return false;
	}
	return true;
}

bool pushButtonCase(int type, int diff) {
	vector<int>::iterator iter;
	int cnt = diff / 3;

	iter = buttoncase[type].begin();

	for (; iter != buttoncase[type].end(); iter++) {
		clocks[*iter] = (clocks[*iter] + (cnt * 3)) % 12;
		if (clocks[*iter] == 0)
			clocks[*iter] = 12;
	}
	bcnt += cnt;

	return checkClocks();
}

void initialize() {
	vector<int> ele;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 5; j++) {
			if (arr[i][j] != -1)
				ele.push_back(arr[i][j]);
		}
		buttoncase.push_back(ele);
		ele.clear();
	}
}
