#include <stdio.h>

int findMinLength(){
	
}

int main(){
	int numE; //edge 총 개수
	int numV; //vertex 총 개수
	int startV;

	scanf("%d", &numV);
	scanf("%d", &numE);
	scanf("%d", &startV);

	int touch[numV+1];
	int length[numV+1];
	int weight[numV+1][numV+1];

	int sol[numV];
	sol[0]=0; //start value

	int a, b, c;
	int min=99; //given weight max=10;

	//initial weight array
	for(int i=1; i<=numV; i++){
		for(int j=1; j=<numV; j++){
			weight[i][j]=-1;
		}
	}

	//set weight arr value
	for(int i=0; i<numE; i++){
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);

		weight[a][b]=c;
	}

	for(int i=1; i<=numV; i++){
		touch[i]=1; //현재 최단 경로의 마지막 마디
		length[i]=weight[1][i]; //현재 확정된 마디에서, 마디간의 최소 길이
	}


	for(int i=1; i<=numV; i++){
		if(0<length[i]<min){
			min=length[i];
			//나머지는 집에서
		}
	}

	/*
	Debug
	printf("numE: %d, numV: %d startV: %d\n", numE, numV, startV);
	for(int i=0; i<numV+1; i++){
		for(int j=0; j<numV+1; j++){
			printf("weight[%d][%d]=%d\n", i, j, weight[i][j]);
		}
	}
*/

}
