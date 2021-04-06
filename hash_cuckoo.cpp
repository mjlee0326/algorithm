#include <iostream>
#include <vector>

using namespace std;

class hash_map{
	vector<int> data1;
	vector<int> data2;

	int size;

	int hash1(int key) const{
		return key % size;
	}

	int hash2(int key) const{
		return (key / size) % size;
	}

public:
	hash_map(int n) : size(n){
		data1 = vector<int>(size, -1);
		data2 = vector<int>(size, -1);
	}

	vector<int>::iterator lookup(int key){ //O(1)
		auto hash_value1 = hash1(key);
		if(data1[hash_value1] == key){
			cout<<"found "<<key<<" in table1"<<endl;
			return data1.begin() + hash_value1;
		}
		auto hash_value2 = hash2(key);
		if(data2[hash_value2] == key){
			cout<<"found "<<key<<" in table2"<<endl;
			return data2.begin() + hash_value2;
		}

		return data2.end();
	}

	void erase(int key){
		auto position = lookup(key);

		if(position != data2.end()){
			*position = -1;
			cout<<"erase "<<key<<endl;
		}
		else{
			cout<<"fail erase "<<key<<" (not found)"<<endl;
		}
	}

	void insert(int key){
		insert_impl(key, 0, 1);
	}

	void insert_impl(int key, int cnt, int table){ //cnt == 재귀 호출 횟수

		//table의 크기보다 재귀횟수가 클 경우 cycle로 간주
		if(cnt >= size){ 
			cout<<"occure cycle! please rehashing"<<endl;
			return;
		}
		if(table == 1){
			int hash = hash1(key);
			if(data1[hash] == -1){
				data1[hash] = key;
				cout<<"insert "<<key<<" Table 1"<<endl;
			}
			else{
				int old = data1[hash];
				data1[hash] = key;
				cout<<"insert "<<key<<" Table 1 ---- move existing value "<<old<<endl;
				insert_impl(old, ++cnt, 2); //기존 key table2로 이동
			}
		}

		else{
			int hash = hash2(key);
			if(data2[hash] == -1){
				data2[hash] = key;
				cout<<"insert "<<key<<" Table 2"<<endl;
			}
			else{
				int old = data2[hash];
				data2[hash] = key;
				cout<<"insert "<<key<<" Table 2 ---- move existing value "<<old<<endl;
				insert_impl(key, ++cnt, 1);
			}
		}
	}

	void print(){
		cout<<"Index: ";
		for(int i = 0; i<size; i++)
			cout<<i<<"\t";
		cout<<endl;


		cout<<"Data1: ";
		for(const auto& i : data1)
			cout<<i<<"\t";
		cout<<endl;

		cout<<"Data2: ";
		for(const auto& i : data2)
			cout<<i<<"\t";
		cout<<endl;
	}
};


int main(){
	hash_map map(7);
	map.print();
	cout<<endl;

	map.insert(10);
	map.insert(20);
	map.insert(30);
	cout<<endl;

	map.insert(104);
	map.insert(2);
	map.insert(70);
	map.insert(9);
	map.insert(90);
	map.insert(2);
	map.insert(7);
	cout<<endl;

	map.print();
	cout<<endl;

	map.insert(14); //occure cycle

	return 0;
}
