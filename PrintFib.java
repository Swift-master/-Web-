import java.math.*;
/**
输出斐波那契数列的前200项
*/
public class PrintFib
{
	public static void main(String[] args) 
	{
		BigInteger a = new BigInteger ("1");
		BigInteger b = new BigInteger ("1");
		for(int i=1;i<101;i++)
		{
		System.out.println(a);
		System.out.println(b);
		a = a.add(b);
		b = b.add(a);
		}
	}
}
