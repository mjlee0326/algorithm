#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void print(unordered_set<int>& container){
	for(const auto& element : container)
		cout<<element<<" ";
	cout<<endl;
}

void print(unordered_map<int, int>& container){
	for(const auto& element : container)
		cout<<element.first<<" -> "<<element.second<<", ";
	cout<<endl;
}

void find(unordered_set<int>& container, const int element){
	cout<<"search "<<element<<": ";
	if(container.find(element) == container.end())
		cout<<"not found "<<element<<endl;
	else
		cout<<"Successfully found "<<element<<endl;
}

void find(unordered_map<int, int>& container, const int element){
	cout<<"search "<<element<<": ";
	auto it = container.find(element);
	if(it == container.end())
		cout<<"not found "<<element<<endl;
	else
		cout<<"Successfully found  "<<it -> second<<endl;
}

int main(){
	cout<<"------------------------------------"<<endl;
	cout<<"unordered_set"<<endl;
	cout<<"------------------------------------"<<endl;
	unordered_set<int> set1 = {1,2,3,4,5};

	cout<<"set1 init value: ";
	print(set1);

	set1.insert(2);
	cout<<"insert 2: ";
	print(set1);

	set1.insert(10);
	set1.insert(300);
	cout<<"insert 10, 300: ";
	print(set1);

	find(set1, 4);
	find(set1, 100);

	set1.erase(2);
	cout<<"delete 2: ";
	print(set1);

	find(set1, 2);

	cout<<"------------------------------------"<<endl;
	cout<<"unoredered_map"<<endl;
	cout<<"------------------------------------"<<endl;

	unordered_map<int, int> map1; //square

	map1.insert({2, 4});
	map1[3] = 9;
	cout<<"square of 2, 3: ";
	print(map1);

	map1[20] = 400;
	map1[30] = 900;
	cout<<"square of 20, 30: ";
	print(map1);

	find(map1, 10);
	find(map1, 20);

	cout<<"map1[30] = "<<map1[3]<<endl;
	cout<<"map1[100] = "<<map1[100]<<endl;
	print(map1);

	return 0;
}
