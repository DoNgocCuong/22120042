#include"thuvien.h"
int main() {
	Login* headsv = NULL;
	Login* headgv = NULL;
    docfilesv(headsv);
    docfilegv(headgv);
    year* head = new year;
    Init_class(head);
    Init_hk(head);
    textColor(10);
    cout << endl << endl << endl << endl << endl << endl;
    cout << "                         =======================================================================" << endl;
    cout << "                         =                   CHAO MUNG BAN DEN VOI HE THONG                    =  " << endl;
    cout << "                         =       QUAN LI SINH THONG TIN VA KET QUA HOC TAP CUA SINH VIEN       =" << endl;
    cout << "                         =======================================================================" << endl;
    cout << "                                                  BAN LA AI" << endl;
    cout << "                                               1/SINH VIEN" << endl;
    cout << "                                               2/GIANG VIEN" << endl;
    textColor(12);
    int n, a, b, tmp; cout << "                             Nhap lua chon cua ban:";  textColor(7); cin >> n;
    //tmp la ma so sinh vien hoac ma so giao vien vua dang nhap
    while (n > 2 || n < 0) {
        textColor(12);
        cout << "lua chon khong hop le vui long nhap lai:";
        textColor(7);
        cin >> n;
    }
    system("cls");
    if (n == 1) {
        textColor(10);
        tmp = dangnhap(headsv);
        b = 1;
        while (b != 0) {
            textColor(10);
            system("cls");
            MENUsv();
            textColor(7);
            cin >> a;
            if (a == 3) {
                return 0;
            }
            while (a != 3) {
                if (a == 1) {
                    system("cls");
                    see_my_list_of_subjects(head->hk->monhoc, tmp);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 2) {
                    system("cls");
                    doiMK(headsv, tmp);
                    char file[100]= "thongtindangnhapsv.txt";
                    write_file_password(headsv,file);
                    system("pause");
                    system("cls");
                    break;
                }
            }
        }
    }
    else {
        textColor(10);
        tmp = dangnhap(headgv);
        b = 1;
        while (b != 0) {
            system("cls");
            MENUgv();
            textColor(7);
            cin >> a;
            if (a >=19&&a<=0) {
                return 0;
            }
            while (a != 18) {
                if (a == 1) {
                    system("cls");
                    see_class_list(head->dslop);
                    system("pause");
                    system("cls");
                    break;
                }
                else if(a==2){
                    system("cls");
                    see_the_list_of_students_in_class(head->dslop);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 3) {
                    system("cls");
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
                    see_list_of_subjects(head->hk,x );
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 4) {
                    system("cls");
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
                    see_list_of_subjects(head->hk, x);
                    see_the_list_of_students_of_all_subjects(head->hk, x);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 5) {
                    system("cls");
                    output_the_resul_file(head->hk->monhoc);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 6) {
                    system("cls");
                    update_subject_scores(head->hk->monhoc);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 7) {
                    system("cls");
                    take_a_look_at_the_score(head->hk);
                    system("pause");
                     system("cls");
                    break;
                }
                else if (a == 8) {
                    system("cls");
                    see_class_grades(head);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 9) {
                    system("cls");
                    themmonhoc(head->hk->monhoc);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 11) {
                    system("cls");
                    popclass(head->dslop);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 12) {
                    system("cls");
                    popsubject(head->hk->monhoc);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 13) {
                    system("cls");
                    push_student_subject(head->hk->monhoc);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 14) {
                    system("cls");
                    pop_student_subject(head->hk->monhoc);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 15) {
                    system("cls");
                    push_student(head->dslop);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 16) {
                    system("cls");
                    pop_student(head->dslop);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 17) {
                    system("cls");
                    doiMK(headgv, tmp);
                    char file[max] = "thongtindangnhapgv.txt";
                    write_file_password(headgv, file);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (a == 10) {
                    system("cls");
                    push_class(head->dslop);
                    system("pause");
                    system("cls");
                    break;
                }
                
            }
        }
    }
    
}
