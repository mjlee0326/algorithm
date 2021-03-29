#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	int cnt;
	int i=0;

	vector<int> answer;
	vector<int> copy = prices;

  for(int i = 0; i < prices.size(); i++){
    auto it_prices = prices.begin() + i;
    auto it_compare = it_prices + 1;
    cnt=0;
    while(it_compare!=prices.end()){
      cnt++;
      if(*it_prices > *it_compare){ //하락 시점
        break;
      }   
      it_compare+=1;
    }   

    answer.insert(answer.end(), cnt);
	}
	return answer;
}

int main(){
	vector<int> answer;
	answer = solution({1, 2, 3, 2, 3});

	for(int i = 0; i < answer.size(); i++){
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	return 0;
}
