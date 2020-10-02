#include <iostream>
#include <list>
#include <iterator>
using namespace std;

/* Main */
int main(void) {
	int C = 0, c = 0;
  int N = 0, n = 0;
  int K = 0, k = 0;

	cin >> C;

	for (c = 0; c < C; c++) {
    list<int> clist;
    list<int>::iterator iter;
    int num1 = 0, num2 = 0;
    cin >> N >> K;

    /* for convenience insert : start on 1 */
    for (n = 1; n <= N; n++) {
      clist.push_back(n);
    }

    iter = clist.begin();
    while (clist.size() > 2) {
      iter = clist.erase(iter);
      k = 1;

      if (iter == clist.end())
        iter = clist.begin();

      while (k != K) {
        ++iter;
        ++k;

        if (iter == clist.end())
          iter = clist.begin();
      }
    }

    cout << clist.front() << " ";
    clist.pop_front();
    cout << clist.front() << endl;
    clist.pop_front(); // not nessesary
	}

	return 0;
}
