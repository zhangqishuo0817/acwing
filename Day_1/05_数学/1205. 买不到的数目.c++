# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>

using namespace std;

bool dfs(int i, int p, int q){
    if(!i) return true;
    if(i >= p && dfs(i - p, p, q)) return true;
    if(i >= q && dfs(i - q, p, q)) return true;
    return false;
}
int main(){
    int p, q;
    int res = 0;
    cin >> p >> q;
    for(int i = 1; i <= 1000; i ++){
        if(!dfs(i, p, q)){
            res = i;
        }
    }
    cout << res << endl ;
    return 0;
}


# include <iostream>

using namespace std;

int main(){
    int p, q;
    cin >> p >> q;
    int res = (p - 1) * (q - 1) - 1;
    cout << res << endl;
    return 0;
}