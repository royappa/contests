import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class OnLineRank
{
	public int calcRanks(int k, int[] scores)
	{
		int sum = 0;
		for (int i = 0; i < scores.length; i++)
		{
			int rank = 0;
			for (int j = i-k+1; j <= i; j++)
			{
				if (j >= 0 && scores[j] > scores[i])
					rank++;
			}
			sum += rank+1;
		}
		return sum;
	}
}

//Powered by [KawigiEdit]
