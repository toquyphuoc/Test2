#include <iostream>
using namespace std;
struct Node {
	int info;
	Node* link;
};
Node* front, * rear;
void init() {
	front = NULL;
	rear = NULL;
}
int isEmpty() {
	if (front == NULL) {
		return 1;
	}
	
	return 0;
	
}
void push(int x) {
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (front == NULL)
		front = p;
	else
		rear->link=p;
	rear = p;
}
int pop(int& x) {
	if (!isEmpty()) {
		Node* p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
			rear == NULL;
		delete p;
		return 1;
	}
	return 0;
}
int main3() {
	int x, t, chon;
	init();
	while (true) {
		cout << "0.Thoat \n";
		cout << "1. Them phan tu vao queue \n";
		cout << "2. Lay phan tu ra khoi queue \n";
		cout << "3. Kiem tra queue co rong khong? \n";
		cout << "Chon:";
		cin >> chon;
		switch (chon) {
		case 0:
			return 0;
		case 1:
			cout << "Nhap gia tri muon them:";
			cin >> x;
			push(x);
			break;
		case 2:
			t = pop(x);
			if (t != 0) {
				cout << "Phan tu duoc lay ra co gia tri la: " << x << endl;
			}
			else {
				cout << "Hang doi rong \n";
			}
			break;
		case 3:
			t = isEmpty();
			if (t != 0) {
				cout << "Hang doi rong \n";
			}
			else {
				cout << "Hang doi khong rong \n";
			}
			break;
		}
	}
}
