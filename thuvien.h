#pragma once
#include<iostream>
#include<fstream>
#include<string.h>
#define max 100
using namespace std;
struct Login {
	int tkhoan;
	int mkhau;
	Login* next;
};
struct thongtinsv {
	int mssv;
	char* tensv;
	int ngaysinh;
	int thangsinh;
	int namsinh;
	char *khoa;
	thongtinsv* next;
};
struct dslop {
	char* tenlop;
	thongtinsv *thongtinsv;
	dslop* next;
};
struct ttsv{
	int mssv;
	char* ten;
	char* tongdiem;
	char* ck;
	char* gk;
	ttsv* next;
};
struct monhoc {
	int id;
	char* tenmh;
	char* tenlop;
	char* tengv;
	int sotin;
	int sosvtd = 50;
	char* ngayhoc;
	char* tgian;
	ttsv* ttsv;
	monhoc* next;
};
struct hocki{
	int hk;
	monhoc* monhoc;
	hocki *next;
};
struct year {
	char* nam;
	dslop *dslop;
	hocki *hk;
	year* next;
};




int newlogin(Login *headsv,Login *headgv);
bool check(Login* head, int mssv);
int dangnhap(Login* head);
void docfilesv(Login*& headsv);
void docfilegv(Login*& headgv);
Login* makeLogin(int tk, int mk);
void pushBack(Login*& head, int tk, int mk);
void xuat(Login* head);
void MENUsv();
void MENUgv(); 
void doiMK(Login* head, int mssv);
int  doi(char a[]);
dslop* newlop();
year* newyear();
void themnamhoc(year*& head);
int  doi(char a[]);
void nhapdshs(char file[], thongtinsv*&head);
void them1sv(thongtinsv*& head, thongtinsv* x);
void them1lop(dslop*& head, dslop* x);
int dem(char file[]);
void them1svmh(ttsv*& head, ttsv* x);
void nhapds(ttsv*& head, char file[]);
monhoc* newmonhoc();
void themmonhoc(monhoc*& head);
hocki* newhk();
void them1hocki(hocki*& head);
void Xuat(ttsv* head);