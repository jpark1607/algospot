#include <iostream>
using namespace std;

/* Global Variable */
int seq[500];
int cache[500];
int N = 0;

/* Function Declaration */
int getLength(int i); 

/* Main */
int main(void) {
	int C = 0, c = 0;
  int n = 0;
  int max_len;

	cin >> C;

	for (c = 0; c < C; c++) {
    cin >> N;

    for (n = 0; n < N; n++) {
      cin >> seq[n];
      cache[n] = 0;
    }

    /* last value's length is always 1 */
    cache[N - 1] = 1;
    max_len = 1;

    for (n = 0; n < N - 1; n++) {
      max_len = max(max_len, getLength(n));
    }

	  cout << max_len << endl;
	}
	return 0;
}

/* Function Implementation */
int getLength(int i) {
  if (cache[i] > 0) 
    return cache[i];

  int max_len = 0;
  int p = i + 1;

  for ( ; p < N; p++) {
    if (seq[p] > seq[i])
      max_len = max(max_len, getLength(p));
  }

  cache[i] = max_len + 1;
  return cache[i];
}
