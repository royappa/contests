import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class FixedPointTheorem
{

	public double cycleRange(double R)
	{
		double X = 0.25;
		for (int i = 0; i < 200000; i++)
			X = R*X*(1-X);
		double min = 0.0, max = 0.0;
		for (int i = 0; i < 1000; i++)
		{
			X = R*X*(1-X);
			if (i == 0)
			{
				min = X;
				max = X;
			}
			else
			{
				min = Math.min(X, min);
				max = Math.max(X, max);
			}
		}
		return Math.abs(max-min);
	}

}

//Powered by [KawigiEdit]

