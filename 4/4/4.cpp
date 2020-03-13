// 4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#define DATALENGTH 16


using namespace std;

#define Minium -10000

typedef struct Node {  //return type 
	int low;
	int high;
	int sum;
}Node;


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


//当最大子数组横跨中点时
Node Find_CrossMax_Subarry(vector<int> &A, int p, int mid, int r)
{
	Node maxLeft,maxRight,maxCross;
	maxLeft.low = 0;
	maxLeft.sum = Minium; 
	maxRight.high = 0;
	maxRight.sum = Minium;


	int tempLeftSum = 0;
	for (int i = mid; i >= p; i--)
	{
		tempLeftSum += A[i];
		if (maxLeft.sum < tempLeftSum)
		{
			maxLeft.sum = tempLeftSum;
			maxLeft.low = i;
		}
	}

	int tempRightSum = 0;
	for (int i = mid+1; i <= r; i++)
	{
		tempRightSum += A[i];
		if (maxRight.sum < tempRightSum)
		{
			maxRight.sum = tempRightSum;
			maxRight.high = i;
		}
	}

	maxCross.low  = maxLeft.low;
	maxCross.high = maxRight.high;
	maxCross.sum = maxLeft.sum + maxRight.sum;

	return maxCross;
}


Node Find_Max_Subarry(vector<int> &A, int low, int high)
{
	Node Res;
	Node Left, Right,Cross;
	if (low == high)
	{
		Res.low  = low;
		Res.high = high;
		Res.sum = A[low];
		return Res;
	}

	int mid = (high - low) / 2 + low;
	Left  = Find_Max_Subarry(A, low, mid);
	Right = Find_Max_Subarry(A, mid + 1, high);
	Cross = Find_CrossMax_Subarry(A, low, mid, high);

	if (Left.sum >= Right.sum && Left.sum >= Cross.sum)
	{
		return Left;
	}
	else if (Right.sum > Left.sum && Right.sum > Cross.sum)
	{
		return Right;
	}
	else if (Cross.sum > Left.sum && Cross.sum > Right.sum)
	{
		return Cross;
	}

}


int main()
{
	////maximumSubarrayForce
	/*int data[DATALENGTH] = { 13,-3,-25,20,-3,-16,-23,18,21,-7,15,-5,-22,15,-4,7 };
	int sum;
	std::vector<int> sumData;
	maximumSubarrayForce(data, DATALENGTH, sumData, sum);
	std::cout << "sum::" << sum << std::endl;*/


	////Find_Max_Subarry
	vector<int> A = { 13,-3,-25,20,-3,-16,-23,18,21,-7,12,-5,-22,15,-4,7 };
	int len = A.size();
	Node res;
	res = Find_Max_Subarry(A, 0, DATALENGTH-1);  //求最大子数组
	cout << res.low << " " << res.high << " " << res.sum << endl;
	system("pause");
    return 0;
}

