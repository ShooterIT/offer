/*
*
* ÃæÊÔÌâ42£º·­×ªµ¥´ÊË³Ğò VS ×óĞı×ª×Ö·û´®
*
*/

#include <string>

using namespace std;

void reverse(string &str, int beg, int end)
{
	while (end > beg){
		swap(str[beg], str[end]);
		end--;
		beg++;
	}
}

string ReverseSentence(string str) 
{
	if (!str.size()) {
		return str;
	}
	reverse(str, 0, str.size() - 1);
	int start = 0; 
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			reverse(str, start, i - 1);
			start = i + 1;
		}
	}
	reverse(str, start, str.size() - 1);

	return str;
}

string LeftRotateString(string str, int n) 
{
	if (!str.size() || n > str.size() || n < 1) {
		return str;
	}
	
	reverse(str, 0, str.size() - 1);
	reverse(str, 0, str.size() - n - 1);
	reverse(str, str.size() - n, str.size() - 1);

	return str;
}