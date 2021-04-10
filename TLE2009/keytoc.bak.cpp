main(n,x,y,v){
	cin>>n;
	while (n--)
	{
		cin>>x,y = x, v = 0;
		while (x)
		{
			v = v * 2 + x % 2;
			x /= 2;
		}
		printf(v-y?"NO\n":"YES\n");
	}
}