vector<string> names;
int n;
string w;
map<string,int> memo;

bool isPrefix(string a, string b)
{
	return a.size() <= b.size() && b.substr(0, a.size())==a;
}

string extend(string a, string b)
{
	return a+b[a.size()];
}

int f(string s)
{
	if (s == w)
	{
		return 1;
	}
	if (memo.count(s) > 0)
	{
		return memo[s];
	}
	int m = f(extend1(s, w));
	int tabs = 0;
	for (int i = 0; i < n; i++)
	{
		if (isPrefix(s, names[i]) && isPrefix(names[i], w))
		{
			tabs++;
			m = min(m, f(names[i])+tabs);
		}
	}
	memo[s] = m;
	return m;
}

int getFewest(vector <string> names_, string w_)
{
	names = names_;
	sort(names.begin(), names.end());
	w = w_;
	n = names.size();

	return f("");
}

Problem Statement

You are in a chat room that supports nickname tab-completion. Suppose the input buffer now contains the string s and you decide to use the completion facility. The first time you press tab you will be shown the lexicographically first element of names that has s as a prefix. Pressing tab again will give the lexicographically second, and so forth. Once the possible options are exhausted the tab key will do nothing. Having found a completion that suits you, you may either press enter to complete the word you are typing, or continue typing characters into the input buffer. If you decide to type characters, they will be appended to the current completion. Your goal is to type the word w, followed by the enter key, using as few keystrokes as possible. Each character and each tab key count as single keystrokes. By interchanging character typing and tab completion sequences as many times as you like, return the fewest number of keystrokes required.
Definition

Class:
CheapestTabComplete
Method:
getFewest
Parameters:
vector <string>, string
Returns:
int
Method signature:
int getFewest(vector <string> names, string w)
(be sure your method is public)


Notes
-
If the buffer is empty, then every element of names is a possible completion for the buffer.
-
The only allowed keystrokes are letters, tabs, and enter.
Constraints
-
names will contain between 0 and 50 elements, inclusive.
-
Each element of names will contain between 1 and 50 lowercase letters ('a'-'z'), inclusive.
-
w will contain between 1 and 50 lowercase letters ('a'-'z'), inclusive.
Examples
0)


{}
"myname"
Returns: 7
Since tab is useless, we type in the 6 letters of myname and then press enter.
1)


{"myn","myname"}
"myname"
Returns: 3
Here we press tab twice, and then enter.
2)


{"abc","ab","abcd","frankies","frank","a","a"}
"frankie"
Returns: 5
Here we type 'f', then tab, then 'i', 'e', and finally enter.
3)


{"a","a","f","f","fr","fr","fra","fra","fran","fran","frank","frank"}
"frankie"
Returns: 8
Due to the weird set of names, tab is of no use.
4)


{"a","a","bcde","bcde","bcde","bcdefghij"}
"bcdefghijk"
Returns: 6

5)


{"aaaa","aaaa","aaaa","aaaa","aaaa"}
"aaaaaaaaaaaaaaaaaaaaaaa"
Returns: 21

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.