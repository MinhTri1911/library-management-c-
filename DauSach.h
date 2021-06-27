#pragma once
#include <sstream>
#include "mylib.h"
#include "Ve_Hinh.h"
#include "Check_Nhap.h"
#include "GlobalVariable.h"
#include "Marcro.h"
#include "System_Config.h"

//............................. danh muc sach................................
struct DanhMucSach
{
	string maSach;
	uint ttSach ;
	string viTri;
};

typedef struct DanhMucSach DMS;

struct NodeDMS
{
	DMS data;
	struct NodeDMS* pNext;
};

typedef struct NodeDMS NODE_DMS;

struct ListDMS
{
	int n = 0;
	NODE_DMS *pHead, *pTail;
};

typedef struct ListDMS LIST_DMS;

//....................dau sach..................................
struct dausach
{
	string tensach;
	string ISBN;
	string tacgia;
	string theloai;
	uint sotrang;
	uint namSB;
};

typedef struct dausach dauSach;

struct DauSach
{
	dauSach info;
	LIST_DMS dms;
	int soluongsachdamuon = 0;
};

typedef struct DauSach DAU_SACH;
typedef struct DauSach* pDAU_SACH;

struct ListDauSach
{
	// n + 1 = so phan tu , n = chi so index.
	int n = 0;
	// mang con tro dung cap phat dong, vung nho heap
	//pDAU_SACH *ListDS = new pDAU_SACH[MAX_DAUSACH];

	// vi so luong dau sach chi co 100 nen dung mang cap phat tinh luon, vung nho stack.
	pDAU_SACH ListDS[MAX_DAUSACH];
};
typedef struct ListDauSach LIST_DAUSACH;
// typedef struct ListDauSach* pLIST_DAUSACH;

// tao ra kieu truct TopSach de xu ly in ra 10 sach co luoc muon nhieu nhat.
struct TopSach
{
	string tensach;
	int sosachmuon;
};

//............................................protocol Dau Sach..............................................
// Phep toan Empty
int Empty_DauSach(LIST_DAUSACH  l);

//Phep toan Full:
int Full_DauSach(LIST_DAUSACH  l);

//..................... loai bo khoang trang.........................
string getString(string a);

// Them mot phan tu vao trong danh sach
int Insert_DauSach(LIST_DAUSACH &l, pDAU_SACH &pDS);

void Delete_DauSach(LIST_DAUSACH &l, int pos);

bool SearchISBN_DS(LIST_DAUSACH lDS, string ISBN);

// tim kiem thong tin dau sach the ten dau sach, co tra ve con co chi nut tim thay, khong tra v� NULL
pDAU_SACH SearchTen_DS(LIST_DAUSACH lDS, string tensach);

void swap_DS(pDAU_SACH ds1, pDAU_SACH ds2);

// .................. vi dau sach toi da 100 phan tu nen su dung selection sort ...........................
void selectionSort_DS(LIST_DAUSACH &lDS);

// ............... ham ho tro cap nhat doc gia...................................
void Update_DauSach(LIST_DAUSACH &lDS, pDAU_SACH &pDS, bool isEdited = false);

int ChooseItems_DS(LIST_DAUSACH &lDS, int &tttrang, int tongtrang);

void Xoa_OutDS_1line(int locate);

void Xoa_OutDS_29lines();

void Output_DS(dauSach ds);

void OutputDS_PerPage(LIST_DAUSACH &lDS, int index);

void Output_ListDStheoTT(LIST_DAUSACH lDS);

//..................quan ly menu dau sach.........................................
void Menu_DauSach(LIST_DAUSACH &lDS);

// ..........................protocol danh muc sach...........................................
// ..... khoi tao........
void initList_DMS(LIST_DMS& l);

// kiem tra rong
bool ListDMSIsEmpty(LIST_DMS l);

// get node
NODE_DMS* GetNode_DMS(DMS DATA);

void AddTailList_DMS(LIST_DMS &l, DMS data);

// xac dinh vi tri cua nut co gia tri ma sach bang keySearch trong danh sach lien ket
int position(NODE_DMS *First, string keySearch);

// xac dinh con tro cua nut thu i trong danh sach lien ket
NODE_DMS * nodepointer(NODE_DMS *First, int i);

// Phep toan Delete_first: xoa nut o dau danh sach lien ket
void Delete_first(NODE_DMS *&First);

// xoa nut sau nut p
void Delete_after(NODE_DMS *p);

// xoa 1 node bat ky trong danh sach lien ket.
int Delete_batky(pDAU_SACH &pDS, string keySearch);

// ham kiem tra sach co ai muon hay chua, co thi tra ve true, ko th� false.
bool Check_DMS(NODE_DMS* nDMS);

// tim kiem theo pp tim kiem tuyen tinh, ko thay tra ve NULL, neu thay tra ve con co chi nut tim thay
NODE_DMS*   Search_DMS1(pDAU_SACH pDS, string masach);

NODE_DMS*  Search_DMS2(NODE_DMS* dms, int pos);

int NhapSach(pDAU_SACH &pDS);

int SuaDanhMucSach(pDAU_SACH &pDS, NODE_DMS* dms);

void Xoa_OutDMS_1line(int locate);

void Xoa_OutDMS_29lines();

int ChooseItems(LIST_DAUSACH &lDS, int &tttrang, int tongtrang);

int ChooseItems1(pDAU_SACH &pDS, int &tttrang, int tongtrang);

void Output_DMS(DMS dms);

void OutputDMS_PerPage(pDAU_SACH pDS, int index);

void Output_ListDMS(pDAU_SACH &pDS);

void NhapDanhMucSach(pDAU_SACH &pDS, int sosach);

//..................quan ly menu danh muc sach...................
void Menu_DMS(LIST_DAUSACH &lDS);

// tong so sach duoc muon cua mot dau sach.
int TongSoSachDuocMuon(LIST_DMS dms);

// xu ly thao tac in ra 10 sach co luoc muon nhieu nhat.
void Sort_Top10(TopSach *top10, int q, int r);

void Top10Sach(LIST_DAUSACH lDS);

void Output_ListDanhMucSach(pDAU_SACH &pDS);

//..........................................define dau sach....................................................
int Empty_DauSach(LIST_DAUSACH  l)
{
	return l.n == 0;
}

int Full_DauSach(LIST_DAUSACH  l)
{
	return l.n == MAX_DAUSACH;
}

string getString(string a)
{
	for (int i = 0; i < (int) a.length(); i++) {
		if (a[i] == ' ') {
			a.erase(i, 1);
			i--;
		}
	}

	return a;
}

int Insert_DauSach(LIST_DAUSACH &l, pDAU_SACH &pDS)
{
	if (Full_DauSach(l)) {
		return 0;
	}

	l.ListDS[l.n++] = pDS;

	return 1;
}

// p1 > tra ve true.

bool KiemTraDauSach(pDAU_SACH p1, pDAU_SACH p2)
{
	string temp1 = getString(p1->info.theloai);
	string temp2 = getString(p2->info.theloai);

	if (temp1 > temp2)
		return true;
	if (temp1 < temp2)
		return false;

	string temp3 = getString(p1->info.tensach);
	string temp4 = getString(p2->info.tensach);

	if (temp3 > temp4)
		return true;
	return false;
}

int InsertOrder_DauSach(LIST_DAUSACH &l, pDAU_SACH &pDS)
{
	if (Full_DauSach(l)) {
		return 0;
	}

	int vitri = 0;

	while(vitri < l.n && KiemTraDauSach(pDS,l.ListDS[vitri]))
		vitri++;

	if (vitri == l.n) {
		l.ListDS[l.n] = pDS;
		l.n++;

		return 1;
	}

	l.n++;

	for (int i = l.n-1; i >= vitri; i--) {
		l.ListDS[i+1] = l.ListDS[i];
	}

	l.ListDS[vitri] = pDS;

	return 1;
}
void Delete_DauSach(LIST_DAUSACH &l, int pos)
{
	if (pos > l.n-1  || Empty_DauSach(l)) {
		return;
	}

	// xoa vi tri cuoi mang
	if (pos == l.n-1) {
		delete l.ListDS[l.n-1];
		// tranh tinh trang con tro bi treo...
		l.ListDS[l.n-1] = NULL;
		l.n = l.n-1;

		return;
	}

	// cho n�y quan trong .
	delete l.ListDS[pos];

	for (int temp = pos + 1; temp < l.n; temp++) {
		l.ListDS[temp - 1] = l.ListDS[temp];
	}

	delete l.ListDS[l.n-1];

	// tranh tinh trang con tro bi treo...
	l.ListDS[l.n-1] = NULL;
	l.n = l.n - 1;

	return;
}

// tim kiem tuyen tinh
bool SearchISBN_DS(LIST_DAUSACH lDS, string ISBN)
{
	for (int i = 0; i < lDS.n; i++) {
		if (lDS.ListDS[i]->info.ISBN == ISBN)
			return true;
	}

	return false;
}

pDAU_SACH SearchTen_DS(LIST_DAUSACH lDS, string tensach)
{
	pDAU_SACH temp = NULL;
	for (int i = 0; i < lDS.n; i++) {
		temp = lDS.ListDS[i];

		if (temp->info.tensach == tensach)
			return temp;
	}

	return NULL;
}

pDAU_SACH SearchTen_TSBN(LIST_DAUSACH lDS, string isbn)
{
	pDAU_SACH temp = NULL;
	for (int i = 0; i < lDS.n; i++) {
		temp = lDS.ListDS[i];

		if (temp->info.ISBN == isbn)
			return temp;
	}
	return NULL;
}
//  nghien cuu cho nay co tham chieu hay khong
void swap_DS(pDAU_SACH ds1, pDAU_SACH ds2)
{
	DAU_SACH temp = *ds1;
	*ds1 = *ds2;
	*ds2 = temp;
}

//  selection sort...
void selectionSort_DS(LIST_DAUSACH &lDS)
{
	int i, j, min_idx;
	string temp1, temp2, temp3,temp4;

	// One by one move boundary of unsorted subarray
	for (i = 0; i <  lDS.n - 1; i++) {
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < lDS.n; j++) {
			if (KiemTraDauSach(lDS.ListDS[min_idx],lDS.ListDS[j]))
				min_idx = j;
		}

		// Swap the found minimum element with the first element
		if (min_idx != i)
			swap_DS(lDS.ListDS[min_idx],lDS.ListDS[i]);
	}
}

void Update_DauSach(LIST_DAUSACH &lDS, pDAU_SACH &pDS, bool isEdited)
{
	dauSach info;
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	int nngang = (int)keyBangNhapDauSach[0].length();
	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isSave = false;
	bool isEscape = false;

	// cac bien luu tru tam thoi
	string tensach = "";
	string ISBN = "";
	string tacgia = "";
	string theloai = "";
	uint sotrang = 0;
	uint namSB = 0;

	CreateBox(X_NOTIFY + 13, Y_NOTIFY, "NOTI:  ", 52);
	BangNhap(85, yDisplay, nngang, keyBangNhapDauSach, 14);
	BangGuides(85, yDisplay + 20, nngang, keyGuide2, 7);

	if (isEdited) {
		tensach = pDS->info.tensach;

		ISBN = pDS->info.ISBN;
		tacgia = pDS->info.tacgia;
		theloai = pDS->info.theloai;
		sotrang = pDS->info.sotrang;
		namSB = pDS->info.namSB;

		gotoxy(85 + (nngang / 3), yDisplay + 3);
		cout << tensach;
		gotoxy(85 + (nngang / 3), yDisplay + 5);
		cout << ISBN;
		gotoxy(85 + (nngang / 3), yDisplay + 7);
		cout << tacgia;
		gotoxy(85 + (nngang / 3), yDisplay + 9);
		cout << theloai;
		gotoxy(85 + (nngang / 3), yDisplay + 11);
		cout << sotrang;
		gotoxy(85 + (nngang / 3), yDisplay + 13);
		cout << namSB;
	}

	while (true) {
		switch (ordinal) {
		case 0:
			gotoxy(85 + (nngang / 3), yDisplay + 3);
			NhapTenSach(tensach, ordinal, isSave, isEscape, isEdited);
			break;
		case 1:
			gotoxy(85 + (nngang / 3), yDisplay + 5);
			NhapISBN(ISBN, ordinal, isSave, isEscape);
			break;
		case 2:
			gotoxy(85 + (nngang / 3), yDisplay + 7);
			NhapTenTacGia(tacgia, ordinal, isSave, isEscape, isEdited);
			break;
		case 3:
			gotoxy(85 + (nngang / 3), yDisplay + 9);
			NhapTheLoaiSach(theloai, ordinal, isSave, isEscape);
			break;
		case 4:
			gotoxy(85 + (nngang / 3), yDisplay + 11);
			nhapSoTrang(sotrang, ordinal, isSave, isEscape);
			break;
		case 5:
			gotoxy(85 + (nngang / 3), yDisplay + 13);
			NhapNamXuatBan(namSB, ordinal, isSave, isEscape);
			break;
		}

		// check Save

		if (isSave) {
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (tensach.length() == 0) {
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 0;

				continue;
			} else if (ISBN.length() == 0) {
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;

				continue;
			} else if(ISBN.length() < 6) {
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "MA ISBN PHAI CO 6 KI TU !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;

				continue;
			} else if (tacgia.length() == 0) {
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;

				continue;
			} else if (theloai.length() == 0) {
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 3;
				continue;
			} else if (sotrang == 0) {
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 4;

				continue;
			} else if (namSB == 0) {
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();
				ordinal = 5;

				continue;
			} else if (namSB > (uint)LayNamHT()) {
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "NAM XUAT BAN KHONG LON HON NAM HIEN TAI !!!";
				normalBGColor();
				ordinal = 5;

				continue;
			}

			if (SearchISBN_DS(lDS, ISBN)) {
				if (pDS->info.ISBN != ISBN) {
					gotoxy(X_NOTIFY + 15, Y_NOTIFY);
					SetColor(BLUE);
					cout << "ISBN VUA NHAP VAO TRUNG VOI ISBN DA CO  !!!";
					normalBGColor();

					// quay lai va dien vao truong du lieu do
					ordinal = 1;

					continue;
				}
			}

			// import data vao info
			info.tensach = ChuanHoaString(tensach);
			info.ISBN = ChuanHoaString(ISBN);
			info.tacgia = ChuanHoaString(tacgia);
			info.theloai = ChuanHoaString(theloai);
			info.sotrang = sotrang;
			info.namSB = namSB;

			if (isEdited) {
				pDS->info = info;
				normalBGColor();

				return;
			} else {
				// gan NULL cho con tro trong DS
				initList_DMS(pDS->dms);

				pDS->info = info;
				//int temp = Insert_DauSach(lDS, pDS);
				int temp = InsertOrder_DauSach(lDS, pDS);
				if (temp == 0) {
					// thong bao ra.
					for (int i = 0; i < 5; i++) {
						SetColor(BLUE);
						gotoxy(X_NOTIFY + 15, Y_NOTIFY);
						Sleep(100);

						cout << "BO NHO DA DAY .KHONG THEM DAU SACH MOI VAO DUOC !";
					}
				} else {
					// In dong thong bao .
					for (int i = 0; i < 5; i++) {
						SetColor(BLUE);
						gotoxy(X_NOTIFY + 15, Y_NOTIFY);
						Sleep(100);
						cout << "           SUCCESSFULLY !!! ";

					}
				}
				normalBGColor();

				return;
			}
		}

        // thoat
		if (isEscape) {
			return;
		}
	}

	ShowCur(false);
}

int ChooseItems_DS(LIST_DAUSACH &lDS, int &tttrang, int tongtrang)
{
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(LIGHT_GREEN);
	gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
	cout << "<<";
	gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
	cout << ">>";

	while (true) {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit) {
				case KEY_UP:
					// xoa muc truoc
					gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
					cout << "  ";
					gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
					cout << "  ";
					(pos > 0) ? pos-- : pos = 28;

					// to mau muc moi
					gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
					cout << "<<";
					gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
					cout << ">>";

					break;

				case KEY_DOWN:
					// xoa muc truoc
					gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
					cout << "  ";
					gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
					cout << "  ";
					(pos < 28) ? pos++ : pos = 0;

					// to mau muc moi
					gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
					cout << "<<";
					gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
					cout << ">>";

					break;

				case PAGE_UP:
					if (tttrang > 1) {
						tttrang--;
					} else {
						tttrang = tongtrang;
					}
					Xoa_OutDS_29lines();
					OutputDS_PerPage(lDS, tttrang);
					pos = 0;
					SetColor(LIGHT_GREEN);
					gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
					cout << "<<";
					gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
					cout << ">>";

					break;

				case PAGE_DOWN:
					if (tttrang <  tongtrang) {
						tttrang++;
					} else {
						tttrang = 1;
					}
					Xoa_OutDS_29lines();
					OutputDS_PerPage(lDS, tttrang);
					pos = 0;
					SetColor(LIGHT_GREEN);
					gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
					cout << "<<";
					gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
					cout << ">>";

					break;

				case ENTER:
					return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;
			}
		}

		ShowCur(false);
		SetColor(WHITE);
		gotoxy(33, 36);
		cout << "Trang " << tttrang << " / " << tongtrang;
		normalBGColor();
	}
}

void Xoa_OutDS_1line(int locate)
{
	gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + locate);
	cout << setw(27) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
	cout << setw(4) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[2] + 1, yDisplay + 3 + locate);
	cout << setw(18) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[3] + 1, yDisplay + 3 + locate);
	cout << setw(11) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[4] + 1, yDisplay + 3 + locate);
	cout << setw(6) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[5] + 1, yDisplay + 3 + locate);
	cout << setw(4) << setfill(' ') << ' ';
}

void Xoa_OutDS_29lines()
{
	for (int i = 0; i <NUMBER_LINES; i++) {
		Xoa_OutDS_1line(i);
	}
}

void Output_DS(dauSach ds)
{
	ShowCur(false);
	Xoa_OutDS_1line(locate);
	gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + locate);
	cout << ds.tensach;
	gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
	cout << ds.ISBN;
	gotoxy(xDisplayDS[2] + 1, yDisplay + 3 + locate);
	cout << ds.tacgia;
	gotoxy(xDisplayDS[3] + 1, yDisplay + 3 + locate);
	cout << ds.theloai;

	gotoxy(xDisplayDS[4] + 1, yDisplay + 3 + locate);
	// cout << ds.sotrang;
	cout << ds.sotrang;
	gotoxy(xDisplayDS[5] + 1, yDisplay + 3 + locate);
	cout << ds.namSB;
	locate++;
}

void OutputDS_PerPage(LIST_DAUSACH &lDS, int index)
{
	Xoa_OutDS_29lines();
	SetColor(WHITE);
	locate = 0;
	index--;
	if (lDS.n == 0)
		return;

	for (int i =  NUMBER_LINES * index;  i < NUMBER_LINES*( 1 + index)  && i <  lDS.n ; i++) {
		Output_DS(lDS.ListDS[i]->info);
	}
}

void Output_ListDStheoTT(LIST_DAUSACH lDS)
{
	system(SYSTEM_CORLOR);

	clrscr();
	normalBGColor();
	selectionSort_DS(lDS);

	label:

	DisplayDS(keyDisplayDS, 6, xDisplayDS);
	normalBGColor();
	gotoxy(10, 1);
	cout << "BANG THONG TIN CAC DAU SACH THEO THU TU THE LOAI VA TEN SACH TANG DAN";
	int nDS = lDS.n;
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	OutputDS_PerPage(lDS, tttrang);

	int check;
	pDAU_SACH temp;
	string tensach = "";

	int kb_hit;
	do {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit) {
				case PAGE_UP:
					(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
					OutputDS_PerPage(lDS, tttrang);

					break;

				case PAGE_DOWN:
					(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
					OutputDS_PerPage(lDS, tttrang);

					break;

				case KEY_F9:
					VeHinhBangNhap(82, 3,50, "         HAY NHAP VAO TEN SACH CAN TRA CUU");
					gotoxy(92, 5);
					check = NhapTenSachTimKiem(tensach);
					// kiem tra dieu kien tra ve .....
					if (check == -1) {
						gotoxy(92, 10);
						cout << "BAN VUA HUY TAC VU TRA CUU !!!";
						_getch();

						return;
					} else if (check == 1) {
						tensach = ChuanHoaString(tensach);
						temp = SearchTen_DS(lDS, tensach);
						if (temp == NULL) {
							gotoxy(86, 10);
							cout << "TEN SACH VUA NHAP KHONG CO TRONG THU VIEN !!!";
							_getch();
							XoaMotVung(82, 1, 35, 50);
						} else {
							Output_ListDanhMucSach(temp);
							//XoaMotVung(82, 1, 37, 50);
							clrscr();
							goto label;
						}
					}
				break;

				// thoat
				case ESC:
					return ;
			}
		}

		ShowCur(false);

		gotoxy(2, 35);
		cout << "HotKey: PgUp, PgDn, ESC,      F9  -  TIM THONG TIN SACH ";
		gotoxy(68, 35);
		cout << "Trang " << tttrang << " / " << tongtrang;
	} while (true);
}

void Menu_DauSach(LIST_DAUSACH &lDS)
{
	selectionSort_DS(lDS);

	system(SYSTEM_CORLOR);
	clrscr();
	gotoxy(35, 1);
	cout << "~~~CAP NHAT DAU SACH~~~ ";

	// nDG la so DG hien co trong danh sach tuyen tinh
	int nDS = lDS.n;
	int choose;
	pDAU_SACH pDS;

	gotoxy(3, yHotkey);
	SetColor(WHITE);
	cout << "HotKey:  ESC - Thoat, F2 - Them, F3 - Sua, F4 - Xoa, F10 - Luu, PgUP, PgDn";
	normalBGColor();

	// thu tu trang
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;

	label1:
	XoaMotVung(79, yDisplay, 30, 53);
	DisplayDS(keyDisplayDS, 6, xDisplayDS);
	OutputDS_PerPage(lDS, tttrang);

	int kb_hit;
	do {
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit) {
				case PAGE_UP:
					(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
					OutputDS_PerPage(lDS, tttrang);

					break;

				case PAGE_DOWN:
					(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
					OutputDS_PerPage(lDS, tttrang);

					break;

				case KEY_F2:
					Beep(600, 100);
					pDS = new DAU_SACH;

					if (pDS == NULL)
						goto label1;
					Update_DauSach(lDS, pDS, false);

					goto label1 ;

				case  KEY_F3:
					Beep(600, 100);
					choose = ChooseItems_DS(lDS, tttrang, tongtrang);

					if (choose > lDS.n)
						goto label1;
					Update_DauSach(lDS, lDS.ListDS[choose], true);

					goto label1;

				case KEY_F4:
					Beep(600, 100);
					choose = ChooseItems_DS(lDS, tttrang, tongtrang);

					if (choose > lDS.n)
						goto label1;

					// neu co nguoi muon thi se khong duoc phep xoa .
					if (Check_DMS(lDS.ListDS[choose]->dms.pHead)) {
						gotoxy(79,20);
						cout << " Dau Sach da co Doc Gia muon nen khong duoc phep xoa !";
						_getch();
						gotoxy(79, 20);
						cout << "                                                      ";

						goto label1;
					}

					gotoxy(0,0);
					cout << "Deo biet gi luon";
					_getch();

					Delete_DauSach(lDS, choose);

					goto label1;

					// thoat
				case ESC:
					Beep(600, 100);

					return ;
			}
		}
		ShowCur(false);
		gotoxy(33, 36);
		cout << "Trang " << tttrang << " / " << tongtrang;

	} while (true);
}

//.......................................define danh muc sach....................................
// ..... khoi tao........
void initList_DMS(LIST_DMS& l)
{
	l.n = 0;
	l.pHead = l.pTail = NULL;
}

// kiem tra rong
bool ListDMSIsEmpty(LIST_DMS l)
{
	return l.pHead == NULL;
}

// get node
NODE_DMS* GetNode_DMS(DMS DATA)
{
	NODE_DMS *p = new NODE_DMS;
	if (p == NULL) {
		return NULL;
	}

	p->data = DATA;
	p->pNext = NULL;

	return (p);
}

void AddTailList_DMS(LIST_DMS &l, DMS data)
{
	// tao Node
	NODE_DMS *p = GetNode_DMS(data);

	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	} else {
		l.pTail->pNext = p;
		l.pTail = p;
	}

	l.n++;
}

int position(NODE_DMS *First, string keySearch)
{
	int vitri;
	NODE_DMS * q;
	q = First;
	vitri = 1;

	if (q == NULL)
		return(-1);

	while (q != NULL && q->data.maSach != keySearch) {
		q = q->pNext;
		vitri++;
	}

	return(vitri);
}

NODE_DMS * nodepointer(NODE_DMS *First, int i)
{
	NODE_DMS * p;
	int vitri = 1;
	p = First;

	while (p != NULL && vitri < i) {
		p = p->pNext;
		vitri++;
	}

	return(p);
}


void Delete_first(NODE_DMS *&First)
{
	NODE_DMS *p;
	if (First == NULL)
		return;
	else {
		// nut can xoa la nut dau
		p = First;
		First = First->pNext;

		delete p;
	}
}

void Delete_after(NODE_DMS *p)
{
	NODE_DMS * q;
	// q chi nut can xoa
	q = p-> pNext;
	p->pNext = q-> pNext;

	delete q;
}

int Delete_batky(pDAU_SACH &pDS, string keySearch)
{
	int pos;
	pos = position(pDS->dms.pHead, keySearch);
	if (pos > pDS->dms.n   || pos == -1) {
		return  -1;
	} else if (pos == 1) {
		// truong hop xoa dau
		Delete_first(pDS->dms.pHead );
		pDS->dms.n--;

		return 1;
	} else {
		//p chi toi nut truoc nut can xoa
		NODE_DMS  *p = nodepointer(pDS->dms.pHead , pos - 1);
		Delete_after(p);

		// truong hop xoa duoi, thi phai cap nhat lai pTail, rat quan trong cho nay.@@
		if (pos == pDS->dms.n) {
			pDS->dms.pTail = p;
		}

		pDS->dms.n--;

		return 1;
	}
}

bool Check_DMS(NODE_DMS* nDMS)
{
	for (NODE_DMS* p = nDMS; p != NULL; p = p->pNext) {
		// sach da co nguoi muon.
		if (p->data.ttSach == 1) {
			return true;
		}
	}

	return false;
}

NODE_DMS* Search_DMS1(pDAU_SACH pDS, string masach)
{
	NODE_DMS* p;
	p = pDS->dms.pHead;

	while (p != NULL && p->data.maSach != masach)
		p = p->pNext;

	return (p);
}

NODE_DMS* Search_DMS2(NODE_DMS* dms, int pos)
{
	int count = -1;

	for (NODE_DMS* temp = dms; temp != NULL; temp = temp->pNext) {
		count++;
		if (pos == count){
			return temp;
		}
	}

	return NULL;
}

int NhapSach(pDAU_SACH &pDS)
{
	DMS info;

	// hien con tro nhap
	ShowCur(true);
	normalBGColor();
	int nngang = (int)keyBangNhapDanhMucSach[0].length();
	CreateBox(40, Y_NOTIFY + 2, "NOTIFICATIONS:  ", 66);
	BangNhap(38, yDisplay + 2, nngang, keyBangNhapDanhMucSach, 8);
	BangGuides(38, yDisplay + 22, nngang, keyGuide3, 4);

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 1;
	bool isSave = false;
	bool isEscape = false;

	// cac bien luu tru tam thoi
	// ma sach = isbn + stt;   aaaa1..aaaa2....aaaa3....aaaa4
	// to_string(++pDS->dms.n)  chuyen kieu int thanh kieu nguyen.

	int stt = pDS->dms.n + 1;
	stringstream ss;
	ss << stt;

	string maSach = pDS->info.ISBN + ss.str();
	// neu maSach co trung thi tang ma sach len.

	uint ttSach = 3;
	string viTri = "";

	gotoxy(40 + (nngang / 3), yDisplay + 5);
	cout << maSach;

	while (true) {
		switch (ordinal) {
			case 1:

				NhapTrangThaiSach(ttSach, ordinal, isSave, isEscape, 40 + (nngang / 3), yDisplay + 7);
				break;
			case 2:

				NhapViTri(viTri, ordinal, isSave, isEscape, 40 + (nngang / 3), yDisplay + 9);
				break;
		}

		// check Save
		if (isSave) {
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (ttSach == 3) {
				gotoxy(55, Y_NOTIFY + 2);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;

				continue;
			}

			if (viTri.length() == 0) {
				gotoxy(55, Y_NOTIFY + 2);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;

				continue;
			}

			// import data vao info
			info.maSach = maSach;
			info.ttSach = ttSach;
			info.viTri = viTri;

			AddTailList_DMS(pDS->dms, info);

			return 0;
		}

		if (isEscape) {
			return -1;
		}
	}
}

int SuaDanhMucSach(pDAU_SACH &pDS, NODE_DMS* dms)
{
	DMS info;
	// kiem tra dieu kien.
	if (dms->data.ttSach == 1)
		return 2;

	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	int nngang = (int)keyBangNhapDanhMucSach[0].length();

	CreateBox(67, Y_NOTIFY + 2, "NOTIFICATIONS:  ", 66);
	BangNhap(65, yDisplay + 6, nngang, keyBangNhapDanhMucSach, 8);
	BangGuides(65, yDisplay + 22, nngang, keyGuide3, 4);

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 1;
	bool isSave = false;
	bool isEscape = false;

	string maSach = dms->data.maSach;

	uint ttSach = dms->data.ttSach ;
	string viTri = dms->data.viTri;

	gotoxy(67 + (nngang / 3), yDisplay + 9);
	cout << maSach;

	gotoxy(89, yDisplay + 11);

	if (ttSach == 0)
		cout << ttSach << ":   CHO MUON DUOC  ";
	else if (ttSach == 1)
		cout << ttSach << ":   DA DUOC MUON   ";
	else if (ttSach == 2)
		cout << ttSach << ":   DA THANH LY    ";

	gotoxy(89, yDisplay + 13);
	cout << viTri;

	while (true) {
		switch (ordinal) {
			case 1:

				NhapTrangThaiSach(ttSach, ordinal, isSave, isEscape, 89,  yDisplay + 11);
				break;
			case 2:

				NhapViTri(viTri, ordinal, isSave, isEscape, 89, yDisplay + 13);
				break;
		}

		// check Save
		if (isSave) {
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (ttSach == 3) {
				gotoxy(67, Y_NOTIFY + 2);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;

				continue;
			}

			if (viTri.length() == 0) {
				gotoxy(67, Y_NOTIFY + 2);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;

				continue;
			}

			// import data vao info
			info.maSach = maSach;
			info.ttSach = ttSach;

			if (ttSach == 1)
				pDS->soluongsachdamuon++;
			info.viTri = viTri;

			dms->data = info;

			return 1;
		}

		if (isEscape) {
			return -1;
		}
	}

}

void Xoa_OutDMS_1line(int locate)
{
	gotoxy(xDisplayDMS[0] + 1, yDisplay + 3 + locate);
	cout << setw(11) << setfill(' ') << ' ';
	gotoxy(xDisplayDMS[1] + 1, yDisplay + 3 + locate);
	cout << setw(13) << setfill(' ') << ' ';
	gotoxy(xDisplayDMS[2] + 1, yDisplay + 3 + locate);
	cout << setw(34) << setfill(' ') << ' ';
}

void Xoa_OutDMS_29lines()
{
	for (int i = 0; i <NUMBER_LINES; i++) {
		Xoa_OutDMS_1line(i);
	}
}

int ChooseItems(LIST_DAUSACH &lDS, int &tttrang, int tongtrang)
{
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(LIGHT_GREEN);
	gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
	cout << "<<";
	gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
	cout << ">>";

	while (true) {
		// mau me, hoa la he...
		gotoxy(20, 1);
		cout << "~~~";
		gotoxy(20, 1);
		Sleep(50);
		cout << "   ";
		gotoxy(62, 1);
		cout << "~~~";
		gotoxy(62, 1);
		Sleep(50);
		cout << "   ";

		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit) {
				case KEY_UP:
					// xoa muc truoc
					gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
					cout << "  ";
					gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
					cout << "  ";
					//	(pos > 0) ? pos-- : pos = 28;
					if (pos > 0)
						pos--;
					else if (pos == 0 && tttrang < tongtrang)
						pos = 28;
					else
						pos = lDS.n -1 - (tongtrang-1)*29;

					// to mau muc moi
					gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
					cout << "<<";
					gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
					cout << ">>";
					break;

				case KEY_DOWN:
					// xoa muc truoc
					gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
					cout << "  ";
					gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
					cout << "  ";
					//(pos < 28) ? pos++ : pos = 0;
					if (pos < 28 && tttrang < tongtrang)
						pos++;
					else if (pos == 28 && tttrang < tongtrang)
						pos = 0;
					else if (tttrang == tongtrang && pos < lDS.n-1-(tongtrang-1)*29)
						pos++;
					else
						pos = 0;

					// to mau muc moi
					gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
					cout << "<<";
					gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
					cout << ">>";

					break;

				case PAGE_UP:
					if (tttrang > 1) {
						tttrang--;
					} else {
						tttrang = tongtrang;
					}

					OutputDS_PerPage(lDS, tttrang);
					// hight light dong dau.
					pos = 0;
					SetColor(LIGHT_GREEN);
					gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
					cout << "<<";
					gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
					cout << ">>";

					break;

				case PAGE_DOWN:
					if (tttrang <  tongtrang) {
						tttrang++;
					} else {
						tttrang = 1;

					}
					OutputDS_PerPage(lDS, tttrang);

					// high light dong dau.
					pos = 0;
					SetColor(LIGHT_GREEN);
					gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + pos);
					cout << "<<";
					gotoxy(xDisplayDS[0] + 26, yDisplay + 3 + pos);
					cout << ">>";

					break;

				case ENTER:
					return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;

				case ESC:
					return -1;
			}
		}

		ShowCur(false);
		gotoxy(33, 35);
		cout << "Trang " << tttrang << " / " << tongtrang;
	}
}

int ChooseItems1(pDAU_SACH &pDS, int &tttrang, int tongtrang)
{
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(LIGHT_GREEN);
	gotoxy(xDisplayDMS[0] + 1, yDisplay + 3 + pos);
	cout << "<<";
	gotoxy(xDisplayDMS[0] + 10, yDisplay + 3 + pos);
	cout << ">>";

	while (true)
	{
		// mau me, hoa la he...
		gotoxy(12, 1);
		cout << "~~~";
		gotoxy(12, 1);
		Sleep(50);
		cout << "   ";
		gotoxy(54, 1);
		cout << "~~~";
		gotoxy(54, 1);
		Sleep(50);
		cout << "   ";

		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit) {
				case KEY_UP:
					// xoa muc truoc
					gotoxy(xDisplayDMS[0] + 1, yDisplay + 3 + pos);
					cout << "  ";
					gotoxy(xDisplayDMS[0] + 10, yDisplay + 3 + pos);
					cout << "  ";
					//(pos > 0) ? pos-- : pos = 28;
					if (pos > 0)
						pos--;
					else if (pos == 0 && tttrang < tongtrang)
						pos = 28;
					else
						pos = pDS->dms.n -1 - (tongtrang-1)*29;

					// to mau muc moi
					gotoxy(xDisplayDMS[0] + 1, yDisplay + 3 + pos);
					cout << "<<";
					gotoxy(xDisplayDMS[0] + 10, yDisplay + 3 + pos);
					cout << ">>";

					break;

				case KEY_DOWN:

					// xoa muc truoc
					gotoxy(xDisplayDMS[0] + 1, yDisplay + 3 + pos);
					cout << "  ";
					gotoxy(xDisplayDMS[0] + 10, yDisplay + 3 + pos);
					cout << "  ";
					//(pos < 28) ? pos++ : pos = 0;
						if (pos < 28 && tttrang < tongtrang)
						pos++;
					else if (pos == 28 && tttrang < tongtrang)
						pos = 0;
					else if (tttrang == tongtrang && pos < pDS->dms.n-1-(tongtrang-1)*29)
						pos++;
					else
						pos = 0;

					// to mau muc moi
					gotoxy(xDisplayDMS[0] + 1, yDisplay + 3 + pos);
					cout << "<<";
					gotoxy(xDisplayDMS[0] + 10, yDisplay + 3 + pos);
					cout << ">>";

					break;

				case PAGE_UP:
					if (tttrang > 1) {
						tttrang--;
					} else {
						tttrang = tongtrang;
					}
					Xoa_OutDMS_29lines();
					OutputDMS_PerPage(pDS, tttrang);

					pos = 0;
					SetColor(LIGHT_GREEN);
					gotoxy(xDisplayDMS[0] + 1, yDisplay + 3 + pos);
					cout << "<<";
					gotoxy(xDisplayDMS[0] + 10, yDisplay + 3 + pos);
					cout << ">>";

					break;

				case PAGE_DOWN:
					if (tttrang <  tongtrang) {
						tttrang++;
					} else {
						tttrang = 1;
					}
					Xoa_OutDMS_29lines();
					OutputDMS_PerPage(pDS, tttrang);
					pos = 0;
					SetColor(LIGHT_GREEN);
					gotoxy(xDisplayDMS[0] + 1, yDisplay + 3 + pos);
					cout << "<<";
					gotoxy(xDisplayDMS[0] + 10, yDisplay + 3 + pos);

					cout << ">>";

					break;

				case ENTER:
					return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;

				case ESC:
					return -1;
			}
		}
		ShowCur(false);
		gotoxy(33, 35);
		cout << "Trang " << tttrang << " / " << tongtrang;
	}
}

void Output_DMS(DMS dms)
{
	Xoa_OutDMS_1line(locate);
	gotoxy(xDisplayDMS[0] + 3, yDisplay + 3 + locate);
	cout << dms.maSach;
	gotoxy(xDisplayDMS[1] + 1, yDisplay + 3 + locate);

	if (dms.ttSach == 0) {
		cout << "Cho Muon Duoc";
	} else if (dms.ttSach == 1) {
		cout << "Da Cho Muon";
	} else if (dms.ttSach == 2) {
		cout << "Da Thanh Ly";
	}

	gotoxy(xDisplayDMS[2] + 10, yDisplay + 3 + locate);
	cout << dms.viTri;
	locate++;
}

void OutputDMS_PerPage(pDAU_SACH pDS, int index)
{
	Xoa_OutDMS_29lines();
	locate = 0;
	if (pDS->dms.pHead == NULL && pDS->dms.pTail == NULL)
		return;

	index--;
	index *= NUMBER_LINES;
	int count = 0;
	NODE_DMS * temp = NULL;

	for (temp = pDS->dms.pHead; temp != NULL  && count < index; temp = temp->pNext) {
		count++;
	}

	for (int i = 0; i < NUMBER_LINES && temp != NULL; i++) {
		Output_DMS(temp->data);
		temp = temp->pNext;
	}

	return;
}


void Output_ListDanhMucSach(pDAU_SACH &pDS)
{
	// thu tu trang
	clrscr();
	SetBGColor(2);
	gotoxy(93, 8);
	cout << "THONG TIN TRA CUU DUOC !";
	gotoxy(82, 10);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 12);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 14);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 16);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 18);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 20);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 22);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 24);
	cout << setw(50) << setfill('-') << "-";
	normalBGColor();
	gotoxy(82, 11);
	cout << "TEN SACH: " << pDS->info.tensach;
	gotoxy(82, 13);
	cout << "TAC GIA: " << pDS->info.tacgia;
	gotoxy(82, 15);
	cout << "THE LOAI: " << pDS->info.theloai;
	gotoxy(82, 17);
	cout << "NAM XUAT BAN: " << pDS->info.namSB;
	gotoxy(82, 19);
	cout << "ISBN: " << pDS->info.ISBN;
	gotoxy(82 ,21);
	cout << "TONG SO SACH CUA DAU SACH: " << pDS->dms.n;
	gotoxy(82, 23);
	cout << "SO SACH CON TRONG THU VIEN:  " << pDS->dms.n - TongSoSachDuocMuon(pDS->dms);

	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = ((pDS->dms.n + 1 ) / NUMBER_LINES) + 1;
	gotoxy(8, 1);
	cout << " BANG DANH MUC SACH CUA DAU SACH : " << pDS->info.tensach;

	DisplayDMS(keyDisplayDMS, 3, xDisplayDMS);
	OutputDMS_PerPage(pDS, tttrang);
	string keySearch = "";

	int kb_hit;
	do {
		//	XoaMotVung(65,2,  30, 67);
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit) {
				case PAGE_UP:
					(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
					OutputDMS_PerPage(pDS, tttrang);

					break;

				case PAGE_DOWN:
					(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
					OutputDMS_PerPage(pDS, tttrang);

					break;
				case ESC:
					Beep(600, 100);

					return;
			}
		}

		ShowCur(false);
		gotoxy(54, 35);
		cout << "Trang " << tttrang << " / " << tongtrang;
	} while (true);
}


void Output_ListDMS(pDAU_SACH &pDS)
{
	// thu tu trang
	clrscr();
	int check1;
	int check2;
	int check3;
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = ((pDS->dms.n + 1 ) / NUMBER_LINES) + 1;
	NODE_DMS* temp = NULL, *temp1 = NULL;
	gotoxy(8, 1);
	cout << " BANG DANH MUC SACH CUA DAU SACH : " << pDS->info.tensach;

	label:
	DisplayDMS(keyDisplayDMS, 3, xDisplayDMS);
	OutputDMS_PerPage(pDS, tttrang);
	string keySearch = "";

	int kb_hit;
	do {
		XoaMotVung(65,2,  30, 67);
		if (_kbhit()) {
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit) {
				case PAGE_UP:
					(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
					OutputDMS_PerPage(pDS, tttrang);

					break;

				case PAGE_DOWN:
					(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
					OutputDMS_PerPage(pDS, tttrang);

					break;

				case  KEY_F3:
					Beep(600, 100);
					VeHinhBangNhap(82, 3, 38, " HAY NHAP VAO MA SACH CAN HIEU CHINH");
					gotoxy(96, 5);
					check1 = NhapMaDauSach(keySearch);

					// kiem tra dieu kien tra ve .....
					if (check1 == -1) {
						gotoxy(84, Y_NOTIFY + 12);
						cout << "BAN VUA HUY TAC VU HIEU CHINH !!!";
						_getch();
					} else if (check1 == 1) {
						temp = Search_DMS1(pDS, keySearch);
						if (temp == NULL) {
							gotoxy(77, Y_NOTIFY + 12);
							cout << "BAN VUA NHAP MA SACH " << "'" << keySearch << "'" << " KHONG CO TRONG DU LIEU";
							_getch();
						} else {
							check3 = SuaDanhMucSach(pDS, temp);
							gotoxy(0,0);
							cout << pDS->soluongsachdamuon;
							// kiem tra cac truong hop.
							if (check3 == 1) {
								gotoxy(73, Y_NOTIFY + 12);
								cout << "BAN VUA HIEU CHINH THONG TIN SACH CO MA SACH LA: " << keySearch;
								_getch();
							} else if (check3 == 2) {
								gotoxy(73, Y_NOTIFY + 12);
								cout << "Sach da co Doc Gia muon nen khong duoc phep hieu chinh !";
								_getch();
								gotoxy(73, Y_NOTIFY + 12);
								cout << "                                                        ";
							} else {
								gotoxy(82, Y_NOTIFY + 12);
								cout << "BAN VUA HUY TAC VU HIEU CHINH !!!";
								_getch();
							}
						}
					}

					goto label;

				case KEY_F4:

					Beep(600, 100);
					VeHinhBangNhap(82, 3, 35,  "HAY NHAP VAO MA SACH DE THANH LI   ");
					gotoxy(96, 5);
					check1 = NhapMaDauSach(keySearch);

					// kiem tra dieu kien tra ve .....
					if (check1 == -1) {
						gotoxy(88, 10);
						cout << "BAN VUA HUY TAC VU XOA !!!";
						_getch();
					} else if (check1 == 1) {
						temp1 = Search_DMS1(pDS, keySearch);
						// da co doc gia muon.
						if (temp1->data.ttSach == 1) {
							gotoxy(78, 20);
							cout << "Sach da co Doc Gia muon nen khong duoc phep xoa !";
							_getch();
							gotoxy(78, 20);
							cout << "                                                      ";
						} else {

							gotoxy(0,0);
							cout << temp1->data.ttSach;

							temp1->data.ttSach = 2;
							gotoxy(82, 10);
							cout << "BAN VUA THANH LY SACH CO MA SACH LA: " << keySearch;
							_getch();
						}
					}
					goto label;

				case ESC:
					Beep(600, 100);
					return;
			}
		}

		ShowCur(false);
		gotoxy(3, 36);
		cout << "HotKey:  F3 - Hieu chinh , F4 - Thanh ly , ESC - Thoat";
		gotoxy(54, 35);
		cout << "Trang " << tttrang << " / " << tongtrang;

	} while (true);
}

void NhapDanhMucSach(pDAU_SACH &pDS, int sosach)
{
	clrscr();
	system(SYSTEM_CORLOR);
	int check1 = 0 ;
	gotoxy(39, 2);
	cout << "BAN DANG NHAP THONG TIN VAO DANH MUC SACH CUA DAU SACH : " << pDS->info.tensach;
	gotoxy(60, 16);
	cout << "SO SACH CAN NHAP: " << sosach << endl;
	gotoxy(51, 17);
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	gotoxy(52, 31);
	cout << " HotKey:   F10 - Luu ,  ESC - Thoat ";

	// nhap sach theo so sach da cho truoc
	for (int i = 0; i < sosach && check1 != -1; i++) {
		// nhap sach
		check1 = NhapSach(pDS);

		XoaMotVung(38, yDisplay + 2, 10, (int)keyBangNhapDanhMucSach[0].length());

		gotoxy(60, 18);
		cout << "SO SACH DA NHAP : " << i + 1;
	}

	Output_ListDMS(pDS);
}

void Menu_DMS(LIST_DAUSACH &lDS)
{
	system(SYSTEM_CORLOR);
	int choose;
	int nDS = lDS.n;
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	int temp = 1;

	do {
		clrscr();
		// hien thi bang chua thong tin dau sach
		DisplayDS(keyDisplayDS, 6, xDisplayDS);
		OutputDS_PerPage(lDS, tttrang);

		gotoxy(23, 1);
		SetBGColor(GREEN);
		cout << "CHON DAU SACH DE CAP NHAT DANH MUC SACH";
		normalBGColor();

		// chon dau sach muon nhap sach vao
		choose = ChooseItems(lDS, tttrang, tongtrang);

		// check cac truong hop ...
		if (choose == -1) {
			return ;
		} else if (choose > lDS.n) {
			// xem th? ch? d?u s�ch c� quay l?i ngay c�i trang h?u n?y lu�n kko
			gotoxy( 2 , yDisplay + 3 + choose % NUMBER_LINES);
			cout << setw(27) << setfill(' ') << ' ';

			continue;
		}

		if (lDS.ListDS[choose]->dms.pHead != NULL && lDS.ListDS[choose]->dms.n == - 1) {
			continue;
		}

		// chon so sach nhap
		int sosach = ChonSoSachNhap();
		if (sosach == -1) {
			XoaMotVung(81, 3, 20, 50);
			continue;
		} else {
			// bat dau nhap thong tin sach
			NhapDanhMucSach(lDS.ListDS[choose], sosach);
		}
	} while (true);
}

int TongSoSachDuocMuon(LIST_DMS dms)
{
	int dem = 0;
	NODE_DMS *temp = NULL;
	for (temp = dms.pHead; temp != NULL; temp = temp->pNext) {
		//  tinh ca sach da muon va da muon nhung lam mat.
		if (temp->data.ttSach == 1   ||  temp->data.ttSach == 2) {
			dem++;
		}
	}

	return dem;
}

void Sort_Top10(TopSach *top10, int q, int r)
{
	TopSach temp;
	int i = q;
	int j = r;
	//L?y ph?n t? gi?a c?a d�y c?n s?p th? t? l�m ch?t
	int x = top10[(q + r) / 2].sosachmuon;

	do {  // Ph�n do?n d�y con a[q],..., a[r]
		while (top10[i].sosachmuon > x)
			i++; //T�m ph?n t? d?u ti�n c� tr? nh? hon hay b?ng x
		while (top10[j].sosachmuon < x)
			j--; //T�m ph?n t? d?u ti�n c� tr? l?n hon hay b?ng x

		if (i <= j) {
			// Hoan vi
			temp = top10[i];
			top10[i] = top10[j];
			top10[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (q<j)   // ph?n th? nh?t c� t? 2 ph?n t? tr? l�n
		Sort_Top10(top10, q, j);
	if (i < r) // ph?n th? ba c� t? 2 ph?n t? tr? l�n
		Sort_Top10(top10, i, r);
}

void Top10Sach(LIST_DAUSACH lDS)
{
	system(SYSTEM_CORLOR);
	clrscr();
	int count = 0;
	TopSach *top10 = new TopSach[lDS.n];

	// nhap thong tin vao mang.
	TopSach temp;
	for (int i = 0; i < lDS.n; i++) {
		top10[i].tensach = lDS.ListDS[i]->info.tensach;
		//top10[i].sosachmuon = TongSoSachDuocMuon(lDS.ListDS[i]->dms);
		top10[i].sosachmuon = lDS.ListDS[i]->soluongsachdamuon;
	}

	int i;
	int vitri_max;
	for (i = 0; i < lDS.n-1; i++) {
		vitri_max = i;
		for(int j = i; j < lDS.n; j++) {
			if (top10[vitri_max].sosachmuon < top10[j].sosachmuon)
				vitri_max = j;
		}

		if (top10[vitri_max].sosachmuon == 0)
			break;

		if (vitri_max != i) {
			temp = top10[i];
			top10[i] = top10[vitri_max];
			top10[vitri_max] = temp;
		}

		if (i >= 10 && top10[i].sosachmuon != top10[9].sosachmuon)
			break;
	}

	// in thong tin ra  console
	gotoxy(50, 2);
	SetBGColor(GREEN);
	cout << "TOP 10 DAU SACH CO SO LUOC MUON NHIEU NHAT ";
	normalBGColor();
	int j = 0;

	while (top10[j].sosachmuon != 0 && j < i) {
		// ||  top10[j].sosachmuon == top10[j + 1].sosachmuon  && top10[j].sosachmuon != 0)
		SetColor(WHITE);
		gotoxy(xDisplayTop10[1] + 3, yDisplayTop10 + 2 + j);
		cout << top10[j].tensach;
		gotoxy(xDisplayTop10[2] + 16, yDisplayTop10 + 2 + j);
		cout << top10[j].sosachmuon;
		gotoxy(xDisplayTop10[0] + 7, yDisplayTop10 + 2 + j);
		j++;
		cout << j;

	}

	DisplayTop10(keyDisplayTop10, 3, xDisplayTop10, j + 2);
	_getch();

	// xoa vung nho....
	delete[] top10;
}
