#include <bits/stdc++.h>
#include <fstream>
#include <openssl/md5.h>
#include <openssl/md5.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>

using namespace std;
typedef long long LL;
int debug = 0;


string computeMD5(const string& input) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), digest);

    // Convert the hash to a readable hexadecimal string
    ostringstream md5String;
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        md5String << hex << setw(2) << setfill('0') << static_cast<int>(digest[i]);
    }
    return md5String.str();
}

int main(int argc, char *argv[]) {
    int num = atoi(argv[1]); // 5 zeroes answer is 254575
    string input = argv[2];
    string md5;
    while ((md5 = computeMD5(input+to_string(num))).substr(0, 6) != "000000") {
      num++;
      if (num % 1000 == 0) cout << num << endl;
    }
    cout << num << endl;
    return 0;
}
