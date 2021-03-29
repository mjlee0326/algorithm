#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	int cnt;

	vector<int> answer;

	while(!prices.empty()){
		auto it_prices = prices.begin();
		auto it_compare = prices.begin()+1;
		cnt=0;
		while(it_compare!=prices.end()){
			cvector<int> solution(vector<int> prices) {
  int cnt;

  vector<int> answer;

  while(!prices.empty()){
    auto it_prices = prices.begin();
    auto it_compare = prices.begin()+1;
    cnt=0;
    while(it_compare!=prices.end()){
      cnt++;
      if(*it_prices > *it_compare){ //하락 시점
        break;
      }   
      it_compare+=1;
    }   
    answer.insert(answer.end(), cnt);
    prices.erase(prices.begin());
  }
  return answer;
nt++;
			if(*it_prices > *it_compare){ //하락 시점
				break;
			}
			it_compare+=1;
		}
		answer.insert(answer.end(), cnt);
		prices.erase(prices.begin());
	}
	return answer;
}

int main(){
	vector<int> answer;
	answer = solution({1, 2, 3, 2, 3});

	for(int i = 0; i < answer.size(); i++){
		cout<<answer[i];
	}
	cout<<endl;
	return 0;
}
