#include <iostream>
using namespace std;
struct Stack {
	int info;
	Stack* link;
};
Stack* sp;
void init() {
	sp = NULL;
}
void processlist() {
	Stack *p = sp;
	while (p->info != NULL){
		cout << p->info<<" ";
		p=p->link;
 }
	cout << endl;
}
void Push(int x) {
	Stack* p = new Stack;
	p->info = x;
	p->link = sp;
	sp = p;
}
int pop(int& x) {
	if (sp != NULL) {
		Stack* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
int isEmpty() {
	if (sp == NULL) {
		return 1;
	}
	return 0;
}
void ThapSangNhi(int x) {
	int du, thuong, y,dem=0;
	Stack* nhi = new Stack;
	init();
	thuong = x;
	while (thuong != 0) {
		du = thuong % 2;
		thuong = thuong / 2;
		Push(du);
		dem++;
	}
	cout << "He nhi phan cua " << x << " la:";
	while (dem!=0) {
		pop(y);
		cout << y;
		dem--;
	}
	cout << endl;
}
int main1() {
	int x, t, chon,u;
	init();
	while (true) {
		cout << "1. Them phan tu vao stack \n";
		cout << "2. Lay phan tu ra khoi stack \n";
		cout << "3. Chuyen doi he thap phan sang nhi phan \n";
		cout << "4. Kiem tra Stack rong \n";
		cout << "5.Thoat \n";
		cout << "Chon:";
		cin >> chon;
		switch (chon)
		{
		case 4:
			t = isEmpty();
			if (t == 1) {
				cout << "Stack rong \n";
			}
			else
			{
				cout << "Stack khong rong \n";
			}
			break;
		case 5:
			return 0;
		case 1:
			cout << "Nhap phan tu can them:";
			cin >> x;
			Push(x);
			/*processlist();*/
			break;
		case 2:
			pop(x);
			cout << "Phan tu lay ra duoc la: " << x << endl;
			break;
		case 3:
			cout << "Nhap 1 so he thap phan:";
			cin >> u;
			ThapSangNhi(u);
			break;
		
		}
	}
}