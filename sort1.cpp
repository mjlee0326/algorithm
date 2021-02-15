#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVector(vector<int> array){
		for(int i=0; i<array.size(); i++){
			cout<<array[i]<<" ";
		}
		cout<<endl;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands){
	vector<int> answer;
	int min, temp, index;

	for(int i=0; i<commands.size(); i++){
		vector<int> copyArray(array);
		copyArray.erase(copyArray.begin()+commands[i][1], copyArray.begin()+copyArray.size()); 
		copyArray.erase(copyArray.begin(), copyArray.begin()+commands[i][0]-1); 
		

		//<sort>
		for(int i=0; i<copyArray.size(); i++){
			min=copyArray[i];
			temp=copyArray[i];
			for(int j=i+1; j<copyArray.size(); j++){
				if(min>copyArray[j]){
					min=copyArray[j];
					index=j;
				}
			}
			if(min!=temp){
				copyArray[i]=min;
				copyArray[index]=temp;
			}
		}
		//</sort>
		answer.push_back(copyArray[commands[i][2]-1]);
	}
	return answer;
}



int main(){
	int num;
	string strArray;
	string strNum;

	vector<int> array={1,5,2,6,3,7,4};
	vector<vector<int>> commands={{2,5,3},{4,4,1},{1,7,3},{2,5,2}};
	vector<int> answer;

	answer=solution(array, commands);

	printVector(answer);
	return 0;

}

/*
	cout<<"input array"<<endl;

	getline(cin, strArray);

	cout<<"init array>> "<<strArray<<endl;
	for(int k=0; k<2; k++){
		for(int i=0; i<strArray.length(); i++){
		//cout<<"current char>> "<<strArray.at(i)<<endl;

			if(strArray.at(i)==','){
				array.push_back(atoi(strNum.c_str()));
				strNum="";
			}
			else if(strArray.at(i)=='['){
				;
			}
			else if(strArray.at(i)==']'){
				array.push_back(atoi(strNum.c_str()));
				break;
			}
			else{
				strNum+=strArray.at(i);
			}
		}
	}
	
*/
