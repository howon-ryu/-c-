#include<iostream>
#include<cstdio>
#include<string>
#include< stdlib.h >
#define null 0
using namespace std;

/*
template<class T>
class BinaryTree
{
public:
	BinaryTree();
	bool IsEmpty();
	BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2);
	BinaryTree<T>LeftSubtree();
	BinaryTree<T>RightSubtree();
	T RootData();

};*/



template <class T>class Tree;
template <class T>
class TreeNode {
public:

	friend class Tree<T>;
	TreeNode(T data = 0, TreeNode* leftChild = null, TreeNode* rightChild = null) 
	{
		this->data = data;
		this->leftChild = leftChild;
		this->rightChild = rightChild;
	}
private:
	T data;
	TreeNode<T>* leftChild;
	TreeNode<T>* rightChild;

};

template <class T>
class Tree {
public:
	//Tree() {};
	void push(T data = 0)
	{
		
		root = new TreeNode<T>(data);
		//root->leftChild = new TreeNode<T>(data);
		//root->rightChild = new TreeNode<T>(data);
		buildTree(data);
		
	}
	void buildTree(T num) {
		//if(root->)
		root->leftChild = new TreeNode<T>(num,root->leftChild,null);
		root->rightChild = new TreeNode<T>(num,null, root->rightChild);
		cout << root->leftChild;
		cout << root->rightChild;
		/*
		root->leftChild = new TreeNode<T>('B', new TreeNode<T>('D', new TreeNode<T>('H')), new TreeNode<T>('E', new TreeNode<T>('I'), new TreeNode<T>('J')));
		root->rightChild = new TreeNode<T>('C', new TreeNode<T>('F'), new TreeNode<T>('G', null, new TreeNode<T>('K')));*/
	}
	TreeNode<T>* getRoot() {
		return root;
	}
	class iterator {
		TreeNode<T>* current;
	public:
		iterator(TreeNode<T>* p) : current(p) {}
		iterator& operator ++() {
			current = current->leftChild;
			return *this;
		}
		T& operator *() { return current->data; }
		bool operator !=(const iterator t) { return current != t.current; }
		bool operator ==(const iterator t) { return current == t.current; }

	};
	iterator begin()
	{
		return iterator(root);
	}
	iterator end()
	{
		return iterator(NULL);
	}
	//void NonrecInorder();
	//void Inorder() ;
	void Inorder(TreeNode<T>* currentNode) ;
	void Visit(TreeNode<T>* currentNode);
	//void Preorder();
	void Preorder(TreeNode<T>* currrentNode);
	//void Postorder();
	void Postorder(TreeNode<T>* currentNode);

private:
	TreeNode<T>* root;

};
/*
template<class T>
void Tree<T>::Inorder()
{
	Inorder(root);
}*/
template<class T>
void Tree<T>::Visit(TreeNode<T>* currentNode)
{
	cout << "[";
	cout << " "<<currentNode->data << " ";
	cout << "]";

}

template<class T>
void Tree<T>::Inorder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);

	}
}
/*
template<class T>
void Tree<T>::Preorder()
{
	Preorder(root);
}*/

template<class T>
void Tree<T>::Preorder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		Visit(currentNode);
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}
/*
template<class T>
void Tree<T>::Postorder()
{
	Postorder(root);
}*/

template<class T>
void Tree<T>::Postorder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);
	}
}


/*
template<class T>
void Tree<T>::NonrecInorder()
{
	Stack<TreeNode<T>*>s;

	TreeNode<T>* currentNode = root;

	while (1)
	{
		while (currentNode)
		{
			s.Push(currentNode);
			currentNode = currentNode->leftChild;
		}
		if (s.IsEmpty()) return;
		currentNode = s.Top();
		s.Pop();
		Visit(currentNode);
		currentNode = currentNode->rightChild;
	}
	
}
template<class T>
class InorderIterator {
public:
	InorderIterator() { currentNode = root; };
	T* Next();
private:
	Stack<TreeNode<T>*>s;
	TreeNode<T> *currentNode;

};

template<class T>
T * InorderIterator::Next()
{
	while (currentNode)
	{
		s.Push(currentNode);
		currentNode = currentNode->leftChild;
	}
	if (s.IsEmpty())return 0;
	currentNode = s.Top();
	s.Pop();
	T& temp = currentNode->data;
	currentNode = currentNode->rightChild;
	return &temp;
}*/

/*
template<class TreeNode>
ostream& operator<< (ostream& os, TreeNode& p)
{
	os << p << endl;
	return os;
}
*/

int main()
{
	Tree<int> a;
	int b = 5;
	a.push(null);
	
	for (int i = 0; i < b; i++)
	{
		char c[10];
		int num = 0;
		cout << "트리에 들어갈 정수를 입력하세요 : ";
		cin >> c;
		cout << "c[] 출력 " << c[0] << '\n';
		if (c[0] == '#')
		{
			cout << "# 만남";
			break;
		}
		num = atoi(c);
		a.push(num);
		/*if (i == 0)
		{
			a.push(num);
		}
		else
			a.buildTree(num);*/
	}
	
	cout << "Preorder >> ";
	a.Preorder(a.getRoot());
	cout << endl;

	cout << "Inorder >> ";
	a.Inorder(a.getRoot());
	cout << endl;

	cout << "Postorder >> ";
	a.Postorder(a.getRoot());
	cout << endl;
	/*for (Tree<int>::iterator ait = a.begin(); ait != a.end(); ++ait)
	{
		cout << *ait; 
		cout << '/';

	}*/
	

}