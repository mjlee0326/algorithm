#include <iostream>
#include <vector>

#define elem 5

using namespace std;

template <typename T>
auto partition(typename vector<T>::iterator begin, typename vector<T>::iterator end){
	auto pivot_val = *begin;
	auto left_iter = begin;
	auto right_iter = end;

	while(true){
		while(*left_iter <= pivot_val && left_iter != right_iter)
			left_iter++;

		while(*right_iter > pivot_val && left_iter != right_iter)
			right_iter--;

		if(left_iter == right_iter)
			break;
		else
			iter_swap(left_iter, right_iter);
	}

	if(pivot_val > *right_iter)
		iter_swap(begin, right_iter);

	return right_iter;
}

template <typename T>
auto partition_using_given_pivot(typename vector<T>::iterator begin, typename vector<T>::iterator end, typename vector<T>::iterator pivot){
	auto left_iter = begin;
	auto right_iter = end;

	while(true){
		//첫번째 원소부터 pivot보다 큰 수 탐색
		while(*left_iter < *pivot && left_iter != right_iter)
			left_iter++;

		while(*right_iter >= *pivot && left_iter != right_iter)
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

template <typename T>
void quick_sort(typename vector<T>::iterator begin, typename vector<T>::iterator last){
	if(distance(begin, last) >= 1){
		auto partition_iter = partition<T>(begin, last);

		quick_sort<T>(begin, partition_iter -1);

		quick_sort<T>(partition_iter, last);
	}
}

template <typename T>
auto find_median(typename vector<T>::iterator begin, typename vector<T>::iterator last){
	quick_sort<T>(begin,last);

	//중간 원소 반복자 반환
	return begin + (distance(begin, last) / 2);
}

//선형 시간 검색 알고리즘
//i번째로 작은 원소 찾기
template <typename T>
typename vector<T>::iterator linear_time_select(typename vector<T>::iterator begin, typename vector<T>::iterator last, size_t i){
	auto size = distance(begin, last);

	if(size > 0 && i < size){
		auto num_Vi = (size + 4) / elem; //부분 벡터 개수(마지막 vector를 제외한 각 vector는 다섯 개(elem)의 원소를 가짐)
		size_t j = 0;

	vector<T> M;
	for(; j < size/elem; j++){
		auto b = begin + (j * elem);
		auto l = begin + (j * elem) + elem;

		M.push_back(*find_median<T>(b, l)); 
	}

	if(j* 5 < size){ //마지막 vector
		auto b = begin + (j * elem);
		auto l = begin + (j * elem) + (size % elem);

		M.push_back(*find_median<T>(b, l));
	}

	auto median_of_medians = (M.size() == 1) ? M.begin() :
		linear_time_select<T>(M.begin(), M.end(), M.size() / 2); // i = M.size() / 2 -> 중앙값 찾기

	//분랑 연산 적용 및 pivot q의 위치 k 찾음
	auto partition_iter = partition_using_given_pivot<T>(begin, last, median_of_medians);
	auto k = distance(begin, partition_iter) + 1;

	if(i == k)
		return partition_iter;
	
	else if(i < k)
		return linear_time_select<T>(begin, partition_iter-1, i);

	else if(i > k)
		return linear_time_select<T>(partition_iter+1, last, i-k);
	}
	else
		return begin;
}


template <typename T>
vector<T> merge(vector<T>& arr1, vector<T>& arr2){
	vector<T> merged;

	auto iter1 = arr1.begin();
	auto iter2 = arr2.begin();

	while(iter1 != arr1.end() && iter2 != arr2.end()){
		if(*iter1 < *iter2){
			merged.emplace_back(*iter1);
			iter1++;
		}
		else{
			merged.emplace_back(*iter2);
			iter2++;
		}
	}

	if(iter1 != arr1.end()){
		for(; iter1 != arr1.end(); iter1++)
			merged.emplace_back(*iter1);
	}
	else{
		for(; iter2 != arr2.end(); iter2++)
			merged.emplace_back(*iter2);
	}

	return merged;
}

template <typename T>
vector<T> merge_sort(vector<T> arr){
	if(arr.size() > 1){
		auto mid = size_t(arr.size() / 2 );
		auto left_half = merge_sort(vector<T>(arr.begin(), arr.begin() + mid));
		auto right_half= merge_sort(vector<T>(arr.begin() + mid, arr.end()));

		return merge<T>(left_half, right_half);
	}
	return arr;
}

template <typename T>
void print_vector(vector<T> arr){
	for(auto i : arr)
		cout<<i<<" ";
	cout<<endl;
}

void run_linear_select_test(){
	vector<int> S1 {45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7};
	cout<<"input vector"<<endl;
	print_vector<int>(S1);

	cout<<"sorted vector"<<endl;
	print_vector<int>(merge_sort<int>(S1));

	cout<<"index 3: "<<*linear_time_select<int>(S1.begin(), S1.end()-1, 3)<<endl;
	cout<<"index 5: "<<*linear_time_select<int>(S1.begin(), S1.end()-1, 5)<<endl;
	cout<<"index 11: "<<*linear_time_select<int>(S1.begin(), S1.end()-1, 11)<<endl;
}

int main(){
	run_linear_select_test();
	return 0;
}
