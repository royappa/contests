#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

vector<string> split_nonre(string s, string sep)
{
	char *sC = (char *) malloc(s.size()+1);
	strcpy(sC, s.c_str());
	char *sepC = (char *) sep.c_str();
	
	char *word;
	vector<string> results;
	while ((word = strtok(sC, sepC)) != NULL)
	{
		results.push_back(word);
		sC = NULL;
	}
	return results;
}

void getInput(vector<string> &v) {
  string line;
  // goddamn c++ returns a \r on the end of line!!!
  while (getline(cin, line)) {
    while (line[line.size()-1] == '\n' || line[line.size()-1] == '\r') 
      line = line.substr(0, line.size()-1);
    v.push_back(line);
  }
  return;
}

vector<pair<LL,LL>> runMap(vector<pair<LL,LL>> &ranges, vector<vector<LL>> &mp) {
  vector<pair<LL,LL>> newRanges;
  for (auto range : ranges) {
    auto [rstart, rlen] = range;
    for (auto m : mp) {
      LL dst = m[0], src = m[1], len = m[2];
      // overlap of [a,b] and [x,y]  iff (a <= y && x <= b)
      LL rend = rstart+rlen-1;
      LL srcend = src+len-1;
      LL dstend = dst+len-1;
      if (rstart <= srcend && src <= rend) {
        LL ostart = max(rstart, src);
        LL oend = min(srcend, rend);
        LL olen = oend-ostart+1;
        LL dstart = dst+(ostart-src);
        newRanges.push_back({dstart, olen});
      }
    }
  }
  // now calculate all the remaining pieces that didn't get mapped
  vector<pair<LL,LL>> remain;
  for (auto range : ranges) {
    auto [rstart, rlen] = range;
    remain.push_back({rstart, rstart+rlen-1});
  }
  for (auto m : mp) {
    LL cutstart = m[1], cutend = m[1]+m[2]-1;
    vector<pair<LL,LL>> temp;
    for (auto range: remain) {
      // pieces = range - m;  either a left piece, a right piece, or both, or none      
      auto [rstart, rend] = range;
      if (cutend < rstart || cutstart > rend) { // whole range is left
        temp.push_back(range);
      }
      else if (cutstart <= rstart && rend <= cutend) { // range entirely inside cut, so nothing left
        continue;
      }
      else if (cutstart <= rstart && cutend < rend) { // piece of range to the right of cut
        temp.push_back({cutend+1, rend});
      }
      else if (cutstart > rstart && cutend >= rend) { // piece of range to the left of cut
        temp.push_back({rstart, cutstart-1});
      }
    }
    remain = temp;
  }
  // add all the remaining pieces to newRanges;
  for (auto r : remain) {
    newRanges.push_back({r.first, r.second-r.first+1});
  }
  return newRanges;
}

main() {
  vector<string> v;
  getInput(v);
  int n = v.size();

  vector<string> s = split_nonre(v[0].substr(v[0].find(':')+2), " ");
  vector<LL> seeds(s.size());
  transform(s.begin(), s.end(), seeds.begin(), [](const string &str) { return stoll(str); });

  //for (auto z : seeds) { cout << z << " "; }; cout << endl;

  v.push_back("");
  vector<vector<vector<LL>>> maps(7);
  int p = 3;
  for (int i = 0; i < 7; i++) {
      while (v[p] != "") {
        LL a, b, c;
        vector<LL> range(3);
        s = split_nonre(v[p], " ");
        transform(s.begin(), s.end(), range.begin(), [](const string &str) { return stoll(str); });
        maps[i].push_back(range);
        p++;
      }
      p += 2;
  }
  vector<LL> loc(seeds.size());
  vector<pair<LL,LL>> ranges;
  for (int i = 0; i < seeds.size() / 2; i++) {
    // get loc of seeds[i]
    LL cur = seeds[2*i], len = seeds[2*i+1];
    ranges.push_back({cur, len});
  }

  for (int j = 0; j < 7; j++) {
    ranges = runMap(ranges, maps[j]);
    // cout << j << endl;
    for (auto r : ranges) {
      // cout << r.first << " " << r.second << endl;
    }
  }
  LL res = ranges[0].first;
  for (int i = 1; i < ranges.size(); i++) {
    res = min(res, ranges[i].first);
  }
  cout << res << endl;
  exit(0);
}
