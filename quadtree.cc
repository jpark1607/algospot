#include <iostream>
#include <string>
using namespace std;

string upsideDown(string::iterator& iter);

int main(void) {
	int C = 0, c = 0;

	cin >> C;
	
	for (c = 0; c < C; c++) {
		string str;
		string::iterator iter;
		
		cin >> str;

		iter = str.begin();

		cout << upsideDown(iter) << endl;
	}

	return 0;
}

string upsideDown(string::iterator& iter) {
	string str;
	string p1, p2, p3, p4;

	if (*iter == 'x') {
		iter++; p1 = upsideDown(iter);
		iter++; p2 = upsideDown(iter);
		iter++; p3 = upsideDown(iter);
		iter++; p4 = upsideDown(iter);

		str = "x" + p3 + p4 + p1 + p2;
	}
	else {
		str = string(1, *iter);
	}

	return str;
}