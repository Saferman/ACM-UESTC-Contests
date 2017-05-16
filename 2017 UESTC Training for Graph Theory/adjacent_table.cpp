# include<stdio.h>
# include<math.h>
#include "malloc.h"
#define MAXVEX 10 //最大顶点数

typedef struct EdgeNode
{
    int vex; //临接点域，储存顶点对应的下标
    int weight; //储存权重
    struct EdgeNode *next;  ////链域，指向下一个邻接点
}EdgeNode;

typedef struct
{
    int numVertexes, numEdges; //图中当前顶点数和边数
    EdgeNode * vertexes[MAXVEX]; //顶点数组，储存边表指针
}GraphList;

void addEdgeNode(EdgeNode *p, int j, int w)
{
    EdgeNode * tem_p, * pNew;
    int flag = 0;
    while (p!= NULL)
    {
        flag = 1;
        tem_p = p;
        p = p->next;
    }
    pNew = (EdgeNode *)malloc(sizeof(EdgeNode));
    pNew->vex = j - 1;
    pNew->weight = w;
    pNew->next = NULL;
    if (flag == 1)
        tem_p->next = pNew;
    else
        tem_p = pNew;
}

void CreateGraph(GraphList *g)
{
    //处理无向图
    scanf("%d %d", &(g->numVertexes), &(g->numEdges));
    int i, j, w;
    //初始化
    for (int k = 0; k < g->numVertexes; k++)
    {
        g->vertexes[k] = NULL;
    }
    for (int k = 0; k < g->numEdges; k++)
    {
        scanf("%d %d %d",&i,&j,&w);
        addEdgeNode(g->vertexes[i - 1], j, w);
        addEdgeNode(g->vertexes[j - 1], i, w); //体现无向图的步骤
    }
}

void printGraph(GraphList *g)
{
    int k = 0;
    EdgeNode *p;
    while (k < g->numVertexes)
    {
        printf("顶点%d: ", k);
        p = g->vertexes[k];
        while (p != NULL)
        {
            printf("(%d,%d) ", p->vex, p->weight);
            p = p->next;
        }
        printf("\n");
        k++;
    }
}

int main()
{
    GraphList g;
    CreateGraph(&g);
    printGraph(&g);
    return 0;
}

