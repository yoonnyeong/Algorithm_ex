#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
/*위상정렬 순서가 있는 작업을 차례대로*/
vector<int> adj[1000001];
int out[1000001];
void testcase(){
		int n, m;
		scanf("%d %d", &n, &m);
	  //out배열을 전부 0으로 초기화
		for(int i = 1; i<=n; i++){
			//배열의 내용들을 다 초기화시켜준다.
					out[i]=0;
					adj[i].clear();
		}
		for(int i = 0; i <m; i++){
				int u, v;
				scanf("%d %d", &u, &v);
				out[u]++;
			  // 반대로 연결
				adj[v].push_back(u);
		}
		queue<int> q;
	  int remove = 0; //제거된 폭탄의 갯수
		for(int i =1; i <=n; i++){
				if(out[i]==0){
						//제거해야하는 큐에 넣어준다
						q.push(i);
						out[i] = -1; //중복처리 안되게 처리
					
				}
		}
	//q가 비어있지 않은 동안에
		while(q.size() > 0){
				// 제거해야하는 target을 정한다.
				int target = q.front();
				q.pop(); //target을 제거
		   
				out[target]= -1;
			  remove++; //제거되었으므로 1 증가
				
				// target이 제거되면 그 타켓과 연결되었던 폭탄들도 제거할 수 있음
				for(int i = 0; i < adj[target].size(); i++){
						int next = adj[target][i];
					  out[next]--;
						if(out[next] == 0){
								out[next] = -1;
								q.push(next);
						}
				}
		}
	
	if(remove == n) printf("YES\n");
	else printf("NO\n");

}
int main(){
	int t;
	scanf("%d", &t);

	for(int i = 0; i < t; i++){
			testcase();
	}


return 0;
}
