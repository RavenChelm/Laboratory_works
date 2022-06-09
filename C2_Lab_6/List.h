#pragma once
template <typename Q> class List;
template <typename T> class Node;
using namespace std;
template < typename T > class Node
{
	T field;
	class Node* ptr;
	friend class List<T>;
};
template < typename Q > class List
{
private:
	Node<Q>* head;    // ������ ������
	int count = 0; // ���������� ����� ������
	//������� � ���������� ����
	Node<Q>* Next(Node<Q>* node)
	{
		if (isEmpty()) return NULL;
		return node->ptr;
	}
	//������� � ����������� ����
	Node<Q>* Prev(Node<Q>* node)
	{
		if (isEmpty()) return NULL;
		if (node == head) return NULL;
		Node<Q>* p = head;
		while (p->ptr != node)
			p = p->ptr;
		return p;
	}
	//��������� ����������� ������ ����
	int getNumber(Node<Q>* number) {
		Node<Q>* p = head;
		int countNumber = 0;
		while (p != number) {
			p = Next(p);
			countNumber++;
		}
		return countNumber++;;
	}
	Node<Q>* getNode(int node) {
		Node<Q>* p = head;
		for (int i = 0; i != node; i++) {
			p = Next(p);
		}
		return p;
	}
public:
	List() { head = NULL; } //���������� ������ ����
	int getCount() { return count; }  //��������� ����� ������
	bool isEmpty() { return head == NULL; }  //��������, ���� �� ������
	void setValue(Node<Q>* p, Q val) { p->field = val; } //��������� �������� ����
	Q getFirst() { return head->field; } //��������� ������� ���� 
	//���������  �������� ���� �� �������� �������
	Q getvalue(int node) {
		Node<Q>* p = head;
		for (int i = 0; i != node; i++) {
			p = Next(p);
		}
		return p->field;
	}
	//��������� �������� ���������� ����
	Q getLast()
	{
		Node<Q>* p = head;
		int q = getNumber(p);
		while ((Next(p) != NULL))
			p = Next(p);
		return p->field;
	}
	//�������� ������
	void Clear()
	{
		class Node<Q>* p = head;
		if (p == NULL) return;
		do {
			Node<Q>* d = p;
			p = Next(p);
			delete d;
		} while (p != NULL);
		count = 0;
		head = NULL;
	}
	//���������� ���� � ������. ��� ������� ��������� ������ ����� ����������� � ������. ����� ����� ����������� ����� ���������. 
	int Add(Q num, int q = 0)
	{
		Node<Q>* node = getNode(q);
		node = Prev(node);
		Node<Q>* elem = new Node<Q>();
		elem->field = num;
		count++;
		if (node == NULL) // ���������� ������ �����
		{
			if (head == NULL) {
				elem->ptr = NULL;
				head = elem;
			}
			else {
				elem->ptr = head;
				head = elem;
			}
			return q++;
		}
		elem->ptr = node->ptr; // ���������� ���� ����� ��������
		node->ptr = elem;
		return q++;
	}
	//�������� ���� �� ������
	int Delete(int p)
	{
		Node<Q> node = getNode(p);
		if (node == NULL) { return NULL; } // � ������ ��� �����
		count--;
		if (node == head)  // �������� ��������� ����
		{
			head = node->ptr;
			delete node;
			return head;
		}
		Node* prev = Prev(node); // �������� �������������� ����
		prev->ptr = node->ptr;
		delete node;
	}
	//����� ����� �������
	void Swap(int p, int q)
	{
		Node<Q>* node2 = getNode(p);
		Node<Q>* node1 = getNode(q);
		if (node1 == NULL || node2 == NULL) return; // �� ��������� ����� � �������������� �����
		if (node1 == node2) return; // ���� ���� ���� ������ ������, ������ ������ �� ����
		Node<Q>* prev1 = Prev(node1);
		Node<Q>* prev2 = Prev(node2);
		Node<Q>* next1 = Next(node1);
		Node<Q>* next2 = Next(node2);
		if (next1 == node2) // ����� �������� �����
		{
			if (prev1 != NULL)
				prev1->ptr = node2;
			else
				head = node2;
			node2->ptr = node1;
			node1->ptr = next2;
			return;
		}
		if (prev1 != NULL)  // ����� ������ �����
			prev1->ptr = node2;
		else
			head = node2;
		if (prev2 != NULL)
			prev2->ptr = node1;
		else
			head = node1;
		node2->ptr = next1;
		node1->ptr = next2;
	}
	//�����
	void Print()
	{
		if (isEmpty()) { cout << "������ ����" << endl; return; }
		Node<Q>* p = head;
		do {
			cout << getvalue(getNumber(p)) << " ";
			p = Next(p);
		} while (p != NULL);
		cout << endl;
	}
};