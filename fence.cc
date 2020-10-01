#include <iostream>
#include <vector>
using namespace std;

vector<int> fences;

int returnMax(int l, int r); 

int main(void) {
	int C = 0, c = 0;
  int N = 0, n = 0;
  int v = 0;
  int max_val = 0;

	cin >> C;

	for (c = 0; c < C; c++) {
    cin >> N;
    fences.clear();

    for (n = 0; n < N; n++) {
      cin >> v;
      fences.push_back(v);
    }

    max_val = returnMax(0, N - 1);

	  cout << max_val << endl;
	}
	return 0;
}


int returnMax(int l, int r) {
  if (l == r) 
    return fences[l];

  int m = (l + r) / 2;
  int max_val = max(returnMax(l, m), returnMax(m + 1, r));
  int pl = m, pr = m + 1;
  int h = min(fences[m], fences[m + 1]);

  max_val = max(max_val, h * 2);

  while (l < pl || r > pr) {
    if (r > pr && (l == pl || fences[pl - 1] < fences[pr + 1])) {
      pr++;
      h = min(h, fences[pr]);
    }
    else {
      pl--;
      h = min(h, fences[pl]);
    }

    max_val = max(max_val, (pr - pl + 1) * h);
  }
  
//  cout << l << " " << r << " " << max_val << endl;
  return max_val;
}
