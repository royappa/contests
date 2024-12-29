import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class EigenVector
{
	private boolean findEigen(int[][] mat, int[] eigen, int norm, int n, int k)
	{
		if (k == n)
		{
		//for (int i = 0; i < n; i++) System.out.print(eigen[i]+" "); System.out.println("");		
			for (int i = 0; i < k; i++)
			{
				if (eigen[i] != 0)
				{
					if (eigen[i] < 0)
						return false;
					else
						break;
				}
			}
			int L1 = 0;
			for (int i = 0; i < k; i++)
				L1 += Math.abs(eigen[i]);
			if (L1 != norm)
				return false;
			int[] result = new int[n];
			
			for (int i = 0; i < n; i++)
			{	
				int s = 0;
				for (int j = 0; j < n; j++)
				{
					s += mat[i][j]*eigen[j];
				}
				result[i] = s;
			}
			int d = 0;
			for (int i = 0; i < n; i++)
			{
				if (result[i] != 0 && eigen[i] != 0)
				{
					if (eigen[i] > result[i])
						d = eigen[i]/result[i];
					else
						d = -result[i]/eigen[i];
					break;
				}
			}
			if (d == 0)
				return false;
			boolean all = true;
			for (int i = 0; i < n; i++)
			{
				if (d > 0)
				{
					if (result[i]*d != eigen[i])
					{
						all = false;
						break;
					}			
				}
				else
				{
					if (eigen[i]*-d != result[i])
					{
						all = false;
						break;
					}				
				}
			}
			return all;
		}
		// fill position k
		int sum = 0;		
		for (int v = -norm; v <= norm; v++)
		{
			eigen[k] = v;
			if (findEigen(mat, eigen, norm, n, k+1))
				return true;
		}
		return false;
	}
	public int[] findEigenVector(String[] A)
	{
		int n = A.length;
		
		int[][] mat = new int[n][n];
		
		for (int i = 0; i < n; i++)
		{
			String[] w = A[i].split(" ");		
			for (int j = 0; j < n; j++)
			{
				mat[i][j] = Integer.parseInt(w[j]);
			}
		}
		
		int[] eigen = new int[n];
		for (int norm = 1; norm <= 9; norm++)
		{
			if (findEigen(mat, eigen, norm, n, 0))
				return eigen;		
		}
		
		return new int[0];
	}
	
}

//Powered by [KawigiEdit]
