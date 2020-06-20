public class Fibonacci
{
	/**
	方法of递归计算数列中第“num”个元素的值
	*/
	public static int of(int num) 
	{
		if(num==1||num==2)
		{
		return 1;
		}
		else
		{
		return of(num-2)+of(num-1);
		}
	}
	
	/**
	主方法
	*/
	public static void main(String[] args)
	{
		int i=1;
		do
		{
		System.out.println(of(i));
		i++;
		}while(of(i)<=200);
	}
	
}
