#include <iostream>
#include <vector>

using namespace std;
using uint = unsigned int;

class hash_map{
	vector<int> data;

	public:
		hash_map(size_t n){
			data = vector<int>(n, -1);
		}

		//현재 해시 값이 중복될 경우 덮어쓰기
		void insert(uint value){
			int n = data.size();
			if(data[value % n]!=-1)
				cout<<"overwrite: "<<data[value % n]<<" -> "<<value<<endl;
			data[value % n] = value;
			cout<<"insert "<<value<<endl;
		}

		bool find(uint value){
			int n = data.size();
			return (data[value % n] == value);
		}

		void erase(uint value){
			if(find(value)){
				data[value % value] = -1;
				cout<<"delete "<<value<<endl;
			}
		}
};

int main(){
	hash_map map(7);

	auto print = [&](int value){
		if(map.find(value))
			cout<<"find "<<value<<" in hash map"<<endl;
		else
			cout<<"could not find "<<value<<" in hash map"<<endl;
	};

	map.insert(2);
	map.insert(25);
	map.insert(10);
	print(25);

	map.insert(100);
	print(100);
	print(2);

	map.erase(25);

	return 0;
}
