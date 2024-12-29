#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;


int main()
{
  string line;
  

  string diskMap;
  getline(cin, diskMap);

  int mapLen = diskMap.size();
  int id = 0;
  vector<int> disk;
  for (int i = 0; i < mapLen; i += 2) {
    for (int j = 0; j < diskMap[i]-'0'; j++) {
      disk.push_back(id);
    }
    if (i != mapLen-1) {
      for (int j = 0; j < diskMap[i+1]-'0'; j++) {
        disk.push_back(-1);
      }
    }
    id++;
  }
  int diskLen = disk.size();
  int end = diskLen - 1;
  int free = 0;
  while (free < end) {
    while (disk[free] != -1) {
      free++;
    }
    while (disk[end] == -1) {
      end--;
    }
    swap(disk[free], disk[end]);
    free++;
    end--;
  }
  LL checkSum = 0;
  for (int i = 0; i < diskLen; i++) {
    if (disk[i] != -1) {
      checkSum += i*disk[i];
    }
  }
  cout << checkSum << endl;
}

