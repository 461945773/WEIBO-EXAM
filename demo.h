#ifndef DEMO_H
#define DEMO_H
#include "Graph.h"
/*
	graph.TheFriendsNumList(10);
	graph.TheAtsInNumList(10);
	graph.TheAtsOutNumList(10);
	graph.Circles();
	graph.showAllCircles();
	graph.FindMostPopularInCircles(1);
	graph.FindMostPopular();
*/
	enum State{
		Menu,
		MenuInput,
		Circle,
		CircleInput,
		CircleFind,
		CircleList,
		Friends,
		Ats
	};

class Demo{

private:
	Graph graph;
	State state;
public:
	Demo(){
		state = Menu;
		char c;
		int n;
		char mybuffer [100];
		bool cir = 0;
		while(1) {
			switch(state){
				case Menu:cout<<" Input q to quit,f to enter Friends Menu,\n Input a to enter @ Menu,c to enter Circle Menu."<<endl;
				state = MenuInput;
				break;
				case MenuInput:	
				switch(c){
					case 'q':goto out;break;
					case 'a':state = Ats;break;
					case 'f':state = Friends;break;
					case 'c':state = Circle;break;
					default:break;
				}
				break;
				case Ats:cout<<" Input a num n to see the @list of n people,\n Input -1 return to MainMenu."<<endl;
						while(1) {
							if(n==-1){
						    	state = Menu;
						    	n = 0;
								break;
						    }else if(n<=0||n>647){

						    }else{
						    	graph.TheAtsInNumList(n);
						    }
						   cin.getline(mybuffer, 100);
				         	n = atoi(mybuffer);
						}
						break;
				case Friends:cout<<" Input a num n to see the friends list of n people,\n Input -1 return to MainMenu."<<endl;
						while(1) {
							if(n==-1){
						    	state = Menu;
						    	n = 0;
								break;
					    	}else if(n<=0||n>647){
						    }else{
						    	graph.TheFriendsNumList(n);
						    }
						   cin.getline(mybuffer, 100);
				         	n = atoi(mybuffer);
						}
						break;
				case Circle:if(!cir){
					graph.Circles();
					cir = true;
				}
					cout<<" Input n enter the CircleList Menu \n Input f enter the PopularPeople Menu\n Input q return the MainMenu"<<endl;
					state = CircleInput;break;
				case CircleInput:
				switch(c){
					case 'n':state = CircleList;break;
					case 'f':state = CircleFind;break;
					case 'q':state = Menu;break;
					default:break;
				}
				break;
				case CircleList:
				cout<<" Input a num n to see the member list of n Circle,\nInput 99 to see all,\n Input -1 return to MainMenu."<<endl;
						while(1) {
							if(n==-1){
						    	state = Circle;
						    	n = 0;
								break;
					    	}else if(n == 99){
					    		graph.showAllCircles();
					    	}else if(n<=0||n>50){
						    }else{
						    	graph.ShowNthCirle(n);
						    }
						   cin.getline(mybuffer, 100);
				         	n = atoi(mybuffer);
						}break;
				case CircleFind:cout<<" Input a num n to see the most popular people int nTh circle,\n Input 99 to see the Most popular one \n Input -1 return to MainMenu."<<endl;
						while(1) {
							if(n==-1){
						    	state = Circle;
						    	n = 0;
								break;
					    	}else if(n == 99){
					    		graph.FindMostPopular();
					    	}else if(n<=0||n>50){
						    }else{
						    	graph.FindMostPopularInCircles(n);
						    }
						   cin.getline(mybuffer, 100);
				         	n = atoi(mybuffer);
						}break;
				default : cout<<"State error"<<endl;state = Menu;break;
			}
			if(state == MenuInput||state == CircleInput)cin>>c;
		}
		out:
		;   
	}
};

#endif // DEMO_H
