#include "Graph.h"

int main(){
	Graph graph;
	graph.TheFriendsNumList(10);
	graph.TheAtsInNumList(10);
	graph.TheAtsOutNumList(10);
	graph.BFS(0);
	cout<<"Data Collect succssfully"<<endl;
}