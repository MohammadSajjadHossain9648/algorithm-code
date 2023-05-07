# include <iostream>
# include <cstdio>
# include <list>
# include <vector>
using namespace std;
int clr[100];
int st[100];
int f[100];
int pri[100];
list <int> adj[100];
int n, t;
bool x;
vector <int> topsort;

void DFS_visit(int s){
    list <int>:: iterator it2;
    int node;
    clr[s] = 1;
    t++;
    st[s] = t;
    for(it2 = adj[s].begin(); it2 != adj[s].end(); it2++){
        node = *it2;
        if(clr[node] == 0){
            pri[node] = s;
            DFS_visit(node);
        }
        else if(clr[node] == 1){
            x = false;
        }

    }
    clr[s] = 2;
    topsort.push_back(s);
    t++;
    f[s] = t;
}

void DFS(){

    for(int i = 1; i <= n; i++){
        clr[i] = 0;
        pri[i] = -1;
        st[i] = -1;
        f[i] = -1;
    }
    t = 0;
    for(int i = 1; i <= n; i++){
        if(clr[i] == 0){
            DFS_visit(i);
        }
    }
}

int main(){
    int k = 1, a, b, s;
    x = true;
    list <int>:: iterator it;
    printf("Input the number of vertex: ");
    scanf("%d", &n);
    while(true){
        printf("Edge %d: ", k);
        scanf("%d %d", &a, &b);
        if(a == 0 && b == 0){
            break;
        }
        else if(a <= 0 || a > n || b <= 0 || b > n){
            printf("Invalid edge try again\n");
            continue;
        }
        else{
            adj[a].push_back(b);
            k++;
        }
    }
    printf("The graph you entered:\n");
    for(int i = 1; i <= n; i++){
        printf("adj[%d]", i);
        for(it = adj[i].begin(); it != adj[i].end(); it++){
            printf(" -> %d", *it);
        }
        printf("\n");
    }

    DFS();

    if(x == true){
        int len = topsort.size();
        cout << "Topological sort: ";
        for(int i = len - 1; i >= 0; i--){
            cout << topsort[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "Graph contains cycle." << endl;
    }

}
