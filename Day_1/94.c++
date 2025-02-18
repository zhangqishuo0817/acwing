# include<cstdio>
# include<cstring>
# include<iostream>

using namespace std;

// 定义全局变量n，用于表示序列的长度
int n;
// 定义常量N，作为数组的最大长度
const int N=10;
// st数组用于存储当前生成的序列
int st[N];
// used数组用于标记数字是否被使用，以避免重复使用
bool used[N];

/**
 * 实现深度优先搜索，生成所有可能的序列
 * @param u 当前位置的索引，从1开始
 */
void dfs(int u){
    // 如果当前位置索引大于n，说明已经生成了一个完整的序列
    if(u>n){
        // 遍历并打印当前序列
        for(int i=1;i<=n;i++){
            printf("%d ",st[i]);
        }
        // 打印换行符，准备输出下一个序列
        puts("");
        // 返回上一级递归，继续生成其他序列
        return ;
    }
    // 遍历所有可能的数字，尝试放在当前位置
    for(int i=1;i<=n;i++){
        // 如果当前数字尚未被使用，则可以将其放入当前位置
        if(!used[i]){
            // 将当前数字放入当前位置
            st[u]=i;
            // 标记当前数字为已使用
            used[i]=true;
            // 递归到下一个位置，继续生成序列
            dfs(u+1);
            
            // 回溯，将当前位置重置为空，以便尝试下一个数字
            st[u]=0;
            // 标记当前数字为未使用，以便在其他序列中使用
            used[i]=false;
        }
    }
}

int main(){
    // 输入序列的长度
    cin>>n;
    
    // 从第一个位置开始，尝试生成所有可能的序列
    dfs(1);
    return 0;
}