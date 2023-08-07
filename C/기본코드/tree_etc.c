#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode* left, * right;
} TreeNode;

//        15
//      4       20
//    1         16  25

int get_node_count(TreeNode* node);   // 전체노드의 수
int get_leaf_count(TreeNode* node);   // 단말노드의 수
int get_height(TreeNode* node);       // 높이

int main()
{
    // 노드 동적 메모리 할당
    TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n5 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n6 = (TreeNode*)malloc(sizeof(TreeNode));

    // 데이터 초기화
    n1->data = 1;
    n2->data = 4;
    n3->data = 16;
    n4->data = 25;
    n5->data = 20;
    n6->data = 15;

    // 노드 연결
    n1->left = NULL;
    n1->right = NULL;

    n2->left = n1;
    n2->right = NULL;

    n3->left = NULL;
    n3->right = NULL;

    n4->left = NULL;
    n4->right = NULL;

    n5->left = n3;
    n5->right = n4;

    n6->left = n2;
    n6->right = n5;
    TreeNode* root = n6;

    int result1, result2, result3;

    result1 = get_node_count(root);
    printf("전체노드 수: %d \n", result1);

    result2 = get_leaf_count(root);
    printf("단말노드 수: %d \n", result2);

    result3 = get_height(root);
    printf("트리의 높이: %d \n", result3);

    return 0;
}

int get_node_count(TreeNode* node) // 전체노드의 수
{
    int count = 0;

    if (node != NULL)
        count = 1 + get_node_count(node->left) +
        get_node_count(node->right);

    return count;
}

int get_leaf_count(TreeNode* node)  // 단말노드의 수
{
    int count = 0;

    if (node != NULL) {
        if (node->left == NULL && node->right == NULL)
            return 1;
        else
            count = get_leaf_count(node->left) +
            get_leaf_count(node->right);
    }
    return count;
}

int get_height(TreeNode* node) // 트리의 높이
{
    int height = 0;

    if (node != NULL)
        height = 1 + max(get_height(node->left), // max는 매크로 함수
            get_height(node->right));

    return height;
}
