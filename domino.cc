#include <iostream>
#include <string>
using namespace std;
/* Main */
int main(void) {
  int N = 0;
  int i = 0;
  int j = 0;
  int sum = 0;

  cin >> N;

  for (i = 1; i <= N; i++) {
    for (j = 0; j <= i; j++) {
      sum += i + j;
    }
  }

  cout << sum << endl;
	return 0;
}

