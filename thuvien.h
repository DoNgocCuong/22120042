#pragma once
#include<iostream>
#include<fstream>
#include<string.h>
#include<cstring>
#include<stdlib.h>
#include<windows.h>
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




void Init_hk(year*& head);
void nhapdsMH(monhoc*& head, char file[]);
void Init_class(year*& head);
void newclass(dslop*& head, char* ten);
void read_file_dslop(dslop*& head);
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
void themmonhoc1(monhoc*& head, monhoc* newNode);
void themmonhoc(monhoc*& head);
hocki* newhk();
void them1hocki(hocki*& head);
void them1hocki(hocki*& head, hocki* newNode);
void Xuat(ttsv* head);
void xoa1sv(thongtinsv*& head, int mssv);
void see_class_list(dslop* head);
void noichuoi(char a[], char b[]);
void see_list_of_subjects(hocki* head, int x);
void see_the_list_of_students_of_all_subjects(hocki* head, int x);
void see_the_list_of_students_in_class(dslop* head);
void pop_student(dslop* head);
void popclass(dslop*& head);
void popsubject(monhoc*& head);
dslop* newlop();
void pop_student(dslop* head);
void push_student(dslop *& head);
void themsvmh(ttsv*& head, ttsv* newNode);
void push_student_subject(monhoc*& head);
void pop_student_subject(monhoc*& head);
void output_the_resul_file(monhoc* head);
void update_subject_scores(monhoc*& head);
void take_a_look_at_the_score(hocki* head);
void see_my_list_of_subjects(monhoc* head, int mssv);
void see_class_grades(year* head);
void duyetdiem(ttsv* head, int mssv);
void read_file_subject(monhoc* head);
void write_student_subject(ttsv* head, char file[]);
void write_student_class(thongtinsv* head, char file[]);
void write_file_class(dslop* head);
void push_class(dslop*& head);
void write_file_password(Login* head, char file[]);
void textColor(int a);