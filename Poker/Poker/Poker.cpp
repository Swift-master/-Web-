#include<stdio.h>
#include<iostream>
//�������ַ�ת��Ϊ����ֵ
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
	printf("�����������\n��ɫ����ƬD ����S ����H ÷��C\n���ִ�С��������Ϊ��2 3 4 5 6 7 8 9 T J Q K A\n");
	printf("ÿ�α������������ƣ���֮���Կո�������س���������\n���磺White��2H 3D 5S 9C KD\n");
	printf("�������ɫ��������\nWhite:");
	WhiteCardNum[0] = 0;
	BlackCardNum[0] = 0;
	//�����ɫ������
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
	char enter = getchar();//���ջس��ַ�
	printf("�������ɫ��������\nBlack:");
	//�����ɫ������
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
	//�����������Ƶ����ͱ��� 0ɢ�� 1����
	int flagW = 0;
	int flagB = 0;
	//���������ƵĴ�С���Բ����ж�����
	int WhiteSanpai[6];
	int BlackSanpai[6];
	int i = 1;
	int j = 1;
	for (i = 0; i < 6; i++)
	{
		WhiteSanpai[i] = WhiteCardNum[i];
		BlackSanpai[i] = BlackCardNum[i];
	}
	//������������
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
	//�ж�1��������
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
	//�Ȱ������ͱȽϴ�С
	if (flagW >flagB)
	{
		printf("White Win");
	}
	if (flagW<flagB)
	{
		printf("Black Win");
	}
	//������ͬ�Ƚϴ�С
	if (flagW == 0 && flagB == 0)
	{
		//�Ƚ��ƵĴ�С
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
		//���ݱȽϵõ���flagֵ������
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
		if (numW >numB)
		{
			printf("White Win");
			return 0;
		}
		if (numW<numB)
		{
			printf("Black Win");
			return 0;
		}
		if (numW==numB)
		{
			printf("Tie");
			return 0;
		}
	}
	system("pause");
	return 0;
}