#include <iostream>
#include <vector>

using namespace std;

template <typename T>
auto find_median(typename vector<T>::iterator begin, typename vector<T>::iterator last){
	//와,,정렬,,,편하네,,,
	quick_sort<T>(begin,last);

	//중간 원소 반복자 반환
	return begin + (distance(begin, last) / 2);
}

template <typename T>
auto partition_using_given_piot(typename vector<T>::iterator begin, typename vector<T>::iterator end, typename vector<T>::iterator pivot){
	auto left_iter = begin;
	auto right_iter = end;

	while(true){
		//첫번째 원소부터 pivot보다 큰 수 탐색
		while(*left_iter < *pivot && left_iter != right_iter)
			left_iter++;

		while(*right_iter >= *pivot && left_lter != right_iter)
			right_iter--;

		//left_iter == right_iter -> 교환할 원소 없음
		//          !=            -> 교환

		if(left_iter == right_iter)
			break;
		else
			iter_swap(left_iter, right_iter);
	}

	if(*pivot > *right_iter)
		iter_swap(pivot, right_iter);

	return right_iter;
}



