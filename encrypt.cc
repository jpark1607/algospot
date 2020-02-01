#include <iostream>
#include <string.h>
using namespace std;

int main(void) {
	int T = 0, t = 0;
	int i = 0;

	cin >> T;

	for (t = 0; t < T; t++) {
		char str[101];
		int len = 0;

		cin >> str;
		len = strlen(str);
		
		for (i = 0; i < len; i += 2)
			cout << str[i];

		for (i = 1; i < len; i += 2)
			cout << str[i];

		cout << endl;
	}

	return 0;
}