#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int map[20][20]={0,};
int cnt;
int answer=0;

void move(int dir){
    queue<int> q;

    switch(dir){
        case 0:
            for(int y=0; y<n;y++){
                for(int x=0; x<n;x++){
                    if(map[x][y]!=0){
                        q.push(map[x][y]);
                        map[x][y]=0;
                    }
                }

                int index=0;
                while(!q.empty()){
                    int val=q.front();
                    q.pop();
                    if(map[index][y]==0){
                        map[index][y]=val;
                    }
                    else if(map[index][y]==val){
                        map[index++][y]*=2;
                    }
                    else{
                        map[++index][y]=val;
                    }
                }

            }
            break;

            case 1:
                for(int y=0; y<n;y++){
                    for(int x=n-1;x>=0;x--){
                        if(map[x][y]!=0){
                            q.push(map[x][y]);
                            map[x][y]=0;
                        }
                    }

                    int index=n-1;
                    while(!q.empty()){
                        int val=q.front();
                        q.pop();
                        if(map[index][y]==0){
                            map[index][y]=val;
                        }
                        else if(map[index][y]==val){
                            map[index--][y]*=2;
                        }
                        else
                            map[--index][y]=val;
                    }
                }
                break;

            case 2:
                for(int x=0; x<n;x++){
                    for(int y=0; y<n;y++){
                        if(map[x][y]!=0){
                            q.push(map[x][y]);
                            map[x][y]=0;
                        }
                    }

                    int index=0;
                    while(!q.empty()){
                        int val=q.front();
                        q.pop();
                        if(map[x][index]==0){
                            map[x][index]=val;
                        }
                        else if(map[x][index]==val){
                            map[x][index++]*=2;
                        }
                        else{
                            map[x][++index]=val;
                        }
                    }
                }
                break;

            case 3:
                for(int x=0; x<n;x++){
                    for(int y=n-1;y>=0;y--){
                        if(map[x][y]!=0){
                            q.push(map[x][y]);
                            map[x][y]=0;
                        }
                    }

                    int index=n-1;
                    while(!q.empty()){
                        int val=q.front();
                        q.pop();
                        if(map[x][index]==0){
                            map[x][index]=val;
                        }
                        else if(map[x][index]==val){
                            map[x][index--]*=2;
                        }
                        else{
                            map[x][--index]=val;
                        }
                    }
                }
                break;
    }
}


int find_max(){
    int tmp=0;
    for(int x=0; x<n;x++){
        for(int y=0; y<n;y++){
            if(tmp<map[x][y])
                tmp=map[x][y];
        }
    }
    return tmp;
}


void solve(int cnt){
    if(cnt==5){
        answer=max(answer, find_max());
        return;
    }

    int tmp[20][20]={0,};

    for(int x=0; x<n;x++){
        for(int y=0; y<n;y++){
            tmp[x][y]=map[x][y];
        }
    }

    for(int i=0; i<4;i++){
        move(i);
        solve(cnt+1);
        for(int x=0; x<n;x++){
            for(int y=0; y<n;y++){
                map[x][y]=tmp[x][y];
            }
        }
    }


}

int main(){

    cin>>n;
    for(int x=0; x<n;x++){
        for(int y=0; y<n;y++){
            cin>>map[x][y];
        }
    }

    solve(0);

    cout<<answer<<endl;
    return 0;
}