#include <iostream>
#include <vector>
using namespace std;


int N=3;
bool maze[3][3]={}, sol[3][3];


void printMatrix(bool a[3][3]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<"\n";
	}
}


bool isSafe(int i, int j){
	return (i<N && j<N && maze[i][j]==1);
}


bool solveMazeRec(int i,int j){
	if(i==N-1 && j==N-1){	sol[i][j]==1;	return 1;}
	if(isSafe(i,j)){
		sol[i][j]=1;
		if(solveMazeRec(i+1,j))		return 1;
		else if(solveMazeRec(i,j+1))	return 1;
		sol[i][j]=0;
	}
	return 1;
}



bool solveMaze(){
	if(!solveMazeRec(0,0))	return 0;
	printMatrix(sol);
	return 1;
}


int main(int argc, char const *argv[])
{
	maze[0][0]=1;
	maze[1][0]=1;
	maze[2][0]=1;
	maze[2][1]=1;
	maze[2][3]=1;
	cout<<solveMaze();
	return 0;
}