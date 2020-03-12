// 4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#define DATALENGTH 16

int maximumSubarrayForce(int* data,int dataLength, std::vector<int>& subData, int& sum)
{
	sum = data[0];
	for (int i = 0; i < dataLength; i++)
	{
		int tempSum = data[i];
		for (int j = i + 1; j < dataLength; j++)
		{
			tempSum = tempSum + data[j];
			if (tempSum > sum)
			{
				sum = tempSum;
			}
		}
	}
	return 0;
}


int main()
{
	int data[DATALENGTH] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,15,-5,-22,15,-4,7 };
	int sum;
	std::vector<int> sumData;
	maximumSubarrayForce(data, DATALENGTH, sumData, sum);
	std::cout << "sum::" << sum << std::endl;
	system("pause");
    return 0;
}

