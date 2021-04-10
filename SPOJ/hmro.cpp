// WORKING DISJOINT SET UNION FIND UNION-FIND
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
#define debug 0

char pesel[100001][12];
char   mro[100001][8];
//char mro_orig[100001][5];

int pind[404][100000], mind[600000];
//int p_orig[100001];

int pmhash[100001];

char used[1000000];

int tree[100001][4]; // 0 = parent, 1 = rank, 2 = canonical representative

int uf_find(int x)
{
	if (tree[x][0] == 0)
	{
		return x;
	}
	tree[x][0] = uf_find(tree[x][0]);
	tree[x][2] = tree[tree[x][0]][2];
	return tree[x][0];
}

int main()
{
	int t;
	char buf[24];
	gets(buf);
	//sscanf(buf, "%d", &t);
	t = atoi(buf);

	while (t-- > 0)
	{
		int p;
		gets(buf);
		//sscanf(buf, "%d", &p);
		p = atoi(buf);
		int k = 1;
		memset(used, 0, sizeof(used));
		int r, c;

		for (int i = 0; i < p; i++)
		{
			gets(buf);
			//int r = ((buf[2]-'0')*10+buf[3]-'0')*31+(buf[4]-'0')*10+(buf[5]-'0');
			r = buf[2]*310+buf[3]*31+buf[4]*10+buf[5]-16896;

			//int c = (buf[6]-'0')*10000+(buf[7]-'0')*1000+(buf[8]-'0')*100+(buf[9]-'0')*10+(buf[10]-'0');
			c = buf[6]*10000+buf[7]*1000+buf[8]*100+buf[9]*10+buf[10]-533328;
			pind[r][c] = i;
			//memcpy(pesel[i], &buf[0], 12);

			*(long long *)&pesel[i][0] = *(long long *)&buf[0];
			*(int *)&pesel[i][8] = *(int *)&buf[8];

			pesel[i][11] = '\0';
			/*
			pesel[i][0]=buf[2];
			pesel[i][1]=buf[3];
			pesel[i][2]=buf[4];
			pesel[i][3]=buf[5];
			pesel[i][4]=buf[6];
			pesel[i][5]=buf[7];
			pesel[i][6]=buf[8];
			pesel[i][7]=buf[9];
			pesel[i][8]=buf[10];
			pesel[i][9] = '\0';
			*/


			//int mhash = (buf[12]-'A')*26*26*26+(buf[13]-'A')*26*26+(buf[14]-'A')*26+(buf[15]-'0');
			int mhash = buf[12]*26*26*26+buf[13]*26*26+buf[14]*26+buf[15]-(65*26*26*26+65*26*26+65*26+48);

			//memcpy(mro_orig[i], &buf[12], 4);
			//*(int *)&mro_orig[i][0] = *(int *)&buf[12];
			//mro_orig[i][5] = '\0';

			pmhash[i] = mhash;

			if (used[mhash])
			{
				//p_orig[i] = mind[mhash];
				continue;
			}
			//p_orig[i] = k;
			used[mhash] = 1;
			//memcpy(mro[k], &buf[12], 4);
			*(int *)&mro[k] = *(int *)&buf[12];
			mro[k][5] = '\0';
			mind[mhash] = k++;
		}

		int z;
		gets(buf);
		//sscanf(buf, "%d", &z);
		z = atoi(buf);
		memset(tree, 0, sizeof(tree));
		for (int i = 1; i <= k; i++)
		{
			tree[i][2] = i;
		}

		char os[24];
		for (int i = 0; i < z; i++)
		{
			gets(buf);
			//int oldi = mind[(buf[0]-'A')*26*26*26+(buf[1]-'A')*26*26+(buf[2]-'A')*26+(buf[3]-'0')];
			int oldi = mind[buf[0]*26*26*26+buf[1]*26*26+buf[2]*26+buf[3]-(65*26*26*26+65*26*26+65*26+48)];
			//int newi = mind[(buf[5]-'A')*26*26*26+(buf[6]-'A')*26*26+(buf[7]-'A')*26+(buf[8]-'0')];
			int newi = mind[buf[5]*26*26*26+buf[6]*26*26+buf[7]*26+buf[8]-(65*26*26*26+65*26*26+65*26+48)];
			int oldroot = uf_find(oldi);
			int newroot = uf_find(newi);
			if (debug) printf("%s(%d,%d) %s(%d,%d)\n", mro[oldi], oldi, oldroot, mro[newi], newi, newroot);
			if (tree[oldroot][1] > tree[newroot][1])
			{
				tree[newroot][0] = oldroot;
			}
			else if (tree[oldroot][1] < tree[newroot][1])
			{
				tree[oldroot][0] = newroot;
			}
			else
			{
				tree[newroot][0] = oldroot;
				tree[oldroot][1]++;
			}
			tree[oldroot][2] = tree[newroot][2];
			if (debug)
			{
				printf("merging %s and %s -> %s\n", mro[oldroot], mro[newroot], mro[tree[newroot][2]]);
			}
		}

		gets(buf);
		//sscanf(buf, "%d", &p);
		p = atoi(buf);

		for (int i = 0; i < p; i++)
		{
			gets(buf);
			//int r = ((buf[2]-'0')*10+buf[3]-'0')*31+(buf[4]-'0')*10+(buf[5]-'0');
			r = buf[2]*310+buf[3]*31+buf[4]*10+buf[5]-16896;
			//int c = (buf[6]-'0')*10000+(buf[7]-'0')*1000+(buf[8]-'0')*100+(buf[9]-'0')*10+(buf[10]-'0');
			c = buf[6]*10000+buf[7]*1000+buf[8]*100+buf[9]*10+buf[10]-533328;
			int pi = pind[r][c];
			//char *s = mro_orig[pi];
			//char *s = mro[p_orig[pi]];
			//int mi = mind[(s[0]-'A')*26*26*26+(s[1]-'A')*26*26+(s[2]-'A')*26+(s[3]-'0')];
			int mi = mind[pmhash[pi]];
			int mroot = uf_find(mi);
			int mroot_parent = tree[mroot][2];
			//if (debug)  printf("i = %d buf = %s\npi = %d s = [%s] mi = %d mroot = %d mroot_parent = %d\n", i, buf, pi, s, mi, mroot, mroot_parent);
			printf("%s %s\n", pesel[pi], mro[mroot_parent]);
			//memcpy(os, pesel[i], 11);
			//os[11] = ' ';
			//memcpy(&os[12], mro[mroot_parent], 5);
			/*
			*(long long *)&os[0] = *(long long *)&pesel[i][0];
			*(int *)&os[8] = *(int *)&pesel[i][8];
			os[11] = ' ';
			*(long long *)&os[12] = *(long long *)&mro[mroot_parent][0];
			puts(os);
			*/
		}
		gets(buf);
		printf("\n");
	}

	return 0;
}
