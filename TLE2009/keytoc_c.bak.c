main(n, x, y, v)
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &x),y = x, v = 0;
		while (x)
		{
			v = v * 2 + x % 2;
			x /= 2;
		}
		puts(v-y?"NO\n":"YES\n");
	}
}