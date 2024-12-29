#include<bits/stdc++.h>
using namespace std;

string c(string s) {
	regex r("(.)\\1{2,}");
	while (regex_search(s, r))
		s = regex_replace(s, r, "", std::regex_constants::format_first_only);
    return s;
}

int main() {
    string inp;
    cin >> inp;

    cout << "C: " << c(inp) << endl;
    return 0;
}