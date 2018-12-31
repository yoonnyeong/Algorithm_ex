#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int map[30][30];
int group[30][30];
// 상, 하 , 좌, 우 에 대하여 탐색
int dx[] ={0,0,1,-1};
int dy[] ={1,-1,0,0};
int n;
int ans[25*25];

void dfs(int x, int y, int cnt){
	// 큐를 만들고 x, y를 대입
	queue<pair<int, int>> q;
	q.push(make_pair(x,y));
	// 방문했다고 표시를 해주기 위해 group에 단지의 number로 표시
	group[x][y] = cnt;
	
	// q가 비어있지 않은 동안에
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		// 4개의 방향에 대해
		for(int k =0; k <4; k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			//새로이동한 좌표가 n * n 안에 있고
			if( 0 <= nx && nx < n && 0 <= ny && ny < n){
					// 이동한 좌표도 집이 있고, 아직 방문 하지 않았다면
					if(map[nx][ny] == 1 && group[nx][ny] == 0 ){
							// nx, ny도 큐에 넣고 큐가 비지 않는 동안에 탐색
							q.push(make_pair(nx, ny));
							//단지의 number를 이 위치에도 표시
							group[nx][ny] = cnt;
					}
			}
		
		}
	
	}

}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
				scanf("%1d", &map[i][j]);
		}
	}
	// 단지의 갯수
	int cnt = 0;
	// 모든 점에 대하여
	for(int i = 0; i <n; i++){
		for(int j =0; j <n; j++){
			// 집이 존재하고, 아직 방문하지 않은 점들에 대해서만 
				if(map[i][j] == 1 && group[i][j] == 0)
					// 단지수 1 증가
					dfs(i, j, ++cnt);
		}
	}
	//총 단지의 수를 출력
	printf("%d\n", cnt);
	
	for(int i =0; i < n; i++){
		for(int j=0; j <n; j++){
				ans[group[i][j]]+=1;
		}
	}
	
	sort(ans+1, ans+cnt+1);
	
	for(int i = 1; i <= cnt; i++){
			printf("%d\n", ans[i]);
	}
	
	return 0;
}
