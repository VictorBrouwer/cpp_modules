#if !defined(FJsortVec_HPP)
#define FJsortVec_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <functional>
#include "jacobNums.cpp"

void mergePairs(std::vector<std::vector<int> > &Pairsvector, int const left, int const mid, int const right);
std::vector<int> mergeInsertSort(std::vector<std::vector<int> > &Pairsvector, int straggler, bool stragBool);
void	insert(std::vector<int> &res, int item, int loc_high);
int binarySearch(std::vector<int> &res, int item, int low, int high);

void reSortPairs(std::vector<std::vector<int> > &Pairsvector, int const begin, int const end)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	reSortPairs(Pairsvector, begin, mid);
	reSortPairs(Pairsvector, mid + 1, end);
	mergePairs(Pairsvector, begin, mid, end);
}

void mergePairs(std::vector<std::vector<int> > &Pairsvector, int const left, int const mid, int const right)
{
	int const leftVecLen = mid - left + 1;
	int const rightVecLen = right - mid;
 
	std::vector<std::vector<int> > leftVec;
	std::vector<std::vector<int> > rightVec;
	for (int i = 0; i <= leftVecLen; i++)
	{
		std::vector<int> pair;
		pair.push_back(Pairsvector[left + i][0]);
		pair.push_back(Pairsvector[left + i][1]);
		leftVec.push_back(pair);
	}
	for (int j = 0; j < rightVecLen; j++)
	{
		std::vector<int> pair;
		pair.push_back(Pairsvector[mid + 1 + j][0]);
		pair.push_back(Pairsvector[mid + 1 + j][1]);
		rightVec.push_back(pair);
	}
 
	int leftIndex = 0, rightIndex = 0;
	int indexOfMergedVec = left;
	
	while (leftIndex < leftVecLen && rightIndex < rightVecLen) {
		if (leftVec[leftIndex][0] <= rightVec[rightIndex][0]) {
			Pairsvector[indexOfMergedVec] = leftVec[leftIndex];
			leftIndex++;
		}
		else {
			Pairsvector[indexOfMergedVec] = rightVec[rightIndex];
			rightIndex++;
		}
		indexOfMergedVec++;
	}
	while (leftIndex < leftVecLen) {
		Pairsvector[indexOfMergedVec] = leftVec[leftIndex];
		leftIndex++;
		indexOfMergedVec++;
	}
	while (rightIndex < rightVecLen) {
		Pairsvector[indexOfMergedVec] = rightVec[rightIndex];
		rightIndex++;
		indexOfMergedVec++;
	}
}

std::vector<int> FJsortVec(std::vector<int> &vec)
{
	bool stragBool = false; 
	int straggler = -1;
	int vecLen = vec.size() -1;
	std::vector<std::vector<int> > Pairsvector;
	if ((vecLen + 1) % 2 == 1)
	{
		straggler = vec[vecLen];
		vec.pop_back();
		stragBool = true;
	}
	for (int i = 1; i <= vecLen; i += 2)
	{
		std::vector<int> pair;
		if (vec[i - 1] > vec[i])
		{
			pair.push_back(vec[i - 1]);
			pair.push_back(vec[i]);
		}
		else
		{
			pair.push_back(vec[i]);
			pair.push_back(vec[i - 1]);
		}
		Pairsvector.push_back(pair);
	}
	reSortPairs(Pairsvector, 0, Pairsvector.size() - 1);
	// std::cout << "len  = " << Pairsvector.size() << "\n";
	// for (size_t i = 0; i < Pairsvector.size(); i ++)
	// 	std::cout << Pairsvector[i][0] << "\n";
	return (mergeInsertSort(Pairsvector, straggler, stragBool));
}

std::vector<int> mergeInsertSort(std::vector<std::vector<int> > &Pairsvector, int straggler, bool stragBool)
{
	std::vector<int> res;
	for (size_t i = 0; i < Pairsvector.size(); i ++)
		res.push_back(Pairsvector[i][0]);
	res.insert(res.begin(), Pairsvector[0][1]);
	std::deque<int> insertionSequence;
	getJacobNums(insertionSequence, Pairsvector.size());
	int lowerBound = 1;
	int index = 0;
	for (std::deque<int>::iterator it = insertionSequence.begin(); it != insertionSequence.end(); it++)
	{
		int upperBound = *it;
		while (upperBound >= lowerBound)
		{
			insert(res, Pairsvector[upperBound][1], upperBound + index);
			upperBound--;
			index++;
		}
		lowerBound = *it + 1;
	}
	int vecLen = Pairsvector.size() - 1;
	if (vecLen == 1)
		insert(res, Pairsvector[vecLen][1], vecLen + index);
	else if (insertionSequence.size() > 0 && vecLen > insertionSequence.back())
	{
		while (vecLen > insertionSequence.back())
		{
			insert(res, Pairsvector[vecLen][1], vecLen + index);
			vecLen--;
			index++;
		}
	}
	if (stragBool)
	{
		int loc_straggler = binarySearch(res, straggler, 0, res.size() - 1);
		res.insert(res.begin() + loc_straggler, straggler);
	}
	return res;
}

int binarySearch(std::vector<int> &res, int item, int low, int high)
{
	if (high <= low)
		return (item > res[low]) ? (low + 1) : low;
	int mid = (low + high) / 2;
	if (item == res[mid])
		return mid + 1;
	if (item > res[mid])
		return binarySearch(res, item, mid + 1, high);
	return binarySearch(res, item, low, mid - 1);
}

void	insert(std::vector<int> &res, int item, int loc_high)
{
	int loc_item = binarySearch(res, item, 0, loc_high);
	res.insert(res.begin() + loc_item, item);
}

#endif // FJsortVec_HPP
