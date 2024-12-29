
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
typedef vector<string> vs;

class SimpleRouter {
public:

// Split on separator
// SPLIT_NONRE()
// TESTED - may be slow if used in a loop because it makes a copy of the string "s" each time.
// That is because stupid strtok_r writes null chars into s.
// Actually strtok_r() should not be needed here but doesn't hurt.

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

bool mm(string r, string p)
{
	if (r == "*")
		return true;
	if (r.find('-') != string::npos)
	{
		int ra, rb, c;
		sscanf(r.c_str(), "%d-%d", &ra, &rb);
		c = atoi(p.c_str());
		return c >= ra && c <= rb;
	}
	return atoi(r.c_str()) == atoi(p.c_str());
}

bool m(string r, string p)
{
	vs rw = split_nonre(r, ".");
	vs pw = split_nonre(p, ".");

	for (int i = 0; i < rw.size(); i++)
	{
		if (!mm(rw[i], pw[i]))
		{
			return false;
		}
	}
	return true;
}

string fix(string s)
{
	char buf[100];
	if (s.find('.') == string::npos)
	{
		sprintf(buf, "%d", atoi(s.c_str()));
		return buf;
	}
	int a,b,c,d;
	sscanf(s.c_str(), "%d.%d.%d.%d", &a, &b, &c, &d);
	sprintf(buf, "%d.%d.%d.%d", a, b, c, d);
	return buf;
}

string accept(string rule, string packet)
{
	vs rw = split_nonre(rule, " ");
	vs pw = split_nonre(packet, " ");
	string action = rw[0];
	string rip = rw[1], rport = rw[2];
	string dest = rw.size() == 3 ? "" : rw[3];
	string dport = rw.size() != 5 ? "" : rw[4];
	string pip = pw[0], pport = pw[1];
	if (m(rip, pip) && m(rport, pport))
	{
		if (action != "FORWARD")
		{
			return action;
		}
		if (dport == "")
			return fix(dest) + ":" + fix(pport);
		return fix(dest) + ":" + fix(dport);
	}
	return "";
}

vs route(vs rules, vs packets)
{
	int n = rules.size();

	vs r;
cout << "hello" << endl;
	for (int i = 0; i < packets.size(); i++)
	{
		bool found = false;
		for (int j = n-1; j >= 0; j--)
		{
			string result = accept(rules[j], packets[i]);
			if (result != "")
			{
				r.push_back(result);
				found = true;
				break;
			}
		}
		if (!found)
		{
			r.push_back("REJECT");
		}

	}
	return r;
}


};


Problem Statement

A router's job is to route packets of information to the correct computer.

In addition, a router may throw out some packets, or handle the packets on its own.

In this problem, you are to implement the software for a simple, rule-based router.

Each rule in the router will take one of the following forms (quotes and angle brackets for clarity only):
"ACCEPT <IP_RANGE> <PORT_RANGE>"
"REJECT <IP_RANGE> <PORT_RANGE>"
"FORWARD <IP_RANGE> <PORT_RANGE> <DESTINATION> (<PORT>)"

Each <IP_RANGE> is a string of exactly four <NUMBER_RANGE>s, separated by periods, and each <PORT_RANGE> consists of a single <NUMBER_RANGE>.

A <NUMBER_RANGE> can take one of three forms.
It may be a single integer, a range of integers (in the form "<LOWER_LIMIT>-<UPPER_LIMIT>", where both limits are inclusive), or an asterisk.
<DESTINATION> consists of exactly 4 integers, with 3 periods separating them (an IP address).

If a FORWARD rule has a <PORT_RANGE> with only a single integer, then the <DESTINATION> may optionally be followed by a single integer, <PORT>.

Each rule tells the router what to do with a packet of information if that packet comes from an IP in the rule's <IP_RANGE> and to a port in the rule's <PORT_RANGE>.

An IP is in the <IP_RANGE> if each <NUMBER_RANGE> in the <IP_RANGE> matches the corresponding number in the IP.

A <NUMBER_RANGE> matches a number, N, if the <NUMBER_RANGE> is an asterisk, if it is a single number that is the same as N, or if it is a range and N falls within the range, inclusive.

The rules for matching a <PORT_RANGE> are the same.

If a rule tells the router to forward the packet, then it should be forwarded to <DESTINATION>.

If no <PORT> is specified, the packet should be forwarded to the same port it was received on.

Otherwise, it should be forwarded to the specified port.

If multiple rules apply to a packet, you should use the one that comes last in the input.

If no rules apply, REJECT the packet.

You will be given a vector <string>, rules, representing a number of rules that the router is to follow.

You will also be given a vector <string>, packets, each of whose elements represents a packet of data in the form "<SOURCE_IP> <PORT>" (<SOURCE_IP> is formatted the same as <DESTINATION>).

You should return a vector <string> with one element per packet, specifying what to do with the packet with the same index in the input as the return.

Each element of the return should be either "ACCEPT", "REJECT", or "<IP>:<PORT>", where <IP> and <PORT> represent the location to which the packet should be forwarded.

Definition

Class:
SimpleRouter
Method:
route
Parameters:
vector <string>, vector <string>
Returns:
vector <string>
Method signature:
vector <string> route(vector <string> rules, vector <string> packets)
(be sure your method is public)


Notes
-
While the input may have extraneous leading zeros, your return should not.
Constraints
-
rules will contain between 1 and 50 elements, inclusive.
-
Each element of rules will be formatted as described in the problem statement.
-
packets will contain between 1 and 50 elements, inclusive.
-
Each element of packets will be formatted as described in the problem statement.
-
Each of the four numbers in an IP address, or a number range in an IP address will be between 0 and 255, inclusive.
-
Each port or number in a port range will be between 1 and 65535 inclusive.
-
In any <NUMBER_RANGE> with two numbers, <LOWER_LIMIT> will be less than or equal to <UPPER_LIMIT>.
Examples
0)


{"FORWARD 192.168.000.* 001-100 192.168.0.10",
 "FORWARD 192.168.0.1 80 10.10.95.184 8080",
 "ACCEPT 192.168.*.* 25",
 "REJECT 192.168.5.38 *"}
{"192.168.0.43 80",
 "00192.00168.000.001 00080",
 "192.168.0.1 110",
 "192.168.1.73 80",
 "192.168.1.73 25",
 "206.26.210.5 53",
 "192.168.5.38 25"
 }
Returns:
{ "192.168.0.10:80",
  "10.10.95.184:8080",
  "REJECT",
  "REJECT",
  "ACCEPT",
  "REJECT",
  "REJECT" }
Packet 0 matches rule 0, and gets forwarded according to that rule. Packet 1 matches both rules 0 and 1, so rule 1 is applied. Packets 2, 3, and 5 don't match any rules, so they are rejected. Packet 4 matches rule 2, and is therefore accepted. Packet 6 matches rules 2 and 3, so it gets rejected (rule 3 is applied).
1)


{"FORWARD *.*.*.* * 192.168.0.1"}
{"213.148.161.82 9484",
 "172.230.108.145 16627",
 "122.141.122.130 46874",
 "241.145.145.77 26390",
 "139.97.106.125 35305",
 "244.131.151.77 26390"}
Returns:
{ "192.168.0.1:9484",
  "192.168.0.1:16627",
  "192.168.0.1:46874",
  "192.168.0.1:26390",
  "192.168.0.1:35305",
  "192.168.0.1:26390" }

2)


{"REJECT *.20-252.114-157.36-91 13171-54085",
 "ACCEPT *.*.73-180.* *",
 "FORWARD 55.63.173.239 * 168.154.33.25",
 "REJECT *.72-73.*.48-191 *",
 "REJECT 20.51.*.* 4579",
 "ACCEPT 70-166.*.*.86-182 *",
 "REJECT 88-190.*.119-157.* 3316-27844",
 "FORWARD *.52-221.134-250.66-207 * 116.94.120.82"}
{"203.11.104.45 44072",
 "154.92.128.87 30085",
 "20.51.68.55 4579",
 "177.73.138.69 14319",
 "112.65.145.82 26287",
 "55.63.173.239 45899"}
Returns:
{ "ACCEPT",
  "ACCEPT",
  "REJECT",
  "116.94.120.82:14319",
  "116.94.120.82:26287",
  "168.154.33.25:45899" }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.