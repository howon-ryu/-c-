#include <iostream>

using namespace std;

class ChainNode {

    friend class Chain;

private:
    int data;
    ChainNode* link;

public:
    ChainNode(int value = 0, ChainNode* _link = NULL)
    {
        data = value;
        link = _link;
    }

};

class Chain {

private:
    ChainNode* first;
    ChainNode* second;

public:
    Chain();
    void makeChainNode(int value);
    int insertChainNode(int value, int pos);
    void print();

};

Chain::Chain() // ������
{
    first = NULL;
    second = NULL;
}

void Chain::makeChainNode(int value)
{
    if (first == NULL)
    {
        second = new ChainNode(0, NULL); // ü�γ�� ���� ���� 0,0���� �ʱ�ȭ
        first = new ChainNode(value, second); // ù ü�γ��� value�� ����, second�� link
    }

    else
    {
        ChainNode* tmp;

        second->data = value;

        tmp = new ChainNode(0, NULL); // �� ���� ���� ������ ��ũ�� NULL

        second->link = tmp; // ������ ����Ű�� second�� link�� ���� ���� second�� link ����Ű����
        second = tmp;
    }
}

int Chain::insertChainNode(int value, int pos)
{
    ChainNode* cur = first;
    ChainNode* tmp;
    int count = 0;

    while (cur->link != NULL) // �� ���� Ȯ��
    {
        cur = cur->link;
        count++;
    }

    cur = first;

    if (count < pos)
    {
        cout << "��尡 �������� �ʽ��ϴ�." << endl;
        return 0;
    }
    else if (count == pos)
    {
        cout << "<< 1. ��� ���� >> �� �̿��� �ּ���" << endl;
        return 0;
    }
    for (int i = 1; i < pos; i++)
    {
        cur = cur->link;
    }

    tmp = new ChainNode(value, cur->link);
    cur->link = tmp;
    return 1;
}

void Chain::print()
{
    ChainNode* cur = first;
    while (cur->link != NULL)
    {
        cout << cur->data << " ";
        cur = cur->link;
    }
    cout << endl;
}

int main()
{
    Chain a;
    int value;
    int num;
    int pos;

    cout << "------------ Chain Node Program ------------" << endl;
    while (1)
    {
        cout << "1. ��� ���� 2. ��� ���� 3. ��� Ȯ�� 4. ��� ���� 5. ����" << endl;

        cout << "��ȣ �Է� :: "; cin >> num;

        switch (num)
        {
        case 1:
            cout << "��� �� �Է� :: "; cin >> value;
            a.makeChainNode(value);
            break;

        case 2:
            cout << "�� ��° ��� ���� ����? :: "; cin >> pos;
            cout << "��� �� �Է� :: "; cin >> value;
            a.insertChainNode(value, pos);
            break;
        case 3:
            a.print();
            break;

        case 4:
            /*
            * ���� ������ �� �ڵ带 ����ϴ� ����� ��
            * ���� ���� :: ������ ������ ����, ù ������ ����, Ư�� ��� ����
            */
            break;

        case 5:
            return 0;
            break;
        }
    }
}

