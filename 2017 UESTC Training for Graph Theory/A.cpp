# include<stdio.h>
# include<math.h>
#include "malloc.h"
#define MAXVEX  100             //最大顶点数，应由用户定义
#define INFINITY   65535               //用65535来代表无穷大
int max_w = 1000000;
typedef struct node
{
    int data;
    struct node *next;
};
//使用链栈来存放一条完整路径的Value值
node *v = NULL; //栈指针
int tem_Charm_Value;
int min_Charm_Value = max_w; //保存最终答案

//栈操作函数
void initial(node *p)
{
    p->next = NULL;
}
void push(node **top, int x)
{
    node *p;
    p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = (*top);
    (*top) = p;
}
int pop(node **top)
{
    node *p;
    int x;
    if ((*top) == NULL)
    {
        printf("stack is underflow");
        return (NULL);
    }
    x = (*top)->data;
    p = (*top);
    (*top) = (*top)->next;
    free(p);
    return x;
}
int findMax(node *top)
{
    int Charm_Value = max_w;
    while (top != NULL)
    {
        if (top->data < Charm_Value)
        {
            Charm_Value = top->data;
        }
        top = top->next;
    }
    return Charm_Value;
}
//--------------------------------以上是栈操作函数

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

void DFS(Graph *g,int i)
{
    for (int j = 0; j < g->numVertexes; j++)
    {
        if (g->arc[i][j] != INFINITY)
        {
            push(&v, g->arc[i][j]);
            if (j == g->numVertexes - 1)
            {
                tem_Charm_Value = findMax(v);
                if (tem_Charm_Value < min_Charm_Value)
                {
                    min_Charm_Value = tem_Charm_Value;
                }
            }
            else
            {
                DFS(g, j);
            }
            pop(&v);
        }
    }
}

void DFSTraverse(Graph *g)
{
    initial(v);
    DFS(g, 0);
}

int main()
{
    Graph g;
    // printf("%d", INFINITY);
    CreateGraph(&g);
    // printGraph(&g);
    DFSTraverse(&g);
    printf("%d\n", min_Charm_Value);
    return 0;
}

