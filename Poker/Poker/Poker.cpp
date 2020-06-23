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
int main()
{
	int WhiteCardNum[6];
	char WhiteCardColor[6];
	int BlackCardNum[6];
	char BlackCardColor[6];
	printf("牌型输入规则：\n花色：方片D 黑桃S 红桃H 梅花C\n数字从小到大依次为：2 3 4 5 6 7 8 9 T J Q K A\n");
	printf("每次必须输入五张牌，牌之间以空格隔开\n例如：White：2H 3D 5S 9C KD\n");
	printf("请输入白色方的牌型\nWhite:");
	WhiteCardNum[0] = 0;
	BlackCardNum[0] = 0;
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
	int i = 1;
	for (i = 1; i < 6; i++)
	{
		printf("%d	", WhiteCardNum[i]);
	}
	printf("\n");
	for (i = 1; i < 6; i++)
	{
		printf("%c	", WhiteCardColor[i]);
	}
	printf("\n");
	for (i = 1; i < 6; i++)
	{
		printf("%d	", BlackCardNum[i]);
	}
	printf("\n");
	for (i = 1; i < 6; i++)
	{
		printf("%c	", BlackCardColor[i]);
	}
	system("pause");
	return 0;
}