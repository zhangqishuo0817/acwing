way 1:
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int ans;
const int N = 20;
int ways[N];

bool used[N];
int n;

// 检查a + b/c 是否等于n
bool check(int a, int b, int c) {
    if (c!= 0 && a + b / c == n && b % c == 0) {
        return true;
    }
    return false;
}

// 计算从a到b位置组成的数字
int calc(int a, int b) {
    int answer = 0;
    for (int i = a; i <= b; i++) {
        answer = answer * 10 + ways[i];
    }
    return answer;
}

// 深度优先搜索函数
void dfs(int u) {
    if (u > 9) {
        for (int i = 1; i <= 7; i++) {
            for (int j = i + 1; j <= 8; j++) {
                int a = calc(1, i);
                int b = calc(i + 1, j);
                int c = calc(j + 1, 9);
                if (check(a, b, c)) {
                    ans++;
                }
            }
        }
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (!used[i]) {
            ways[u] = i;
            used[i] = true;
            dfs(u + 1);
            ways[u] = 0;
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;

    dfs(1);

    printf("%d\n", ans);
    return 0;
}


way 2:
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N =10;

bool st[N],backup[N]; // st[N]是已经使用过的数组，
int ans; // 最终输出的符合答案的数量
int n; //输入的数字

// a参数代表的是带分数的整数部分 b参数代表的是带分数的分数部分的分子部分 c参数代表的是带分数的分数部分的分母部分
// 在题目中，我们可以得到一个通式 : n = a + b / c 两边同时乘 c ,得到 n * c = a * c + b 所以 b = n * c - a * c 可以用a , c两个参数推出b参数，从而得到a ,b ,c 三个参数
bool check(int a , int c) // check函数是用来检查 a , b , c三个参数是否符合题意。
{
    long long b = n *(long long)c - a*c; //用来表达 a b c 三个参数的通式
    if (!a || !b || !c) return false ; //这句话的意思是 a b c 三个数字如果有一个数字为0，则停止本函数运行 
                                        //if()里面为0，不运行if后的表达式,即return false 如果a b c 三个函数中存在0 ， 则！n为1，if内不为0，则运行return false;

    memcpy(backup , st , sizeof st); // 这句话的意思是复制一个数组 backup为原数组 st 为复制过的backup的新数组, sizeof 为长度。

    while (b)  //对b的每位数进行遍历
    {
        int x = b%10; // 对b取余,并存储在x中
        b/=10; //取余后删掉此位
        if(!x ||backup[x]) return false; //如果x为0 或backup[]不为0，则停止此函数运行。
        backup[x] =true;
    }
    for (int i =1 ; i <= 9 ; i++ ) // 判断每个数字
        if(!backup[i])return false ; 
    return true;
}

void dfs_c(int u , int a , int c ) // u表示我们已经使用了多少个数字
{
    if(u > 9) return; //如果9个数字全部使用，则直接输出就好了。
    if(check(a,c)) ans ++; //如果a c 满足情况，即a b c三个参数军满足情况，那么ans 则加一
    for(int i = 1 ; i <= 9; i++ )  // 判断每个数字
    if(!st[i]) //如果st[i] = 0则运行
    {
        st[i] = true; //让st[i] = 1 
        dfs_c  (u+1 , a , c * 10 + i); // 如果这个数没有用过，就把它放在c后面，dfs的下一层。
        st[i] = false; // 恢复现场
    }
}

void dfs_a(int u , int a )
{
    if (a >= n) return ;  //如果当前的a 大于等于输入的n ,则返回 (带分数的整数部分大于等于输入的数字)
    if (a)  dfs_c(u , a , 0);//如果a满足情况，则枚举c，0为c的大小
    for(int i = 1; i <= 9 ; i++)
        if(!st[i])
        {
            st[i] = true;
            dfs_a (u+1 , a*10+i);
            st[i] = false; //恢复现场
        }
}

int  main()
{
    cin >> n ;
    dfs_a (0,0); // 第一个0表示用了多少个数字；第二个0表示当前的a为多少。
    cout << ans <<endl;
    return 0;

}
