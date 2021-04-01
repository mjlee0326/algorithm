#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
using uint = unsigned int;

struct hash_map{
	vector<list<int>> data;

	public:
		hash_map(int n){
			data.resize(n);
		}

		void insert(int value){
			int n = data.size();
			data[value % n].push_back(value);
			cout<<"insert "<<value<<endl;
		}

		bool find_value(int value){
			int n = data.size();
			for(const auto& d: data[value % n]){
				if(d == value)
					return true;
			}
			return false;

			//auto& entries = data[value % n];
			//return find(entries.begin(), entries.end(), value) != entries.end();
		}

		void erase(int value){
			int n = data.size();
			auto& entries = data[value % n];
			auto iter = find(entries.begin(), entries.end(), value);

			if(iter != entries.end()){
				entries.erase(iter);
				cout<<"delete "<<value<<endl;
			}
		}
};


int main(){
  hash_map map(7);

  auto print = [&](int value){
    if(map.find_value(value))
      cout<<"find "<<value<<" in hash map"<<endl;
    else
      cout<<"could not find "<<value<<" in hash map"<<endl;
  };

  map.insert(2);
  map.insert(25);
  map.insert(10);

  map.insert(100);
	map.insert(55);

  print(100);
  print(2);

  map.erase(2);

  return 0;
}


