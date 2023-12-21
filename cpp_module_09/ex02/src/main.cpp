#include "PmergeMeVector.cpp"
#include "PmergeMeDeque.cpp"
#include <chrono>
#include <algorithm>
#include <cassert>

double	PmergeMeDeq(int argc, char **argv)
{
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	std::deque<int> deque;
	for (int i = 1; i < argc; i++)
	{
		try	{
			deque.push_back(std::atoi(argv[i]));
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	std::deque<int> res = FJsorDeq(deque);
	assert(std::is_sorted(res.begin(), res.end()));
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	std::cout << "After:  ";
	for (std::deque<int>::iterator it = res.begin(); it < res.end(); it++)
		std::cout << *it << " ";
	return duration;
}

double	PmergeMeVec(int argc, char **argv)
{
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	std::vector<int> vec;
	vec.reserve(argc - 1);
	for (int i = 1; i < argc; i++)
	{
		try {
			vec.push_back(std::atoi(argv[i]));
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	std::vector<int> res;
	res = FJsortVec(vec);
	assert(std::is_sorted(res.begin(), res.end()));
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	return duration;
}

int main(int argc, char **argv)
{
	if (argc <= 2) {
		std::cerr << "Not enough arguments provided " << std::endl;
		return 1;
	}
	std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << "\n";
	double durVec, durDeq;
	durVec = PmergeMeVec(argc, argv);
	durDeq = PmergeMeDeq(argc, argv);
	std::cout << "\nTime to process a range of " << argc - 1 << " elements with std::vector : " << durVec/10000 << " us\n";
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : " << durDeq/10000 << " us\n";
	// int len = argc - 1;
	// std::vector<int> vec;
	// vec.reserve(len);
	// for (int i = 1; i < argc; i++)
	// {
	// 	try {
	// 		vec.push_back(std::atoi(argv[i]));
	// 	}
	// 	catch(const std::exception& e){
	// 		std::cerr << e.what() << '\n';
	// 	}
	// }
	// std::vector<int> res;
	// res = FJsortVec(vec);
	// std::cout << "-----sorted-----" << std::endl;
	// for (std::vector<int>::iterator it = res.begin(); it < res.end(); it++)
	// 	std::cout << *it << " - ";
	// std::cout << "\n";
	// std::deque<int> deque;
	// for (int i = 1; i < argc; i++)
	// {
	// 	try	{
	// 		deque.push_back(std::atoi(argv[i]));
	// 	}
	// 	catch(const std::exception& e){
	// 		std::cerr << e.what() << '\n';
	// 	}
	// }
	// std::deque<int> res2 = FJsorDeq(deque);
	// for (std::deque<int>::iterator it = res2.begin(); it < res2.end(); it++)
	// 	std::cout << *it << " - ";
}