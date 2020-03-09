// 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define DATALENGTH 16

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

int mergedata(int* data,int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int k = 0;
	int* copy = new int[end];

	while (i <= mid && j <= end)
	{
		if (data[i] <= data[j])
		{
			copy[k++] = data[j++];
		}
		else if (data[i] > data[j])
		{
			copy[k++] = data[i++];
		}
	}
	while (i <= mid)
	{
		copy[k++] = data[i++];
	}
	while (j <= end)
	{
		copy[k++] = data[j++];
	}
	for (int i = 0; i < k; ++i)
		data[start + i] = copy[i];

	delete[] copy;
	return 0;
}

int  mergesort(int* data,int start, int end)
{
	if (start == end)
	{
		return 0;
	}
	if (start < end)
	{
		//int mid = ((end - start) >> 1) + start;
		int mid = ((end - start) /2) + start;
		mergesort(data, start, mid);
		mergesort(data, mid + 1 , end);
		mergedata(data,start, mid, end);
	}
	return 0;
}

void mergeSort(int* data, int length)
{
	if (data == nullptr || length <= 0)
		return;
	mergesort(data, 0, length - 1);

}

int binarySearch(int* data, int start, int end, int searchData, int* index)
{
	if (end - start == 0)
	{
		*index = start;
		return 0;
	}
	int middle = (end - start) / 2 + start;
	if (searchData > data[middle])
	{
		binarySearch(data, middle + 1, end, searchData, index);
	}
	else if (searchData < data[middle])
	{
		binarySearch(data, start, middle - 1, searchData, index);
	}
	else
	{
		*index = middle;
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

	
	////MergeSort
	int dataA[DATALENGTH] = { 18,15,969,1081,333,3535,37,99,2,6,9,155,444,555,6,-5};
	//int dataA[DATALENGTH] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	//Merge(dataA, 7, 8, DATALENGTH-1);
	mergeSort(dataA,DATALENGTH);
	for (int i = 0; i < DATALENGTH; i++)
	{
		std::cout << dataA[i] << std::endl;
	}
	system("pause");

    return 0;
}

