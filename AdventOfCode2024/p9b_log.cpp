#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;

int main()
{
  string line;
  

  string diskMap;
  getline(cin, diskMap);

  int mapLen = diskMap.size();

  set<tiii> idLenPos;
  set<pii> freeLenPos;

  int fileId = 0;
  int filePos = 0;
  for (int i = 0; i < mapLen; i += 2) {
    int fileLen = diskMap[i]-'0';
    idLenPos.insert({fileId, fileLen, filePos});
    filePos += fileLen;
    fileId++;
    if (i != mapLen-1) {
      int freeLen = diskMap[i+1]-'0';
      freeLenPos.insert({freeLen, filePos});
      filePos += freeLen;
    }
  }
  set<tiii> idLenPos2;
  for (auto it = idLenPos.rbegin(); it != idLenPos.rend(); it++) {
    auto [id, len, pos] = *it;
    auto it2 = freeLenPos.lower_bound({len, 0});
    if (it2 == freeLenPos.end()) {
      idLenPos2.insert({id, len, pos});
    }
    else {
      if (it2->second >= pos) {
        idLenPos2.insert({id, len, pos});
      }
      else {
        auto best = it2;
        while (it2 != freeLenPos.end()) {
          if (it2->second < best->second) {
            best = it2;
          }
          it2++;
        }
        auto [freeLen, freePos] = *best;
        if (freeLen >= len) {
          idLenPos2.insert({id, len, freePos});
          freeLenPos.erase(best);
          if (freeLen > len) {
            int freeLeftLen = freeLen - len;
            int freeLeftPos = freePos + len;
            freeLenPos.insert({freeLeftLen, freeLeftPos});
          } 
        }
      }
    }
  }
  LL checkSum = 0;
  for (auto it = idLenPos2.begin(); it != idLenPos2.end(); it++) {
    auto [id, len, pos] = *it;
    for (int i = 0; i < len; i++) {
      checkSum += (LL(pos)+LL(i))*LL(id);
    }
  }
  cout << checkSum << endl;
}

