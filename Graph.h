#ifndef GRAPH_H
#define GRAPH_H
#include "list.h"
#include "sort.h"
#include <stdio.h>

/*struct KeyToValue
{
	int key;
	int value;
};
*/
class Graph{
	
public:

	Graph(){

		matrix = new int *[Default_Size];
		for (int i=0; i<Default_Size; i++){
			matrix[i] = new int[Default_Size];
		}
		for (int i=0; i<Default_Size; i++)
		for (int j=0; j<Default_Size; j++){
			matrix[i][j] =0;
		}
		for (int i=0;i<peoList.friCollector.friPairs.length;i++){
			matrix[peoList.FindIndex(peoList.friCollector.friPairs.pairs[i].str1)][peoList.FindIndex(peoList.friCollector.friPairs.pairs[i].str2)] = 1;
			matrix[peoList.FindIndex(peoList.friCollector.friPairs.pairs[i].str2)][peoList.FindIndex(peoList.friCollector.friPairs.pairs[i].str1)] = 1;
		}
			for (int i=0;i<peoList.atCollector.atPairs.length;i++){
			if(matrix[peoList.FindIndex(peoList.atCollector.atPairs.pairs[i].str1)][peoList.FindIndex(peoList.atCollector.atPairs.pairs[i].str2)]<1)
				matrix[peoList.FindIndex(peoList.atCollector.atPairs.pairs[i].str1)][peoList.FindIndex(peoList.atCollector.atPairs.pairs[i].str2)]=0;
				matrix[peoList.FindIndex(peoList.atCollector.atPairs.pairs[i].str1)][peoList.FindIndex(peoList.atCollector.atPairs.pairs[i].str2)] += defaultWeight;
 		}

 		vis = new int[Default_Size];
 		circles = new set[50];
 		createNumFriends();
 		createNumAtsIn();
 		createNumAtsOut();
	}

	void Search(string s1,string s2){
	   int index1 = peoList.FindIndex(s1);
   	   int index2 = peoList.FindIndex(s2);
   	   if((index1>=0&&index1<=Default_Size-1)&&(index2>=0&&index2<=Default_Size-1))
   	   cout<<"The relation score of "<<s1<<" and "<<s2<<" is "<<matrix[index1][index2]<<endl;
   		else{
   			cout<<"error ID"<<endl;
   		}
	}

	void TheFriendsNumList(int n){
		KeyToValue sorted[Default_Size];
		for (int i = 0; i < Default_Size; ++i){
			sorted[i].key = i;
			sorted[i].value = numFriends[i];
		}
		sort(sorted,Default_Size);
		cout<<"Here is the FriendsNum List (The num means how many friends a man/woman have.)"<<endl;
		cout<<"Show as { Id : Num of friends }"<<endl;
		cout<<"{"<<endl;

		for (int i = Default_Size-1; i >= 0; --i){
			if(sorted[i].value > 0){
			cout<<"		"<<peoList.list[sorted[i].key].value<<" : "<<sorted[i].value<<endl; 
			n--;
			if(n==0)goto out;
		  }
		}
		out:
		cout<<"}"<<endl;
	}

	void TheAtsInNumList(int n){
		KeyToValue sorted[Default_Size];
		for (int i = 0; i < Default_Size; ++i){
			sorted[i].key = i;
			sorted[i].value = numAtsIn[i];
		}
		sort(sorted,Default_Size);
		cout<<"Here is the AtsIn List (The num means how many @ a man/woman get from others.)"<<endl;
		cout<<"Show as { Id : Num of friends }"<<endl;
		cout<<"{"<<endl;

		for (int i = Default_Size-1; i >= 0; --i){
			if(sorted[i].value > 0){
				cout<<"		"<<peoList.list[sorted[i].key].value<<" : "<<sorted[i].value<<endl; 
			n--;
			if(n==0)goto out;
		  }
		}
		out:
		cout<<"}"<<endl;
	}

	void TheAtsOutNumList(int n){
		KeyToValue sorted[Default_Size];
		for (int i = 0; i < Default_Size; ++i){
			sorted[i].key = i;
			sorted[i].value = numAtsOut[i];
		}
		sort(sorted,Default_Size);
		cout<<"Here is the AtsIn List (The num means how many @ a man/woman send to others .)"<<endl;
		cout<<"Show as { Id : Num of friends }"<<endl;
		cout<<"{"<<endl;

		for (int i = Default_Size-1; i >= 0; --i){
			if(sorted[i].value > 0){
			cout<<"		"<<peoList.list[sorted[i].key].value<<" : "<<sorted[i].value<<endl; 
			n--;
			if(n==0)goto out;
		  }
		}
		out:
		cout<<"}"<<endl;
	}

	
	void TheAverage(){
		int AtsIN = 0;
		int Firs = 0;
		int AtsOUT = 0;
		for (int i = 0; i < Default_Size; ++i){
			AtsIN += numAtsIn[i];
			AtsOUT += numAtsOut[i];
			Firs += numFriends[i];
		}
		printf("Average of Firs is %d,of AtsOUT is %d,of AtsIn is %d\n",Firs,AtsOUT,AtsIN);
	}

	void Circles(){
		cout<<"The circles is collecting . . ."<<endl;
		BFS(0);
		setSort(circles);
		cout<<"The circles is find and sorted"<<endl;
	}

	void showAllCircles(){
		for(int i = 1;i <= 50;i++){
			if(circles[50-i].length!=0){
				ShowNthCirle(i);	
			}
		}
	}

	void FindMostPopular(){
		int max = 0;
		int maxi = 0;

		for(int i = 0;i<Default_Size;i++){
				int temp = 0;
				temp += numFriends[i];
				temp += numAtsIn[i]*defaultWeight;
				if(temp>max){
					max = temp;
					maxi = i;
				}				
		}
		cout<<"The MostPopular is "<<peoList.list[maxi].value<<endl;
		cout<<"He has "<<numFriends[maxi]<<" friends and "<<numAtsIn[maxi]<<"@"<<endl;;
	}
	void FindMostPopularInCircles(int n){
		ShowNthCirle(n);
		int max = 0;
		int maxi = 0;
		for(int i = 0;i<circles[50-n].length;i++){
				int temp = 0;
				temp += numFriends[circles[50-n].el[i]];
				temp += numAtsIn[circles[50-n].el[i]]*defaultWeight;
				if(temp>max){
					max = temp;
					maxi = i;
				}				
		}
		cout<<"The MostPopular In "<<n<<"th Circles is "<<peoList.list[circles[50-n].el[maxi]].value<<endl;
		cout<<"He has "<<numFriends[circles[50-n].el[maxi]]<<" friends and "<<numAtsIn[circles[50-n].el[maxi]]<<"@"<<endl;;
	}

	void ShowNthCirle(int n){
		cout<<" "<<n<<"th : {"<<endl;
		for(int i = 0; i < circles[50-n].length; i++){
			cout<<peoList.list[circles[50-n].el[i]].value<<" ; ";
		}
		cout<<" } \n The total is "<<circles[50-n].length<<"people.\n"<<endl;
	}

	void BFS(int v){
		static int total = 0;
		int constV = v;

		if(peoList.list[v].value.length() == 0){
				v++;
			if(v == Default_Size)
				return ;
		}
		int front,rear;
		static int count = 0;
		front = rear = -1;
		int Q[Default_Size];
		vis[v] = 1;
		set S;
		S.append(v);
		Q[++rear] = v;
		while(front!=rear) {
		    v = Q[++front];
		    for(int j = 0;j < Default_Size; j++){
		    	if((matrix[v][j]>2)&&(vis[j]==0)){
		    		S.append(j);
		    		vis[j] = 1;
		    		Q[++rear] = j;
		    	}
		    }
		}

		if(S.length>1){
			circles[count] = S;
			count++;
		}

		v = constV;
		while(1){
			if(v == Default_Size)
				break;
			if(vis[v]==0&&peoList.list[v].value.length()!=0){
				BFS(v);
			}
			else v++;
		}
}

private:

	struct set{
		int *el;
		int length;
		set(){
			el = new int[850];
			length = 0;
		}
		void append(int n){
			if(!exist(n)){
				el[length] = n;
				length ++;
			}
		}
		bool exist(int n){
			for (int i = 0; i < length; i++){
				if (n == el[i]){
					return true;
				}
			}
			return false;
		}
	};



	void setSort(set *S){
		qucickSetSort(S,0,50);
	}	

	void qucickSetSort(set *S,int left,int right){
		int i = left,j = right;
		set pivot = S[(right+left)/2];
		while(i<=j) {
		    if(S[i].length < pivot.length){
		    	i++;
		    }
		    if(S[j].length > pivot.length){
				j--;
			}
			if(i <= j){
				set temp;
				temp.length = S[i].length;
				temp.el = S[i].el;
				S[i].length = S[j].length;
				S[i].el = S[j].el;
				S[j].length = temp.length;
				S[j].el= temp.el;
				i++;
				j--;
			}
		}

		if(i < right)
			qucickSetSort(S,i,right);
		if(j > left)
			qucickSetSort(S,left,j);
	}

	void createNumFriends(){
		int temp = 0;
		for (int i = 0;i<Default_Size;i++){
			temp = 0;
			for (int j = 0; j < Default_Size; j++)
			{   
				if(matrix[i][j]>0){
					if(matrix[i][j]%defaultWeight!=0){
						temp ++;
					}
				}
			}
			numFriends[i] = temp;
		}
	}

	void createNumAtsIn(){
		int temp = 0;
		for (int i = 0;i<Default_Size;i++){
			temp = 0;
			for (int j = 0; j < Default_Size; j++)
			{  
				temp += matrix[i][j]/defaultWeight;
			}
			numAtsIn[i] = temp;
		}
	}

	void createNumAtsOut(){
		int temp = 0;
		for (int i = 0;i<Default_Size;i++){
			temp = 0;
			for (int j = 0; j < Default_Size; j++)
			{  
				temp += matrix[j][i]/defaultWeight;
			}
			numAtsOut[i] = temp;
		}
	}
	int *vis;
	set *circles;
	int numAtsIn[850];
	int numAtsOut[850];
	int numFriends[850];
	PeopleList peoList;
	int **matrix;
	static const int defaultWeight = 22;
	static const int Default_Size = 850;
};


#endif