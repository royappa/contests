int waysToTear(std::vector< int > Z)
{
	int N =Z[0], A = Z[1], B = Z[2], C = Z[3], MOD = Z[4], BIAS = Z[5];
  	vector<int> v;
  	for (int i = 0; i < N; i++)
    {
      	v.push_back((A*i*i+B*i+C)%MOD-BIAS);
    }
  	vector<int> vs(1, v[0]);
  	for (int i = 1; i < v.size(); i++)
  	{
		vs.push_back(v[i]+vs[i-1]);
	}
	for (int i = 1; i <

}
