# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>

using namespace std;
typedef long long LL;
const int N = 100010;
int n, k;
LL cnt[N],s[N];


int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> s[i];
        s[i] += s[i-1];
    }
    
    LL res = 0;
    //cnt[0] = 1;//注意：cnt记录的是0-R-1之间的余数为k的个数，而s【0】=0,0%任意数为0，而我们从1开始枚举，故先把0 这一方面的可能算上
    for (int i = 0; i <= n; i ++){
        res += cnt[s[i] % k];
        cnt[s[i] % k]++;
    }
    
    cout << res << endl;
    return 0;
}