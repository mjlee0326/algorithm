#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
		int sum = 0;
		vector<int> cnt;

		auto it_truck=truck_weights.begin();

    while(!truck_weights.empty()){
			sum+=*(it_truck+cnt.size());
			if(sum<=weight){ //새로운 트럭이 지나갈 수 있음
				cnt.insert(cnt.end(),0); //Add new truck cnt
			}
			else{ //못 지나감 
				sum-=*(it_truck+cnt.size());
			}
			for(int i = 0; i < cnt.size(); i++){
				cnt[i]+=1;
			}
			while(!cnt.empty() && cnt.front()==bridge_length){ //다리 건너기 완료
				sum-=*(it_truck);
				truck_weights.erase(truck_weights.begin());
				cnt.erase(cnt.begin());
			}
			answer++;
    }

		answer++;
		cout<<answer<<endl;
    return answer;
}

int main(){
	vector <int> test3 (10, 10);
	solution(2, 10, {7,4,5,6});
	solution(100, 100, {10});
	solution(100, 100, test4);
	return 0;
}
