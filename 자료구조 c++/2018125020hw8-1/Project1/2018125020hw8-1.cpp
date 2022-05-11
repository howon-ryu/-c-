#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

// Node �ڷ��� ����
typedef struct node* nodePointer;
typedef struct node {
	int value;
	nodePointer leftchild, rightchild;
}node;

// BST �Լ� ����
nodePointer insertNode(nodePointer root, int value);
nodePointer findMinNode(nodePointer root);
nodePointer deleteNode(nodePointer root, int value);
void printTree(nodePointer root);
void printTreee(nodePointer root);

// ����
nodePointer insertNode(nodePointer root, int value) {
	// �ʱ�ȭ
	if (root == NULL) {
		root = (nodePointer)malloc(sizeof(node));
		root->leftchild = NULL;
		root->rightchild = NULL;
		root->value = value;
		return root;
	}

	// �׿� ��ġ ã�Ƽ� ����(�����)
	else {
		// ���� ��� ���� �ڽ� Ʈ��
		if (root->value > value) {
			root->leftchild = insertNode(root->leftchild, value);
		}

		// Ŭ ��� ������ �ڽ� Ʈ��
		else {
			root->rightchild = insertNode(root->rightchild, value);
		}
	}

	return root;
}

// �ּҳ�� ã��
nodePointer findMinNode(nodePointer root) {
	nodePointer search_np = root;
	while (search_np->leftchild != NULL) {
		search_np = search_np->leftchild;
	}
	return search_np;
}

// ����
nodePointer deleteNode(nodePointer root, int value) {
	nodePointer t_np = NULL;

	// NULL
	if (root == NULL) {
		return NULL;
	}

	// Ž��
	// ���� ���
	if (root->value > value) {
		root->leftchild = deleteNode(root->leftchild, value);
	}
	// Ŭ ���
	else if (root->value < value) {
		root->rightchild = deleteNode(root->rightchild, value);
	}
	// ã���� ���
	else {
		// �ڽĳ�尡 �ΰ� �������(�ٷ� ������ �����ͼ� ��ȯ)
		if (root->leftchild != NULL && root->leftchild != NULL) {
			t_np = findMinNode(root->rightchild);
			root->value = t_np->value;
			root->rightchild = deleteNode(root->rightchild, t_np->value); // ������ Ʈ�� ���� ����
		}

		// �ڽĳ�尡 �ϳ� ������ ���
		else {
			t_np = (root->leftchild == NULL) ? root->rightchild : root->leftchild;
			free(root); // ����
			return t_np; // �ڽ�Ʈ���� ��ȯ�Ѵ�
		}
	}
	return root;

}

// ���� ��ȸ ��� 
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
		cout << "������ �Է��ϼ��� : ";
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