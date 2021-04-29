//O(M+N)

q.push(1); //q.push(start)
while(!q.empty()){
	keep = q.front();
	q.pop();
	if(keep == n){// keep == end
		flag = true;
	}
	for(int i=0;i<g[keep].size();i++){
		if(vis[g[keep][i]] == 0){
			vis[g[keep][i]] = keep;
              //紀錄路徑的上個點，用來找輸出路徑
			q.push(g[keep][i]);
		}
	}
}
keep = n;//從最後開始找
vector<int> v;//存路徑
while(keep != 1){
     v.push_back(keep);
	keep = vis[keep];
}
v.push_back(1);  // v 是倒著的路徑
