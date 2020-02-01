#include <iostream>
#include <list>

using namespace std;


int main(void) {
	int C = 0, c = 0;
	int N = 0, n = 0;
	int num = 0;

	cin >> C;

	for (c = 0; c < C; c++) {
		list<int> list1;
		list<int> list2;
		list<int>::iterator iter1;
		list<int>::iterator iter2;

		cin >> N;
		
		if (N == 0) {
			cout << 0 << endl;
		}
		cin >> num;
		if (N == 1) {
			cout << 1 << endl;
		}

		list1.push_back(num);
		iter1 = list1.begin();

		for (n = 1; n < N; n++) {
			cin >> num;
			if (num > *iter1) {
				list1.push_back(num);
				iter1++;
			}
			else {
				list2.push_back(num);
				iter2 = list2.begin();
				n++;
				break;
			}
		}

		for (; n < N; n++) {
			cin >> num;

			if (num > *iter1 || num > *iter2) {
				if (num > *iter1) {
					list1.push_back(num);
					iter1++;
				}
				if (num > *iter2) {
					list2.push_back(num);
					iter2++;
				}
				continue;
			}
			else if (*iter1 >= num && *iter2 >= num) {
				if (list2.size() > list1.size()) {
					list1.swap(list2);
					iter1 = iter2;
				}

				list2.clear();
				list2.push_back(num);
				iter2 = list2.begin();
			}
		}
		
		cout << (list1.size() > list2.size() ? list1.size() : list2.size()) << endl;

	}

	return 0;
}