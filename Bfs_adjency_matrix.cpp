#include<bits/stdc++.h>

using namespace std;

int vertex;
int matrix[100][100];
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

        for( int i=1 ; i<=vertex ; i++){
            if(matrix[u][i]==1 && color[i]=='w'){
           /// printf("matrix[%d][%d] = %d\n",u,i,matrix[u][i]);
                color[i] = 'g';
                dis[i] = dis[u] + 1 ;
                prev[i] = u ;
                Q.push(i);
            }
            color[u] = 'b';
        }
    }
}

int main(){

    int  a , b , i=1;
    memset(matrix,0,sizeof(matrix));

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
            matrix[a][b] = 1;
            matrix[b][a] = 1;
        }

        i++;
    }
    cout<<endl;

    for(int r=1 ; r<=vertex ; r++){

        for(int c=1 ; c<=vertex ; c++)
            printf("%d ",matrix[r][c]);

        cout<<endl;
    }

    printf("Enter source: ");
    int source;
    scanf("%d",&source);

    if(source<1 || source>vertex)
        printf("invalid source\n");
    else
        bfs(source);

    for( int i=1 ; i<=vertex ; i++)
        printf("vertex %d , distance %d , previous %d , color %c\n",i,dis[i],prev[i],color[i]);

}
