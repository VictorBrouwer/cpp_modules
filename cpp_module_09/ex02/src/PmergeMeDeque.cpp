#if !defined(FJsorDeqUE_HPP)
#define FJsorDeqUE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <functional>
// #include "jacobNums.cpp"

std::deque<std::pair<int, int>>	MergeDeque(std::deque<std::pair<int, int>>& first, std::deque<std::pair<int, int>>& second);
void	insert(std::deque<int> &res, int item, int loc_high);
std::deque<int> mergeInsertSort(std::deque<std::pair<int, int>> &PairsDeque, int straggler, bool stragBool);
int binarySearch(std::deque<int> &res, int item, int low, int high);

std::deque<std::pair<int, int>>	MergeDeque(std::deque<std::pair<int, int>>& first, std::deque<std::pair<int, int>>& second)
{
	std::deque<std::pair<int, int>> result;

	auto iterFirst 	= first.begin();
	auto endFirst 	= first.end();
	auto iterSecond = second.begin();
    auto endSecond 	= second.end();
	while (iterFirst != endFirst && iterSecond != endSecond) {
        if (iterFirst->first <= iterSecond->first) {
            result.push_back(std::move(*iterFirst));
            iterFirst++;
        } else {
            result.push_back(std::move(*iterSecond));
            iterSecond++;
        }
    }
	result.insert(result.end(), iterFirst, endFirst);
    result.insert(result.end(), iterSecond, endSecond);
	return result;
}

std::deque<std::pair<int, int>> SortDequeBig(std::deque<std::pair<int, int>>& pairs){
	if (pairs.size() <= 1) {
        return pairs;
    }
	size_t middle = pairs.size() / 2;
	std::deque<std::pair<int, int>> first(pairs.begin(), pairs.begin() + middle);
	std::deque<std::pair<int, int>> second(pairs.begin() + middle, pairs.end());
	first  = SortDequeBig(first);
	second = SortDequeBig(second);
	return (MergeDeque(first, second));
}

std::deque<int> FJsorDeq(std::deque<int> &deq)
{
	bool stragBool = false; 
	int straggler = -1;
	int deqLen = deq.size() -1;
	std::deque<std::pair<int, int>> PairsDeque;
	if ((deqLen + 1) % 2 == 1)
	{
		straggler = deq[deqLen];
		deq.pop_back();
		stragBool = true;
	}
	for (int i = 1; i <= deqLen; i += 2)
	{
		int high, low;
		std::tie(low, high) = std::minmax(deq[i - 1], deq[i]);
        PairsDeque.push_back(std::make_pair(high, low));
	}
	PairsDeque = SortDequeBig(PairsDeque);

	return (mergeInsertSort(PairsDeque, straggler, stragBool));
}

std::deque<int> mergeInsertSort(std::deque<std::pair<int, int>> &PairsDeque, int straggler, bool stragBool)
{
	std::deque<int> res;
	for (auto it = PairsDeque.begin(); it != PairsDeque.end(); it ++)
		res.push_back(it->first);
	res.push_front(PairsDeque[0].second);
	std::deque<int> insertionSequence;
	getJacobNums(insertionSequence, PairsDeque.size());
	int lowerBound = 1;
	int index = 0;
	for (std::deque<int>::iterator it = insertionSequence.begin(); it != insertionSequence.end(); it++)
	{
		int upperBound = *it;
		while (upperBound >= lowerBound)
		{
			insert(res, PairsDeque[upperBound].second, upperBound + index);
			upperBound--;
			index++;
		}
		lowerBound = *it + 1;
	}
	int deqLen = PairsDeque.size() - 1;
	if (deqLen == 1)
		insert(res, PairsDeque[deqLen].second, deqLen + index);
	else if (insertionSequence.size() > 0 && deqLen > insertionSequence.back())
	{
		while (deqLen > insertionSequence.back())
		{
			insert(res, PairsDeque[deqLen].second, deqLen + index);
			deqLen--;
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

int binarySearch(std::deque<int> &res, int item, int low, int high)
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

void	insert(std::deque<int> &res, int item, int loc_high)
{
	int loc_item = binarySearch(res, item, 0, loc_high);
	res.insert(res.begin() + loc_item, item);
}

#endif // FJsorDeqUE_HPP
