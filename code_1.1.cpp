#include <iostream>
#include <stack>   
#include <queue>       
#include <fstream>
#include <string>
#include <cmath> 
#include <algorithm>   
#include <vector>    
#include <limits> 
using namespace std;


class node {
  	public:
	  	char state;
	  	int selfX;
	  	int selfY;
	    int prevX;
	    int prevY;
	    int visited; //1 is visited, 0 is not
	    int inlist;
	    int dist;

	bool operator<(const node& right) const {
    	return (this->dist > right.dist);
	}

};




int distance(int x1,int y1,int x2,int y2){
	int result=abs(x1-x2)+abs(y1-y2);
	return result;
}


int main () {
	int MAX=10000;
	//read from file to create map in 2d array
  	string line;
  	ifstream myfile ("openMaze.txt");
	int eachlines=0;
	int alllines=0;
    while ( getline (myfile,line) )
    {
    	for(;line[eachlines]!='\0';eachlines++){}
  	  	alllines=alllines+1;
    }
    

    myfile.clear();
	myfile.seekg(0, ios::beg);



	node map[alllines][eachlines];
	for(int i=0;i<alllines;i++){
		for(int k=0;k<eachlines;k++){
			map[i][k].state=' ';
			map[i][k].selfX=i;
			map[i][k].selfY=k;
			map[i][k].prevX=0;
			map[i][k].prevY=0;
			map[i][k].visited=0;
			map[i][k].inlist=0;
		}
	}
	int lineNum=0;
	int startX=0;
	int startY=0;
	int endX=0;
	int endY=0;

    
	while ( getline (myfile,line) )
    {
    	for(int k=0;line[k]!='\0';k++){
    		map[lineNum][k].state=line[k];
    		if(map[lineNum][k].state=='P'){
    			startX=lineNum;
    			startY=k;
    		}
    		if(map[lineNum][k].state=='.'){
    			endX=lineNum;
    			endY=k;
    		}
    	}
  	  	lineNum=lineNum+1;
    }

    for(int i=0;i<alllines;i++){
		for(int k=0;k<eachlines;k++){
			map[i][k].dist=distance(i,k, endX,endY);
		}
	}




    for(int i=0;i<alllines;i++){
		for(int k=0;k<eachlines;k++){
			cout << map[i][k].state;
		}
    	cout<<endl;
	}
    myfile.close();


    int currentX=startX;
    int currentY=startY;





    //DFS: stack 
 //  	stack<node> mystack;
	// mystack.push(map[startX][startY]);

	// node temp;
	// for(;;){

	// 	temp=mystack.top();
	//     mystack.pop();
	//     currentX=temp.selfX;
	//     currentY=temp.selfY;
	//     if(temp.selfX==endX && temp.selfY==endY){
	//     	break;
	//     }
	//     if(map[currentX][currentY].visited==0){
	//     	map[currentX][currentY].visited=1;

	    
	// 	    if(currentX+1<alllines){
	// 	    	if(map[currentX+1][currentY].visited==0 && map[currentX+1][currentY].state!='%'){
	// 	    		mystack.push(map[currentX+1][currentY]);
	// 	    		map[currentX+1][currentY].prevX=currentX;
	// 	    		map[currentX+1][currentY].prevY=currentY;
	// 	    	}
	// 	    }
	// 	    if(currentY+1<eachlines){
	// 	    	if(map[currentX][currentY+1].visited==0 && map[currentX][currentY+1].state!='%'){
	// 	    		mystack.push(map[currentX][currentY+1]);
	// 	    		map[currentX][currentY+1].prevX=currentX;
	// 	    		map[currentX][currentY+1].prevY=currentY;
	// 	    	}
	// 	    }
	// 	    if(currentX-1>0){
	// 	    	if(map[currentX-1][currentY].visited==0 && map[currentX-1][currentY].state!='%'){
	// 	    		mystack.push(map[currentX-1][currentY]);
	// 	    		map[currentX-1][currentY].prevX=currentX;
	// 	    		map[currentX-1][currentY].prevY=currentY;
	// 	    	}
	// 	    }
	// 	    if(currentY-1>0){
	// 	    	if(map[currentX][currentY-1].visited==0 && map[currentX][currentY-1].state!='%'){
	// 	    		mystack.push(map[currentX][currentY-1]);
	// 	    		map[currentX][currentY-1].prevX=currentX;
	// 	    		map[currentX][currentY-1].prevY=currentY;    		
	// 	    	}
	// 	    }
	// 	}
	// }


	// temp=map[endX][endY];
	// for(;;){
	// 	if(temp.selfX==startX && temp.selfY==startY){
	// 		break;
	// 	}
	// 	temp.state='.';
	// 	map[temp.selfX][temp.selfY]=temp;
	// 	temp=map[temp.prevX][temp.prevY];

	// }

	// map[startX][startY].state='.';
	// map[endX][endY].state='P';
	// for(int i=0;i<alllines;i++){
	// 	for(int k=0;k<eachlines;k++){
	// 		cout << map[i][k].state;
	// 	}
	//     cout<<endl;
	// }













	//BFS: queue
	// queue<node> myqueue;
	// myqueue.push(map[startX][startY]);

	// node temp;
	// for(;;){

	// 	temp=myqueue.front();
	//     myqueue.pop();
	//     currentX=temp.selfX;
	//     currentY=temp.selfY;
	//     if(temp.selfX==endX && temp.selfY==endY){
	//     	break;
	//     }
	//     if(map[currentX][currentY].visited==0){
	//     	map[currentX][currentY].visited=1;

	    
	// 	    if(currentX+1<alllines){
	// 	    	if(map[currentX+1][currentY].inlist==0 && map[currentX+1][currentY].state!='%'){
	// 	    		myqueue.push(map[currentX+1][currentY]);
	// 	    		map[currentX+1][currentY].inlist=1;
	// 	    		map[currentX+1][currentY].prevX=currentX;
	// 	    		map[currentX+1][currentY].prevY=currentY;
	// 	    	}
	// 	    }
	// 	    if(currentY+1<eachlines){
	// 	    	if(map[currentX][currentY+1].inlist==0 && map[currentX][currentY+1].state!='%'){
	// 	    		myqueue.push(map[currentX][currentY+1]);
	// 	    		map[currentX][currentY+1].inlist=1;
	// 	    		map[currentX][currentY+1].prevX=currentX;
	// 	    		map[currentX][currentY+1].prevY=currentY;
	// 	    	}
	// 	    }
	// 	    if(currentX-1>0){
	// 	    	if(map[currentX-1][currentY].inlist==0 && map[currentX-1][currentY].state!='%'){
	// 	    		myqueue.push(map[currentX-1][currentY]);
	// 	    		map[currentX-1][currentY].inlist=1;
	// 	    		map[currentX-1][currentY].prevX=currentX;
	// 	    		map[currentX-1][currentY].prevY=currentY;
	// 	    	}
	// 	    }
	// 	    if(currentY-1>0){
	// 	    	if(map[currentX][currentY-1].inlist==0 && map[currentX][currentY-1].state!='%'){
	// 	    		myqueue.push(map[currentX][currentY-1]);
	// 	    		map[currentX][currentY-1].inlist=1;
	// 	    		map[currentX][currentY-1].prevX=currentX;
	// 	    		map[currentX][currentY-1].prevY=currentY;    		
	// 	    	}
	// 	    }
	// 	}
	// }


	// temp=map[endX][endY];
	// for(;;){
	// 	if(temp.selfX==startX && temp.selfY==startY){
	// 		break;
	// 	}
	// 	temp.state='1';
	// 	map[temp.selfX][temp.selfY]=temp;

	// 	// cout<<temp.prevX<<","<<temp.prevY<<endl;
	// 	temp=map[temp.prevX][temp.prevY];
	// }

	// map[startX][startY].state='P';
	// map[endX][endY].state='.';
	// for(int i=0;i<alllines;i++){
	// 	for(int k=0;k<eachlines;k++){
	// 		cout << map[i][k].state;
	// 	}
	//     cout<<endl;
	// }




    int height=alllines;
    int width=eachlines;
	priority_queue<node> greedy;
	map[startX][startY].prevX=startX;
	map[startX][startY].prevY=startY;
	greedy.push(map[startX][startY]);
	map[startX][startY].inlist=1;
	node smallest;
	for(;;){
		smallest=greedy.top();
		currentX=smallest.selfX;
		currentY=smallest.selfY;

		greedy.pop();
		if(smallest.selfX==endX  && smallest.selfY==endY ){
			break;
		}
		

    if(currentX+1<height-1){
	     if( map[currentX+1][currentY].state!='%'   && map[currentX+1][currentY].inlist==0  ){
	     	map[currentX+1][currentY].inlist=1;
	     	map[currentX+1][currentY].prevX=currentX;
	     	map[currentX+1][currentY].prevY=currentY;
			greedy.push(map[currentX+1][currentY]);
			}		
		}

	 if(currentY+1<width-1){
	     if( map[currentX][currentY+1].state!='%'   && map[currentX][currentY+1].inlist==0  ){
	     	map[currentX][currentY+1].inlist=1;
	     	map[currentX][currentY+1].prevX=currentX;
	     	map[currentX][currentY+1].prevY=currentY;
			greedy.push(map[currentX][currentY+1]);
			}		
		}	

		 if(currentX-1>0){
	     if( map[currentX-1][currentY].state!='%'   && map[currentX-1][currentY].inlist==0  ){
	     	map[currentX-1][currentY].inlist=1;
	     	map[currentX-1][currentY].prevX=currentX;
	     	map[currentX-1][currentY].prevY=currentY;
			greedy.push(map[currentX-1][currentY]);
			}		
		}	
	
		 if(currentY-1>0){
	     if( map[currentX][currentY-1].state!='%'   && map[currentX][currentY-1].inlist==0  ){
	     	map[currentX][currentY-1].inlist=1;
	     	map[currentX][currentY-1].prevX=currentX;
	     	map[currentX][currentY-1].prevY=currentY;
			greedy.push(map[currentX][currentY-1]);
			}		
		}	
	
		


	}



	node temp=map[endX][endY];
	for(;;){
		if(temp.selfX==startX && temp.selfY==startY){
			break;
		}
		temp.state='.';
		map[temp.selfX][temp.selfY]=temp;

		temp=map[temp.prevX][temp.prevY];
	}

	for(int i=0;i<alllines;i++){
		for(int k=0;k<eachlines;k++){
			cout << map[i][k].state;
		}
    	cout<<endl;
	}




  return 0;
}