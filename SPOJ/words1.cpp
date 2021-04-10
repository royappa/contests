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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;
int debug=0;

int inDeg[105000];
int outDeg[105000];
int A[30][30];
int V[26];

void dump(int A[30][30])
{
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			printf("%2d", A[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	char buf[1024];

	while (t-- > 0)
	{
		memset(inDeg, 0, sizeof(inDeg));
		memset(outDeg, 0, sizeof(outDeg));
		memset(V, 0, sizeof(V));
		memset(A, 0, sizeof(A));
		int numEdges = 0;
		scanf("%d", &numEdges);
		for (int i = 0; i < numEdges; i++)
		{
			scanf("%s", buf);
			int s = buf[0]-'a';
			int d = buf[strlen(buf)-1]-'a';
			V[s] = V[d] = 1;
			A[s][d] = 1;
			inDeg[d]++;
			outDeg[s]++;
		}
		vector<int> v;
		for (int i = 0; i < 26; i++)
		{
			if (V[i])
				v.push_back(i);
		}
		int n = v.size();

		if (debug)
		{
			printf("%d vertices\n", n);
			for (int i = 0; i < n; i++)
			{
				printf("%c ", char('a'+v[i]));
			}
			printf("\n");
		}

		for (int k = 0; k < 26; k++)
		{
			for (int i = 0; i < 26; i++)
			{
				for (int j = 0; j < 26; j++)
				{
					A[i][j] = A[i][j] || (A[i][k] && A[k][j]);
				}
			}
		}

		if (debug) { dump(A); }

		/*
		A directed graph contains an Eulerian cycle iff (1) it is connected and (2) each vertex has the same in-degree as out-degree.
		A directed graph contains an Eulerian path iff (1) it is connected and (2) all but two vertices have the same in-degree as out-degree, and these two vertices have their in-degree and out-degree differ by one.
		*/
		bool connected = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) continue;
				if (!(A[v[i]][v[j]] || A[v[j]][v[i]]))
				{
					if (debug) printf("%d and %d  (%c and %c) are not connected\n", v[i], v[j], char(v[i]+'a'), char(v[j]+'a'));
					connected = false;
				}
			}
		}

		if (debug) { printf("connected: %d\n", connected); }
		if (!connected) // graph is not connected
		{
			printf("The door cannot be opened.\n");
			continue;
		}
		int odd = 0;
		vector<int> q;
		for (int i = 0; i < n; i++)
		{
			if (inDeg[v[i]] != outDeg[v[i]])
			{
				q.push_back(abs(inDeg[v[i]] - outDeg[v[i]]));
			}
		}
		if (q.size() != 0 && q.size() != 2)
		{
			printf("The door cannot be opened.\n");
		}
		else if (q.size() == 0)
		{
			printf("Ordering is possible.\n");
		}
		else
		{
			if (q[0] == 1 && q[1] == 1)
			{
				printf("Ordering is possible.\n");
			}
			else
			{
				printf("The door cannot be opened.\n");
			}
		}
	}
	return 0;
}
