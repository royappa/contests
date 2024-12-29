import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class RPN
{
	private int atoi(String s) { return Integer.parseInt(s); }
	public int evaluate(String expr)
	{
		ArrayList stack = new ArrayList();
		
		String[] w = expr.split(" ");
		for (int i = 0; i < w.length; i++)
		{
			char ch = w[i].charAt(0);
			if (Character.isDigit(ch))
				stack.add(0, new Integer(atoi(w[i])));
			else if (ch == '+' || ch == '-' || ch == '*')
			{
				if (stack.size() < 2) return -999;
				int top = ((Integer) stack.get(0)).intValue();
				int next = ((Integer) stack.get(1)).intValue();
				int result = ch=='+'?top+next :
							ch=='*'?top*next:next-top;
				stack.remove(0);
				stack.remove(0);
				stack.add(0, new Integer(result));
			}
			else
			{
				if (stack.size() == 0) return -999;
				int top = ((Integer) stack.get(0)).intValue();
				stack.remove(0);
				stack.add(0, new Integer(-top));
			}
		}
		if (stack.size() > 1) return -999;
		return ((Integer) stack.get(0)).intValue();
	}
	
}

//Powered by [KawigiEdit]

