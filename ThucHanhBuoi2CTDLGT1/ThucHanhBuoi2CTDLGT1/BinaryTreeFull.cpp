#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;
void tree_empty() {
	root = NULL;
}
Node *SearchNode(Node *p, int x) {
	if (p != NULL) {
		if (p->info == x)
			return p;
		else if (p->info < x)
			return SearchNode(p->right, x);
		else
			return SearchNode(p->left, x);
	}
	return NULL;
}
void Insert_node(Node *&p, int x) {
	if (p == NULL) {
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else if (p->info == x) {
		return;
	}
	else {
		if (p->info > x)
			Insert_node(p->left, x);
		else
			Insert_node(p->right, x);
	}	
}
void searchStandFor(Node *&p, Node *&q) {
	if (q->left == NULL) {
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		return searchStandFor(p, q->left);
}
int DeleteNode(Node *&T, int x) {
	if (T == NULL)
		return 0;
	if (T->info == x) {
		Node *p = T;
		if (T->left == NULL)
			T = T->right;
		else if (T->right == NULL)
			T = T->left;
		else //have 2 childs
			searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)
		return DeleteNode(T->right, x);
	if (T->info > x)
		return DeleteNode(T->left, x);
}
void DuyetLNR(Node *p) {
	if (p != NULL) {
		DuyetLNR(p->left);
		cout << p->info << " ";
		DuyetLNR(p->right);
	}
}
void DuyetNLR(Node *p) {
	if (p != NULL) {
		cout << p->info<<" ";
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}
void DuyetLRN(Node *p) {
	if (p != NULL) {
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout << p->info << " ";
	}
}
int CountNode(Node *p)
{
	if (p == NULL)
		return 0;
	else
		return CountNode(p->left) + CountNode(p->right) + 1;
}
int TinhTong(Node *p)
{
	if (p == NULL)
		return 0;
	else
		return TinhTong(p->left) + TinhTong(p->right) + p->info;
}
int TrungBinhCong(Node *p) {
	if (p == NULL)
		return 0;
	else
		return TinhTong(p)/CountNode(p);
}
int findMax(Node *p) {
	if (p != NULL) {
		if (p->right == NULL) {
			return p->info;
		}
		else
			return findMax(p->right);
	}
}
int checkSNT(int x) {
	int dem = 0;
	for (int i = 1; i <= x; i++) {
		if (x%i == 0)
			dem++;
	}
	if (dem == 2)
		return 1;
	else
		return 0;
}
int CountNodeSNT(Node *p,int &dem)
{
	if (p != NULL)
	{
		if (checkSNT(p->info) == 1) {
			dem++;
		}
		CountNodeSNT(p->left,dem);
		CountNodeSNT(p->right,dem);
	}
	return dem;
	
}
int sumOfOneChildNodesv3(Node* p, int& tong) {
	if (p != NULL)
	{
		if ((p->left == NULL || p->right == NULL) && !(p->left == NULL && p->right == NULL)) {
			tong+=p->info;
		}
		sumOfOneChildNodesv3(p->left, tong);
		sumOfOneChildNodesv3(p->right, tong);
	}
	return tong;
}
int sumOfOneChildNodes(Node* p) {
	if (p == NULL)
		return 0;


	else if (!(p->left!=NULL&&p->right!=NULL) && (p->left == NULL || p->right == NULL)) {
		return sumOfOneChildNodes(p->left) + sumOfOneChildNodes(p->right)+p->info;
	}
	else {
		return sumOfOneChildNodes(p->left) + sumOfOneChildNodes(p->right);
	}

}
int sumOfOneChildNodesv2(Node* p) {
	if (p == NULL)
		return 0;

	int sum = 0;

	if ((p->left == NULL || p->right == NULL)&&!(p->left == NULL && p->right == NULL)) {
		sum += p->info;
	}

	sum += sumOfOneChildNodes(p->left) + sumOfOneChildNodes(p->right);

	return sum;
}
int main() {
	int x, t,chon,dem=0,tong=0;
	Node *tmp;
	tree_empty();
	while (true)
	{
		dem = tong = 0;
		cout << "\nXin moi chon \n";
		cout << "0.Thoat chuong trinh \n";
		cout << "1.Them \n";
		cout << "2.Tim kiem \n";
		cout << "3.Duyet LNR \n";
		cout << "4.Duyet NLR \n";
		cout << "5.Duyet LRN \n";
		cout << "6.Xoa \n";
		cout << "7. Dem so Node \n";
		cout << "8. Trung binh cong gia tri \n";
		cout << "9. Gia tri lon nhat \n";
		cout << "10. Dem so nguyen to trong cay \n";
		cout << "11. Sum of one child \n";
		cout << "Xin moi chon:";
		cin >> chon;
		switch (chon)
		{
		case 0:
			return 1;
			break;
		case 1:
			cout << "Nhap gia tri ban muon them:";
			cin >> x;
			Insert_node(root, x);
			break;
		case 2:
			cout << "Nhap gia tri ban muon tim kiem:";
			cin >> x;
			tmp = SearchNode(root, x);
			if (tmp != NULL)
				cout << "Node mang gia tri " << x << " co trong cay \n";
			else
				cout << "Khong tim thay! \n";
			break;
		case 3:
			cout << "Cay duyet theo LNR: \n";
			DuyetLNR(root);
			cout << endl;
			break;
		case 4:
			cout << "Cay duyet theo NLR: \n";
			DuyetNLR(root);
			cout << endl;
			break;
		case 5:
			cout << "Cay duyet theo LRN: \n";
			DuyetLRN(root);
			cout << endl;
			break;
		case 6:
			cout << "Nhap gia tri can xoa:";
			cin >> x;
			t = DeleteNode(root, x);
			if (t == 1)
				cout << "Xoa thanh cong gia tri " << x << endl;
			else
				cout << "Khong tim thay gia tri" << x << endl;
			break;
		case 7:
			t = CountNode(root);
			cout << "So node trong cay la: " << t << endl;;
			break;
		case 8:
			t = TrungBinhCong(root);
			cout << "Trung binh cong cac gia tri trong cay la: " << t << endl;;
			break;
		case 9:
			t = findMax(root);
			cout << "Gia tri lon nhat trong cay la: " << t << endl;;
			break;
		case 10:
			t = CountNodeSNT(root,dem);
			cout << "So node la so nguyen to trong cay la: " << t << endl;
			break;
		case 11:
			t = sumOfOneChildNodesv3(root,tong);
			cout << "Sum cua Node con la: " << t << endl;
			break;
		default:
			cout << "Gia tri khong hop le!\n";
			break;
		}
	}
	return 0;
}