#include <iostream>
using namespace std;
#define MOD 1000000007

int pibo(int n);

int cache[101] = { 0, };


/* 사실 피보나치 */
int main(void) {
	int C = 0, c = 0;
	int N = 0;

	cache[0] = 1;
	cache[1] = 1;
	cache[2] = 2;

	cin >> C;
	for (c = 0; c < C; c++) {
		cin >> N;
		cout << pibo(N) << endl;
	}
	
	return 0;
}

int pibo(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;

	if (cache[n] > 0)
		return cache[n];
	
	cache[n] = (pibo(n - 1) + pibo(n - 2)) % MOD;

	return cache[n];
}