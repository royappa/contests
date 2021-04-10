import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class PascalCount
{
	int [] b;
	public int howMany(int n, int d)
	{
		b = new int [6000000];
		
		b[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			b[i] = i*b[i-1] % 120;
		}
		
		int count = 0;
		for (int j = 0; j < n; j++) // j'th element of nth row
		{
		System.out.println(b[n] + " " + b[j] + " " + b[n-j] + " " + d);
			if ( (b[n] / (b[j]*b[n-j])) % d == 0)
				count++;
		}
		return count;
	}
	
}

//Powered by [KawigiEdit]
