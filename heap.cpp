#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct median{
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	//current mid value 보다 큰 값이면 min heap
	//작은 값이 들어오면 max heap에 push

	void insert(int data){
		if(maxHeap.size()==0){
			maxHeap.push(data);
			return;
		}
		if(maxHeap.size() == minHeap.size()){
			if(data <= get()) //insert value가 현재 중앙값보다 작거나 같음
				maxHeap.push(data);
			else
				minHeap.push(data);

			return;
		}
		if(maxHeap.size() < minHeap.size()){
			if(data > get()){ //minHeap이 더 큰 경우인데 minHeap에 들어가야 함
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(data);
			}
			else
				maxHeap.push(data);
		}
		//maxHeap.size()가 더 큰 경우 
		if(data < get()){ //maxHeap에 들어가야 함
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(data);
		}
		else //minHeap에 들어가야 함
			minHeap.push(data);
	}

	double get(){
		if(maxHeap.size() == minHeap.size())
			return (maxHeap.top() + minHeap.top()) / 2.0 ;

		if(maxHeap.size() < minHeap.size())
			return minHeap.top();

		return maxHeap.top();
	}
};


int main(){
	median med;

	med.insert(1);
	cout<<"1 삽입 후 중앙값: "<<med.get()<<endl;

	med.insert(5);
	cout<<"5 삽입 후 중앙값: "<<med.get()<<endl;

	med.insert(2);
	cout<<"2 삽입 후 중앙값: "<<med.get()<<endl;

	med.insert(10);
	cout<<"10 삽입 후 중앙값: "<<med.get()<<endl;

	med.insert(40);
	cout<<"40 삽입 후 중앙값: "<<med.get()<<endl;

	return 0;
}
