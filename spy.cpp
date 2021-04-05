#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> m;

	for(const auto& c : clothes){
		m[c[1]]++;
	}

	auto it = m.begin();
	while(it != m.end()){
		answer*=(it -> second) + 1;
		it++;
	}
	
	return --answer;
}

int main(){
	int answer;

	answer = solution({{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}});
	cout<<answer<<endl;

	answer = solution({{"corwmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}});
	cout<<answer<<endl;

	return 0;
}
