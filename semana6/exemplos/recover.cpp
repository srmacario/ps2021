vi recover(int u){
    vi ans;
    while(par[u]] != u){
        ans.pb(u);
        u = par[u];
    }
    ans.pb(u);
}