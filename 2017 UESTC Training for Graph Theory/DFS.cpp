# include<stdio.h>
# include<math.h>
#define MAXVEX  200             //最大顶点数，应由用户定义
#define INFINITY   65535               //用65535来代表无穷大
typedef int Boolean;            //Boolean 是布尔类型，其值是TRUE 或FALSE
Boolean visited[MAXVEX];        //访问标志数组
#define TRUE 1
#define FALSE 0

typedef struct
{
    int arc[MAXVEX][MAXVEX];    //邻接矩阵，可看做边
    int numVertexes, numEdges;  //图中当前顶点数
}Graph;

void CreateGraph(Graph *g)
{
    int i, j, w;
    scanf("%d %d", &(g->numVertexes), &(g->numEdges));
    //初始化临接矩阵
    for (int m = 1; m <= g->numVertexes; m++)
    {
        for (int n = 1; n <= g->numVertexes; n++)
        {
            g->arc[m - 1][n - 1] = INFINITY;
        }
    }
    for (int k = 0; k < g->numEdges; k++)
    {
        scanf("%d %d %d", &i, &j, &w);
        g->arc[i - 1][j - 1] = w;
        g->arc[j - 1][i - 1] = w;//因为是无向图
    }
}

void printGraph(Graph *g)
{

    for (int m = 1; m <= g->numVertexes; m++)
    {
        for (int n = 1; n <= g->numVertexes; n++)
        {
            printf("%d     ", g->arc[m - 1][n - 1]);
        }
        printf("\n");
    }
}

//邻接矩阵的深度优先递归算法
void DFS(Graph *g, int i)
{
    int j;
    visited[i] = TRUE;
    
    for (j = 0; j < g->numVertexes; j++)
    {
        if (g->arc[i][j] != INFINITY && !visited[j])
        {
            DFS(g, j);                  //对为访问的邻接顶点递归调用
        }
        if (g->arc[i][j] != INFINITY)
        {
            printf("%d\n", g->arc[i][j]);//打印i,j位置权重，也可以其他操作
        }
    }
}

//邻接矩阵的深度遍历操作
void DFSTraverse(Graph *g)
{
    int i;
    for (i = 0; i < g->numVertexes; i++)
    {
        visited[i] = FALSE;         //初始化所有顶点状态都是未访问过状态
    }
    for (i = 0; i < g->numVertexes; i++)
    {
        if (!visited[i])             //对未访问的顶点调用DFS，若是连通图，只会执行一次
        {
            DFS(g, i);
        }
    }
}

int main()
{
    Graph g;
    // printf("%d", INFINITY);
    CreateGraph(&g);
    // printGraph(&g);
    DFSTraverse(&g);
    return 0;
}

