#include<stdio.h>
#include<iostream>
//将牌面字符转化为整数值
int numChange(char c)
{
	if (c == '2') 
	{
		return 2;
	}
	if (c == '3')
	{
		return 3;
	}
	if (c == '4')
	{
		return 4;
	}
	if (c == '5')
	{
		return 5;
	}
	if (c == '6')
	{
		return 6;
	}
	if (c == '7')
	{
		return 7;
	}
	if (c == '8')
	{
		return 8;
	}
	if (c == '9')
	{
		return 9;
	}
	if (c == 'T')
	{
		return 10;
	}
	if (c == 'J')
	{
		return 11;
	}
	if (c == 'Q')
	{
		return 12;
	}
	if (c == 'K')
	{
		return 13;
	}
	if (c == 'A')
	{
		return 14;
	}
}
//牌型相同比较大小并输出
void compare(int numW, int numB)
{
	if (numW >numB)
	{
		printf("White Win");
	}
	if (numW<numB)
	{
		printf("Black Win");
	}
	if (numW == numB)
	{
		printf("Tie");
	}
}
int main()
{
	int WhiteCardNum[6];
	char WhiteCardColor[6];
	int BlackCardNum[6];
	char BlackCardColor[6];
	printf("牌型输入规则：\n花色：方片D 黑桃S 红桃H 梅花C\n数字从小到大依次为：2 3 4 5 6 7 8 9 T J Q K A\n");
	printf("每次必须输入五张牌，牌之间以空格隔开，回车结束输入\n例如：White：2H 3D 5S 9C KD\n");
	printf("请输入白色方的牌型\nWhite:");
	WhiteCardNum[0] = 0;
	BlackCardNum[0] = 0;
	//读入白色方牌型
	while (WhiteCardNum[0]<5)
	{
		char c = getchar();
		if (c == ' ')
		{
			c = getchar();
		}
		WhiteCardNum[WhiteCardNum[0] + 1] = numChange(c);
		c = getchar();
		WhiteCardColor[WhiteCardNum[0] + 1] = c;
		WhiteCardNum[0] = WhiteCardNum[0] + 1;
	}
	char enter = getchar();//吸收回车字符
	printf("请输入黑色方的牌型\nBlack:");
	//读入黑色方牌型
	while (BlackCardNum[0]<5)
	{
		char c = getchar();
		if (c == ' ')
		{
			c = getchar();
		}
		BlackCardNum[BlackCardNum[0] + 1] = numChange(c);
		c = getchar();
		BlackCardColor[BlackCardNum[0] + 1] = c;
		BlackCardNum[0] = BlackCardNum[0] + 1;
	}
	//保存两幅牌牌型的变量 0散牌 1对子 2两对 3三条 4顺子 5同花 6同花顺
	int flagW = 0;
	int flagB = 0;
	//复制两组牌的大小用以操作判定牌型
	int WhiteSanpai[6];
	int BlackSanpai[6];
	int i = 1;
	int j = 1;
	for (i = 0; i < 6; i++)
	{
		WhiteSanpai[i] = WhiteCardNum[i];
		BlackSanpai[i] = BlackCardNum[i];
	}
	//对两组牌排序
	for (i = 1; i < 5; i++)
	{
		int t;
		for (j = 1; j < 6-i; j++)
		{
			if (WhiteSanpai[j]<WhiteSanpai[j+1])
			{
				t = WhiteSanpai[j];
				WhiteSanpai[j] = WhiteSanpai[j + 1];
				WhiteSanpai[j + 1] = t;
			}
		}
	}
	for (i = 1; i < 5; i++)
	{
		int t;
		for (j = 1; j < 6-i; j++)
		{
			if (BlackSanpai[j]<BlackSanpai[j + 1])
			{
				t = BlackSanpai[j];
				BlackSanpai[j] = BlackSanpai[j + 1];
				BlackSanpai[j + 1] = t;
			}
		}
	}
	//判定1对子牌型
	for (i = 1; i < 5; i++)
	{
		if (WhiteSanpai[i] == WhiteSanpai[i + 1])
		{
			flagW = 1;
		}
	}
	for (i = 1; i < 5; i++)
	{
		if (BlackSanpai[i] == BlackSanpai[i + 1])
		{
			flagB = 1;
		}
	}
	//判定2两对牌型
	int flag2W = 0;
	int flag2B = 0;
	for (i = 1; i < 5; i++)
	{
		if (WhiteSanpai[i] == WhiteSanpai[i + 1])
		{
			flag2W = flag2W + 1;
			i = i + 1;
		}
	}
	for (i = 1; i < 5; i++)
	{
		if (BlackSanpai[i] == BlackSanpai[i + 1])
		{
			flag2B = flag2B + 1;
			i = i + 1;
		}
	}
	if (flag2W == 2)
	{
		flagW = 2;
	}
	if (flag2B == 2)
	{
		flagB = 2;
	}
	//判定3三条牌型
	for (i = 1; i < 4; i++)
	{
		if (WhiteSanpai[i] == WhiteSanpai[i + 1]&& WhiteSanpai[i+1]==WhiteSanpai[i+2])
		{
			flagW = 3;
		}
	}
	for (i = 1; i < 4; i++)
	{
		if (BlackSanpai[i] == BlackSanpai[i + 1]&& BlackSanpai[i+1]== BlackSanpai[i+2])
		{
			flagB = 3;
		}
	}
	//判定4顺子牌型
	int flag4W=0;
	int flag4B=0;
	for (i = 1; i < 5; i++)
	{
		if (WhiteSanpai[i] - WhiteSanpai[i + 1]==1 )
		{
			flag4W = flag4W + 1;
		}
	}
	for (i = 1; i < 5; i++)
	{
		if (BlackSanpai[i] - BlackSanpai[i + 1] ==1)
		{
			flag4B = flag4B + 1;
		}
	}
	if (flag4W == 4)
	{
		flagW = 4;
	}
	if (flag4B == 4)
	{
		flagB = 4;
	}
	//判定5同花牌型
	int flag5W = 0;
	int flag5B = 0;
	for (i = 1; i < 5; i++)
	{
		if (WhiteCardColor[i] == WhiteCardColor[i + 1] )
		{
			flag5W = flag5W + 1;
		}
	}
	for (i = 1; i < 5; i++)
	{
		if (BlackCardColor[i] == BlackCardColor[i + 1])
		{
			flag5B = flag5B + 1;
		}
	}
	if (flag5W == 4)
	{
		flagW = 5;
	}
	if (flag5B == 4)
	{
		flagB = 5;
	}
	//判定6同花顺牌型
	if (flag4W == 4 && flag5W == 4)
	{
		flagW = 6;
	}
	if (flag4B == 4 && flag5B == 4)
	{
		flagB = 6;
	}
	//先按照牌型比较大小
	if (flagW >flagB)
	{
		printf("White Win");
	}
	if (flagW<flagB)
	{
		printf("Black Win");
	}
	//牌型相同比较大小
	if (flagW == 0 && flagB == 0)
	{
		//比较牌的大小
		int flag = 0;
		for (i = 1; i < 6; i++)
		{
			if (WhiteSanpai[i] > BlackSanpai[i])
			{
				flag = 1;
				break;
			}
			if (WhiteSanpai[i] < BlackSanpai[i])
			{
				flag = -1;
				break;
			}
		}
		//根据比较得到的flag值输出结果
		if (flag == 0)
		{
			printf("Tie");
		}
		if (flag == 1)
		{
			printf("White Win");
		}
		if (flag == -1)
		{
			printf("Black Win");
		}
	}
	if (flagW == 1 && flagB == 1)
	{
		int i = 0;
		int j = 0;
		int duiziW;
		int duiziB;
		for (i = 1; i < 5; i++)
		{
			if (WhiteSanpai[i] == WhiteSanpai[i + 1])
			{
				duiziW = WhiteSanpai[i];
				WhiteSanpai[i] = 0;
				WhiteSanpai[i + 1] = 0;
			}
		}
		for (i = 1; i < 5; i++)
		{
			if (BlackSanpai[i] == BlackSanpai[i + 1])
			{
				duiziB = BlackSanpai[i];
				BlackSanpai[i] = 0;
				BlackSanpai[i + 1] = 0;
			}
		}
		if (duiziW >duiziB)
		{
			printf("White Win");
			return 0;
		}
		if (duiziW<duiziB)
		{
			printf("Black Win");
			return 0;
		}
		for (i = 1; i < 5; i++)
		{
			int t;
			for (j = 1; j < 6 - i; j++)
			{
				if (WhiteSanpai[j]<WhiteSanpai[j + 1])
				{
					t = WhiteSanpai[j];
					WhiteSanpai[j] = WhiteSanpai[j + 1];
					WhiteSanpai[j + 1] = t;
				}
			}
		}
		for (i = 1; i < 5; i++)
		{
			int t;
			for (j = 1; j < 6 - i; j++)
			{
				if (BlackSanpai[j]<BlackSanpai[j + 1])
				{
					t = BlackSanpai[j];
					BlackSanpai[j] = BlackSanpai[j + 1];
					BlackSanpai[j + 1] = t;
				}
			}
		}
		int numW = 10000 * WhiteSanpai[1] + 100 * WhiteSanpai[2] + WhiteSanpai[3];
		int numB = 10000 * BlackSanpai[1] + 100 * BlackSanpai[2] + BlackSanpai[3];
		compare(numW, numB);
	}
	if (flagW == 2 && flagB == 2)
	{
		int numWbig, numWsmall;
		int numBbig,numBsmall;
		for (i = 1; i < 5; i++)
		{
			if (WhiteSanpai[i] == WhiteSanpai[i + 1])
			{
				numWbig = WhiteSanpai[i];
				WhiteSanpai[i] = 0;
				WhiteSanpai[i + 1] = 0;
				i = i + 1;
			}
			if (WhiteSanpai[i] == WhiteSanpai[i + 1])
			{
				numWsmall = WhiteSanpai[i];
				WhiteSanpai[i] = 0;
				WhiteSanpai[i + 1] = 0;
				i = i + 1;
			}
		}
		for (i = 1; i < 5; i++)
		{
			if (BlackSanpai[i] == BlackSanpai[i + 1])
			{
				numBbig = BlackSanpai[i];
				BlackSanpai[i] = 0;
				BlackSanpai[i + 1] = 0;
				i = i + 1;
			}
			if (BlackSanpai[i] == BlackSanpai[i + 1])
			{
				numBsmall = BlackSanpai[i];
				BlackSanpai[i] = 0;
				BlackSanpai[i + 1] = 0;
				i = i + 1;
			}
		}
		for (i = 1; i < 5; i++)
		{
			int t;
			for (j = 1; j < 6 - i; j++)
			{
				if (WhiteSanpai[j]<WhiteSanpai[j + 1])
				{
					t = WhiteSanpai[j];
					WhiteSanpai[j] = WhiteSanpai[j + 1];
					WhiteSanpai[j + 1] = t;
				}
			}
		}
		for (i = 1; i < 5; i++)
		{
			int t;
			for (j = 1; j < 6 - i; j++)
			{
				if (BlackSanpai[j]<BlackSanpai[j + 1])
				{
					t = BlackSanpai[j];
					BlackSanpai[j] = BlackSanpai[j + 1];
					BlackSanpai[j + 1] = t;
				}
			}
		}
		int numW = 10000 * numWbig + 100 * numWsmall + WhiteSanpai[1];
		int numB = 10000 * numBbig + 100 * numBsmall + BlackSanpai[1];
		compare(numW, numB);
	}
	if (flagW == 3 && flagB == 3)
	{
		int santiaoW;
		int santiaoB;
		for (i = 1; i < 4; i++)
		{
			if (WhiteSanpai[i] == WhiteSanpai[i + 1] && WhiteSanpai[i + 1] == WhiteSanpai[i + 2])
			{
				santiaoW = 10000 * WhiteSanpai[i];
				WhiteSanpai[i] = 0;
				WhiteSanpai[i + 1] = 0;
				WhiteSanpai[i + 2] = 0;
				i = i + 2;
			}
		}
		for (i = 1; i < 4; i++)
		{
			if (BlackSanpai[i] == BlackSanpai[i + 1] && BlackSanpai[i + 1] == BlackSanpai[i + 2])
			{
				santiaoB = 10000 * BlackSanpai[i];
				BlackSanpai[i] = 0;
				BlackSanpai[i + 1] = 0;
				BlackSanpai[i + 2] = 0;
				i = i + 2;
			}
		}
		for (i = 1; i < 5; i++)
		{
			int t;
			for (j = 1; j < 6 - i; j++)
			{
				if (WhiteSanpai[j]<WhiteSanpai[j + 1])
				{
					t = WhiteSanpai[j];
					WhiteSanpai[j] = WhiteSanpai[j + 1];
					WhiteSanpai[j + 1] = t;
				}
			}
		}
		for (i = 1; i < 5; i++)
		{
			int t;
			for (j = 1; j < 6 - i; j++)
			{
				if (BlackSanpai[j]<BlackSanpai[j + 1])
				{
					t = BlackSanpai[j];
					BlackSanpai[j] = BlackSanpai[j + 1];
					BlackSanpai[j + 1] = t;
				}
			}
		}
		santiaoW = santiaoW + 100 * WhiteSanpai[1] + WhiteSanpai[2];
		santiaoB = santiaoB + 100 * BlackSanpai[1] + BlackSanpai[2];
		compare(santiaoW, santiaoB);
	}
	if (flagW == 4 && flagB == 4)
	{
		compare(WhiteSanpai[1], BlackSanpai[1]);
	}
	if (flagW == 5 && flagB == 5)
	{
		//比较牌的大小
		int flag = 0;
		for (i = 1; i < 6; i++)
		{
			if (WhiteSanpai[i] > BlackSanpai[i])
			{
				flag = 1;
				break;
			}
			if (WhiteSanpai[i] < BlackSanpai[i])
			{
				flag = -1;
				break;
			}
		}
		//根据比较得到的flag值输出结果
		if (flag == 0)
		{
			printf("Tie");
		}
		if (flag == 1)
		{
			printf("White Win");
		}
		if (flag == -1)
		{
			printf("Black Win");
		}
	}
	if (flagW == 6 && flagB == 6)
	{
		compare(WhiteSanpai[1], BlackSanpai[1]);
	}
	system("pause");
	return 0;
}