#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
		int size = board.size();
		int cnt[size];
		deque<int> stack;

		for(int i = 0; i < size; i++){
			int j = 0;
			cnt[i] = 0;
			while(board[j][i]==0){
				cnt[i]++;
				j++;
			}
		}

			
		for(auto m : moves){
			if(cnt[m-1] >= board.size())
				continue;
			int cur_cnt = cnt[m-1];
			int value = board[cur_cnt][m-1];	
			stack.push_back(value);
			cnt[m-1]++;
			
			if(stack.size()>1){
				auto it = stack.end()-1;
				auto second = it - 1;
				if(*it == *second){
					answer+=2;
					stack.pop_back();
					stack.pop_back();
				}
			}
		}

    return answer;
}

int main(){
	cout<<solution({{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}}, {1, 5, 3, 5, 1, 2, 1, 4})<<endl;
	

	return 0;
}
