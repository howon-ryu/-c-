#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

template<class T> class ChainNode {
    template<class U>friend class Chain;/*<U>*/
private:
    T data;
    ChainNode* link;
public:
    ChainNode(T d, ChainNode* l) : data(d), link(l) {}
};



template<class T>class Chain {
private:
    ChainNode<T>* first;
public:
    Chain() { first = 0; }
    void push(T data)
    {
        first = new ChainNode<T>(data, first);
    }
    class iterator {
        ChainNode<T>* current;
    public:
        iterator(ChainNode<T>* p) : current(p) {}
        iterator& operator ++() {
            current = current->link;
            return *this;
        }
        T& operator *() { return current->data; }
        bool operator !=(const iterator t) { return current != t.current; }
        bool operator ==(const iterator t) { return current == t.current; }

    };
    iterator begin()
    {
        return iterator(first);
    }
    iterator end()
    {
        return iterator(NULL);
    }

};


int main()
{
    Chain<int> a;
    int b = 0;
    cout << "ü�� ����Ʈ�� ���� ������ �� ������ �Է��ϼ��� : ";
    cin >> b;
    for (int i = 0; i < b; i++)
    {
        int c = 0;
        cout << "ü�θ���Ʈ�� �� ������ �Է��ϼ��� : ";
        cin >> c;
        a.push(c); // ���� (1)
    }
    
    cout << "ü�� �ȿ� �ִ� ��� ���Ҵ� : ";
    for (Chain<int>::iterator ait = a.begin(); ait != a.end(); ++ait)
    {
        cout << *ait; // ����(2)
        cout << '/';
 
    }
    cout << "(���� ���)";
    cout << '\n';
    cout << "ü�� ����Ʈ �ȿ����� �ּڰ��� : ";
    int minValue = 99999;
    int min = 0;
    for (Chain<int>::iterator ait = a.begin(); ait != a.end(); ++ait)
    {
        if (minValue > *ait)
        {

            minValue = *ait;

        }

        min = minValue;
    }

    cout << min; // ���� (3)
}