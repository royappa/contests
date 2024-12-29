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
  vector<priority_queue<int,vector<int>,greater<int>>> freeLenPos(10); // free[1] = all the free positions of size 1


  int fileId = 0;
  int filePos = 0;
  for (int i = 0; i < mapLen; i += 2) {
    int fileLen = diskMap[i]-'0';
    idLenPos.insert({fileId, fileLen, filePos});
    filePos += fileLen;
    fileId++;
    if (i != mapLen-1) {
      int freeLen = diskMap[i+1]-'0';
      if (freeLen > 0) {
        freeLenPos[freeLen].push(filePos);
        filePos += freeLen;
      }
    }
  }
  set<tiii> idLenPos2;
  for (auto it = idLenPos.rbegin(); it != idLenPos.rend(); it++) {
    auto [id, len, pos] = *it;
    int minFreePos = 1<<30;
    int minFreeLen = -1;
    for (int freeLen = len; freeLen <= 9; freeLen++) {
      if (!freeLenPos[freeLen].empty() && freeLenPos[freeLen].top() < minFreePos && freeLenPos[freeLen].top() < pos) {
        minFreeLen = freeLen;
        minFreePos = freeLenPos[freeLen].top();
      }
    }
    if (minFreeLen == -1) {
      idLenPos2.insert({id, len, pos});
    }
    else {
      freeLenPos[minFreeLen].pop();
      idLenPos2.insert({id, len, minFreePos});
      if (minFreeLen > len) {
        int newFreeLen = minFreeLen - len;
        freeLenPos[newFreeLen].push(minFreePos+len);
      }
    }
  }
  LL checkSum = 0;
  for (auto it = idLenPos2.begin(); it != idLenPos2.end(); it++) {
    auto [id, len, pos] = *it;
    checkSum +=(LL)id*(LL(len)*(len-1))/2 + (LL)len*pos*id;
  }
  cout << checkSum << endl;
}

