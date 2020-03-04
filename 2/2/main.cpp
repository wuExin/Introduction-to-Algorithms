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


int main()
{
	int data[DATALENGTH] = { 1111,4,2,6,3,2,12,44,223,51 };
	for (int i = 0; i < DATALENGTH; i++)
	{
		std::cout << data[i] << std::endl;
	}
	InsertionDecSort(data, DATALENGTH);
	std::cout << "..................." << std::endl;
	for (int i = 0; i < DATALENGTH; i++)
	{
		std::cout << data[i] << std::endl;
	}
	system("pause");
	
    return 0;
}

