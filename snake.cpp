#include <iostream>

using namespace std;

int N, K, L;

int map[101][101];

int snake_y[10201], snake_x[10201];
int cmd[10001];

int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

int main() {
    cin>>N;
    cin>>K;

    int x, y;
    for(int i=0; i<K;i++){
        cin>>y>>x;
        map[y][x]=1;
    }

    cin>>L;
    int time;
    char c;
    for(int i=0; i<L;i++){
        cin>>time>>c;
        cmd[time]=c;
    }

    int dir=0;
    time=0;
    int head_y=1, head_x=1, tail=time;
    snake_y[time]=head_y, snake_x[time]=head_x;
    map[head_y][head_x]=-1;

    while(1){
        time+=1;

        head_y+=dy[dir], head_x+=dx[dir];

        if(head_y<1 || head_x<1 || head_y>N || head_x>N || map[head_y][head_x]==-1)
            break;
        
        snake_y[time]=head_y, snake_x[time]=head_x;

        if(map[head_y][head_x]==0){
            int tail_y= snake_y[tail], tail_x= snake_x[tail];
            map[tail_y][tail_x]=0;
            tail++;
        }

        map[head_y][head_x]=-1;

        if(dir==0){
            if(cmd[time]=='D')
                dir=1;
            else if(cmd[time]=='L')
                dir=3;
        }

        else if(dir==1){
            if(cmd[time]=='D')
                dir=2;
            else if(cmd[time]=='L')
                dir=0;
        }

        else if(dir==2){
            if(cmd[time]=='D')
                dir=3;
            else if(cmd[time]=='L')
                dir=1;
        }

        else if(dir==3){
            if(cmd[time]=='D')
                dir=0;
            else if(cmd[time]=='L')
                dir=2;
        }

    }

    cout<<time<<endl;

    return 0;
}