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


vector<string> split_nonre(string s, string sep)
{
	char *sC = (char *) malloc(s.size()+1);
	strcpy(sC, s.c_str());
	char *sepC = (char *) sep.c_str();
	char *status = NULL;

	char *word;
	vector<string> results;
	while ((word = strtok_r(sC, sepC, &status)) != NULL)
	{
		results.push_back(word);
		sC = NULL;
	}
	return results;
}

int A[1200][1200];
int n;
int done[1200];
int indeg[1200];

void dom() // output a sort of "incoming edge dominating set" of current graph
{
	/*
		algorithm
		1. sort all vertices by number of incoming neighbors
		2. initially mark all vertices as done=false
		3. for each vertex v in sorted list
				if done[v] is true then continue
				add v to dominator list
				mark v as dominated, so we don't process him again
				mark every incoming neighbor of v as done
	*/
	vector< pair<int,int> > L;
	for (int i = 1; i <= n; i++)
	{
		indeg[i] = 0;
		done[i] = 0;
		for (int j = 1; j <= n; j++)
		{
			indeg[i] += A[j][i];
		}
		L.push_back(make_pair(indeg[i], i));
	}
	sort(L.rbegin(), L.rend());
	vector<int> dominators;
	for (int k = 0; k < L.size(); k++)
	{
		int v = L[k].second;
		if (done[v]) continue;
		done[v] = 1;
		dominators.push_back(v);
		for (int j = 1; j <= n; j++)
		{
			if (A[j][v])
				done[j] = 1;
		}
	}
	int dn = dominators.size();
	cout << dn << endl;
	for (int i = 0; i < dn; i++)
	{
		cout << dominators[i];
		if (i < dn-1)
			cout << " ";
	}
	cout << endl;

}

int main()
{
	char buf[10000];
	int T;
	memset(buf, '\0', sizeof(buf));
	cin.getline(buf, sizeof(buf));
	string line(buf);
	T = atoi(line.c_str());
	cin.getline(buf, sizeof(buf));
	for (int t = 0; t < T; t++)
	{
		memset(A, 0, sizeof(A));
		memset(buf, '\0', sizeof(buf));
		cin.getline(buf, sizeof(buf));
		line = string(buf);
		n = atoi(line.c_str());
		for (int i = 1; i <= n; i++)
		{
			memset(buf, '\0', sizeof(buf));
			cin.getline(buf, sizeof(buf));
			line = string(buf);
			vector<string> w = split_nonre(line, " ");
			for (int j = 0; j < w.size(); j++)
			{
				if (w[j].size() == 0) continue;
				int nbr = atoi(w[j].c_str());
					A[i][nbr] = 1;
			}
		}
		cin.getline(buf, sizeof(buf)); // blank line
		/*
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << A[i][j] << " " ;
			}
			cout << endl;
		}
		*/
		dom();
	}



}


