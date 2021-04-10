#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	char *s = "T4 .:x8:.NS29.x16.NS28:x19:.NS27.x23:NS26:x25:NS26x26X1:NS26x3C3x8C4x9:NS25.x2:S3C2x5:S5:x8NS25:x2S2x1.S2x4:S2x2.S2x8NS25:x2 x3S2x4: x4S2:x7NS25'x2 'x2S2x4:. x2'S2x8NS26x2 C6x2C5.S3x8NS26x2C5.C4.C7x8NS26:x1'C4'C4'C5':x9.NS26:x2.C12'S3x10NS26:x2: 'C8'S5:x10.NS25.x2S5'C4'S8'x10.NS23.x4S21'x9.NS21.x4S25'x9.NS19.x5:S26x10.NS18.x5:'S26x11.NS17.x6C3.S11.S7D2C3U1x11:.NS16.x7Q2S6'C3Q2S12Q2C2x12.NS16x6S12:S18'C2x12NS15:x4:'S12:S20'x12:NS14.x5S14:S21C2x12NS14x4:'S36C2x12NS14x4S15.S22C2x12.NS10.:x6S15:S22C2x12C2NS10x8S15:S22C2x13:NS10x8S15:S22C2x13:NS10':x6S15'S22C2x12:'NS12.:. x2:.S35.:x13'NS10C6.'x2:.S12:S18.C2 x11':NS2.C15.'x4.S28C4'x8'C3.NS2C18.'x5S26C5.'.x2.'C6.NS2C20.'x4:.S23C7.Q2C9NS2'C21.'x2:'S21.'C20D2NS4C21.'x2S20.C2 C23NS2.C23. x2S15.C2x4 C23NS2C25.'x3D2S8.C2x7 C20'NS2'C25 x23 C17'NS4'C23 x23 C15'NS8'C19U1x6C2Q3C2x10 'C12'NS13Q2:.C10'S24B1.U1'C6Q2N";

	char *t = s;
	while (*t)
	{
		char c = *t;
		if (c == 'N') cout << '\n';
		else if (isalpha(c))
		{
			int v = 0;
			t++;
			while (isdigit(*t))
				v = v*10+(*t++-'0');
			cout << string(v, c=='T'?'\t':c=='S'?' ':c=='Q'?'\'':c=='C'?':':c=='D'?'.':c=='X'?'X':c=='U'?'_':c=='B'?'`':'x');
			continue;
		}
		else
			cout << c;
		t++;
	}
}


