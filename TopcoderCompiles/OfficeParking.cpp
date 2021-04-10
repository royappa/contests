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

class OfficeParking {
public:
vector<string> split_space(string s)
{
	vector<string> results;
	istringstream fin(s);
	while (!fin.eof())
	{
		string x;
		fin >> x;
		results.push_back(x);
	}
	return results;
}

int spacesUsed(vector <string> events) 
{
	int m = 0;
	set<string> who;
	for (int i = 0; i < events.size(); i++)
	{
		vector<string> v = split_space(events[i]);
		if (v[1] == "arrives")
		{
			who.insert(v[0]);
		}	
		else
		{
			who.erase(v[0]);
		}
		m = max(m, (int)who.size());
	}
	return m;
}
};


//Powered by [KawigiEdit]

double test0() {
	string t0[] = {"Alice arrives","bob arrives","Alice departs",
 "Charles arrives","bob departs","Charles departs"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OfficeParking * obj = new OfficeParking();
	clock_t start = clock();
	int my_answer = obj->spacesUsed(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	string t0[] = {"AdminBrett arrives","lbackstrom arrives","AdminBrett departs","mike arrives",
 "TheFaxman arrives","AdminBrett arrives","lbackstrom departs","dok arrives",
 "AdminBrett departs","gt arrives","AdminBrett arrives","lbackstrom arrives",
 "AdminBrett departs","jhughes arrives","jhughes departs","TheFaxman departs",
 "MaryJoe arrives","AdminBrett arrives","AdminBrett departs","AdminBrett arrives"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OfficeParking * obj = new OfficeParking();
	clock_t start = clock();
	int my_answer = obj->spacesUsed(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	string t0[] = {"SnapDragon arrives","tomek arrives","JohnDethridge arrives","ZorbaTHut arrives",
 "snewman arrives","reid arrives","NGBronson arrives","Yarin arrives",
 "bstanescu arrives","mathijs arrives","radeye arrives","bladerunner arrives",
 "dgarthur arrives","venco arrives","dmwright arrives","WishingBone arrives",
 "Eryx arrives","antimatter arrives","ChristopherH arrives","lars arrives",
 "biggnate arrives","JanKuipers arrives","dary arrives","haha arrives","grotmol arrives",
 "XuChuan arrives","Ryan arrives","LunaticFrindge arrives","Wasteland arrives",
 "RunningWild arrives","hampster arrives","RalphFurmaniak arrives",
 "kyky arrives","qubits arrives","Rustyoldman arrives","turuthok arrives",
 "Vulpecular arrives","Eeyore arrives","wackes arrives","Ishan arrives",
 "dimkadimon arrives","dplass arrives","Olorin arrives","TangentZ arrives",
 "NeverMore arrives","Pops arrives","srowan arrives","tjq arrives",
 "vorthys arrives","schveiguy arrives"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OfficeParking * obj = new OfficeParking();
	clock_t start = clock();
	int my_answer = obj->spacesUsed(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 50;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	string t0[] = {"AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs",
 "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs",
 "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs",
 "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OfficeParking * obj = new OfficeParking();
	clock_t start = clock();
	int my_answer = obj->spacesUsed(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test4() {
	string t0[] = {"snapdragon arrives","SnapDragon arrives",
 "AdminBrett arrives","AdminBrett departs",
 "SnapDragon departs","snapdragon departs"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OfficeParking * obj = new OfficeParking();
	clock_t start = clock();
	int my_answer = obj->spacesUsed(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test5() {
	string t0[] = {"departs arrives","arrives arrives","arrives departs","departs departs"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OfficeParking * obj = new OfficeParking();
	clock_t start = clock();
	int my_answer = obj->spacesUsed(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main(int argc, char **argv) {
	double time;
	bool errors = false;
	
	if (argc < 2 || atoi(argv[1]) == 0) {
		time = test0();
		if (time < 0.0)
			errors = true;
	}
	
	if (argc < 2 || atoi(argv[1]) == 1) {
		time = test1();
		if (time < 0.0)
			errors = true;
	}
	
	if (argc < 2 || atoi(argv[1]) == 2) {
		time = test2();
		if (time < 0.0)
			errors = true;
	}
	
	if (argc < 2 || atoi(argv[1]) == 3) {
		time = test3();
		if (time < 0.0)
			errors = true;
	}
	
	if (argc < 2 || atoi(argv[1]) == 4) {
		time = test4();
		if (time < 0.0)
			errors = true;
	}
	
	if (argc < 2 || atoi(argv[1]) == 5) {
		time = test5();
		if (time < 0.0)
			errors = true;
	}
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

