#include <iostream>
#include <vector>

using namespace std;

class bloom_filter{
	vector<bool> data; //bloom은 실제값을 저장하지 않고 bool type 저장
	int nBits;

	int hash(int num, int key){
		switch(num){
			case 0:
				return key % nBits;
			case 1:
				return (key / 7) % nBits;
			case 2:
				return (key / 11) % nBits;
		}
		return 0;
	}

public:
	bloom_filter(int n) : nBits(n){
		data = vector<bool>(nBits, false);
	}
	
	void lookup(int key){
		bool result = data[hash(0, key)] & data[hash(1, key)] & data[hash(2, key)];

		if(result)
			cout<<key<<" 존재할 수도 있음"<<endl;
		else
			cout<<key<<" 존재하지 않음"<<endl;
	}

	void insert(int key){
		data[hash(0, key)] = true;
		data[hash(1, key)] = true;
		data[hash(2, key)] = true;
		cout<<"complete insert"<<key<<endl;

		for(const auto& i : data)
			cout<<i<<" ";
		cout<<endl;
	}
};

int main(){
	bloom_filter bf(7);
	bf.insert(100);
	bf.insert(54);
	bf.insert(82);

	bf.lookup(5);
	bf.lookup(50);
	bf.lookup(20);
	bf.lookup(54);

	return 0;
}
