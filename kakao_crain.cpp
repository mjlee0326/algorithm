#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
		int size = board.size();
		int cnt[size]={0};

		for(int i = 0; i < size; i++){
			int j = size-1;
			while(board[i][j]==0){
				cnt[i]++;
				j--;
			}
		}
		for(auto c : cnt)
			cout<<c<<" ";

		cout<<endl;
		

    return answer;
}

int main(){
	cout<<solution({{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}}, {1, 5, 3, 5, 1, 2, 1, 4})<<endl;
	

	return 0;
}
