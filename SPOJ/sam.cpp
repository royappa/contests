// correct, debugged, efficient max Heap class with O(n) operations INCLUDING, FIND and UPDATE
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

using namespace std;
int debug = 0;

#define MAX_TIME	500001
int vp[MAX_TIME];

int last[101000], next[501000];

typedef struct { int node, value; } SimpleHeapNode;

class SimpleHeap
{

public:
	SimpleHeapNode heap[101000]; // maximum number of items in the heap should be <= 100,000
	int heapPos[101000];

	int heapCount;

	int maxValue;
	int maxCount;

public:
SimpleHeap(int _maxCount, int _maxValue)	// maxValue must NOT be the same as MAXINT (we need to be able to calculate maxValue+1)
{
	maxCount = _maxCount;
	maxValue = _maxValue;
	memset(heapPos, -1, sizeof(int)*(maxCount+1));
	heapCount = 0;
}

int size()
{
	return heapCount;
}

// FIND operations - returns 1 or 0 depending on whether heap contains item
int count(int node)
{
	return heapPos[node] != -1;
}

void insert(int node, int value)	 // MUST be called when heap is not full
{
	SimpleHeapNode newNode;
	newNode.node = node;
	newNode.value = value;

	int pos = ++heapCount;
	while (pos > 1 && heap[pos/2].value < value)
	{
		heap[pos] = heap[pos/2];
		heapPos[heap[pos].node] = pos;
		pos /= 2;
	}
	heap[pos] = newNode;
	heapPos[node] = pos;
}

void pop_max(int& node, int& value)	// MUST be called when heap is non-empty
{
	SimpleHeapNode topNode = heap[1];
	node = topNode.node;
	value = topNode.value;
	heapPos[node] = -1;

	if (heapCount == 1)
	{
		heapCount--;
		return;
	}
	heap[1] = heap[heapCount];
	heapPos[heap[1].node] = 1;
	int pos = 1;
	heapCount--;
	while (pos*2 <= heapCount)
	{
		int m = pos;
		if (pos*2 <= heapCount && heap[pos*2].value > heap[m].value)
		{
			m = pos*2;
		}
		if (pos*2+1 <= heapCount && heap[pos*2+1].value > heap[m].value)
		{
			m = pos*2+1;
		}
		if (m == pos) break;
		SimpleHeapNode t = heap[pos];
		heap[pos] = heap[m];
		heap[m] = t;
		int tt = heapPos[heap[pos].node];
		heapPos[heap[pos].node] = heapPos[heap[m].node];
		heapPos[heap[m].node] = tt;
		pos = m;
	}

	return;
}

void update(int node, int value) // node MUST be present in heap
{
	int pos = heapPos[node];
	SimpleHeapNode t = heap[pos];
	while (pos > 1)
	{
		heap[pos] = heap[pos/2];
		heapPos[heap[pos].node] = pos;
		pos /= 2;
	}
	heap[1] = t;
	heapPos[heap[1].node] = 1;
	int dummyNode, dummyValue;
	pop_max(dummyNode, dummyValue);
	insert(node, value);
}

void dump(int m)
{
	printf("---\n");
	for (int i = 1; i <= m; i++)
	{
		printf("heap[%d] = (%d,%d)\n", i, heap[i].node, heap[i].value);
	}
	printf("**\n");
	for (int i = 1; i <= m; i++)
	{
		printf("heapPos[%d] = %d\n", i, heapPos[i]);
	}
}

};

int main()
{
	int t;

	scanf("%d", &t);


	while (t-- > 0)
	{
		int n, k, p;
		scanf("%d%d%d", &n, &k, &p);
		SimpleHeap heap(n+1, MAX_TIME);
		memset(last, -1, sizeof(last));

		for (int i = 0; i < p; i++)
		{
			scanf("%d", &vp[i]);
			if (last[vp[i]] != -1)
			{
				next[last[vp[i]]] = i;
				next[i] = MAX_TIME;
				last[vp[i]] = i;
			}
			else
			{
				last[vp[i]] = i;
				next[i] = MAX_TIME;
			}
		}

		int pageFault = 0;
		for (int i = 0; i < p; i++)
		{
			int q = vp[i]; // next desired item
if (debug) { printf("item %d\n", q); heap.dump(n); }
			int qNextTime = next[i];
			if (heap.size() < k || heap.count(q) == 1)
			{
				// there is room in memory, or q is in memory already - just update future
				if (heap.count(q) == 0)
				{
if (debug) printf("PF add %d\n", q);
					heap.insert(q, qNextTime);
					pageFault++;
				}
				else
				{
if (debug) printf("PF keep %d\n", q);
					heap.update(q, qNextTime);
				}
			}
			else
			{
				// page fault - memory is full, and q is not in memory
				pageFault++;
				int g, gValue;
				heap.pop_max(g, gValue);
				heap.insert(q, qNextTime); // put new page in memory
if (debug) printf("PF %d replaces %d\n", q, g);
			}
		}
		printf("%d\n", pageFault);
	}
	return 0;
}

