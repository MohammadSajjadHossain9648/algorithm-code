#include<bits/stdc++.h>

using namespace std;

list<int>List[100];
list<int>:: iterator it;

int vertex;
int dis[100];
int prev[100];
char color[100];

void bfs(int s){

    for( int i=1 ; i<=vertex ; i++){
        dis[i] = 20000;
        color[i] = 'w';
        prev[i] = -1;
    }

    dis[s] = 0;
    color[s] = 'g';

    queue<int>Q;
    Q.push(s);

    while(!Q.empty()){
        int u = Q.front();

        Q.pop();

        for( it=List[u].begin() ; it!=List[u].end() ; it++){
            int v= *it;
            if(color[v]=='w'){
                color[v] = 'g';
                dis[v] = dis[u] + 1 ;
                prev[v] = u ;
                Q.push(v);

            }
            color[u] = 'b';
        }
    }
}


int main(){

    int  a , b , i=1;

    cout<<"Enter number of vertex :";
    cin>>vertex;

    while(true){

        cout<<"Edge "<<i<<" :";
        cin>>a>>b;

        if(a==0 && b==0)
            break;

        else if( a<1 || b<1 || a>vertex || b>vertex){
            cout<<"Invalid input"<<endl;
            continue;
        }
        else{
            List[a].push_back(b);
            List[b].push_back(a);

        }

        i++;
    }
    cout<<endl;
    for(int r=1 ; r<=vertex ; r++){

        printf("List[%d]-",r);
        for(it=List[r].begin() ; it!=List[r].end() ; it++)
            printf("->%d",*it);
        cout<<endl;
    }

    printf("Enter source: ");
    int source;
    scanf("%d",&source);

   /* if(source<1 || source>vertex)
        printf("invalid source\n");*/

     bfs(source);

    for( int i=1 ; i<=vertex ; i++)
        printf("vertex %d , distance %d , previous %d , color %c\n",i,dis[i],prev[i],color[i]);
}
