#include <iostream>

using namespace std;


bool isPrime(int n) {
	if (n <= 1)
		return false;

	for (int i = 2; i <= n/2; i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}


class Node {
	public:
		int data;
		Node* link;

		Node(int d = -1, Node* l = 0) {
			data = d;
			link = l;
		}
};


class LinkList {
	public:
		Node* first;
		Node* last;
		LinkList() {
			first = new Node();
			first->link = first;
			last = first;
		}

		Node* addNode(int data) {
			Node* node = new Node(data);
			last->link = node;
			node->link = first;
			last = node;
			return node;
		}

		void deletePrimes() {
			Node* p = first->link;
			Node* q = first;

			while (p != first) {
				if (isPrime(p->data))
					q->link = p->link;
				else
					q = p;

				p = p->link;
			}

			last = q; // node qabl az first
		}

		void print() {
			Node* p = first->link;
			cout << "< ";
			while (p != first) {
				cout << p->data << " ";
				p = p->link;
			}
			cout << ">" << endl;
		}

		bool isEmpty() {
			if (first->link == first)
				return true;
			else 
				return false;
		}

		static LinkList merge(LinkList a, LinkList b) {
			LinkList c;

			Node* p = a.first->link;
			Node* q = b.first->link;
			Node* last = c.first;

			while (p != a.first && q != b.first) {
				if (p->data <= q->data) {
					last->link = p;
					last = p;
					p = p->link;
				} else {
					last->link = q;
					last = q;
					q = q->link;
				}
			}

			if (p != a.first) { // vojud dasht
				last->link = p;
				a.last->link = c.first; // halqavi kardan
			} else if (q != b.first) { // vojud dasht
				last->link = q;
				b.last->link = c.first; // halqavi kardan
			}

			return c;
		}
};


class Stack {
	private:
		LinkList list;
	public:
		void push(int x) {
			list.addNode(x);
		}

		int pop() {
			if (list.isEmpty()) {
				cout << "Stack is empty" << endl;
				return -1;
			} else {
				Node* first = list.first;
				Node* p = first->link;
				Node* q = first;
				
				while (p->link != first)
				{
					q = p;
					p = p->link;
				}
				
				q->link = p->link;
				return p->data;
			}
		}

		void print() {
			list.print();
		}
};

class Queue {
	private:
		LinkList list;
	public:
		void Add(int x) {
			list.addNode(x);
		}

		int Delete() {
			if (list.isEmpty()) {
				cout << "Queue is empty" << endl;
				return -1;
			}
			
			Node* front = list.first->link;
			list.first->link = front->link;
			return front->data;
		}

		void print() {
			list.print();
		}
};



int main() {
	cout << "<<< Primes >>>" << endl;
	LinkList l;
	for (int i = 0; i < 15; i++)
		l.addNode(i);

	cout << "List:";
	l.print();
	l.deletePrimes();
	cout << "Without Primes: ";
	l.print();


	
	cout << endl << "<<< Merge >>>" << endl;
	LinkList a;
	LinkList b;
	for (int i = 0; i < 27; i+= 2)
		a.addNode(i);

	for (int i = 1; i < 20; i+= 2)
		b.addNode(i);

	cout << "A => ";
	a.print();
	cout << "B => ";
	b.print();
	LinkList c = LinkList::merge(a, b);
	cout << "Merged => ";
	c.print();
	


	
	cout << endl << "<<< Stack >>>" << endl;
	Stack s;
	for (int i = 1; i <= 5; i++)
		s.push(i);
	for (int i = 0; i < 5; i++)
		cout << s.pop() << endl;
	

	
	cout << endl << "<<< Queue >>>" << endl;
	Queue q;
	for (int i = 1; i <= 10; i++)
		q.Add(i);
	for (int i = 0; i < 10; i++)
		cout << q.Delete() << endl;
	

	return 0;
}
