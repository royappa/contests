// @JUDGE_ID:  55118HH  725  Java 

import java.io.*;
import java.util.*;

class Main
{

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
                if ((car < 0) || (car == '\n')) break;
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
    
    public static void main (String args[])   // entry point from OS
    {
        Main myWork = new Main();  // create a dinamic instance
        myWork.Begin();            // the true entry point
    }

    void Begin() 
    {
    
		String line = ReadLn(255);
		int N = Integer.parseInt(line);
		
		int[] used = new int[10];
		while (N != 0)
		{
			int count = 0;
			// all 10*9*9*9*9 numerators
			for (int a = 0; a <= 9; a++)
				for (int b = 0; b <= 9; b++)
					for (int c = 0; c <= 9; c++)
						for (int d = 0; d <= 9; d++)
							for (int e = 0; e <= 9; e++)
							{
								int numerator = a*10000+b*1000+c*100+d*10+e;
								if (numerator % N == 0)
								{
									int denom = numerator / N;
									
									if ( numerator < 1000 || denom < 1000 )
										continue;
									if ( numerator <= 9999 && denom <= 9999)
										continue;
									String num = ""+numerator;
									String den = ""+(numerator/N);
									if (numerator <= 9999) num = "0"+num;
									if (denom <= 9999) den = "0"+den;
									for (int i = 0; i < 10; i++)
										used[i] = 0;
									for (int i = 0; i < 5; i++)
									{
										used[num.charAt(i)-'0']++;
										used[den.charAt(i)-'0']++;
									}
									boolean rep = false;
									for (int i = 0; i < 10; i++)
										if (used[i] != 1)
											rep = true;
									if (rep)
										continue;									
									System.out.println(num + " / " + den + " = " + N);
									count++;
								}
							}
			if (count == 0)
				System.out.println("There are no solutions for " + N + ".");
			line = ReadLn(255);
			N = Integer.parseInt(line);
		}

    }
}
