#include "thuvien.h"
/* PHAN DANG NHAP */
//////////////////////////////////////////////////////////////////////////////////////////////
void Init_class(year*& head) {
    head->nam = new char[10];
    char ten[max];
    strcpy_s(head->nam, 10, "2022-2023");
    head->dslop = NULL;
    int n = 0;
    ifstream read("danhsachlop2022-2023.CSV");
    while (!read.eof()) {
        read.getline(ten, max, ',');
        newclass(head->dslop, ten);
    }
    read.close(); 
    head->hk = NULL;
    head->next = NULL;
}
void newclass(dslop*& head, char ten[]) {
    dslop* tmp = new dslop;
    tmp->tenlop = new char[strlen(ten) + 1];
    strcpy_s(tmp->tenlop, strlen(ten) + 1, ten);
    tmp->thongtinsv = NULL;
    char tmp1[max] = ".CSV";
    char tmp2[max] = "danhsachlop";
    noichuoi(tmp2, ten);
    noichuoi(tmp2, tmp1);
    nhapdshs(tmp2, tmp->thongtinsv);
    tmp->next = NULL;
    if (head == NULL) {
        head = tmp;
        return;
    }
    dslop* tmpp = head;
    while (tmpp->next != NULL) {
        tmpp = tmpp->next;
    }
    tmpp->next = tmp;
}
void Init_hk(year*& head) {
    hocki* newNode = new hocki;
    newNode->hk = 1;
    newNode->monhoc = NULL;
    newNode->next = NULL;
    char link[max] = "danhsachlinkmonhoc2022-2023.CSV";
    nhapdsMH(newNode->monhoc,link);
    them1hocki(head->hk,newNode);
}
void nhapdsMH(monhoc*& head, char file[]) {
   
    ifstream read(file, ios::in);
    if (read.is_open()) {
        for (int i = 0; i < dem(file); i++) {
            char link[max] = "danhsachmon";
            monhoc* newNode;
            char tmp[max];
            newNode = new monhoc;
            read.getline(tmp, max, ',');
            newNode->id = doi(tmp);
            read.getline(tmp, max,',');
            noichuoi(link, tmp);
            newNode->tenmh = new char[strlen(tmp) + 1];
            strcpy_s(newNode->tenmh, strlen(tmp) + 1, tmp);
            read.getline(tmp, max, ',');
            newNode->tenlop = new char[strlen(tmp) + 1];
            strcpy_s(newNode->tenlop, strlen(tmp) + 1, tmp);
            read.getline(tmp, max, ',');
            newNode->tengv = new char[strlen(tmp) + 1];
            strcpy_s(newNode->tengv, strlen(tmp) + 1, tmp);
            read.getline(tmp, max, ',');
            newNode->sotin = doi(tmp);
            read.getline(tmp, max, ',');
            newNode->ngayhoc = new char[strlen(tmp) + 1];
            strcpy_s(newNode->ngayhoc, strlen(tmp) + 1, tmp);
            read.getline(tmp, max);
            newNode->tgian = new char[strlen(tmp) + 1];
            strcpy_s(newNode->tgian, strlen(tmp) + 1, tmp); 
            char link1[max] = ".CSV";
            noichuoi(link, link1);
            newNode->ttsv = NULL;
            nhapds(newNode->ttsv, link);
            newNode->next = NULL;
            themmonhoc1(head, newNode);
        }
    }
    else {
        cout << "link khong duoc mo";
        return;
    }
    read.close();
    
}

void nhapds(ttsv*& head, char file[]) {
    ifstream read(file, ios::in);
    if (read.is_open()) {
        for (int i = 0; i < dem(file); i++) {
            ttsv* newNode = new ttsv;
            char tmp[max];
            read.getline(tmp, max, ',');
            newNode->mssv = doi(tmp);
            read.getline(tmp, max);
            newNode->ten = new char[strlen(tmp) + 1];
            strcpy_s(newNode->ten, strlen(tmp) + 1, tmp);
            newNode->gk = NULL;
            newNode->ck = NULL;
            newNode->tongdiem = NULL;
            newNode->next = NULL;
           them1svmh(head, newNode);
        }
    }
    else {
        cout << "file " << file << " khong duoc mo";
    }
    read.close();
}
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
void them1sv(thongtinsv*& head, thongtinsv* x) {
    if (head == NULL) {
        head = x;
        return;
    }
    thongtinsv* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = x;
}
void nhapdshs(char file[], thongtinsv*& head) {
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
            strcpy_s(newNode->tensv, strlen(tmp) + 1, tmp);
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
    else {
        cout << "file khong duoc mo:" << endl;
    }
}
//////////////////////////////////////////
void MENUsv() {
    cout << endl << endl << endl << endl << endl;
    cout << "                         ======================================================================" << endl;
    cout << "                         =                    BAN MUON LUA CHON GI:                           =" << endl;
    cout << "                         =                  1/xem thong tin cua minh                          =" << endl;
    cout << "                         =                  2/doi mat khau                                    =" << endl;
    cout << "                         =                  3/thoat                                           =" << endl;
    cout << "                         ======================================================================" << endl;
    textColor(12);
    cout << "                         nhap su lua chon cua ban:";
}
void MENUgv() {
    textColor(10);
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
    cout << "=                      10/ them 1 lop                                         =" << endl;
    cout << "=                      11/xoa 1 lop hoc                                       =" << endl;
    cout << "=                      12/xoa mot mon hoc                                     =" << endl;
    cout << "=                      13/them 1 sinh vien vao khoa hoc                       =" << endl;
    cout << "=                      14/xoa 1 sinh vien ra khoi khoa hoc                    =" << endl;
    cout << "=                      15/them sinh vien vao 1 lop                            =" << endl;
    cout << "=                      16/xoa sinh vien ra khoi lop                           =" << endl;
    cout << "=                      17/doi mat khau                                        =" << endl;
    cout << "=                      18/thoat                                               =" << endl;
    cout << "===============================================================================" << endl;
    textColor(12);
    cout << "nhap su lua chon cua thay co:";
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
    cout << endl << endl << endl << endl << endl;
    cout << "                               DANG NHAP                     " << endl;
    textColor(12);
    cout << "   nhap tai khoan:";
    textColor(7);
    cin >> mssv;
    textColor(12);
    cout << "   nhap mat khau:";  textColor(7);  cin >> mk;
    while (check(head, mssv, mk) == false) {
        textColor(12);
        cout << "thong tin dang nhap khong chinh xac vui long nhap lai:" << endl;
        cout << "nhap tai khoan:"; textColor(7);
        cin >> mssv;
        textColor(12);
        cout << "nhap mat khau:"; textColor(7);
        cin >> mk;
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
//doi mat khau
void doiMK(Login* head,int mssv){
    int tmp1, tmp2, tmp;
    cout << endl << endl << endl << endl << endl;
    textColor(12);
    cout << "                      nhap lai mat khau cu:";
    textColor(7);
    cin >> tmp;
    while (head->tkhoan != mssv) {
        head = head->next;
    }
    textColor(12);
    cout << "                      nhap mat khau moi:";
    textColor(7);
    cin >> tmp1;
    textColor(12);
    cout << "                      nhap lai mat khau moi:";
    textColor(7);
    cin >> tmp2;
    while (tmp != head->mkhau) {
        textColor(12);
        cout << "                      mat khau cu khong hop le vui long nhap lai:";
        textColor(7);
        cin >> tmp;
    }
    while (tmp1 != tmp2) {
        textColor(12);
        cout << "                      mat khau moi khong trung nhau vui long nhap lai:" << endl;
        cout << "                      nhap mat khau moi:";
        textColor(7);
        cin >> tmp1;
        textColor(12);
        cout << "                      nhap lai mat khau moi:";
        textColor(7);
        cin >> tmp2;
    }
    head->mkhau = tmp1;
    textColor(10);
    cout << "                      doi mat khau thanh cong:" << endl;
}
/*XONG PHAN DANG NHAP*/
/*PHAN TAO NAM HOC MOI BAO GOM CAC LOP VA TAI DANH SACH SINH VIEN CUA TUNG LOP LEN*/
//////////////////////////////////////////////////////////////////////////////////////////////
//them lop moi
dslop* newlop() {
    cout << endl << endl << endl << endl << endl << endl;
    textColor(12);
    cout << "nhap ten lop can them vao:";
    char tmp[max];
    textColor(7);
    dslop* newNode = new dslop;
    cin.ignore();
    cin.getline(tmp, 50);
    newNode->tenlop = new char[strlen(tmp) + 1];
    strcpy_s(newNode->tenlop, strlen(tmp) + 1, tmp);
    textColor(12);
    cout << "nhap link file danh sach hoc sinh cua lop " << newNode->tenlop << ":";
    char file[max];
    textColor(7);
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
    tmp->next = newNode;
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
    write_student_class(tmp->next->thongtinsv,tmp->next->tenlop);
}
void push_class(dslop*& head) {
    dslop* newNode;
    newNode = newlop();
    dslop* tmp = head;
    them1lop(tmp, newNode);
    write_file_class(head);
}
////////////////////////////////////////////////////////////////////////////////////////
/*XONG PHAN TAO NAM HOC*/
/*TAO CAC MON HOC TRONG NAM  VA TAI DANH SACH CAC SINH VIEN TRONG TUNG KHOA HOC*/
///////////////////////////////////////////////////////////////////////////////////////////

monhoc* newmonhoc() {
    monhoc* newNode;
    newNode = new monhoc;
    textColor(12);
    cout << "nhap id mon hoc:";
    textColor(7);
    cin >> newNode->id;
    char tmp[max];
    textColor(12);
    cout << "nhap ten mon hoc:";
    textColor(7);
    cin.ignore();
    cin.getline(tmp, max);
    newNode->tenmh = new char[strlen(tmp) + 1];
    strcpy_s(newNode->tenmh, strlen(tmp) + 1, tmp);
    textColor(12);
    cout << "nhap ten lop hoc:";
    textColor(7);
    cin.getline(tmp, max);
    newNode->tenlop = new char[strlen(tmp) + 1];
    strcpy_s(newNode->tenlop, strlen(tmp) + 1, tmp);
    textColor(12);
    cout << "nhap ten giao vien:";
    textColor(7);
    cin.getline(tmp, max);
    newNode->tengv = new char[strlen(tmp) + 1];
    strcpy_s(newNode->tengv, strlen(tmp) + 1, tmp);
    textColor(12);
    cout << "nhap so tin chi:";
    textColor(7);
    cin >> newNode->sotin;
    textColor(12);
    cout << "nhap ngay hoc:";
    textColor(7);
    cin.ignore();
    cin.getline(tmp, max);
    newNode->ngayhoc = new char[strlen(tmp) + 1];
    strcpy_s(newNode->ngayhoc, strlen(tmp) + 1, tmp);
    textColor(12);
    cout << "nhap gio hoc:";
    textColor(7);
    cin.getline(tmp, max);
    newNode->tgian = new char[strlen(tmp) + 1];
    strcpy_s(newNode->tgian, strlen(tmp) + 1, tmp);
    newNode->ttsv = NULL;
    char file[max];
    textColor(12);
    cout << "nhap link danh sach " << newNode->tenmh << ":";
    textColor(7);
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
    read_file_subject(head);
    write_student_subject(newNode->ttsv, newNode->tenmh);
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
void them1hocki(hocki*& head,hocki*newNode) {
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    hocki* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}/////////////////////////////////////////
/////////THEM SINH VIEN VAO 1 MON HOC//////
void push_student_subject(monhoc*& head) {
    textColor(12);
    cout << endl << endl << endl << endl << endl;
    cout << "nhap mon hoc ma ban can them vao:";
    textColor(7);
    char tenmh[max];
    cin.ignore();
    cin.getline(tenmh, max);
    monhoc* tail = head;
    while (tail != NULL) {
        if (strcmp(tail->tenmh, tenmh) == 0) {
            break;
        }
        tail = tail->next;
    }
    ttsv* sv = new ttsv;
    textColor(12);
    cout << "nhap ma so sinh vien:";
    textColor(7);
    cin >> sv->mssv;
    textColor(12);
    cout << "nhap ho va ten sinh vien:";
    textColor(7);
    char tmp[max];
    cin.ignore();
    cin.getline(tmp, max);
    sv->ten = new char[strlen(tmp) + 1];
    strcpy_s(sv->ten, strlen(tmp) + 1, tmp);
    sv->tongdiem = NULL;
    sv->ck = NULL;
    sv->gk = NULL;
    sv->next = NULL;
    themsvmh(tail->ttsv, sv);
    write_student_subject(tail->ttsv, tail->tenmh);
}
///them sinh vien vao mon hoc///
void themsvmh(ttsv*& head, ttsv* newNode) {
    if (head == NULL) {
        head = newNode;
        return;
    }
    ttsv* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}///////////////////XOA SINH VIEN KHOI MON HOC///////
void pop_student_subject(monhoc*& head) {
    cout << endl << endl << endl << endl << endl << endl;
    textColor(12);
    cout << "nhap mon hoc co sinh vien can xoa:";
    textColor(7);
    char mh[max], name[max];
    cin.ignore();
    cin.getline(mh, max);
    monhoc* tmp = head;
    int dem = 0, mssv;
    cout << mh << endl;
    while (tmp != NULL) {
        if (strcmp(tmp->tenmh, mh) == 0) {
            dem++;
            break;
        }
        tmp = tmp->next;
    }
    if (dem == 0) {
        textColor(12);
        cout << "mon hoc thay co vua nhap hien khong co" << endl;
        return;
    }
    dem = 0;
    textColor(12);
    cout << "nhap ma so sinh vien can xoa:";
    textColor(7);
    cin >> mssv;
    textColor(12);
    cout << "nhap ten sinh vien can xoa:";
    textColor(7);
    cin.ignore();
    cin.getline(name, max);
    cout << name << endl; 
    ttsv* tail = tmp->ttsv;
    while (tail != NULL) {
        if (strcmp(tail->next->ten, name) == 0 && tail->next->mssv == mssv) {
            dem++;
            break;
        }
        tail = tail->next;
    }
    if (dem == 0) {
        textColor(12);
        cout << "sinh vien thay co vua nhap hien khong co" << endl;
        return;
    }
    ttsv* pop = tail->next;
    tail->next = pop->next;
    delete pop; 
    write_student_subject(tmp->ttsv, tmp->tenmh);
}

////////////////////////////////////
/// THEM sv vao 1 lop//////////////////
void push_student(dslop*& head) {
    thongtinsv* newNode;
    newNode = new thongtinsv;
    textColor(12);
    cout << "nhap mssv can them vao:";
    textColor(7);
    char tmp[max];
    cin>>newNode->mssv;
    textColor(12);
    cout << "nhap ten sinh vien can them vao:";
    textColor(7);
    cin.ignore();
    cin.getline(tmp, max);
    newNode->tensv = new char[strlen(tmp) + 1];
    strcpy_s(newNode->tensv, strlen(tmp) + 1, tmp);
    textColor(12);
    cout << "nhap ngay sinh:";
    textColor(7);
    cin >> newNode->ngaysinh;
    textColor(12);
    cout << "nhap thang sinh:";
    textColor(7);
    cin >> newNode->thangsinh;
    textColor(12);
    cout << "nhap nam sinh:";
    textColor(7);
    cin >> newNode->namsinh;
    textColor(12);
    cout << "nhap khoa cua sinh vien:";
    textColor(7);
    cin.ignore();
    cin.getline(tmp, max);
    newNode->khoa = new char[strlen(tmp) + 1];
    strcpy_s(newNode->khoa, strlen(tmp) + 1, tmp);
    newNode->next = NULL;
    textColor(12);
    cout << "nhap lop can them vao:";
    textColor(7);
    cin.getline(tmp, max);
    dslop* tail = head;
    int dem = 0;
    while (tail != NULL) {
        if (strcmp(tmp, tail->tenlop) == 0) {
            break;
        }
        tail = tail->next;
    }
    them1sv(tail->thongtinsv, newNode);
    write_student_class(tail->thongtinsv, tmp);
}
////////////////////////////////////////////////////
////XOA 1 SINH VIEN TRONG LOP ///////////////////////////////
void pop_student(dslop *head) { 
    cout << endl << endl << endl << endl << endl << endl;
    textColor(12);
    cout << "                  nhap lop sinh vien ban muon xoa:";
    textColor(7);
    char tmp[50];
    cin.ignore();
    cin.getline(tmp, max);
    textColor(12);
    cout << "                  nhap mssv cua sinh vien muon xoa:";
    textColor(7);
    int id; cin >> id;
    while (strcmp(tmp, head->tenlop) != 0) {
        head = head->next;
    }
   
    xoa1sv(head->thongtinsv, id);
    write_student_class(head->thongtinsv, tmp);
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
    cout << endl << endl << endl << endl << endl;
    textColor(12);
    cout << "                        nhap ten lop muon xoa:";
    char tmp[max];
    cin.ignore();
    textColor(7);
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
    dslop* tail = head;
    write_file_class(tail);
}
/////////////////////////////////////////////////////////////
////////////// XOA MOT MON HOC//////////////
void popsubject(monhoc*& head) {
    cout << endl << endl << endl << endl << endl << endl;
    textColor(12);
    cout << "nhap ten mon hoc muon xoa:";
    textColor(7);
    char tmp[max];
    cin.ignore();
    cin.getline(tmp, max);
    if (strcmp(head->tenmh, tmp) == 0) {
        monhoc* x;
        x = head;
        head = x->next;
        delete x;
        return;
    }
    monhoc* tmp1 = head;
    while (strcmp(tmp1->next->tenmh, tmp) != 0) {
        tmp1 = tmp1->next;
    }
    monhoc* tmp2 = tmp1->next;
    tmp1->next = tmp2->next;
    delete tmp2;
    read_file_subject(head);
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////
/////XEM DANH SACH CAC LOP//////
void see_class_list(dslop* head) {
    int i = 0;
    textColor(12);
    cout << "                             danh sach cac lop hien co:" << endl;
    textColor(7);
    while (head != NULL) {
        cout << "                             ";
        i++;
        cout <<i<<"   "<< head->tenlop << endl;
        head = head->next;
    }
}
/////////XEM DANH SACH HOC SINH TRONG LOP////////////
void see_the_list_of_students_in_class(dslop* head) {
    int dem = 0;
    textColor(10);
    cout << "nhap lop ma thay co muon xem danh sach:";
    char tmp[max];
    cin.ignore();
    textColor(7);
    cin.getline(tmp, max);
    system("cls");
    while (1) {
        dslop* x = head;
        while(x != NULL) {
            if (strcmp(tmp, x->tenlop) == 0) {
                dem++;
                textColor(12);
                cout << "                                  danh sach lop " << tmp << " la:" << endl;
                textColor(7);
                while (x->thongtinsv != NULL) {
                    cout << x->thongtinsv->mssv << "   " << x->thongtinsv->tensv << "   " << x->thongtinsv->ngaysinh << "/" << x->thongtinsv->thangsinh << "/" << x->thongtinsv->namsinh << "   " << x->thongtinsv->khoa << endl;
                    x->thongtinsv = x->thongtinsv->next;
                }
                return;
            }
            x = x->next;
        }
        if (dem == 0) {
            textColor(10);
            cout << "lop thay co tim kiem hien khong co" << endl;
            break;
        }
    }
}
///////////////////XEM DANH SACH CAC MON HOC/////////////////////////
void see_list_of_subjects(hocki* head,int x) {
    int i = 1;
    hocki* tmp = head;
    textColor(12);
    system("cls");
    cout << "                            danh sach cac mon hoc cua hoc ki " << x << " la:" << endl;
    while (tmp != NULL) {
        if (tmp->hk == x) {
            break;
        }
        tmp = tmp->next;
    }
    monhoc* tail = head->monhoc;
    textColor(7);
    while (tail != NULL) {
        cout << tail->tenmh << endl;
        tail = tail->next;
    }
}
///////////////XEM DANH SACH HOC SINH TRONG CAC MON HOC////////////////////
void see_the_list_of_students_of_all_subjects(hocki* head,int x) {
    int dem = 1;
    hocki* tmp = head;
    char tmp1[max];
    textColor(12);
    cout << "nhap mon hoc ma thay co muon xem danh sach:";
    cin.ignore();
    textColor(7);
    cin.getline(tmp1, max);
    textColor(10);
    system("cls");
    cout << "                                danh sach cac sinh vien cua mon "<<tmp1<< " la:" << endl;
    textColor(7);
    while (tmp != NULL) {
        if (tmp->hk == x) {
            break;
        }
        tmp = tmp->next;
    }
    monhoc* tail1 = tmp->monhoc;
    while (tail1!= NULL) {
        if (strcmp(tmp1, tail1->tenmh) == 0) {
            break;
        }
        tail1 = tail1->next;
    }
    ttsv* tail = tail1->ttsv;
    while (tail != NULL) {
        cout << tail->mssv << "   " << tail->ten << endl;
        tail = tail->next;
    }
}
/////////////////////////// XEM KET QUA MOT MON HOC/////////////////////
void take_a_look_at_the_score(hocki* head) {
    int dem = 0;
    textColor(12);
    cout << "nhap hoc ki ma cac thay co muon xem:";
    textColor(7);
    int x; cin >> x;
    while (x > 3 || x < 0) {
        textColor(12);
        cout << "hoc ki thay co nhap khong hop le vui long nhap lai:";
        textColor(7);
        cin >> x;
    }
    char tmp1[max];
    textColor(12);
    cout << "nhap mon hoc ma thay co muon xem danh sach:";
    cin.ignore();
    textColor(7);
    cin.getline(tmp1, max);
    hocki* tmp = head;
    system("cls");
    textColor(10);
    cout << "                            danh sach cac sinh vien cua mon " << tmp1 << " la:" << endl;
    textColor(7);
    while (tmp != NULL) {
        if (tmp->hk == x) {
            break;
        }
        tmp = tmp->next;
    }
    monhoc* last = tmp->monhoc;
    while (last != NULL) {
        if (strcmp(last->tenmh, tmp1) == 0) {
            dem++;
            break;
        }
        last = last->next;
    }
    if (dem == 0) {
        textColor(12);
        cout << "mon hoc thay co tim kiem khong co:" << endl;
        return;
    }
    ttsv* tail = last->ttsv;
    while (tail != NULL) {
        cout << tail->mssv << "   " << tail->ten << "    " << tail->gk << "    " << tail->ck << "    " << tail->tongdiem << endl;
        tail = tail->next;
    }
}
//noi chuoi
void noichuoi(char a[], char b[]) {
    int n1, n2;
    n1 = strlen(a);
    n2 = strlen(b);
    int i, j;
    j = 0;
    for (i = n1; i < n1 + n2; i++) {
        a[i] = b[j];
        j++;
    }

    a[i] = '\0';
}
void themmonhoc1(monhoc*& head, monhoc* newNode) {
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
//////XUAT FILE DE NHAP KET QUA///////
void output_the_resul_file(monhoc* head) {
    textColor(12);
    cout << "nhap mon hoc can xuat danh sach:";
    char tenmh[max];
    cin.ignore();
    textColor(7);
    cin.getline(tenmh, max);
    char file[max] = "ket qua mon ";
    noichuoi(file, tenmh);
    char file1[max] = ".CSV";
    noichuoi(file, file1);
    monhoc* tmp = head;
    int dem = 0;
    while (tmp != NULL) {
        if (strcmp(tenmh, tmp->tenmh) == 0) {
            dem++;
            break;
        }
        tmp = tmp->next;
    }
    if (dem == 0) {
        textColor(12);
        cout << "mon hoc thay co tim kiem hien khong co" << endl; return;
    }
    ttsv* tail = tmp->ttsv;
    ofstream ketqua(file, ios::out);
    if (!ketqua.is_open()) {
        cout << "file khong duoc mo" << endl;
    }
    ketqua << "mssv" << "," << "Ho va ten" << "," << "giua ki" << "," << "cuoiki" << "," << "tong diem" << endl;
    while (tail != NULL) {
        ketqua << tail->mssv << "," << tail->ten << endl;
        tail = tail->next;
    }
    ketqua.close();
}
/////////////////////////CAP NHAP DIEM MON HOC///////////////
void update_subject_scores(monhoc*& head) {
    cout << endl << endl << endl << endl << endl << endl;
    textColor(12);
    cout << "                           nhap mon hoc thay co muon cap nhap diem:";
    char mh[max];
    cin.ignore();
    textColor(7);
    cin.getline(mh, max);
    monhoc* tmp = head;
    int dem = 0;
    while (tmp != NULL) {
        if (strcmp(tmp->tenmh, mh) == 0) {
            dem++;
            break;
        }
        tmp = tmp->next;
    }
    if (dem == 0) {
        textColor(12);
        cout << "mon hoc thay co nhap vao hien khong co" << endl;
        return;
    }
    ttsv* tmp1 = tmp->ttsv;
    char file[max];
    textColor(12);
    cout << "thay co vui long nhap link danh sach ket qua:";
    textColor(7);
    cin.getline(file, max);
    ifstream read(file, ios::in);
    if (!read.is_open()) {
        textColor(12);
        cout << "file khong mo duoc" << endl;
        return;
    }
    char tmp2[max], tmp3[max], tmp4[max], tmp5[max], tmp6[max], tmp7[max], tmp8[max];
    read.getline(tmp2, max, ','); read.getline(tmp3, max, ','); read.getline(tmp4, max, ','); read.getline(tmp5, max, ','); read.getline(tmp6, max);
     while (tmp1 != NULL) {
        read.getline(tmp8, max, ',');
        tmp1->mssv = doi(tmp8);
        read.getline(tmp1->ten, max, ',');
        read.getline(tmp8, max, ',');
        tmp1->gk = new char[strlen(tmp8) + 1];
        strcpy_s(tmp1->gk, strlen(tmp8) + 1, tmp8);
        read.getline(tmp8, max, ',');
        tmp1->ck = new char[strlen(tmp8) + 1];
        strcpy_s(tmp1->ck, strlen(tmp8) + 1, tmp8);
        read.getline(tmp8, max);
        tmp1->tongdiem = new char[strlen(tmp8) + 1];
        strcpy_s(tmp1->tongdiem, strlen(tmp8) + 1, tmp8);

        tmp1 = tmp1->next;
    }
    read.close();
}/////////////XEM DANH SACH CAC MON HOC CUA SINH VIEN///////////
void see_my_list_of_subjects(monhoc* head,int mssv) {
    textColor(10);
    cout << endl << endl << endl << endl << endl;
    cout << "id         " << "ten mon hoc     " << "ten giao vien    " << "ten lop   " << "so tin chi    " << "thoi gian hoc   " << "diem gk   " << "diem ck   " << "diem tong    " << endl;
    textColor(7);
    while (head != NULL) {
        ttsv* tmp = head->ttsv;
        while (tmp != NULL) {
            if (tmp->mssv == mssv) {
                cout << head->id << "   ";
                cout << head->tenmh << "    ";
                cout << head->tengv << "    ";
                cout << head->tenlop << "    ";
                cout << head->sotin << "     ";
                cout << head->tgian << "    ";
                if (tmp->gk == NULL) {
                    cout << endl;
                }
                if (tmp->gk != NULL) {
                    cout << tmp->gk << "     ";
                    cout << tmp->ck << "    ";
                    cout << tmp->tongdiem << "    " << endl;
                }
            }
            tmp = tmp->next;
        }
        head = head->next;
    }
}
////////////XEM DIEM CUA LOP//////////////
void see_class_grades(year* head) {
    cout << endl << endl << endl << endl << endl << endl;
    textColor(12);
    cout << "                        nhap lop thay co muon xem diem:";
    char diemlop[max];
    textColor(7);
    cin.ignore();
    cin.getline(diemlop, max);
    textColor(12);
    cout << "                        nhap mon hoc ma thay co muon xem cua lop " << diemlop << ":";
    char lop[max];
    textColor(7);
    cin.getline(lop, max);
    dslop* tmplop = head->dslop;
    monhoc* tmphk = head->hk->monhoc;
    while (tmplop != NULL) {
        if (strcmp(tmplop->tenlop, diemlop) == 0) {
            break;
        }
        tmplop = tmplop->next;
    }
    thongtinsv* taillop = tmplop->thongtinsv;
    while (tmphk != NULL) {
        if (strcmp(tmphk->tenmh, lop) == 0) {
            break;
        }
        tmphk = tmphk->next;
    }
    ttsv* tailhk = tmphk->ttsv;
    system("cls");
    textColor(10);
    cout << "                            diem cua lop " << diemlop << " la:" << endl;
    textColor(7);
    while (taillop != NULL) {
        cout << taillop->mssv << "     " << taillop->tensv << "     ";
        duyetdiem(tailhk, taillop->mssv);
        taillop = taillop->next;
    }
}
void duyetdiem(ttsv* head,int mssv) {
    while (head != NULL) {
        if (head->mssv == mssv) {
            cout  << head->gk << "    " << head->ck << "     " << head->tongdiem << endl;
            return;
        }
        head = head->next;
    }
    cout << "khong dang ki" << endl;
}
///////viet file them mon hoc va xoa monhoc//////////
void read_file_subject(monhoc* head) {
    char link[max] = "danhsachlinkmonhoc2022-2023.CSV";
    ofstream write(link, ios::out);
    if (!write.is_open()) {
        cout << "file khong duoc mo" << endl;
        return;
    }
    while (head != NULL) {
        write << head->id << "," << head->tenmh << "," << head->tenlop << "," << head->tengv << "," << head->sotin << "," << head->ngayhoc << "," << head->tgian << endl;
        head = head->next;
    }
    write.close();
}
/////////////viet file danh sach sinh vien cho cac mon hoc////
void write_student_subject(ttsv* head,char file[]) {
    char file1[50] = "danhsachmon";
    char file2[50] = ".CSV";
    noichuoi(file1, file);
    noichuoi(file1, file2);
    ofstream write(file1, ios::out);
    if (!write.is_open()) {
        cout << "file khong duoc mo" << endl;
        return;
    }
    while (head != NULL) {
        write << head->mssv << "," << head->ten << endl;
        head = head->next;
    }
}
////////////viet ham viet lai file cho ham xoa,them sinh vien
void write_student_class(thongtinsv* head,char file[]) {
    char link[max] = "danhsachlop";
    char link1[max] = ".CSV";
    noichuoi(link, file);
    noichuoi(link, link1);
    cout <<  link << endl;
    ofstream write(link, ios::out);
    if (!write.is_open()) {
        cout << "file khong duoc mo" << endl;
        return;
    }
    while (head != NULL) {
        write << head->mssv << "," << head->tensv << "," << head->ngaysinh << "," << head->thangsinh << "," << head->namsinh << "," << head->khoa << endl;
        head = head->next;
    }
    write.close();
}
void write_file_class(dslop* head) {
    char link[max] = "danhsachlop2022-2023.CSV";
    ofstream write(link, ios::out);
    if (!write.is_open()) {
        textColor(12);
        cout << "file khong duoc mo" << endl;
        return;
    }
    while (head != NULL) {
        write << head->tenlop;
        head = head->next;
        if (head != NULL) {
            write << ",";
        }
    }
    write.close();
}
////////////////////////hHAM VIET LAI FILE DOI MK GIAO VIEN
void write_file_password(Login *head,char file[]) {
    Login* tmp = head;
    int dem = 0;
    while (tmp != NULL) {
        dem++;
        tmp = tmp->next;
    }
    ofstream write(file, ios::out);
    write << dem << endl;
    while (head != NULL) {
        write << head->tkhoan << endl;
        write << head->mkhau << endl;
        head = head->next;
    }
}
void textColor(int a) {
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, a);
}