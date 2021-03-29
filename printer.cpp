#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
		int cur_prio;

		while(1){
			auto it_prio = priorities.begin();
			int findBiggerPrio = 0;
			cur_prio = *it_prio;
			it_prio++;
			for(; it_prio!=priorities.end(); it_prio++){
				if(cur_prio < *it_prio){ //더 큰 우선순위 발견
					priorities.erase(priorities.begin());
					priorities.insert(priorities.end(), cur_prio);
					if(location > 0){ //내가 요청한 문서 순서 앞당겨짐 
						location--;
					}
					else{ //방금 밀려난 인쇄 대기가 내가 요청한 문서라면
					 location = priorities.size() - 1; //맨 뒤로
					}
					findBiggerPrio = 1;
					break;
				}
			}
			if(!findBiggerPrio){ //현재 문서가 가장 큰 우선순위라면
				answer++;
				if(location == 0){ //내가 요청한 문서라면 
					break;
				}
				priorities.erase(priorities.begin());
				location--;
			}
		}
    return answer;
}

int main(){
	int answer;
	answer = solution({2, 1, 3, 2}, 2);
	cout<<answer<<endl;
	answer = solution({1, 1, 9, 1, 1, 1}, 0);
	cout<<answer<<endl;

	return 0;
}
