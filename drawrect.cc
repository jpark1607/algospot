#include <iostream>
#include <math.h>

using namespace std;

int getLength(pair<int, int> f, pair<int, int> s);
pair<int, int> makeResult(pair<int, int> pmain, pair<int, int> p1, pair<int, int> p2);

int main(void) {
	int T = 0, t = 0;

	cin >> T;
	for (t = 0; t < T; t++) {
		pair<int, int> p1;
		pair<int, int> p2;
		pair<int, int> p3;
		pair<int, int> res;
		int r12, r23, r31;

		int num1, num2;

		cin >> num1 >> num2;
		p1 = make_pair(num1, num2);
		cin >> num1 >> num2;
		p2 = make_pair(num1, num2);
		cin >> num1 >> num2;
		p3 = make_pair(num1, num2);

		r12 = getLength(p1, p2);
		r23 = getLength(p2, p3);
		r31 = getLength(p3, p1);

		if (r12 == (r23 + r31)) {
			res = makeResult(p3, p1, p2);
		}
		else if (r23 == (r12 + r31)) {
			res = makeResult(p1, p2, p3);
		}
		else if (r31 == (r12 + r23)) {
			res = makeResult(p2, p1, p3);
		}

		cout << res.first << " " << res.second << endl;
	}

	return 0;
}

int getLength(pair<int, int> f, pair<int, int> s) {
	int res = 0;
	res = pow(f.first - s.first, 2) + pow(f.second - s.second, 2);
	return res;
}

pair<int, int> makeResult(pair<int, int> pmain, pair<int, int> p1, pair<int, int> p2) {
	int diffx = 0, diffy = 0;

	diffx = pmain.first - p1.first;
	diffy = pmain.second - p1.second;

	return make_pair(p2.first - diffx, p2.second - diffy);
}