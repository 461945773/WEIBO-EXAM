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
		CircleInput
	};
class Demo{

private:
	Graph graph;
	State state;
public:
	Demo(){
		state = Menu;
		char c = '\0';
		while(1) {
			switch(state){
				case Menu:cout<<"Input q to quit."<<endl;
				state = MenuInput;
				break;
				case MenuInput:	
				switch(c){
					case 'q':goto out;break;
					case '\0':break;
					default:cout<<"syntax input"<<endl;
				}
				break;
				default : cout<<"State error"<<endl;break;
			}
			cin>>c;
		}
		out:
		;   
	}
};

#endif // DEMO_H
