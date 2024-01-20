#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);

typedef struct
{
    int u, v, w;
} Edge;

typedef struct
{
    Edge data[MAX_EDGES];
    int n;
} EdgeList;

EdgeList primList, kruskalList;
int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

int minimumKey(int key[], int mstSet[])
{
    int min = INT_MAX, minIndex, i;
    for (i = 0; i < numVertices; i++)
    {
        if (mstSet[i] == 0 && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void primMST()
{
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES];
    int i, count, u, v;

    for (i = 0; i < numVertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < numVertices - 1; count++)
    {
        u = minimumKey(key, mstSet);
        mstSet[u] = 1;

        for (v = 0; v < numVertices; v++)
        {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Constructing Prim's MST Edge List
    primList.n = 0;
    for (i = 1; i < numVertices; i++)
    {
        Edge e = {parent[i], i, graph[i][parent[i]]};
        primList.data[primList.n++] = e;
    }
}

void kruskalMST()
{
    int belongs[MAX_VERTICES];
    int i, j, cno1, cno2;

    primList.n = 0;
    for (i = 1; i < numVertices; i++)
        for (j = 0; j < i; j++)
            if (graph[i][j] != 0)
            {
                Edge e = {i, j, graph[i][j]};
                primList.data[primList.n++] = e;
            }

    // Sorting edges based on weight
    for (i = 1; i < primList.n; i++)
        for (j = 0; j < primList.n - 1; j++)
            if (primList.data[j].w > primList.data[j + 1].w)
            {
                Edge temp = primList.data[j];
                primList.data[j] = primList.data[j + 1];
                primList.data[j + 1] = temp;
            }

    for (i = 0; i < numVertices; i++)
        belongs[i] = i;

    kruskalList.n = 0;
    for (i = 0; i < primList.n; i++)
    {
        cno1 = find(belongs, primList.data[i].u);
        cno2 = find(belongs, primList.data[i].v);

        if (cno1 != cno2)
        {
            kruskalList.data[kruskalList.n++] = primList.data[i];
            applyUnion(belongs, cno1, cno2);
        }
    }
}

int find(int belongs[], int vertexno)
{
    return belongs[vertexno];
}

void applyUnion(int belongs[], int c1, int c2)
{
    int i;
    for (i = 0; i < numVertices; i++)
        if (belongs[i] == c2)
            belongs[i] = c1;
}

void printEdgeList(EdgeList list, const char *title)
{
    int i, cost = 0;
    printf("\n%s MST Edges:\n", title);
    for (i = 0; i < list.n; i++)
    {
        printf("%d - %d : %d\n", list.data[i].u, list.data[i].v, list.data[i].w);
        cost += list.data[i].w;
    }
    printf("Total MST Cost: %d\n", cost);
}

void inputGraph()
{
    int i, j;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the graph adjacency matrix:\n");
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}

int main()
{
    inputGraph();
    primMST();
    printEdgeList(primList, "Prim's");

    kruskalMST();
    printEdgeList(kruskalList, "Kruskal's");

    return 0;
}