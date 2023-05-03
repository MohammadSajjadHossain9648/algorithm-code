# include <iostream>
# include <cstdio>
# include <list>
# include <vector>
using namespace std;
int clr[100];
int clr2[100];
int st[100];
int f[100];
int pri[100];
list <int> adj[100];
list <int> tadj[100];
int n, t, scc;

vector <int> ve;
vector <int> vescc[10];

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
    }
    clr[s] = 2;
    t++;
    f[s] = t;
    ve.push_back(s);
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

void DFS2(int s){
    clr2[s] = 1;
    vescc[scc].push_back(s);
    list <int>:: iterator it;
    for(it = tadj[s].begin(); it != tadj[s].end(); it++){
        if(clr2[*it] == 0){
            DFS2(*it);
        }
    }
    clr2[s] = 2;
}

void scc_fun(){
    DFS();
    for(int i = 1; i <= n; i++){
        clr2[i] = 0;
    }
    int len = ve.size();
    for(int i = len - 1; i >= 0; i--){
        if(clr2[ve[i]] == 0){
            DFS2(ve[i]);
            scc++;
        }
    }
    cout << "There is " << scc << " component." << endl;
    for(int i = 0; i < scc; i++){
        int l = vescc[i].size();
        cout << i + 1 << " no component: ";
        for(int j = 0; j < l; j++){
            cout << vescc[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int k = 1, a, b;
    scc = 0;
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
            tadj[b].push_back(a);
            k++;
        }
    }

    scc_fun();
}
