#pragma once
#include "DauSach.h"

struct MuonTra
{
	string MASACH;
	NGAY_THANG ngaymuon;
	NGAY_THANG ngaytra;
	uint trangthai = 0;

	// them vao... khong co trong yeu cau
};

typedef struct MuonTra MUON_TRA;

struct NodeMuonTra
{
	MUON_TRA data;
	// struct NodeMuonTra *pNext;
	// struct NodeMuonTra *left;
	struct NodeMuonTra *right;
};

typedef struct NodeMuonTra *NODE_MT;

struct ListMT
{
	// so phan tu
	int n;
	NODE_MT pHead;
	NODE_MT pTail;
};

typedef struct ListMT LIST_MT;

// ..... khoi tao........
void initList_MT(LIST_MT &l);

// kiem tra rong
bool ListMTIsEmpty(LIST_DMS l);

// get node
NODE_MT GetNode_MT(MUON_TRA DATA);

void AddHeadList_MT(LIST_MT &l, MUON_TRA data);

void AddTailList_MT(LIST_MT &l, MUON_TRA data);

// thieu cai them sau nua

void ClearAll_ListMT(LIST_MT &l);

bool SearchTenSach_MT(LIST_MT lMT, string tensach);

int SoSachDangMuon(LIST_MT lMT);

// ham kiem tra doc gia co lam mat sach hay khong? .Co thi tra lai 1, khong thi tra lai 0.
int MatSach(LIST_MT lMT);

int SoNgayMuon_Max(LIST_MT lMT);

int SoNgayQuaHan(LIST_MT lMT);

void Output_MT(NODE_MT  p, int i);

void XoaDisplay_MT(int i);

void OutputList_MT(LIST_MT lMT);

void EffectiveMenu_MT(LIST_MT lMT, int pos, int flag);

int chonItem_MT(LIST_MT lMT);


void initList_MT(LIST_MT &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
	l.n = 0;
}

bool ListMTIsEmpty(LIST_DMS l)
{
	return l.pHead == NULL;
}

NODE_MT GetNode_MT(MUON_TRA DATA)
{
	NODE_MT p = new NodeMuonTra;
	if (p == NULL) {
		return NULL;
	}

	p->data = DATA;
	// p->left = NULL;
	p->right = NULL;

	return (p);
}

void AddHeadList_MT(LIST_MT &l, MUON_TRA data)
{
	// tao Node
	NODE_MT p = GetNode_MT(data);
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	} else {
		// l.pHead->left = p;
		p->right = l.pHead;
		l.pHead = p;
	}

	l.n++;
}

void AddTailList_MT(LIST_MT &l, MUON_TRA data)
{
	// tao Node
	NODE_MT p = GetNode_MT(data);
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	} else {
		l.pTail->right = p;
		// p->left = l.pTail;
		l.pTail = p;
	}

	l.n++;
}

void ClearAll_ListMT(LIST_MT &l)
{
	NODE_MT p;

	while (l.pHead != NULL)
	{
		p = l.pHead;
		// l.pHead = l.pHead->left;
		l.pHead = l.pHead->right;

		delete p;
	}
}

bool SearchISBN_MT(LIST_MT lMT, string isbn)
{
	NODE_MT point = lMT.pHead;
	bool status = false;

	while (point != NULL) {
		bool condition1 = ((point->data.MASACH).substr(0,6) == isbn && point->data.trangthai == 0);
		bool condition2 = ((point->data.MASACH).substr(0,6) == isbn && point->data.trangthai == 2);
		if (condition1 || condition2) {
			status = true;

			break;
		}

		point = point->right;
	}

	return status;
}

int SoSachDangMuon(LIST_MT lMT)
{
	int i = 0;

	for (NODE_MT p = lMT.pHead; p != NULL; p = p->right)
	{
		if (p->data.trangthai == 0 || p->data.trangthai == 2) {
			i++;
		}
	}

	return i;
}

// ham kiem tra doc gia co lam mat sach hay khong? .Co thi tra lai 1, khong thi tra lai 0.
int MatSach(LIST_MT lMT)
{
	NODE_MT p = lMT.pHead;
	bool status = 0;

	while (p != NULL) {
		if (p->data.trangthai == 2) {
			status = 1;

			break;
		}
		p = p->right;
	}

	return status;
}

int SoNgayMuon_Max(LIST_MT lMT)
{
	NGAY_THANG ngayht;
	LayNgayGioHT(ngayht);
	int max = 0;
	int nngay;

	NODE_MT p = lMT.pHead;

	while (p != NULL) {
		if ((p->data.trangthai == 0) || (p->data.trangthai == 2)) {
			nngay = tinhKhoangCachNgay(p->data.ngaymuon, ngayht);
			if (max < nngay) {
				max = nngay;
			}
		}

		p = p->right;
	}

	return max;
}

int SoNgayQuaHan(LIST_MT lMT)
{
	int nNgayMuonMax = SoNgayMuon_Max(lMT);

	return nNgayMuonMax - 7;
}

void LayTenSachVaViTriSach(LIST_DAUSACH lDS, string masach,string &tensach,string &vitri)
{
	string maISBN = masach.substr(0,6);

	pDAU_SACH pdausach = SearchTen_TSBN(lDS, maISBN);
	tensach = pdausach->info.tensach;

	NODE_DMS*  pdms =  Search_DMS1(pdausach, masach);
	vitri = pdms->data.viTri;
}
void Output_MT(NODE_MT  p, int i, LIST_DAUSACH &lDS)
{
	string tensach = "";
	string vitri = "";

	LayTenSachVaViTriSach(lDS, p->data.MASACH, tensach, vitri);

	gotoxy(XDisplayMT[0] + 2, 21 + i);

	cout << tensach;
	gotoxy(XDisplayMT[1] + 1, 21 + i);
	cout << p->data.MASACH;

	xuatNgayThang(p->data.ngaymuon, XDisplayMT[2] + 1, 21 + i);


	gotoxy(XDisplayMT[3] + 8, 21 + i);
	cout << KhoangCachNgay(p->data.ngaymuon);
	gotoxy(XDisplayMT[4] + 2, 21 + i);

	cout << vitri;

	gotoxy(XDisplayMT[5] + 6, 21 + i);
	if (p->data.trangthai == 2)
		cout << " Lam Mat Sach";
	else if (KhoangCachNgay(p->data.ngaymuon) > 7)
		cout << " M. Qua 7 ngay";
	else if (p->data.trangthai == 0)
		cout << " Dang Muon";
	else if (p->data.trangthai == 1)
		cout << " Da Tra";
}

void XoaDisplay_MT(int i)
{
	gotoxy(XDisplayMT[0] + 1, 21 + i);
	cout << setw(XDisplayMT[1] - XDisplayMT[0] - 1) << setfill(' ') << " ";
	gotoxy(XDisplayMT[1] + 1, 21 + i);
	cout << setw(XDisplayMT[2] - XDisplayMT[1] - 1) << setfill(' ') << " ";
	gotoxy(XDisplayMT[2] + 1, 21 + i);
	cout << setw(XDisplayMT[3] - XDisplayMT[2] - 1) << setfill(' ') << " ";
	gotoxy(XDisplayMT[3] + 1, 21 + i);
	cout << setw(XDisplayMT[4] - XDisplayMT[3] - 1) << setfill(' ') << " ";
	gotoxy(XDisplayMT[4] + 1, 21 + i);
	cout << setw(XDisplayMT[5] - XDisplayMT[4] - 1) << setfill(' ') << " ";
	gotoxy(XDisplayMT[5] + 1, 21 + i);
	cout << setw(XDisplayMT[6] - XDisplayMT[5] - 1) << setfill(' ') << " ";
	gotoxy(XDisplayMT[6] + 1, 21 + i);
	cout << setw(XDisplayMT[7] - XDisplayMT[6] - 1) << setfill(' ') << " ";
}

void OutputList_MT(LIST_MT lMT, LIST_DAUSACH &lDS)
{
	int i = 0;

	// xoa display dau sach
	for (int j = 0; j < 3; j++)
	{
		XoaDisplay_MT(j);
	}

	// thuc hien ouput

	NODE_MT p = lMT.pHead;

	while (p != NULL) {
		if (p->data.trangthai == 0 || p->data.trangthai == 2) {
			Output_MT(p, i, lDS);
			i++;
		}

		p = p->right;
	}
}

void EffectiveMenu_MT(LIST_MT lMT, int pos, int flag, LIST_DAUSACH &lDS)
{
	int i = 0;
	ShowCur(false);

	// get so sach dang muon trong danh sach.
	int n = SoSachDangMuon(lMT);

	// 0 --> 2;  2---> 1;  1---> 0

	NODE_MT p = lMT.pHead;

	if (flag != 1 && flag != 2) {
		return;
	}

	while (p != NULL) {
		if (p->data.trangthai == 0 || p->data.trangthai == 2) {
			if (i == pos) {
				SetBGColor(GREEN);
				SetColor(BLACK);
				Output_MT(p, i, lDS);
				normalBGColor();
			}

			bool condition1 = flag == 1 && i == (pos + n - 1) % n;
			bool condition2 = flag == 2 && i == (pos + 1) % n;

			if (flag == 1 && i == (pos + n - 1) % n)

			if (condition1 || condition2) {

				SetColor(WHITE);
				Output_MT(p, i, lDS);
			}
			i++;
		}

		p = p->right;
	}
}

int chonItem_MT(LIST_MT lMT, LIST_DAUSACH &lDS)
{
	int currpos = 0;
	ShowCur(false);

	// get so sach dang muon trong danh sach.
	int n = SoSachDangMuon(lMT);

	if (n == 0)
		return -1;

	// high light muc dau.
	int i = 0;

	NODE_MT p = lMT.pHead;

	while (p != NULL) {
		if (p->data.trangthai == 0 || p->data.trangthai == 2) {
			if (i == 0) {
				SetBGColor(GREEN);
				SetColor(BLACK);
				Output_MT(p, i, lDS);
				normalBGColor();
				i++;

				break;
			}
		}

		p = p->right;
	}

	// xu ly.
	int kb_hit;

	while (true) {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0) {
				kb_hit = _getch();
			}

			switch (kb_hit) {
				case KEY_UP:
					if (currpos > 0) {
						currpos = currpos - 1;
					} else {

						currpos = n - 1;  // vi tri hien tai bang so so sach muon.
					}

					EffectiveMenu_MT(lMT, currpos, 2, lDS);
					break;

				case KEY_DOWN:
					if (currpos <  n - 1) {
						currpos = currpos + 1;
					} else {
						currpos = 0;
					}

					EffectiveMenu_MT(lMT, currpos, 1, lDS);
					break;

				case ENTER: //enter
					Beep(600, 100);
					return currpos;
			}
		}
	}
}
