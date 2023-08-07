#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char* message);
void queue_init(QueueType* q);
int is_empty(QueueType* q);
int is_full(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct {
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void queue_init(QueueType* q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
    if (is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
    if (is_empty(q))
        error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

void init(GraphType* g) {
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) {
    for (int i = 0; i < g->n; i++) {
        GraphNode* p = g->adj_list[i];
        printf("정점 %d의 인접 리스트: ", i);
        while (p != NULL) {
            printf("%d ", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

void bfs_list(GraphType* g, int v)
{
    GraphNode* w;
    QueueType q;

    queue_init(&q);
    visited[v] = TRUE;
    printf("%d 방문 -> ", v);
    enqueue(&q, v);
    while (!is_empty(&q)) {
        v = dequeue(&q);
        for (w = g->adj_list[v]; w != NULL; w = w->link) {
            if (!visited[w->vertex]) {
                visited[w->vertex] = TRUE;
                printf("%d 방문 -> ", w->vertex);
                enqueue(&q, w->vertex);
            }
        }
    }
}

int main(void)
{
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 6; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 0, 4);
    insert_edge(g, 4, 5);
    insert_edge(g, 1, 5);

    printf("너비 우선 탐색\n");

    printf("너비 우선 탐색: ");
    bfs_list(g, 0);
    printf("\n");

    free(g);

    return 0;
}

