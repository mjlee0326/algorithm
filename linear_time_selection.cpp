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


