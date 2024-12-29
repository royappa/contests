#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

typedef pair<int,int> pii;

int main()
{
  string line;
  

  string diskMap;
  getline(cin, diskMap);

  int mapLen = diskMap.size();
  int id = 0;
  map<int,int> idToLen;
  map<int,int> idToPos;
  map<int,int> freePosToLen;
  int pos = 0;
  for (int i = 0; i < mapLen; i += 2) {
    int fileLen = diskMap[i]-'0';
    idToLen[id] = fileLen;
    idToPos[id] = pos;
    pos += fileLen;
    id++;
    if (i != mapLen-1) {
      int freeLen = diskMap[i+1]-'0';
      freePosToLen[pos] = freeLen;
      pos += freeLen;
    }
  }
  map<int,int> idToLen2, idToPos2;
  for (auto it = idToLen.rbegin(); it != idToLen.rend(); it++) {
    int id = it->first;
    int fileLen = it->second;
    int filePos = idToPos[id];
    bool moved = false;
    for (auto it2 = freePosToLen.begin(); it2 != freePosToLen.end(); it2++) {
      int freePos = it2->first;
      if (freePos > filePos) {
        break;
      }
      int freeLen = it2->second;
      if (freeLen >= fileLen) {
        idToPos2[id] = freePos;
        idToLen2[id] = fileLen;
        freePosToLen.erase(it2);
        if (freeLen > fileLen) {
          int freeLeftLen = freeLen - fileLen;
          int freeLeftPos = freePos + fileLen;
          freePosToLen[freeLeftPos] = freeLeftLen;
        }
        moved = true;
        break;
      }
    }
    if (!moved) {
      idToLen2[id] = fileLen;
      idToPos2[id] = filePos;
    }
  }
  LL checkSum = 0;
  for (auto it = idToPos2.begin(); it != idToPos2.end(); it++) {
    id = it->first;
    int filePos = it->second;
    int fileLen = idToLen2[id];
    for (int i = 0; i < fileLen; i++) {
      checkSum += LL(filePos+i)*LL(id);
    }
  }
  cout << checkSum << endl;
}

