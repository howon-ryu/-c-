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

Chain::Chain() // 생성자
{
    first = NULL;
    second = NULL;
}

void Chain::makeChainNode(int value)
{
    if (first == NULL)
    {
        second = new ChainNode(0, NULL); // 체인노드 다음 것을 0,0으로 초기화
        first = new ChainNode(value, second); // 첫 체인노드는 value값 대입, second로 link
    }

    else
    {
        ChainNode* tmp;

        second->data = value;

        tmp = new ChainNode(0, NULL); // 새 노드는 값만 가지고 링크는 NULL

        second->link = tmp; // 이전에 가리키던 second의 link가 새로 생긴 second의 link 가리키도록
        second = tmp;
    }
}

int Chain::insertChainNode(int value, int pos)
{
    ChainNode* cur = first;
    ChainNode* tmp;
    int count = 0;

    while (cur->link != NULL) // 총 개수 확인
    {
        cur = cur->link;
        count++;
    }

    cur = first;

    if (count < pos)
    {
        cout << "노드가 존재하지 않습니다." << endl;
        return 0;
    }
    else if (count == pos)
    {
        cout << "<< 1. 노드 생성 >> 을 이용해 주세요" << endl;
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
        cout << "1. 노드 생성 2. 노드 삽입 3. 노드 확인 4. 노드 삭제 5. 종료" << endl;

        cout << "번호 입력 :: "; cin >> num;

        switch (num)
        {
        case 1:
            cout << "노드 값 입력 :: "; cin >> value;
            a.makeChainNode(value);
            break;

        case 2:
            cout << "몇 번째 노드 다음 삽입? :: "; cin >> pos;
            cout << "노드 값 입력 :: "; cin >> value;
            a.insertChainNode(value, pos);
            break;
        case 3:
            a.print();
            break;

        case 4:
            /*
            * 삭제 과정은 이 코드를 사용하는 사용자 몫
            * 삭제 구현 :: 마지막 노드부터 삭제, 첫 노드부터 삭제, 특정 노드 삭제
            */
            break;

        case 5:
            return 0;
            break;
        }
    }
}

