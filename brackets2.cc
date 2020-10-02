#include <iostream>
#include <stack>
using namespace std;

/* Global Variable */
const char startchr[3] = {'(', '{', '['};
const char endchr[3] = {')', '}', ']'};

/* Function Declaration */
bool checkBracket(string str);
int getStartIndex(char chr); 
int getEndIndex(char chr); 

/* Main */
int main(void) {
	int C = 0, c = 0;

	cin >> C;

	for (c = 0; c < C; c++) {
    string str;
    cin >> str;
    cout << (checkBracket(str) ? "YES" : "NO") << endl;
	}
	return 0;
}

/* Function Implementation */
bool checkBracket(string str) {
  stack<char> bracket;
  int startno = 0, endno = 0;
  char chr;

  for (int i = 0; i < str.length(); i++) {
    startno = getStartIndex(str[i]);
    if (startno >= 0) {
      bracket.push(str[i]);
      continue;
    }

    endno = getEndIndex(str[i]);
    if (endno >= 0) {
      if (bracket.size() == 0)
        return false;

      chr = bracket.top();

      if (chr == startchr[endno]) {
        bracket.pop();
        continue;
      }
      else
        return false;
    }
  }
  if (bracket.size() == 0)
    return true;
  return false;
}

int getStartIndex(char chr) {
  for (int i = 0; i < 3; i++) {
    if (startchr[i] == chr)
      return i;
  }
    return -2;
}
int getEndIndex(char chr) {
  for (int i = 0; i < 3; i++) {
    if (endchr[i] == chr)
      return i;
  }
  return -1;
}
