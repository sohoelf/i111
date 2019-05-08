#include <iostream>
class Node {
public:
	int data;
	Node* next;
	Node(int i, Node* n) : data(i), next(n) {}
};
class DoublyNode {//双方向連結リスト
public:
	int data;
	DoublyNode* pre;
	DoublyNode* next;
	DoublyNode(DoublyNode* b, int i, DoublyNode* n) :pre(b), data(i), next(n) {}
};
void delete_(Node* n, Node*& head, Node*& tail)//delete を追加
{
	if (n != tail)//tailではないなら
	{
		Node* del = n->next;
		n->data = del->data;
		n->next = del->next;
		if (del->next == nullptr)tail = n;
		delete(del);
	}
	else
	{
		if (n != head)//tailだけど、headではない
		{
			auto i = head;
			while (i->next != n)
			{
				i = i->next;
			}
			i->next = nullptr;
			tail = i;
			delete(n);
		}
		else//tail&&head
		{
			head = tail = nullptr;
			delete(n);
		}
	}
}
void delete_(DoublyNode* n, DoublyNode*& head, DoublyNode*& tail)// delete を追加
{
	if (n != tail)//tailではないなら
	{
		DoublyNode* del = n->next;
		n->data = del->data;
		n->next = del->next;
		if (del->next == nullptr)//次のやつもtailではないなら
		{
			tail = n;
			delete(del);
		}
		else
		{
			del->next->pre = n;
			delete(del);
		}
	}
	else
	{
		if (n != head)//tailだけど、headではない
		{
			tail = n->pre;
			tail->next = nullptr;
			delete(n);
		}
		else//tail&&head
		{
			head = tail = nullptr;
			delete(n);
		}
	}
}
void headAndTail() {
	Node* head = nullptr;
	Node* tail = nullptr;//末尾を表すtailを加えて
	int array_[]{ 2,1,0,-1,-2 };
	for (int& i : array_)//先頭にinsert
	{
		Node* r = new Node(i, head);
		head = r;
		if (tail == nullptr)tail = r;//今tail == nullptrなので、これを実行しなきゃ・・
	}
	for (int& i : array_)//後ろににinsert
	{
		Node* r = new Node(i, nullptr);
		tail->next = r;
		tail = r;
	}
	Node* n = head;
	std::cout << "削除前:";
	while (n != nullptr)//削除前状態を出力
	{
		std::cout << n->data << "-> ";
		n = n->next;
	}
	std::cout << "\nhead=" << head->data << " tail=" << tail->data << "\n";
	n = head;
	while (n != nullptr)//ある数字を探索し，-2を削除する関数
	{
		if (n->data == -2)
		{
			delete_(n, head, tail);
			n = head;
		}
		n = n->next;
	}
	n = head;
	std::cout << "削除後:";
	while (n != nullptr)
	{
		std::cout << n->data << "-> ";
		n = n->next;
	}
	std::cout << "\nhead=" << head->data << " tail=" << tail->data << "\n";
}
void doubly() {//双方向連結リストを表す
	DoublyNode* head = nullptr;
	DoublyNode* tail = nullptr;
	int array_[]{ 2,1,0,-1,-2 };
	for (int& i : array_)//先頭にinsert
	{
		if (tail == nullptr || head == nullptr)//単に(tail == nullptr)を判断しても大丈夫
		{
			DoublyNode* r = new DoublyNode(nullptr, i, nullptr);
			head = tail = r;
		}
		else
		{
			DoublyNode* r = new DoublyNode(nullptr, i, head);
			head->pre = r;
			head = r;
		}
	}
	for (int& i : array_)//後ろににinsert
	{
		DoublyNode* r = new DoublyNode(tail, i, nullptr);
		tail->next = r;
		tail = r;
	}
	DoublyNode* n = head;
	std::cout << "削除前:";
	while (n != nullptr)//削除前状態を出力
	{
		std::cout << "<- " << n->data << " -> ";
		n = n->next;
	}
	std::cout << "\nhead=" << head->data << " tail=" << tail->data << "\n";
	n = head;
	while (n != nullptr)//ある数字を探索し，-2を削除する関数
	{
		if (n->data == -2)
		{
			delete_(n, head, tail);
			n = head;
		}
		n = n->next;
	}
	n = head;
	std::cout << "削除後:";
	while (n != nullptr)
	{
		std::cout << "<- " << n->data << " -> ";
		n = n->next;
	}
	std::cout << "\nhead=" << head->data << " tail=" << tail->data << "\n";
}
int main()
{
	headAndTail();
	doubly();
	return 0;
}
/*////////////実行結果/////////////////
削除前:-2-> -1-> 0-> 1-> 2-> 2-> 1-> 0-> -1-> -2->
head=-2 tail=-2
削除後:-1-> 0-> 1-> 2-> 2-> 1-> 0-> -1->
head=-1 tail=-1
削除前:<- -2 -> <- -1 -> <- 0 -> <- 1 -> <- 2 -> <- 2 -> <- 1 -> <- 0 -> <- -1 -> <- -2 ->
head=-2 tail=-2
削除後:<- -1 -> <- 0 -> <- 1 -> <- 2 -> <- 2 -> <- 1 -> <- 0 -> <- -1 ->
head=-1 tail=-1
*//////////////////////////////////////