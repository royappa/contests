import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class QuizShow
{
	private int prob(int[] scores, int a, int b, int c)
	{
		int wins = 0;
		for (int i = 0; i <= 1; i++)
			for (int j = 0; j <= 1; j++)
				for (int k = 0; k <= 1; k++)
				{
					int p0 = i==0?scores[0]-a:scores[0]+a;
					int p1 = j==0?scores[1]-b:scores[1]+b;
					int p2 = k==0?scores[2]-c:scores[2]+c;
					if (p0 > p1 && p0 > p2)
						wins++;
				}
		return wins;				
	}

	public int wager(int[] scores, int wager1, int wager2)
	{
		int pmax = 0;
		int imax = -1;

		for (int i = 0; i <= scores[0]; i++)
		{
			int p = prob(scores, i, wager1, wager2);
			if (p > pmax)
			{
				pmax = p;
				imax = i;
			}		
		}
		return imax == -1 ? 0 : imax;
		
	}
}

//Powered by [KawigiEdit]

