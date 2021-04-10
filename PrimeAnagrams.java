import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class PrimeAnagrams
{
	private boolean[] isPrime;
	
	public int[] primes(String anagram)
	{
		isPrime = new boolean[1000001]; 
		Arrays.fill(isPrime, true);
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i <= 1000000; i++)
		{
			for (int j = 2; j*j <= i; j++)
			{
				if (i%j == 0)
				{
					isPrime[i] = false;
					break;
				}
			}
		}
		int n = anagram.length();
		LinkedList q = new LinkedList();
		HashMap seen = new HashMap();
		
		int minProd = Integer.MAX_VALUE;
		int best1 = 0, best2 = 0, best3 = 0;
		// FIRST, generate all digit permutations of original string (thanks to brogers)
		// then partition into sets of 3
		q.add(anagram);
		seen.put(anagram, "yes");
	
		while (q.size() > 0)
		{
			String head = (String) q.remove(0);
			char[] dig = head.toCharArray();
			for (int i = 1; i < n; i++)
			{
				if (dig[0] == '0')
					continue;
					
				int num1 = 0, num2 = 0, num3 = 0;
				for (int k = 0; k < i; k++)
					num1 = num1*10+(dig[k]-'0');
				if (!isPrime[num1])
					continue;				
				for (int j = i+1; n-j >= 1; j++)
				{
					num2 = num3 = 0;
					if (dig[i] == '0' || dig[j] == '0')
						continue;
					for (int k = i; k < j; k++)
						num2 = num2*10+dig[k]-'0';
					if (!isPrime[num2])
						continue;
					for (int k = j; k < n; k++)
						num3 = num3*10+dig[k]-'0';
					if (isPrime[num3])
					{
						int t = num1*num2*num3;
						if (t < minProd)
						{
							minProd = t;
							best1 = num1;
							best2 = num2;
							best3 = num3;
						}
					}
				}
			}
			
			for (int i = 0; i < n; i++)
			{
				for (int j = i+1; j < n; j++)
				{
					char ti = dig[i];
					char tj = dig[j];
					dig[i] = tj;
					dig[j] = ti;
					String next = new String(dig);
					if (!seen.containsKey(next))
					{
						q.add(next);
						seen.put(next, "yes");
					}
					dig[i] = ti;
					dig[j] = tj;
				}
			}
		}
		if (minProd == Integer.MAX_VALUE)
			return new int[0];
		int[] best = new int[] { best1, best2, best3 };
		Arrays.sort(best);
		return best;	
	} 
}

//Powered by [KawigiEdit]
