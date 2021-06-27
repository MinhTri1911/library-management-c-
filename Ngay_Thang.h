

#include <time.h>
#include <iostream>
#include "mylib.h"
#include "Marcro.h"
using std::cout;

// 1800 <  NAM < 9999
//const int MAX_NAM = 9999;
//const int MIN_NAM = 1800;

struct NgayThang
{
	uint ngay;
	uint thang;
	uint nam;
};
typedef struct NgayThang NGAY_THANG;

// kiem tra nam nhuan
bool namNhuan(int year);

// kiem tra ngay hop format hay khong?
int ngayHopLe(NGAY_THANG nt);

//xuat ngay thang
void xuatNgayThang(NGAY_THANG dt, int x, int y);

//  lay ngay gio he thong
void LayNgayGioHT(NGAY_THANG &d);

// lay nam tu he thong
int LayNamHT();

//ham tra ve  so ngay 
// nguon: http://mathforum.org/library/drmath/view/66535.html
int tinhNgay(NGAY_THANG dt);

// ham tinh khoang cach so ngay giua hai ngay da cho.
int KhoangCachNgay(NGAY_THANG nt1);


int SoSanhNgay(NGAY_THANG nt1, NGAY_THANG nt2);





bool namNhuan(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) ||
		(year % 400 == 0));
}

int ngayHopLe(NGAY_THANG nt)
{
	// return 0 chi ngay sai, 1 chi thang sai , 2 chi nam sai va 3 chi ngay gio dung format
	
	if (nt.nam > 2050 || nt.nam < 2000)
		return 2;
	if (nt.thang < 1 || nt.thang > 12)
		return 1;
	if (nt.ngay < 1 || nt.ngay > 31)
		return 0;

	// xu ly thang 2 voi nam  nhuan
	if (nt.thang == 2)
	{
		if (namNhuan(nt.nam))
		{
			if (nt.ngay > 29)
				return 0;
		}
		else
		{
			if (nt.ngay > 28)
			{
				return 0;
			}
		}
	}
	if ((nt.thang == 4 || nt.thang == 6 || nt.thang == 9 || nt.thang == 11) && (nt.ngay > 30))
	{
		return 0;
	}
	return 3;
}

void xuatNgayThang(NGAY_THANG dt, int x, int y)
{
	gotoxy(x, y);
	cout << dt.ngay << " /";
	gotoxy(x + 4, y);
	cout << dt.thang << " /";
	gotoxy(x + 8, y);
	cout << dt.nam;
}

void LayNgayGioHT(NGAY_THANG &d)
{
//	//    int ngay,thang,nam ;
//	tm today;
//	time_t ltime;
//	time(&ltime);
//	 //today = localtime( &ltime );
//	//localtime_s(&today, &ltime);
//	d.ngay = today.tm_mday;
//	d.thang = today.tm_mon + 1;
//	d.nam = today.tm_year + 1900;
	 // tra ve date/time hien tai dua tren system hien tai
   time_t baygio = time(0);

   //cout << "So giay ke tu 1/1/1970 la: " << baygio << endl;

   tm *ltm = localtime(&baygio);
   d.ngay = ltm->tm_mday;
   d.thang = 1 + ltm->tm_mon;
   d.nam = 1900 + ltm->tm_year;

   // in cac thanh phan cua cau truc tm struct.
//   cout << "Nam: "<< 1900 + ltm->tm_year << endl;
//   cout << "Thang: "<< 1 + ltm->tm_mon<< endl;
//   cout << "Ngay: "<<  ltm->tm_mday << endl;
//   cout << "Thoi gian: "<< 1 + ltm->tm_hour << ":";
//   cout << 1 + ltm->tm_min << ":";
//   cout << 1 + ltm->tm_sec << endl;
}

int LayNamHT()
{
	 time_t baygio = time(0);

   //cout << "So giay ke tu 1/1/1970 la: " << baygio << endl;

   tm *ltm = localtime(&baygio);
	 //today = localtime( &ltime );
	//localtime_s(&today, &ltime);
	return (ltm->tm_year + 1900);
}

int tinhNgay(NGAY_THANG dt)
{
	if (dt.thang < 3) {
		dt.nam--;
		dt.thang += 12;
	}
	return 365 * dt.nam + dt.nam / 4 - dt.nam / 10 + dt.nam / 400 + (153 * dt.thang - 457) / 5 + dt.ngay - 306;
}

int KhoangCachNgay(NGAY_THANG nt1)
{
	NGAY_THANG nt2;
	LayNgayGioHT(nt2);
	return (tinhNgay(nt2) - tinhNgay(nt1));
}
int LeapYear(int year)
{
    if (year % 400==0) return 1;
    else if (year % 100!=0 && year % 4==0) return 1;
    return 0;
}


int tinhKhoangCachNgay1(NGAY_THANG ngay1, NGAY_THANG ngay2)
{

   int a[]={31,28,31,30,31,30,31,31,30,31,30,31};

	int sonam1 = 0;
	for(int i = 2000; i < ngay1.nam; i++)
	{
		if(LeapYear(i)) sonam1 += 366;
		else sonam1 += 365;
	}
	int sothang1 = 0;
	if(LeapYear(ngay1.nam))
		a[1] = 29;
	
	for(int i = 1; i < ngay1.thang; i++)
		sothang1 += a[i-1];
		
	int songay1 = ngay1.ngay - 1;
	
	int tongngay1 = sonam1 + sothang1 + songay1;	
	
	
	int sonam2 = 0;
	for(int i = 2000; i < ngay2.nam; i++)
	{
		if(LeapYear(i)) sonam2 += 366;
		else sonam2 += 365;
	}
	int sothang2 = 0;
	if(LeapYear(ngay2.nam))
		a[1] = 29;
	else a[1]=28;
	for(int i = 1; i < ngay2.thang; i++)
		sothang2 += a[i-1];
		
	int songay2 = ngay2.ngay - 1;
	
	int tongngay2 = sonam2 + sothang2 + songay2;
	
	return (tongngay2 - tongngay1);
}

int tinhKhoangCachNgay(NGAY_THANG ngay1, NGAY_THANG ngay2)
{

    	 int dateOfYear=0;
    for (int i=ngay1.nam;i<ngay2.nam;i++)
        if( LeapYear(i)) dateOfYear+=366;  
        else dateOfYear+=365;
 
   
    int a[]={31,28,31,30,31,30,31,31,30,31,30,31};

	int lechngaythang1 = 0;
	int lechngaythang2 = 0;
	
	if ( LeapYear(ngay1.nam)) a[1]=29; 
	for(int i = 1; i < ngay1.thang; i++)
	{
		lechngaythang1 += a[i-1];
	}	
	lechngaythang1 = lechngaythang1 + ngay1.ngay - 1;
	
	if ( LeapYear(ngay2.nam)) a[1]=29; 
	else a[1] = 28;
	for(int i = 1; i < ngay2.thang; i++)
	{
		lechngaythang2 += a[i-1];
	}	
	lechngaythang2 = lechngaythang2 + ngay2.ngay - 1;
	
	int khoangcachngay = dateOfYear + lechngaythang2 - lechngaythang1;
	return khoangcachngay;
}
int SoSanhNgay(NGAY_THANG nt1, NGAY_THANG nt2)
{
	return (tinhNgay(nt2) - tinhNgay(nt1));
}

