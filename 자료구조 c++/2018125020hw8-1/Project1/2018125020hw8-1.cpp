#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

// Node 자료형 선언
typedef struct node* nodePointer;
typedef struct node {
	int value;
	nodePointer leftchild, rightchild;
}node;

// BST 함수 선언
nodePointer insertNode(nodePointer root, int value);
nodePointer findMinNode(nodePointer root);
nodePointer deleteNode(nodePointer root, int value);
void printTree(nodePointer root);
void printTreee(nodePointer root);

// 삽입
nodePointer insertNode(nodePointer root, int value) {
	// 초기화
	if (root == NULL) {
		root = (nodePointer)malloc(sizeof(node));
		root->leftchild = NULL;
		root->rightchild = NULL;
		root->value = value;
		return root;
	}

	// 그외 위치 찾아서 삽입(재귀적)
	else {
		// 작을 경우 왼쪽 자식 트리
		if (root->value > value) {
			root->leftchild = insertNode(root->leftchild, value);
		}

		// 클 경우 오른쪽 자식 트리
		else {
			root->rightchild = insertNode(root->rightchild, value);
		}
	}

	return root;
}

// 최소노드 찾기
nodePointer findMinNode(nodePointer root) {
	nodePointer search_np = root;
	while (search_np->leftchild != NULL) {
		search_np = search_np->leftchild;
	}
	return search_np;
}

// 삭제
nodePointer deleteNode(nodePointer root, int value) {
	nodePointer t_np = NULL;

	// NULL
	if (root == NULL) {
		return NULL;
	}

	// 탐색
	// 작을 경우
	if (root->value > value) {
		root->leftchild = deleteNode(root->leftchild, value);
	}
	// 클 경우
	else if (root->value < value) {
		root->rightchild = deleteNode(root->rightchild, value);
	}
	// 찾았을 경우
	else {
		// 자식노드가 두개 있을경우(바로 다음값 가져와서 교환)
		if (root->leftchild != NULL && root->leftchild != NULL) {
			t_np = findMinNode(root->rightchild);
			root->value = t_np->value;
			root->rightchild = deleteNode(root->rightchild, t_np->value); // 오른쪽 트리 끝값 삭제
		}

		// 자식노드가 하나 이하일 경우
		else {
			t_np = (root->leftchild == NULL) ? root->rightchild : root->leftchild;
			free(root); // 삭제
			return t_np; // 자식트리를 반환한다
		}
	}
	return root;

}

// 전위 순회 방식 
void printTree(nodePointer root) {
	if (root == NULL) {
		return;
	}

	printTree(root->leftchild);
	printf("%d ", root->value);
	printTree(root->rightchild);

}

void printTreee(nodePointer root) {
	if (root == NULL) {
		return;
	}

	printTreee(root->rightchild);

	printf("%d ", root->value);

	printTreee(root->leftchild);

	
}
void main() {
	nodePointer root = NULL;

	while (1)
	{
		cout << "정수를 입력하세요 : ";
		char b[10];
		int a = 0;
		cin >> b;
		if (b[0] == '#')
			break;
		a = atoi(b);
		root = insertNode(root, a);


	}

	cout << "A0: ";
	printTree(root); 	cout << '#';


	printf("\n");
	cout << "D0: ";
	printTreee(root);	cout << '#';

}