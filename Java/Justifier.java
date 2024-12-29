import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Justifier
{
	public String[] justify(String[] textIn)
	{
		int max = 0;
		int n = textIn.length;
		for (int i = 0; i < n; i++)
			max = Math.max(textIn[i].length(), max);
		
		for (int i = 0; i < n; i++)
		{
			int d = max-textIn[i].length();
			for (int j = 0; j < d; j++)
				textIn[i] = " " + textIn[i];
		}
		return textIn;
	}
	
}

//Powered by [KawigiEdit]

