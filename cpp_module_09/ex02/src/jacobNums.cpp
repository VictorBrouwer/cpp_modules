#include <deque>

int jacobsthalNumber(int limit)
{
	if (limit < 4)
		return 3;
    int jacobsthalPrev = 0;
    int jacobsthalCurr = 1;
    int jacobsthalNext = jacobsthalPrev * 2 + jacobsthalCurr;

    while (jacobsthalNext < limit) {
        jacobsthalPrev = jacobsthalCurr;
        jacobsthalCurr = jacobsthalNext;
        jacobsthalNext = jacobsthalPrev * 2 + jacobsthalCurr;
    }
    return jacobsthalCurr;
}

void getJacobNums(std::deque<int> &insertionSequence, int lenMainChain)
{
	int maxJ = lenMainChain + 1;
	while (maxJ > 3)
	{
		maxJ = jacobsthalNumber(maxJ);
		insertionSequence.push_front(maxJ - 1); // - 1 because of indexing
	}
}