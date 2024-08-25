#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <cassert>
#include <string>

#include "sorting.h"

template<typename Iterator>
using sortf_t = void(*)(Iterator, Iterator);

std::default_random_engine rengine(time(nullptr));

//tests a specifc sorting algorithm
template<typename Iterator>
void test_sorting_algorithm(void(*sortf)(Iterator begin, Iterator end));

template<typename Iterator>
bool test_sorted(Iterator begin, Iterator end);

int main(){

	std::vector<sortf_t<std::vector<int>::iterator>> sortfs = {
																insertion_sort,
																selection_sort,
																merge_sort
																};
	std::vector<std::string> names = 	{
											"insertion_sort",
											"selection_sort",
											"merge_sort"
										};

	for (int i = 0; i < sortfs.size(); i++){
		auto f = sortfs[i];
		std::cout << "Testing: " << names[i] << "\n\n";
		test_sorting_algorithm(f);
	}

	return 0;
}

template<typename Iterator>
bool test_sorted(Iterator begin, Iterator end){

	Iterator curr = ++begin;

	while (curr < end){
		if (*(curr) < *(curr-1)) return false;
		curr++;
	}
	return true;

}

template<typename Iterator>
void test_sorting_algorithm(void(*sortf)(Iterator begin, Iterator end)){

	//distribution
	std::uniform_int_distribution dist(0, 1000000);
	//generating vectors
	std::vector<int> V1(100, 0);
	std::vector<int> V2(1000, 0);
	std::vector<int> V3(10000, 0);

	for(int i = 0; i < V1.size(); i++) V1[i] = dist(rengine);
	for(int i = 0; i < V2.size(); i++) V2[i] = dist(rengine);
	for(int i = 0; i < V3.size(); i++) V3[i] = dist(rengine);

	//sorting
	sortf(V1.begin(), V1.end());
	assert(test_sorted(V1.begin(), V1.end()));
	std::cout << "100 items sorted" << "\n";
	sortf(V2.begin(), V2.end());
	assert(test_sorted(V2.begin(), V2.end()));
	std::cout << "10000 items sorted" << "\n";
	sortf(V3.begin(), V3.end());
	assert(test_sorted(V3.begin(), V3.end()));
	std::cout << "100000 items sorted" << "\n";
	std::cout << "Iteration CHECK" << "\n\n";


}
