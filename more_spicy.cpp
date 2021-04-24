#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
		int first, second, result = 0; 
		priority_queue<int, vector<int>, greater<int>> heap;

		for(auto s : scoville)
			heap.push(s);

		while(!heap.empty()){
			first = heap.top();
			heap.pop();
			second = heap.top();
			heap.pop();
			result = first + (second * 2);
			heap.push(result);
			answer++;
			if(heap.top() >= K)
				return answer;
			if(heap.size() == 1)
				return -1;
		}
}

int main(){
	int answer;
	
	answer = solution({1, 2, 10, 3, 9, 12}, 7);
	cout<<answer<<endl;
	answer = solution({0, 0, 0, 0}, 7);
	cout<<answer<<endl;
	return 0;
}


