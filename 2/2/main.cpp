// 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define DATALENGTH 15

int InsertionAscSort(int* data,int length)
{
	for (int i = 1; i < length; i++)
	{
		int insertData = data[i];
		int j = i - 1;
		while(insertData < data[j] && j>-1)
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j+1] = insertData;
	}
	
	return 0;
}

int InsertionDecSort(int* data, int length)
{
	for (int i = 2; i < length; i++)
	{
		int insertData = data[i];
		int j = i - 1;
		while (insertData > data[j] && j>-1)
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = insertData;
	}

	return 0;
}

int AddBINARY(int* a, int* b,int dataLength,int* c)
{
	int carry=0;
	for (int i = 0; i < dataLength; i++)
	{
		c[i] = (a[i] + b[i] + carry) % 2;
		carry = (a[i] + b[i] + carry) / 2;
	}
	c[dataLength] = carry;
	return 0;
}

int Merge(int* A, int p, int q, int r)
{
	int B[DATALENGTH] = {};
	int i = 0, j = q,index = 0;
	while (i <= p && j <= r && index < DATALENGTH)
	{
		if (A[i] <= A[j])
		{
			B[index] = A[i];
			i++;
		}
		else
		{
			B[index] = A[j];
			j++;
		}
		index++;
	}
	if (i <= p)
	{
		for (; i <= p; i++)
		{
			B[index] = A[i];
			index++;
		}
	}
	else if (j <= r)
	{
		for (; j <= r; j++)
		{
			B[index] = A[j];
			index++;
		}
	}

	for (int k = 0; k < DATALENGTH; k++)
	{
		std::cout << B[k] << std::endl;
	}

	return 0;
}

int main()
{
	////InsertionAscSort   InsertionDecSort
	//int data[DATALENGTH] = { 1111,4,2,6,3,2,12,44,223,51 };
	//for (int i = 0; i < DATALENGTH; i++)
	//{
	//	std::cout << data[i] << std::endl;
	//}
	//InsertionDecSort(data, DATALENGTH);
	//std::cout << "..................." << std::endl;
	//for (int i = 0; i < DATALENGTH; i++)
	//{
	//	std::cout << data[i] << std::endl;
	//}

	////AddBINARY
	//int dataA[DATALENGTH] = { 1,0,0,1,1,1,0,1,1,0 };
	//int dataB[DATALENGTH] = { 1,0,0,1,1,1,0,1,1,1 };
	//int dataC[DATALENGTH + 1] = {};
	//AddBINARY(dataA, dataB, DATALENGTH, dataC);
	//for (int i = 0; i < DATALENGTH; i++)
	//{
	//	std::cout << dataA[i];
	//}
	//std::cout << std::endl;
	//for (int i = 0; i < DATALENGTH; i++)
	//{
	//	std::cout << dataB[i];
	//}
	//std::cout << std::endl;
	//for (int i = 0; i < DATALENGTH+1; i++)
	//{
	//	std::cout << dataC[i];
	//}
	//std::cout << std::endl;

	
	////Merge
	int dataA[DATALENGTH] = { 8,15,99,101,333,335,387,999,2,6,9,155,444,555,888};
	//int dataA[DATALENGTH] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	Merge(dataA, 7, 8, DATALENGTH-1);

	system("pause");

    return 0;
}

