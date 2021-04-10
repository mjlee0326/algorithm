#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

bool linear_search(int N, vector<int>& S){
	for(auto i : S){
		if(i==N)
			return true;
	}
	return false;
}

bool binary_search(int N, vector<int>& S){

	auto first = S.begin();
	auto last = S.end();

	while(true){
		auto range_length = distance(first, last);
		auto mid_element_index = floor(range_length / 2);
		auto mid_element = *(first + mid_element_index);

		if(mid_element == N)
			return true;

		else if(mid_element > N)
			advance(last, -mid_element_index);
		
		else if(mid_element < N)
			advance(first, mid_element_index); 

		if(range_length == 1)
			return false;
	}
}

void run_small_search_test(){
	auto N = 2;

	vector<int> S {1, 3, 2, 4, 5, 7, 9, 8, 6};

	sort(S.begin(), S.end());

	if(linear_search(N, S))
		cout<<"Found by linear_search"<<endl;
	else
		cout<<"Not found by linear_search"<<endl;

	if(binary_search(N, S))
		cout<<"Found by binary_search"<<endl;
	else
		cout<<"Not found by binary_search"<<endl;

}

void run_large_search_test(int size, int N){
	vector<int> S;
	random_device rd;
	mt19937 rand(rd());

	//[1, size] random value
	uniform_int_distribution<mt19937::result_type> uniform_dist(1, size);

	for(auto i = 0; i < size; i++)
		S.push_back(uniform_dist(rand));


	sort(S.begin(), S.end());

	chrono::steady_clock::time_point begin = chrono::steady_clock::now();

	bool search_result = binary_search(N, S);

	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
	cout<<"Binary Excution time: "<<diff.count()<<endl;

	if(search_result)
		cout<<"Found element"<<endl;
	else
		cout<<"Not found element"<<endl;
		
}

int main(){
	
	run_small_search_test();


	run_large_search_test(100000, 36543);
	run_large_search_test(1000000, 36543);
	run_large_search_test(10000000, 36543);

	return 0;
}
