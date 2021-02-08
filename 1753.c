#include <stdio.h>

int main(){
	int numE; //edge 총 개수
	int numV; //vertex 총 개수
	int startV;

	scanf("%d", &numV);
	scanf("%d", &numE);
	scanf("%d", &startV);

	//문제는 1부터 시작하는데, 배열 0부터 쓰기 헷갈려서 [0]은 그냥 쓰레기값으로 냅둠
	int length[numV+1];
	int weight[numV+1][numV+1];

	int a, b, c;
	int min; 
	int vnear=startV; //

	//initial weight array
	for(int i=1; i<=numV; i++){
		for(int j=1; j<=numV; j++){
			weight[i][j]=99;
			if(i==j){
				weight[i][j]=0;
			}
		}
	}

	//set weight value
	for(int i=0; i<numE; i++){
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);

		weight[a][b]=c;
	}


	for(int i=1; i<=numV; i++){
		length[i]=weight[startV][i]; //현재 확정된 마디에서, 마디간의 최소 길이
	}
	

	for(int k=1; k<=numV; k++){
		min=99; //given weight max=10;
		vnear=-1;

		for(int i=1; i<=numV; i++){
			if(0<=length[i] && length[i]<min){
				min=length[i];
				vnear=i; //최단 경로를 제공해주는 vertex index 저장
			}
		}

		if(vnear!=-1){
			printf("%d\n", length[vnear]);
		}
		else{
			printf("INF\n");
			return 0;
		}

		//length 재설정
		for(int i=1; i<=numV; i++){
			if(length[i] > length[vnear]+weight[vnear][i]){
				length[i]=length[vnear]+weight[vnear][i];
			}
		}
		length[vnear]=-1;
	}
}
