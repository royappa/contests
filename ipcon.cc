vector <string> IPConverter::possibleAddresses(string s) 
{
	vector<string> results;
	
	for (int i = 1; i <= n-1; i++)
	{
		for (int j = 1; i+j <= n-2; j++)
		{
			for (int k = 1; k <= n-3; k++)
			{
				if (i > 3 || j > 3 || k > 3 || (n-(i+j+k)) > 3)
					continue;
				string a = s.substr(0, i);
				if (a[0] == '0') continue; if (atoi(a) < 1 || atoi(a) > 255) continue;
				string b = s.substr(i, j);
				if (b[0] == '0') continue; if (atoi(b) < 1 || atoi(b) > 255) continue;
				string c = s.substr(j, k);
				if (c[0] == '0') continue; if (atoi(c) < 1 || atoi(c) > 255) continue;
				string d = s.substr(k, n-(i+j+k));
				if (d[0] == '0') continue; if (atoi(n) < 1 || atoi(d) > 255) continue;
			}
		}
	}
	sort(results.begin(), results.end());
	return results;
}

Problem Statement
    
A computer connected to the internet is identified by an IP address. The most common way of displaying an IP address is the dotted quad method: four eight-bit (0-255 in base ten) numbers separated by periods.

Someone has given you a possible IP address, but the periods have been removed, leaving only a string of digits. 

Write a class IPConverter with a method possibleAddresses that takes a string ambiguousIP containing the digits and returns a vector <string> containing all the possible IP addresses that can be formed from those digits by inserting three periods to form a dotted quad. 

Sort the elements of the return value lexicographically, using their string ordering (the period character precedes all digit characters).

The numbers in each of the four positions can have any integer value between zero and 255, inclusive. However, a number may not have leading zeroes. 

For example, the digits 1902426 can form 1.90.24.26, 19.0.24.26, 190.2.4.26, and other IP addresses (see Example 0). However, it cannot form 19.02.4.26.
Definition
    
Class:
IPConverter
Method:
possibleAddresses
Parameters:
string
Returns:
vector <string>
Method signature:
vector <string> possibleAddresses(string ambiguousIP)
(be sure your method is public)
    

Constraints
-
ambiguousIP will contain between 0 and 50 characters, inclusive.
-
Each character of ambiguousIP will be between '0' and '9', inclusive.
Examples
0)

    
"1902426"
Returns: 
{ "1.90.24.26",
  "1.90.242.6",
  "19.0.24.26",
  "19.0.242.6",
  "190.2.4.26",
  "190.2.42.6",
  "190.24.2.6" }
This is the example from the problem statement.
1)

    
"000"
Returns: { }

2)

    
""
Returns: { }

3)

    
"0186290"
Returns: { "0.18.62.90",  "0.186.2.90",  "0.186.29.0" }

4)

    
"11111111"
Returns: 
{ "1.1.111.111",
  "1.11.11.111",
  "1.11.111.11",
  "1.111.1.111",
  "1.111.11.11",
  "1.111.111.1",
  "11.1.11.111",
  "11.1.111.11",
  "11.11.1.111",
  "11.11.11.11",
  "11.11.111.1",
  "11.111.1.11",
  "11.111.11.1",
  "111.1.1.111",
  "111.1.11.11",
  "111.1.111.1",
  "111.11.1.11",
  "111.11.11.1",
  "111.111.1.1" }

5)

    
"3082390871771742784899852251737850570843857369760"
Returns: { }

6)

    
"256255255"
Returns: { "2.56.255.255",  "25.6.255.255",  "25.62.55.255" }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.