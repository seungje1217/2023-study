#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;	// 스레드이면 TRUE
} TreeNode;

TreeNode* find_successor(TreeNode* p) {
	TreeNode* q = p->right; // q는 p의 오른쪽 포인터
	if (q == NULL || p->is_thread == TRUE)
		return q;

	while (q->left != NULL) // 만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
		q = q->left;

	return q;
}

void thread_inorder(TreeNode* t) {
	TreeNode* q = t;

	while (q->left)
		q = q->left; // 가장 왼쪽 노드로 이동

	do {
		printf("%c -> ", q->data); // 데이터 출력
		q = find_successor(q); // 후속자 함수 호출
	} while (q); // NULL이 아니면
}

TreeNode* create_node(int data, TreeNode* left, TreeNode* right, int is_thread) 
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = left;
	node->right = right;
	node->is_thread = is_thread;
	return node;
}

int main(void) {
	TreeNode* n1 = create_node('A', NULL, NULL, 1);
	TreeNode* n2 = create_node('B', NULL, NULL, 1);
	TreeNode* n3 = create_node('C', n1, n2, 0);
	TreeNode* n4 = create_node('D', NULL, NULL, 1);
	TreeNode* n5 = create_node('E', NULL, NULL, 0);
	TreeNode* n6 = create_node('F', n4, n5, 0);
	TreeNode* n7 = create_node('G', n3, n6, 0);
	TreeNode* exp = n7;

	// 스레드 설정 
	n1->right = n3;
	n2->right = n7;
	n4->right = n6;

	// 중위 순회
	thread_inorder(exp);
	printf("\n");

	// 메모리 해제
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	free(n6);
	free(n7);

	return 0;
}
