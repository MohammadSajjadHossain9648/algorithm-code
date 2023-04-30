#include<bits/stdc++.h>

using namespace std;

int vertex;
int t;
int matrix[100][100];
int dis[100];
int fin[100];
int prev[100];
char color[100];

void Dfs_Visit(int u){
   // printf("\nu = %d\n",u);
    color[u] = 'g';
    t = t+1;
    dis[u] = t;

    for(int i=1 ; i<=vertex ; i++){
        if(matrix[u][i]==1 && color[i]=='w'){
            prev[i] = u ;
            Dfs_Visit(i);
        }
    }
    color[u] = 'b';
    t = t+1;
    fin[u] = t;
}

void Dfs(){

    for( int i=1 ; i<=vertex ; i++){
        dis[i] = -1;
        fin[i] = -1;
        color[i] = 'w';
        prev[i] = -1;
    }

    t = 0;
    for(int i=1 ; i<=vertex ; i++)
        if(color[i]=='w')
            Dfs_Visit(i);

}

void display(){
    printf("Vertex   dis[u]   fin[u]  prev[u]\n");

    for(int i=1 ; i<=vertex ; i++)
        printf("  %d      %d       %d       %d\n",i,dis[i],fin[i],prev[i]);
}


void edge_counter(){ /// This function is not accurate
    int tr=0 , b=0 , c=0 , f=0 ;
    for(int u=1 ; u<=vertex ; u++){
        for(int v=1 ; v<=vertex ; v++){
            if(matrix[u][v]==1){
                if( dis[u]<dis[v] && dis[u]<fin[v] && fin[u]>fin[v] )
                    tr++;
                else if(dis[u]>dis[v] && fin[u]<fin[v])
                    b++;
                else if( dis[u]>dis[v] && fin[u]>dis[v])
                    c++;
                else if(dis[u]<dis[v])
                    f++;
            }
        }
    }

    printf("\n Tree edge: %d \n Back edge: %d \n Forward edge: %d \n Cross edge: %d\n",tr,b,f,c);
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
           /// matrix[b][a] = 1;
        }

        i++;
    }
    cout<<endl;

    for(int r=1 ; r<=vertex ; r++){

        for(int c=1 ; c<=vertex ; c++)
            printf("%d ",matrix[r][c]);

        cout<<endl;
    }

    Dfs();
    display();
    edge_counter(); /// This function is not accurate
   /// for( int i=1 ; i<=vertex ; i++)
    ///    printf("vertex %d , distance %d , previous %d , color %c\n",i,dis[i],prev[i],color[i]);

}
