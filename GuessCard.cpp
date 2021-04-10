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

class GuessCard {
public:
	int whichRow(int, int, vector <int>);
};

int board[110][110];
map<int,int> origRow;
 
void putCards(vector<int> cards, int width, int height)
{
  int k = 0;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      board[i][j] = cards[k];
      origRow[cards[k]] = i;
      k++;
    }
  }
}
 
int GuessCard::whichRow(int width, int height, vector <int> columns) 
{
  vector<int> cards;
  int n = width*height;
  for (int i = 0; i < n; i++)
  {
    cards.push_back(i);
  }
  
  putCards(cards, width, height);
  vector<int> candidates;
  for (int i = 0; i < n; i++)
  {
    candidates.push_back(cards[i]);
  }
  
  int val = -1;
  for (int k = 0; k < columns.size(); k++)
  {
    int c = columns[k];
    vector<int> newcand;
    for (int i = 0; i < height; i++)
    {
      newcand.push_back(board[i][c]);
    }
    vector<int> result; // intersection of candidates, newcand
	sort(newcand.begin(), newcand.end());
	sort(candidates.begin(), candidates.end());
	set_intersection(newcand.begin(), newcand.end(), candidates.begin(), candidates.end(), std::inserter(result,result.begin()));
    candidates = result;
    if (val == -1 && candidates.size() == 1)
    {
      val = candidates[0];
    }
    cards.clear();
    for (int i = 0; i < width; i++)
    {
      for (int j = 0; j < height; j++)
      {
        cards.push_back(board[j][i]);
      }
    }
    if (k != columns.size()-1) putCards(cards, width, height);
  }
  return candidates.size() == 1 ? origRow[val] : -1;
}
double test0() {
	int p0 = 3;
	int p1 = 7;
	int t2[] = {2, 1, 0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	GuessCard * obj = new GuessCard();
	clock_t start = clock();
	int my_answer = obj->whichRow(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	int p0 = 3;
	int p1 = 7;
	int t2[] = {2, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	GuessCard * obj = new GuessCard();
	clock_t start = clock();
	int my_answer = obj->whichRow(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	int p0 = 1;
	int p1 = 10;
	int t2[] = {0, 0, 0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	GuessCard * obj = new GuessCard();
	clock_t start = clock();
	int my_answer = obj->whichRow(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test3() {
	int p0 = 10;
	int p1 = 1;
	int t2[] = {4, 4, 4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	GuessCard * obj = new GuessCard();
	clock_t start = clock();
	int my_answer = obj->whichRow(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}

//Powered by [KawigiEdit]

int main() {
int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
