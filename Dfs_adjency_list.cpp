#include<bits/stdc++.h>

using namespace std;

list<int>List[100];


int vertex;
int t;
int dis[100];
int fin[100];
int prev[100];
char color[100];

void Dfs_Visit(int u){
   // printf("\nu = %d ",u);
    color[u] = 'g';
    t = t+1;
    dis[u] = t;
    printf("%d ",u);
  //  int S = List[u].size();
    //for( int v=0 ; v<S ; v++){
      //  if(color[List[u][v]]=='w'){
    list<int>:: iterator it;
    for( it=List[u].begin() ; it!=List[u].end() ; it++){
        int v= *it;
        if(color[v]=='w'){
            prev[v] = u ;
            Dfs_Visit(v);
        }
    }
    color[u] = 'b';
    t = t+1;
    fin[u] = t;
    printf("%d\n",u);
    return ;
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
        list<int>:: iterator it;
        for(it=List[u].begin() ; it!=List[u].end() ; it++){
                int v = *it ;
                if( dis[u]<dis[v] && dis[u]<fin[v] && fin[u]>fin[v] )
                    tr++;
                else if(dis[u]>dis[v] && fin[u]<fin[v])
                    b++;
                else if( dis[u]>dis[v] && fin[u]>dis[v])
                    c++;
                else if(dis[v]<dis[v] && fin[u]>fin[v])
                    f++;

        }
    }

    printf("\n Tree edge: %d \n Back edge: %d \n Forward edge: %d \n Cross edge: %d\n",tr,b,f,c);
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
        }

        i++;
    }
    cout<<endl;

    for(int r=1 ; r<= vertex ; r++){
        //printf("List[%d]-",r);
        cout << "List- " << r;
        list<int>:: iterator it;
        for(it=List[r].begin() ; it!=List[r].end() ; it++)
            printf("->%d",*it);
        cout<<endl;
    }

    Dfs();
    display();
    edge_counter();/// This function is not accurate

}
