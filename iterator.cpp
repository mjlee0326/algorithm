#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

int main(){
	vector<string> vec={
		"클라라", "클라라", "맷스미스", "데이비드테넌트", "피터카팔디", "데이비드테넌드", "아멜리아폰드", "아멜리아폰드", "로즈 타일러"
	};

	auto it = vec.begin();
	cout<<"최근 우승자: "<<*it<<endl;

	it+=8;
	cout<<"8년 전 우승자: "<<*it<<endl;

	advance(it, -3);
	cout<<"그 후 3년 전 우승자: "<<*it<<endl;
}
