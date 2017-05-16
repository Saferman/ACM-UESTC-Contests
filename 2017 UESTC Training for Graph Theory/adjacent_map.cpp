# include<stdio.h>
# include<math.h>
#define MAXVEX  100             //最大顶点数，应由用户定义
#define INFINITY   65535               //用65535来代表无穷大

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
            g->arc[m-1][n-1] = INFINITY;
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

    for (int m = 1; m <= g->numVertexes;m++)
    {
        for (int n = 1; n <= g->numVertexes; n++)
        {
            printf("%d     ", g->arc[m - 1][n - 1]);
        }
        printf("\n");
    }
}

int main()
{
    Graph g;
    // printf("%d", INFINITY);
    CreateGraph(&g);
    // printGraph(&g);
    return 0;
}

