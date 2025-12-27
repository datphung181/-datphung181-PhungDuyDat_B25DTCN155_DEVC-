#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ===== LOP CHA ===== 
class Manager {
public:
    virtual void display() = 0;
    virtual void add() = 0;
    virtual void remove() = 0;
    virtual void update() = 0;
};

// ===== DOI TUONG LOP HOC ===== 
class ClassRoom {
public:
    string classId;
    string className;
    string major;
    string type;
};

// ===== QUAN LY LOP HOC ===== 
class ClassManager : public Manager {
private:
    vector<ClassRoom> classList;

public:
    void addSampleData() {
        ClassRoom c1 = {"C001", "CNTT K25", "Cong nghe thong tin", "CNTT"};
        ClassRoom c2 = {"C002", "ENG K25", "Tieng Anh", "Ngoai ngu"};
        classList.push_back(c1);
        classList.push_back(c2);
    }

    void add() {
        ClassRoom c;
        cout << "Nhap ma lop: ";
        cin >> c.classId;
        cin.ignore();
        cout << "Nhap ten lop: ";
        getline(cin, c.className);
        cout << "Nhap chuyen nganh: ";
        getline(cin, c.major);
        cout << "Nhap loai lop (CNTT / Ngoai ngu): ";
        getline(cin, c.type);
        classList.push_back(c);
    }

    void display() {
        for (int i = 0; i < classList.size(); i++) {
            cout << classList[i].classId << " | "
                 << classList[i].className << " | "
                 << classList[i].major << " | "
                 << classList[i].type << endl;
        }
    }

    void remove() {
        string id;
        cout << "Nhap ma lop can xoa: ";
        cin >> id;

        for (int i = 0; i < classList.size(); i++) {
            if (classList[i].classId == id) {
                classList.erase(classList.begin() + i);
                break;
            }
        }
    }

    void update() {
        string id;
        cout << "Nhap ma lop can cap nhat: ";
        cin >> id;
        cin.ignore();

        for (int i = 0; i < classList.size(); i++) {
            if (classList[i].classId == id) {
                cout << "Nhap ten lop moi: ";
                getline(cin, classList[i].className);
                cout << "Nhap chuyen nganh moi: ";
                getline(cin, classList[i].major);
                cout << "Nhap loai lop moi: ";
                getline(cin, classList[i].type);
                break;
            }
        }
    }
};

//===== DOI TUONG SINH VIEN ===== 
class Student {
public:
    string studentId;
    string studentName;
    string birthday;
    string email;
    string phone;
};

//===== QUAN LY SINH VIEN ===== 
class StudentManager : public Manager {
private:
    vector<Student> studentList;

public:
    void addSampleData() {
        Student s1 = {"SV001", "Nguyen Van A", "01/01/2004", "NguyenVanA@gmail.com", "0376892469"};
        Student s2 = {"SV002", "Tran Thi B", "15/03/2004", "TranThiB@gmail.com", "0987759821"};
        studentList.push_back(s1);
        studentList.push_back(s2);
    }

    void add() {
        Student s;
        cout << "Nhap ma sinh vien: ";
        cin >> s.studentId;
        cin.ignore();
        cout << "Nhap ten sinh vien: ";
        getline(cin, s.studentName);
        cout << "Nhap ngay sinh: ";
        getline(cin, s.birthday);
        cout << "Nhap email: ";
        getline(cin, s.email);
        cout << "Nhap so dien thoai: ";
        getline(cin, s.phone);
        studentList.push_back(s);
    }

    void display() {
        for (int i = 0; i < studentList.size(); i++) {
            cout << studentList[i].studentId << " | "
                 << studentList[i].studentName << " | "
                 << studentList[i].birthday << " | "
                 << studentList[i].email << " | "
                 << studentList[i].phone << endl;
        }
    }

    void remove() {
        string id;
        cout << "Nhap ma sinh vien can xoa: ";
        cin >> id;

        for (int i = 0; i < studentList.size(); i++) {
            if (studentList[i].studentId == id) {
                studentList.erase(studentList.begin() + i);
                break;
            }
        }
    }

    void update() {
        string id;
        cout << "Nhap ma sinh vien can cap nhat: ";
        cin >> id;
        cin.ignore();

        for (int i = 0; i < studentList.size(); i++) {
            if (studentList[i].studentId == id) {
                cout << "Nhap ten moi: ";
                getline(cin, studentList[i].studentName);
                cout << "Nhap ngay sinh moi: ";
                getline(cin, studentList[i].birthday);
                cout << "Nhap email moi: ";
                getline(cin, studentList[i].email);
                cout << "Nhap so dien thoai moi: ";
                getline(cin, studentList[i].phone);
                break;
            }
        }
    }
};

// ===== MAIN ===== 
int main() {
    ClassManager classManager;
    StudentManager studentManager;

    classManager.addSampleData();
    studentManager.addSampleData();

    int mainChoice, subChoice;

    do {
        cout << "\n===== MENU TONG =====\n";
        cout << "1. Quan ly lop hoc\n";
        cout << "2. Quan ly sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> mainChoice;

        Manager* manager = NULL;

        if (mainChoice == 1) manager = &classManager;
        if (mainChoice == 2) manager = &studentManager;

        if (manager != NULL) {
            do {
                cout << "\n1. Hien thi\n";
                cout << "2. Them moi\n";
                cout << "3. Xoa\n";
                cout << "4. Cap nhat\n";
                cout << "0. Quay lai\n";
                cout << "Chon: ";
                cin >> subChoice;

                if (subChoice == 1) manager->display();
                else if (subChoice == 2) manager->add();
                else if (subChoice == 3) manager->remove();
                else if (subChoice == 4) manager->update();

            } while (subChoice != 0);
        }

    } while (mainChoice != 0);

    return 0;
}

