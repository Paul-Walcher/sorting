/*
This file contains an implementation of different sorting algorithms.
Every function receives two pointers/iterators to the begin and the end.
Every item to be sorted needs to implement operator<, operator<= and operator==.
*/

#ifndef __SORTING__
#define __SORTING__

#include <vector>

//insertion sort
template<typename Iterator>
void insertion_sort(Iterator begin, Iterator end){

	size_t size = (end - begin);

	for(size_t i = 1; i < size; i++){

		size_t j = i;

		while (j > 0 && *(begin + j - 1) > *(begin + j)){

			std::swap(*(begin + j - 1), *(begin + j));
	
			j--;


		}

	}

}

//selection sort
template<typename Iterator>
void selection_sort(Iterator begin, Iterator end){

	size_t size = (end - begin);

	for(size_t i = 0; i < (size-1); i++){

		Iterator smallest = (begin + i);

		for(Iterator next = (begin + i + 1); next < end; next++){
			if (*(next) < *(smallest)) smallest = next;
		}

		std::swap(*(begin + i), *(smallest));

	}

}

//merge sort
template<typename Iterator>
void merge(Iterator begin, Iterator middle, Iterator end);

template<typename Iterator>
void merge_sort(Iterator begin, Iterator end){

	size_t size = (end - begin);

	if (size <= 1) return;

	Iterator middle = begin + (size >> 1);

	merge_sort(begin, middle);
	merge_sort(middle, end);
	merge(begin, middle, end);
}

template<typename Iterator>
void merge(Iterator begin, Iterator middle, Iterator end){

	size_t size = (end - begin);

	std::vector<typename Iterator::value_type> V;

	Iterator i1 = begin;
	Iterator i2 = middle;

	while (i1 < middle && i2 < end){

		if (*(i1) < *(i2)){
			V.push_back(*(i1));
			i1++;
		}
		else{
			V.push_back(*(i2));
			i2++;
		}

	}

	while (i1 < middle){
		V.push_back(*(i1));
		i1++;
	}

	while (i2 < end){
		V.push_back(*(i2));
		i2++;
	}

	for (size_t i = 0; i < size; i++){
		*(begin + i) = V[i];
	}

}

#endif