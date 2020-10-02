#include <iostream>
#include <string.h>
using namespace std;

int main(void) {
	int N = 0, n = 0;

	cin >> N;

	for (n = 1; n <= N; n++) {
		int M = 0;
		char str[81] = "";
		int len;

		cin >> M >> str;
		len = strlen(str);

		strncpy(str + (M - 1), str + M, len - M);
		str[len - 1] = '\0';

		cout << n << " " << str << endl;
	}

	return 0;
}
