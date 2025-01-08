#include <bits/stdc++.h>
#include "../third_party/json/include/nlohmann/json.hpp"

// g++ -o p12b.exe p12b.cpp -I../third_party/json/include

using namespace std;
using json = nlohmann::json;

typedef long long LL;
int debug = 0;


int f(json &j) {
  if (j.is_number()) {
    return j;
  }
  else if (j.is_array()) {
    int sum = 0;
    for (auto &e : j) {
      sum += f(e);
    }
    return sum;
  }
  else if (j.is_object()) {
    bool foundRed = false;
    int sum = 0;
    for (auto &[key, value] : j.items()) {
      if (value.is_string() && value == "red") { foundRed = true; break; }
      else { sum += f(value); }
    }
    return foundRed ? 0 : sum;
  }
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  
  string line;
  int res = 0;
  while (getline(cin, line)) {
    json j = json::parse(line);
    res += f(j);
  }
  cout << res << endl;
}
