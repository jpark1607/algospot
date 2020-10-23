#include <iostream>
using namespace std;

/* Main */
int main(void) {
	int C = 0, c = 0;

	cin >> C;

	for (c = 0; c < C; c++) {
    int A, B;

    cin >> A >> B;

    if (A > B)
      cout << 0 << endl;
    else if (A == B)
      cout << 4 << endl;
    else
      cout << 4 + (B - A) << endl;
	}
	return 0;
}

