#include "thuvien.h"
/* PHAN DANG NHAP */
//////////////////////////////////////////////////////////////////////////////////////////////
int newlogin(Login * headsv,Login *headgv) {
    cout << "=======================================================================" << endl;
    cout << "=                   CHAO MUNG BAN DEN VOI HE THONG                    =  " << endl;
    cout << "=       QUAN LI SINH THONG TIN VA KET QUA HOC TAP CUA SINH VIEN       =" << endl;
    cout << "=======================================================================" << endl;
    cout << "  BAN LA AI" << endl;
    cout << "1/SINH VIEN" << endl;
    cout << "2/GIANG VIEN" << endl;
    int n,a,b,tmp; cout << "nhap lua chon cua ban:"; cin >> n;
    while (n > 2 || n < 0) {
        cout << "lua chon khong hop le vui long nhap lai:";
        cin >> n;
    }
    if (n == 1) {
        tmp = dangnhap(headsv);
        b = 1;
        while (b != 0) {
            MENUsv();
            cin >> a;
            while (a != 0) {
                if (a == 1) {

                }
                else if (a == 2) {
                    doiMK(headsv,tmp);
                    break;
                }
            }
        }
    }
    else {
        tmp = dangnhap(headgv);
        b = 1;
        while (b != 0) {
            MENUgv();
            cin >> a;
            while (a != 0) {
                if (a == 1) {

                }
                else if (a == 2) {
                    doiMK(headgv,tmp );
                    break;
                }
            }
        }
    }
    return tmp;
}
//kiem tra tai khoan mat khau co ton tai khong
bool check(Login* head, int mssv,int mk) {
    int dem = 0;
    while (head != NULL) {
        if (mssv == head->tkhoan&& mk==head->mkhau) {
            dem++;
        }
        head = head->next;
    }
    if (dem != 0) {
        return true;
    }
    else {
        return false;
    }
}
int dangnhap(Login* head) {
    int mssv, mk;
    cout << "                        DANG NHAP                     " << endl;
    cout << "nhap tai khoan:";
    cin >> mssv;
    cout << "nhap mat khau:"; cin >> mk;
    while (check(head, mssv, mk) == false) {
        cout << "thong tin dang nhap khong chinh xac vui long nhap lai:" << endl;
        cout << "nhap tai khoan:"; cin >> mssv;
        cout << "nhap mat khau:"; cin >> mk;
    }
    return mssv;
}
//doc file tai khoan mat khau hoc sinh vao bo nho
void docfilesv(Login*& headsv) {
    int n, tk, mk;
    ifstream file;
    file.open("thongtindangnhapsv.txt");
    file >> n;
    for (int i = 1; i <= n; i++) {
        file >> tk;
        file >> mk;
        pushBack(headsv,tk, mk);
    }
    file.close();
}
//doc file tai khoan mat khau cua giao vien vao bo nho
void docfilegv(Login*& headgv) {
    int n, tk, mk;
    ifstream file;
    file.open("thongtindangnhapgv.txt");
    file >> n;
    for (int i = 1; i <= n; i++) {
        file >> tk;
        file >> mk;
        pushBack(headgv, tk, mk);
    }
    file.close();
}
//tao 1 tai khoan
Login* makeLogin(int tk, int mk) {
    Login* newLogin;
    newLogin = new Login;
    newLogin->tkhoan = tk;
    newLogin->mkhau = mk;
    newLogin->next = NULL;
    return newLogin;
}
//them 1 tai khoan 
void pushBack(Login*& head,int tk,int mk) {
    Login* newNode = makeLogin(tk, mk);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Login* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
void xuat(Login* head) {
    while (head != NULL) {
        cout << head->tkhoan << "     " << head->mkhau << endl;
        head = head->next;
    }
}
void MENUsv() {
    cout << "======================================================================" << endl;
    cout << "=                    BAN MUON LUA CHON GI:                           =" << endl;
    cout << "=                  1/xem thong tin cua minh                          =" << endl;
    cout << "=                  2/doi mat khau                                    =" << endl;
    cout << "======================================================================" << endl;
    cout << "nhap su lua chon cua ban:";
}
void MENUgv() {
    cout << "===============================================================================" << endl;
    cout << "=                   LUA CHON CUA THAY CO LA GI                                =" << endl;
    cout << "=                      1/xem danh sach cac lop                                =" << endl;
    cout << "=                      2/xem danh sach hoc sinh trong lop                     =" << endl;
    cout << "=                      3/xem danh sach cac mon hoc                            =" << endl;
    cout << "=                      4/xem  danh sach hoc sinh trong moi mon hoc            =" << endl;
    cout << "=                      5/xuat danh sach sinh vien trong khoa hoc ra file csv  =" << endl;
    cout << "=                      6/cap nhap diem mon hoc                                =" << endl;
    cout << "=                      7/xem ket qua 1 mon hoc                                =" << endl;
    cout << "=                      8/xem ket qua 1 lop hoc                                =" << endl;
    cout << "=                      9/tao them mon hoc                                     =" << endl;
    cout << "=                      10/xoa 1 lop hoc                                       =" << endl;
    cout << "=                      11/xoa mot mon hoc                                     =" << endl;
    cout << "=                      12/them 1 sinh vien vao khoa hoc                       =" << endl;
    cout << "=                      13/xoa 1 sinh vien ra khoi khoa hoc                    =" << endl;
    cout << "=                      14/doi mat khau                                        =" << endl;
    cout << "===============================================================================" << endl;
    cout << "nhap su lua chon cua thay co:";
}
//doi mat khau
void doiMK(Login* head,int mssv){
    int tmp1, tmp2, tmp;
    cout << "nhap lai mat khau cu:";
    cin >> tmp;
    while (head->tkhoan != mssv) {
        head = head->next;
    }
    cout << "nhap mat khau moi:";
    cin >> tmp1;
    cout << "nhap lai mat khau moi:";
    cin >> tmp2;
    while (tmp != head->mkhau) {
        cout << "mat khau cu khoong hop le vui long nhap lai:";
        cin >> tmp;
    }
    while (tmp1 != tmp2) {
        cout << "mat khau moi khong trung nhau vui long nhap lai:" << endl;
        cout << "nhap mat khau moi:";
        cin >> tmp1;
        cout << "nhap lai mat khau moi:";
        cin >> tmp2;
    }
    head->mkhau = tmp1;
    cout << "doi mat khau thanh cong:" << endl;
}
/*XONG PHAN DANG NHAP*/
/*PHAN TAO NAM HOC MOI BAO GOM CAC LOP VA TAI DANH SACH SINH VIEN CUA TUNG LOP LEN*/
//////////////////////////////////////////////////////////////////////////////////////////////
//them lop moi
dslop* newlop() {
    cout << "nhap ten lop can them vao:";
    char tmp[max];
    dslop* newNode = new dslop;
    cin.ignore();
    cin.getline(tmp, 50);
    newNode->tenlop = new char[strlen(tmp) + 1];
    strcpy_s(newNode->tenlop, strlen(tmp) + 1, tmp);
    cout << "nhap link file danh sach hoc sinh cua lop " << newNode->tenlop << ":";
    char file[max];
    cin.getline(file, max);
    newNode->thongtinsv = NULL;
    nhapdshs(file, newNode->thongtinsv);
    newNode->next = NULL;
    return newNode;
}
//them nam moi
year* newyear() {
    year *newNode = new year;
    cout << "nhap nam hoc:";
    char tmp[max];
    cin.ignore();
    cin.getline(tmp, max);
    newNode->nam = new char[strlen(tmp) + 1];
    strcpy_s(newNode->nam, strlen(tmp) + 1, tmp);
    cout << "so luong lop cua nam hoc:";
    int n;
    cin >> n;
    newNode->dslop = NULL;
    for (int i = 0; i < n; i++) {
        them1lop(newNode->dslop, newlop());
    }
    newNode->next = NULL;
    return newNode;
}
//them 1 nam hoc bao gom ca cac lop va danh sach cac lop
void themnamhoc(year*& head) {
    year* newNode;
    newNode = newyear();
    if (head == NULL) {
        head = newNode;
        return;
    }
    year* tmp = head;
    while (tmp->next == NULL) {
        tmp = tmp->next;
    }
    tmp->next = newyear();
}
int dem(char file[]) {
    int dem = 0;
    ifstream read(file, ios::in);
    if (read.is_open()) {
        while (!read.eof()) {
            char x[max];
            read.getline(x, max);
            if (strlen(x) != 0) {
                dem++;
            }
        }
    }
    read.close();
    return dem;
}
//chuyen doi char sang int 
int  doi(char a[]) {
    int tmp = 0;
    for (int i = 0; i < strlen(a); i++) {
        tmp = tmp * 10 + (a[i] - '0');
    }
    return tmp;
}
void nhapdshs(char file[], thongtinsv*&head) {
    ifstream read(file, ios::in);
    if (read.is_open()) {
        for (int i = 0; i < dem(file); i++) {
            thongtinsv* newNode;
            newNode = new thongtinsv;
            char tmp[max];
            read.getline(tmp, max, ',');
            newNode->mssv = doi(tmp);
            read.getline(tmp, max, ',');
            newNode->tensv = new char[strlen(tmp) + 1];
            strcpy_s(newNode->tensv, strlen(tmp)+1, tmp);
            read.getline(tmp, max, ',');
            newNode->ngaysinh = doi(tmp);
            read.getline(tmp, max, ',');
            newNode->thangsinh = doi(tmp);
            read.getline(tmp, max, ',');
            newNode->namsinh = doi(tmp);
            read.getline(tmp, max);
            newNode->khoa = new char[strlen(tmp) + 1];
            strcpy_s(newNode->khoa, strlen(tmp) + 1, tmp);
            newNode->next = NULL;
            them1sv(head, newNode);
        }
    }
}
void them1sv(thongtinsv*& head, thongtinsv* x) {
    if (head == NULL) {
        head = x;
        return;
    }
    thongtinsv*tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = x;
}
void them1lop(dslop*& head, dslop*x) {
    if (head == NULL) {
        head = x;
        return;
    }
    dslop*tmp=head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = x;
}
////////////////////////////////////////////////////////////////////////////////////////
/*XONG PHAN TAO NAM HOC*/
/*TAO CAC MON HOC TRONG NAM  VA TAI DANH SACH CAC SINH VIEN TRONG TUNG KHOA HOC*/
///////////////////////////////////////////////////////////////////////////////////////////
void them1svmh(ttsv*& head, ttsv* x) {
    if (head == NULL) {
        head = x;
        return;
    }
    ttsv* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = x;
}
void nhapds(ttsv*& head,char file[]) {
    ifstream read(file, ios::in);
    if (read.is_open()) {
        
        for (int i = 0; i < dem(file); i++) {
            ttsv* newNode;
            char tmp[max];
            newNode = new ttsv;
            read.getline(tmp, max, ',');
            newNode->mssv = doi(tmp);
            read.getline(tmp, max);
            newNode->ten = new char(strlen(tmp) + 1);
            strcpy_s(newNode->ten, strlen(tmp) + 1, tmp);
            newNode->next = NULL;
            them1svmh(head, newNode);
        }
    }
    read.close();
}
monhoc* newmonhoc() {
    monhoc* newNode;
    newNode = new monhoc;
    cout << "nhap id mon hoc:";
    cin >> newNode->id;
    char tmp[max];
    cout << "nhap ten mon hoc:";
    cin.ignore();
    cin.getline(tmp, max);
    newNode->tenmh = new char[strlen(tmp) + 1];
    strcpy_s(newNode->tenmh, strlen(tmp) + 1, tmp);
    cout << "nhap ten lop hoc:";
    cin.getline(tmp, max);
    newNode->tenlop = new char[strlen(tmp) + 1];
    strcpy_s(newNode->tenlop, strlen(tmp) + 1, tmp);
    cout << "nhap ten giao vien:";
    cin.getline(tmp, max);
    newNode->tengv = new char[strlen(tmp) + 1];
    strcpy_s(newNode->tengv, strlen(tmp) + 1, tmp);
    cout << "nhap so tin chi:";
    cin >> newNode->sotin;
    cout << "nhap ngay hoc:";
    cin.ignore();
    cin.getline(tmp, max);
    newNode->ngayhoc = new char[strlen(tmp) + 1];
    strcpy_s(newNode->ngayhoc, strlen(tmp) + 1, tmp);
    cout << "nhap gio hoc:";
    cin.getline(tmp, max);
    newNode->tgian = new char[strlen(tmp) + 1];
    strcpy_s(newNode->tgian, strlen(tmp) + 1, tmp);
    newNode->ttsv = NULL;
    char file[max];
    cout << "nhap link danh sach " << newNode->tenmh << ":";
    cin.ignore();
    cin.getline(file, max);
    nhapds(newNode->ttsv, file);
    newNode->next = NULL;
    return newNode;
}
void themmonhoc(monhoc*& head) {
    monhoc* newNode = newmonhoc();
    if (head == NULL) {
        head = newNode;
        return;
    }
    monhoc* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
hocki* newhk(){
    cout << "nhap hk ban muon tao trong nam:";
    hocki* newNode;
    newNode = new hocki;
    cin >> newNode->hk;
    newNode->monhoc = NULL;
    cout << "nhap so mon hoc can them:";
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        themmonhoc(newNode->monhoc);
    }
    newNode->next = NULL;
    return newNode;
}
void them1hocki(hocki*& head) {
    hocki* newNode = newhk();
    if (head == NULL) {
        head = newNode;
        return;
    }
    hocki* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
////////////////////////////////////
/// THEM sv vao 1 lop//////////////////
void push_student(thongtinsv*& head) {
    thongtinsv* newNode;
    newNode = new thongtinsv;
    cout << "nhap mssv can them vao";
    char tmp[max];
    cin>>newNode->mssv;
    cout << "nhap ten sinh vien can them vao:";
    cin.ignore();
    cin.getline(tmp, max);
    newNode->tensv = new char[strlen(tmp) + 1];
    strcpy_s(newNode->tensv, strlen(tmp) + 1, tmp);
    cout << "nhap ngay sinh:";
    cin >> newNode->ngaysinh;
    cout << "nhap thang sinh:";
    cin >> newNode->thangsinh;
    cout << "nhap nam sinh:";
    cin >> newNode->namsinh;
    cout << "nhap khoa cua sinh vien:";
    cin.getline(tmp, max);
    newNode->khoa = new char[strlen(tmp) + 1];
    strcpy_s(newNode->khoa, strlen(tmp) + 1, tmp);
    newNode->next = NULL;
    them1sv(head, newNode);
}
////////////////////////////////////////////////////
////XOA 1 SINH VIEN///////////////////////////////
void pop_student(dslop *head) { 
    cout << "nhap lop sinh vien ban muon xoa:";
    char tmp[50];
    cin.ignore();
    cin.getline(tmp, max);
    cout << "nhap mssv cua sinh vien muon xoa:";
    int id; cin >> id;
    while (strcmp(tmp, head->tenlop) != 0) {
        head = head->next;
    }
    xoa1sv(head->thongtinsv, id);
}
void xoa1sv(thongtinsv*& head, int mssv) {
    if (head->mssv == mssv) {
        thongtinsv* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    thongtinsv* tmp = head;
    while (tmp->next->mssv != mssv) {
        tmp = tmp->next;
    }
    thongtinsv* tmp1;
    tmp1 = tmp->next;
    tmp->next = tmp1->next;
    delete tmp1;
}
////////////////////////////////////////////////////
/////////////XOA 1 LOP////////////////
void popclass(dslop*& head) {
    cout << "nhap ten lop muon xoa:";
    char tmp[max];
    cin.ignore();
    cin.getline(tmp, max);
    if (strcmp(head->tenlop, tmp) == 0) {
        dslop* x;
        x = head;
        head = x->next;
        delete x;
        return;
    }
    dslop *tmp1=head;
    while (strcmp(tmp1->next->tenlop, tmp) != 0) {
        tmp1 = tmp1->next;
    }
    dslop* tmp2 = tmp1->next;
    tmp1->next = tmp2->next;
    delete tmp2;
}
/////////////////////////////////////////////////////////////
////////////// XOA MOT MON HOC//////////////
void popsubject(monhoc*& head) {
    cout << "nhap ten mon hoc muon xoa:";
    char tmp[max];
    cin.ignore();
    cin.getline(tmp, max);
    if (strcmp(head->tenlop, tmp) == 0) {
        monhoc* x;
        x = head;
        head = x->next;
        delete x;
        return;
    }
    monhoc* tmp1 = head;
    while (strcmp(tmp1->next->tenlop, tmp) != 0) {
        tmp1 = tmp1->next;
    }
    monhoc* tmp2 = tmp1->next;
    tmp1->next = tmp2->next;
    delete tmp2;
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////
/////XEM DANH SACH CAC LOP//////
void see_class_list(dslop* head) {
    int i = 0;
    cout << "danh sach cac lop hien co:" << endl;
    while (head != NULL) {
        cout <<i<<"   "<< head->tenlop << endl;
        head = head->next;
        i++;
    }
}
/////////XEM DANH SACH HOC SINH TRONG LOP////////////
void see_the_list_of_students_in_class(dslop* head) {
    int dem = 0;
    cout << "nhap lop ma thay co muon xem danh sach:";
    char tmp[max];
    cin.ignore();
    cin.getline(tmp, max);
    while (dem != 0) {
        dslop* x = head;
        while(x != NULL) {
            if (strcmp(tmp, x->tenlop) == 0) {
                dem++;
                cout << "danh sach lop " << tmp << " la:" << endl;
                while (x->thongtinsv != NULL) {
                    cout << x->thongtinsv->mssv << "   " << x->thongtinsv->tensv << "   " << x->thongtinsv->ngaysinh << "/" << x->thongtinsv->thangsinh << "/" << x->thongtinsv->namsinh << "   " << x->thongtinsv->khoa << endl;
                    x->thongtinsv = x->thongtinsv->next;
                }
                return;
            }
            x = x->next;
        }
        if (dem == 0) {
            cout << "lop thay co tim kiem hien khong co" << endl;
        }
    }
}
///////////////////XEM DANH SACH CAC MON HOC/////////////////////////
void see_list_of_subjects(hocki* head) {
    cout << "nhap hoc ki ma cac thay co muon xem:";
    int x; cin >> x;
    while (x > 3 || x < 0) {
        cout << "hoc ki thay co nhap khong hop le vui long nhap lai:";
        cin >> x;
    }
    hocki* tmp = head;
    cout << "danh sach cac mon hoc cua hoc ki " << x << " la:" << endl;
    while (tmp != NULL) {
        if (tmp->hk == x) {
            while (tmp->monhoc != NULL) {
                cout << tmp->monhoc->tenmh << endl;
                tmp->monhoc = tmp->monhoc->next;
            }
            return;
        }
        tmp = tmp->next;
    }
}
///////////////XEM DANH SACH HOC SINH TRONG CAC MON HOC////////////////////
void see_the_list_of_students_of_all_subjects(hocki* head) {
    int dem = 0;
    cout << "nhap hoc ki ma cac thay co muon xem:";
    int x; cin >> x;
    while (x > 3 || x < 0) {
        cout << "hoc ki thay co nhap khong hop le vui long nhap lai:";
        cin >> x;
    }
    char tmp1[max];
    cout << "nhap mon hoc ma thay co muon xem danh sach:";
    cin.ignore();
    cin.getline(tmp1, max);
    hocki* tmp = head;
    cout << "danh sach cac sinh vien cua mon "<<tmp1<< " la:" << endl;
    while (dem != 0) {
        while (tmp != NULL) {
            if (tmp->hk == x) {
                while (tmp->monhoc != NULL) {
                    if (strcmp(tmp1, tmp->monhoc->tenmh) == 0) {
                        dem++;
                        while (tmp->monhoc->ttsv != NULL) {
                            cout << tmp->monhoc->ttsv->mssv << "   " << tmp->monhoc->ttsv->ten << endl;
                            tmp->monhoc->ttsv = tmp->monhoc->ttsv->next;
                        }
                        return;
                    }
                    tmp->monhoc = tmp->monhoc->next;
                }
            }
            tmp = tmp->next;
        }
        if (dem == 0) {
            cout << "mon hoc thay co tim kiem khong co,moi thay co nhap lai:";
            cin.getline(tmp1, max);
        }
    }
}
/////////////////////////// XEM KET QUA MOT MON HOC/////////////////////
void take_a_look_at_the_score(hocki* head) {
    int dem = 0;
    cout << "nhap hoc ki ma cac thay co muon xem:";
    int x; cin >> x;
    while (x > 3 || x < 0) {
        cout << "hoc ki thay co nhap khong hop le vui long nhap lai:";
        cin >> x;
    }
    char tmp1[max];
    cout << "nhap mon hoc ma thay co muon xem danh sach:";
    cin.ignore();
    cin.getline(tmp1, max);
    hocki* tmp = head;
    cout << "danh sach cac sinh vien cua mon " << tmp1 << " la:" << endl;
    while (dem != 0) {
        while (tmp != NULL) {
            if (tmp->hk == x) {
                while (tmp->monhoc != NULL) {
                    if (strcmp(tmp1, tmp->monhoc->tenmh) == 0) {
                        dem++;
                        while (tmp->monhoc->ttsv != NULL) {
                            cout << tmp->monhoc->ttsv->mssv << "   " << tmp->monhoc->ttsv->ten << "   " << tmp->monhoc->ttsv->tongdiem << "   " << tmp->monhoc->ttsv->ck << "   " << tmp->monhoc->ttsv->gk << "     " << endl;
                            tmp->monhoc->ttsv = tmp->monhoc->ttsv->next;
                        }
                        return;
                    }
                    tmp->monhoc = tmp->monhoc->next;
                }
            }
            tmp = tmp->next;
        }
        if (dem == 0) {
            cout << "mon hoc thay co tim kiem khong co,moi thay co nhap lai:";
            cin.getline(tmp1, max);
        }
    }
}