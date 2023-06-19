#include <iostream>
using namespace std;
#define MAX 100
int sp;
int a[MAX];
void init(int a[], int& sp) {
	sp = -1;
}
void output(int a[], int sp) {
	for (int i = 0; i <= sp; i++) {
		cout << a[i] << " ";
	}
}
int isFull(int a[], int sp) {
	if (sp == MAX - 1) {
		return 1;
	}
	return 0;
}
int isEmpty(int a[], int sp) {
	if (sp == -1) {
		return 1;
	}
	return 0;
}
int push(int a[], int& sp, int x) {
	if (sp < MAX - 1) {
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int pop(int a[], int& sp, int& x) {
	if (sp != -1) {
		x = a[sp--];
		return 1;
	}
	return 0;
}
void ThapSangNhi(int a[], int& sp, int x) {
	int du, thuong, y;
	thuong = x;
	while (thuong != 0) {
		du = thuong % 2;
		thuong = thuong / 2;
		push(a, sp, du);
	}
	cout << "He nhi phan cua " << x << " la:";
	while (!isEmpty(a, sp)) {
		pop(a, sp, y);
		cout << y;
	}
	cout << endl;

}
int main() {
	int x, t, chon;
	init(a, sp);
	while (true) {
		cout << "1. Them 1 phan tu vao stack\n";
		cout << "2. Lay phan tu ra khoi stack\n";
		cout << "3. Kiem tra ngan xep rong \n";
		cout << "4. Kiem tra ngan xep day \n";
		cout << "6. Thap phan sang nhi phan \n";
		cout << "5. Thoat \n";
		cout << "Moi ban chon:";
		cin >> chon;
		switch (chon) {
		case 1:
			cout << "Nhap phan tu can them vao:";
			cin >> x;
			t = push(a, sp, x);
			if (t == 1) {
				cout << "Them thanh cong! \n";
				output(a, sp);
				cout << endl;
			}
			else {
				cout << "Them that bai vi ngan xep da day";
			}
			break;
		case 2:
			t = pop(a, sp, x);
			if (t == 1) {
				cout << "Xoa thanh cong, Phan tu duoc lay ra co gia tri la:" << x << "\n";
			}
			else {
				cout << "Lay phan tu that bai vi ngan xep rong";
			}
			break;
		case 3:
			if (isEmpty(a, sp) == 1) {
				cout << "Ngan xep rong \n";
			}
			else {
				cout << "Ngan xep khong rong \n";
			}
			break;
		case 4:
			if (isFull(a, sp) == 1) {
				cout << "Ngan xep day \n";
			}
			else {
				cout << "Ngan xep khong day \n";
			}
			break;
		case 6:
			int b[MAX], sb, o;
			init(b, sb);
			cout << "Nhap so thap phan:";
			cin >> o;
			ThapSangNhi(b, sb, o);
			break;
		case 5:
			return 0;
		}




	}
}
