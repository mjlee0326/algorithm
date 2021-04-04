#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void print(unordered_set<int>& container){
	for(const auto& element : container)
		cout<<element<<" ";
	cout<<endl;
}

void print(unorederd_map<int, int>& container){
	for(const auto& element : container)
		cout<<element.first<<": "<<element.second<<", ";
	cout<<endl;
}

void find(unorderd_set<int>& container, const int element){
	if(container.find(element) == container.end())
		cout<<"not found "<<element<<endl;
	else
		cout<<"Successfully found "<<element<<endl;
}

void find(unorderd_map<int>& container, const int element){
	auto it = container.find(element);
	if(it == coontainer.end())
		cout<<"not found "<<element<<endl;
	else
		cout<<"Successfully found  "<<it -> second<<endl;
}

int main(){
	cout<<"unorderd_set"<<endl;
	unordert_set<int> set1 = {1,2,3,4,5};

	cout<<"set1 init value: "<<print(set1);

	set1.insert(2);
	cout<<"insert 2: "<<print(set1);

	set1.insert(10);
	set1.insert(300);
	cout<<"insert 10, 300: "<< print(set1);

	find(set1, 4);
	find(set1, 100);

	set1.erase(2);
	cout<<"delete 2: "<<print(set1);

	find(set1, 2);

	return 0;
}
