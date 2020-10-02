#include <iostream>
#include <queue>
using namespace std;

/* Global Variable */

/* Function Declaration */
static long makeValue(unsigned long val) {
  return ((val * 214013) + 2531011) % 4294967296;
}
static int makeSignal(unsigned long val) {
  return (int) ((val % 10000) + 1);
}

/* Main */
int main(void) {
	int C = 0, c = 0;
  int K = 0;
  int N = 0, n = 0;

	cin >> C;

	for (c = 0; c < C; c++) {
    unsigned long val = 1983; // first value
    int sig;
    int sum = 0;
    int count = 0;
    queue<int> signals;
    cin >> K >> N;

    for (n = 0; n < N; n++) {
      sig = makeSignal(val); 
      sum += sig;
      signals.push(sig);

      while (sum > K) {
        sum -= signals.front();
        signals.pop();
      }

      if (sum == K) {
        count++;
        sum -= signals.front();
        signals.pop();
      }

      val = makeValue(val);
    }

    cout << count << endl;
	}
	return 0;
}
