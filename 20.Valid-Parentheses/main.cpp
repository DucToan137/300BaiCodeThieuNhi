#include<iostream>
#include<string>
#include<stack>
using namespace std;

int count(string n, char c) {
	int count = 0;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] == c) {
			count++;
		}
	}
	return count;
}

bool isValid(string s) {
	if(s.size() % 2 != 0) {
		return false;
	}

	if(s[0] == ')' || s[0] == ']' || s[0] == '}') {
		return false;
	}
	
	int n = s.size();

	if(s[n - 1] == '(' || s[n - 1] == '[' || s[n - 1] == '{') {
		return false;
	}

	if(count(s, '(') != count(s, ')') || count(s, '[') != count(s, ']') || count(s, '{') != count(s, '}')) {
		return false;
	}

	stack<char> st;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			st.push(s[i]);
		}
		else {
			if (s[i] == ')') {
				if (st.top() == '[' || st.top() == '{') {
					return false;
				}
				else {
					while (st.top() != '(') {
						st.pop();
					}
					st.pop();
				}
			}
			else if (s[i] == ']') {
				if (st.top() == '(' || st.top() == '{') {
					return false;
				}
				else {
					while (st.top() != '[') {
						st.pop();
					}
					st.pop();
				}
			}
			else if (s[i] == '}') {
				if (st.top() == '(' || st.top() == '[') {
					return false;
				}
				else {
					while (st.top() != '{') {
						st.pop();
					}
					st.pop();

				}
			}

			if (st.empty()) {
				return true;
			}
		}
	}
	return false;
}


bool isValid1(string s) {
	stack<char> st;
	int n = s.size();

	for (char c:s) {
		if (c == '(' || c == '[' || c == '{') {
			st.push(c);
		}
		else {
			if (st.empty() ||
				(c != ')' && st.top() == '(' ||
					c != ']' && st.top() == '[' ||
					c != '}' && st.top() == '{')) {
				return false;
			}
			st.pop();
		}
	}

	return st.empty();
}

int main() {

	string s = "{}{}{}{}{}{(([[]]))]";
	cout << isValid1(s) << endl;

	return 0;
}