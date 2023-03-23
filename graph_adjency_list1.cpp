#include<bits/stdc++.h>

using namespace std;

int main(){

    int vertex , a , b , i=1;
    list<int>List[100];
    list<int>:: iterator it;


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
}
