// @JUDGE_ID:  55118HH  357  Java 

import java.io.*;
import java.util.*;

class Main
{
	private int[] coins  ;
	
    static String ReadLn (int maxLg)  // utility function to read from stdin
    {
        byte lin[] = new byte [maxLg];
        int lg = 0, car = -1;
        String line = "";

        try
        {
            while (lg < maxLg)
            {
                car = System.in.read();
                if ((car < 0) || (car == '\n') || (car == '\r')) 
                {
                	if (car == '\r')
                		car = System.in.read();
                	break;
                }
                lin [lg++] += car;
            }
        }
        catch (IOException e)
        {
            return (null);
        }

        if ((car < 0) && (lg == 0)) return (null);  // eof
        return (new String (lin, 0, lg));
    }

	public static void main (String args[]) throws IOException  // entry point from OS
	{
		Main myWork = new Main();  // create a dinamic instance
		myWork.Begin();            // the true entry point
	}

	long[][] cache;
	
	private long count(int cents, int n)
	{
		if (n == 1 || cents == 0)
		{
			return 1;
		}
		
		if (cache[cents][n] != -1)
			return cache[cents][n];
		
		long ways = 0;
		if (cents >= coins[n-1])
			ways += count(cents-coins[n-1], n);
		ways += count(cents, n-1);
		
		cache[cents][n] = ways;
		return ways;
	}
		
	void Begin() throws IOException
	{

		coins = new int[5];
		coins[0] = 1;
		coins[1] = 5;
		coins[2] = 10;
		coins[3] = 25;
		coins[4] = 50;
		
		cache = new long[30001][6];
		for (int i = 0; i <= 30000; i++)
			for (int j = 0; j <= 5; j++)
				cache[i][j] = -1;
		
		String line = ReadLn(80);
		while (line != null)
		{
		System.out.println(line);
			int N = Integer.parseInt(line);
			long ways = count(N, 5);
				
			if (ways > 1)
				System.out.println("There are " + ways + " ways to produce " + N + " cents change.");
			else
				System.out.println("There is only 1 way to produce " + N + " cents change.");
				
				
			line = ReadLn(80);
		}
	}

}
