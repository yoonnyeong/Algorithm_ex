#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
/*번호가 빠른 폭탄을 먼저 해체할 수 있도록 선택 -> 만약, 1 < 3 이라면 부호를 바꿔주면 빠른게 큰 숫자가 된다 -1 > -3
priority_queue -> 내부가 오름차순으로 기본정렬이 되어있음.

*/
vector<int> adj[1000001];
int out[1000001];
void testcase(){
		int n, m;
		scanf("%d %d", &n, &m);
	  //out배열을 전부 0으로 초기화
		for(int i = 1; i<=n; i++){
					out[i]=0;
					adj[i].clear();
		}
		for(int i = 0; i <m; i++){
				int u, v;
				scanf("%d %d", &u, &v);
				out[u]++;
			  // 반대로 연결 왜 u -> v 순서로 제거를 하면, 폭탄이 터지니까 반대로 연결하여 제거해주어야함.
				adj[v].push_back(u);
		}
		priority_queue<int> q;
	  int remove = 0; //제거된 폭탄의 갯수
		for(int i =1; i <=n; i++){
				if(out[i]==0){
						//제거해야하는 큐에 넣어준다
						q.push(-i); // "-"를 붙여 큐에 넣어준다.
						out[i] = -1; //중복처리 안되게 처리
					
				}
		}
	vector<int> order; //출력되는 순서를 저장할 배열
	//q가 비어있지 않은 동안에
		while(q.size() > 0){
				// 제거해야하는 target을 정한다.
				int target = - q.top(); // "-"를 붙이는 이유는 큐에 넣을 때 -를 붙였기 때문에
				q.pop(); //target을 제거

			  remove++; //제거되었으므로 1 증가
				order.push_back(target);
				// target이 제거되면 그 타켓과 연결되었던 폭탄들도 제거할 수 있음
				for(int i = 0; i < adj[target].size(); i++){
						int next = adj[target][i];
					  out[next]--;
						if(out[next] == 0){
								out[next] = -1;
								q.push(-next);
						}
				}
		}
	
	if(remove == n){
		for(int i =0; i < n; i++){
				printf("%d ",order[i]);
			
		}
		printf("\n");
	}
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
