#include <iostream>
using namespace std;
#define MAX 100
int a[MAX];
int front, rear;
void init(int a[],int &front,int &rear) {
	front = -1;
	rear = -1;
}
int isEmpty() {
	if (front == -1&&rear==-1) {
		return 1;
	}
	return 0;
}
int isFull() {
	if (rear - front == MAX - 1) {
		return 1;
	}
	return 0;
}
int push(int a[], int& front, int& rear, int x) {
	if (rear - front == MAX - 1) {
		return 0;//Hang doi day
	}
	else {
		if (front == -1) {
			front = 0;//Chua co phan tu
		}
		if (rear == MAX - 1) {//Hang doi tran
			for (int i = front;i <= rear;i++)
				a[i - front] = a[i];
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
}
int pop(int a[], int& front, int& rear, int& x) {
	if (front == -1) {
		return 0;
	}
	else {
		x = a[front++];
		if (front > rear) {
			front = -1;
			rear = -1;
		}
		return 1;
	}
}
void reverse_using_queue(int x) {
	init(a,front,rear);
	int du, y;
	while (x > 0) {
		du = x % 10;
		x = x / 10;
		push(a, front, rear, du);
	}
	cout << "So sau khi dao nguoc:";
	while (!isEmpty()) {
		pop(a, front, rear, y);
		cout << y;
	}
	cout << endl;
}
int main2() {
	int x, t, chon;
	init(a, front, rear);
	while (true) {
		cout << "0. Thoat \n";
		cout << "1. Them phan tu vao queue \n";
		cout << "2. Lay phan tu ra khoi queue \n";
		cout << "3. Kiem tra rong \n";
		cout << "4. Kiem tra day \n";
		cout << "5. Dao nguoc so \n";
		cout << " Moi chon:";
		cin >> chon;
		switch (chon)
		{
		case 0:
			return 0;
		case 1:
			cout << "Nhap gia tri phan tu muon them:";
			cin >> x;
			t = push(a, front, rear, x);
			if (t == 1)
				cout << "Them thanh cong! \n";
			else
				cout << "Hang doi day! \n";
			break;
		case 2:
			t = pop(a, front, rear, x);
			if (t == 1)
				cout << "Gia tri cua phan tu vua lay ra la :"<<x<<endl;
			else
				cout << "Hang doi rong! \n";
			break;
		case 3:
			t = isEmpty();
			if (t == 1) {
				cout << "Hang doi rong \n";
			}
			else
				cout << "Hang doi khong rong \n";
			break;
		case 4:
			t = isFull();
			if (t == 1) {
				cout << "Hang doi day \n";
			}
			else
				cout << "Hang doi khong day \n";
			break;
		case 5:
			cout << "xin moi nhap 1 so nguyen de dao nguoc:";
			cin >> x;
			reverse_using_queue(x);
			break;
		default:
			cout << "Gia tri khong hop le \n";
			break;
		}
	}
}