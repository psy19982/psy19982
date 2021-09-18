#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO {
    int ri, rj, bi, bj, count;
};

INFO start;

int n,m;
char arr[10][10];

int di[4]={0,0,-1,1};
int dj[4]={-1,1,0,0};

int solve(){
    queue<INFO> q;
    q.push(start);
    int visited[10][10][10][10]={0,};
    visited[start.ri][start.rj][start.bi][start.bj]=1;

    int answer=-1;
    while(!q.empty()){
        INFO current=q.front();
        q.pop();

        if(current.count>10)
            break;
        if(arr[current.ri][current.rj]=='O' && arr[current.bi][current.bj]!='O'){
            answer=current.count;
            break;
        }

        for(int i=0; i<4;i++){
            int new_ri=current.ri;
            int new_rj=current.rj;
            int new_bi=current.bi;
            int new_bj=current.bj;

            while(1){
                if(arr[new_ri][new_rj]!='O' && arr[new_ri][new_rj]!='#'){
                    new_ri+=di[i];
                    new_rj+=dj[i];
                }
                else{
                    if(arr[new_ri][new_rj]=='#'){
                        new_ri-=di[i];
                        new_rj-=dj[i];
                    }
                    break;
                }
            }

            while(1){
                if(arr[new_bi][new_bj]!='O' && arr[new_bi][new_bj]!='#'){
                    new_bi+=di[i];
                    new_bj+=dj[i];
                }
                else{
                    if(arr[new_bi][new_bj]=='#'){
                        new_bi-=di[i];
                        new_bj-=dj[i];
                    }
                    break;
                }
            }
        

            if(new_ri==new_bi && new_rj==new_bj){
                if(arr[new_ri][new_rj]!='O'){
                    int r_distance=abs(new_ri-current.ri)+abs(new_rj-current.rj);
                    int b_distance=abs(new_bi-current.bi)+abs(new_bj-current.bj);

                    if(r_distance>b_distance){
                        new_ri-=di[i];
                        new_rj-=dj[i];
                    }
                    else{
                        new_bi-=di[i];
                        new_bj-=dj[i];
                    }
                }
            }

            if(visited[new_ri][new_rj][new_bi][new_bj]==0){
                visited[new_ri][new_rj][new_bi][new_bj]=1;
                INFO next;
                next.ri=new_ri;
                next.rj=new_rj;
                next.bi=new_bi;
                next.bj=new_bj;
                next.count=current.count+1;
                q.push(next);
            }
        }
    }
    return answer;
}

int main(){
    cin>>n>>m;

    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='R'){
                start.ri=i;
                start.rj=j;
            }
            if(arr[i][j]=='B'){
                start.bi=i;
                start.bj=j;
            }
        }
    }

    start.count=0;
    int answer=solve();
    cout<<answer<<endl;
    
    return 0;
}