// 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define DATALENGTH 10

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
	int dataA[DATALENGTH] = { 1,0,0,1,1,1,0,1,1,0 };
	int dataB[DATALENGTH] = { 1,0,0,1,1,1,0,1,1,1 };
	int dataC[DATALENGTH + 1] = {};
	AddBINARY(dataA, dataB, DATALENGTH, dataC);
	for (int i = 0; i < DATALENGTH; i++)
	{
		std::cout << dataA[i];
	}
	std::cout << std::endl;
	for (int i = 0; i < DATALENGTH; i++)
	{
		std::cout << dataB[i];
	}
	std::cout << std::endl;
	for (int i = 0; i < DATALENGTH+1; i++)
	{
		std::cout << dataC[i];
	}
	std::cout << std::endl;
	system("pause");
	
    return 0;
}

