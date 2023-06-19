#include <iostream>
#include <string>
using namespace std;
struct SinhVien {
	string MaSV;
	string HoTen;
	double Diem;
};
struct Node {
	SinhVien info;
	Node* link;
};
Node* first;
void init() {
	first = NULL;
}
Node* search(string code) {
	Node* p = first;
	while ((p != NULL) && (p->info.MaSV != code)) {
		p = p->link;
	}
	return p;


}
void process_list() {
	Node* p = first;
	while (p != NULL) {
		cout << "MSSV: " << p->info.MaSV << " ,Ho ten: " << p->info.HoTen << " ,Diem: " << p->info.Diem << endl;
		p = p->link;
	}
}
void insert_first(string code, string name, double score) {
	Node* p = new Node;
	p->info.MaSV = code;
	p->info.HoTen = name;
	p->info.Diem = score;
	p->link = first;
	first = p;
}
void insert_last(string code, string name, double score) {
	Node* p = new Node;
	p->info.MaSV = code;
	p->info.HoTen = name;
	p->info.Diem = score;
	p->link = NULL;
	if (first == NULL)
		first = p;
	else {
		Node* q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}
int delete_first() {
	if (first != NULL) {
		Node* p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
int delete_last() {
	if (first != NULL) {
		Node* p = first, * q = NULL;
		while (p->link != NULL) {
			q = p;
			p = p->link;
		}
		if (p != first)
			q->link = first;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
void InterchangeSortGiamDan() {
	for (Node* p = first;p != NULL;p = p->link)
		for (Node* q = p->link;q != NULL;q = q->link) {
			if (q->info.Diem > p->info.Diem) {
				string tmp1, tmp2;
				double tmp3;
				//swap code
				tmp1 = q->info.MaSV;
				q->info.MaSV = p->info.MaSV;
				p->info.MaSV = tmp1;
				//swap name
				tmp2 = q->info.HoTen;
				q->info.HoTen = p->info.HoTen;
				p->info.HoTen = tmp2;
				//swap score
				tmp3 = q->info.Diem;
				q->info.Diem = p->info.Diem;
				p->info.Diem = tmp3;

			}
		}
}
void SinhVienTop2() {
	InterchangeSortGiamDan();
	Node* p = first;
	p = p->link;
	cout << "Sinh vien top 2 la:" << endl;
	cout << "MSSV: " << p->info.MaSV << " ,Ho ten: " << p->info.HoTen << " ,Diem: " << p->info.Diem << endl;
}
//void SinhVienTop2v2() {
//	SinhVien* p = first;
//	SinhVien* Max = p, *MaxTop2 = NULL;
//	while (p != NULL) {
//		if (p->Diem > Max -> Diem) {
//			Max = p;
//		}
//		MaxTop2 = Max;
//		p = p->link;
//	}
//	if (Max == p) {
//
//	}
//	cout << "Sinh vien top 2 la:" << endl;
//	cout << "MSSV: " << MaxTop2->MaSV << " ,Ho ten: " << MaxTop2->HoTen << " ,Diem: " << MaxTop2->Diem << endl;
//}
int main() {
	int t, chon;
	string code, name;
	double score;
	Node* tmp;
	init();
	while (true) {
		cout << "\n Nhap chon:\n"
			<< "0. Thoat\n"
			<< "1. Xuat danh sach sinh vien\n"
			<< "2. Tim sinh vien\n"
			<< "3. Xoa Dau\n"
			<< "4. Xoa Cuoi \n"
			/*<< "5. Tim va xoa phan tu \n"*/
			<< "6. Them dau \n"
			<< "7. Them cuoi \n"
			<< "8. Sap xep thu tu giam dan\n"
			<< "9. Sinh vien dung top 2 \n"
			<< "Chon: ";
		cin >> chon;
		switch (chon) {
		case 0:
			return 1;
			break;
		case 1:
			cout << "Danh sach phan tu la:";
			process_list();
			break;
		case 2:
			cin.ignore();
			cout << "Nhap gia tri can tim trong danh sach:";
			getline(cin, code);
			tmp = search(code);
			if (tmp != NULL) {
				cout << "Gia tri co trong dslk \n";
				process_list();
			}
			else
				cout << "Gia tri khong co trong danh sach";
			break;

		case 3:
			t = delete_first();
			if (t != 0)
				cout << "Xoa thanh cong!";
			else
				cout << "Xoa that bai!";
			break;
		case 4:
			t = delete_last();
			if (t != 0)
				cout << "Xoa thanh cong!";
			else
				cout << "Xoa that bai!";
			break;
			/*case 5:
				cout << "Nhap gia tri can tim de xoa:";
				cin >> x;
				t = find_and_delete(x);
				if (t != 0)
					cout << "Xoa thanh cong!";
				else
					cout << "Xoa that bai vi khong tim thay phan tu hoac danh sach rong!";
				break;*/
		case 6:
			cin.ignore();
			cout << "Nhap ma sinh vien can them:";
			getline(cin, code);
			cout << "Nhap ho ten sinh vien can them:";
			getline(cin, name);
			cout << "Nhap diem sinh vien can them:";
			cin >> score;
			if (score >= 0 && score <= 10) {
				insert_first(code, name, score);
				cout << "Danh sach sau khi them dau:\n";
				process_list();
			}
			else
			{
				cout << "Yeu cau nhap dung diem so (tren thang diem 10)!, moi ban chon lai chuc nang ! \n";
			}
			break;
		case 7:
			cin.ignore();

			cout << "Nhap ma sinh vien can them:";
			getline(cin, code);
			cout << "Nhap ho ten sinh vien can them:";
			getline(cin, name);
			cout << "Nhap diem sinh vien can them:";
			cin >> score;
			
			if (score >= 0 && score <= 10) {
				insert_last(code, name, score);
				cout << "Danh sach sau khi them cuoi:\n";
				process_list();
			}
			else
			{
				cout << "Yeu cau nhap dung diem so (tren thang diem 10)!, moi ban chon lai chuc nang ! \n";
			}
			break;
		case 8:
			InterchangeSortGiamDan();
			cout << "Ket qua sau khi sap xep thu tu:" << endl;
			process_list();
			break;
		case 9:
			SinhVienTop2();
			break;
		default:
			cout << "gia tri khong hop le! \n";
			break;

		}
	}
	return 0;
}
