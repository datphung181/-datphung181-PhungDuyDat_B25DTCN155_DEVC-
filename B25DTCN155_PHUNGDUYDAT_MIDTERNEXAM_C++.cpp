#include <iostream>
#include <vector>
#include <string>

using namespace std;

//======================= LOP EMPLOYEE ======================= 
class Employee {
private:
    int id;             // Ma nhan vien
    string name;        // Ten nhan vien
    float salary;       // Luong nhan vien

public:
    // Ham tao khong tham so
    Employee() {
        id = 0;
        name = "";
        salary = 0;
    }

    // Ham tao co tham so
    Employee(int id, string name, float salary) {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    // Ham nhap thong tin 
    void input(int id) {
        this->id = id;
        cin.ignore();
        cout << "Nhap ten nhan vien: ";
        getline(cin, name);
        cout << "Nhap luong: ";
        cin >> salary;
    }

    // Ham hien thi thong tin nhan vien
    void printInfo() {
        cout << "ID: " << id
             << " - Ten: " << name
             << " - Luong: " << salary << endl;
    }

    // Ham lay ma nhan vien
    int getId() {
        return id;
    }

    // Ham cap nhat luong
    void setSalary(float salary) {
        this->salary = salary;
    }
};

// ======================= LOP EMPLOYEE MANAGER ======================= 
class EmployeeManager {
private:
    vector<Employee> list; 
    int nextId;           

public:
    EmployeeManager() {
        nextId = 3001;
    }

    // Ham them nhan vien moi
    void addEmployee() {
        Employee emp;
        emp.input(nextId);     // Nhap thong tin nhan vien
        list.push_back(emp);  // Them vao danh sach
        nextId++;              // Tang ma nhan vien
        cout << ">>> Them nhan vien thanh cong!\n";
    }

    // Ham hien thi danh sach nhan vien
    void showAll() {
        if (list.empty()) {
            cout << ">>> Danh sach nhan vien rong!\n";
            return;
        }

        for (int i = 0; i < list.size(); i++) {
            list[i].printInfo();
        }
    }

    // Ham cap nhat luong nhan vien theo id
    void updateSalaryById() {
        int id;
        cout << "Nhap ma nhan vien can cap nhat: ";
        cin >> id;

        for (int i = 0; i < list.size(); i++) {
            if (list[i].getId() == id) {
                float newSalary;
                cout << "Nhap luong moi: ";
                cin >> newSalary;
                list[i].setSalary(newSalary);
                cout << ">>> Cap nhat luong thanh cong!\n";
                return;
            }
        }

        cout << ">>> Khong tim thay nhan vien!\n";
    }

    // Ham xoa nhan vien theo id
    void deleteById() {
        int id;
        cout << "Nhap ma nhan vien can xoa: ";
        cin >> id;

        for (int i = 0; i < list.size(); i++) {
            if (list[i].getId() == id) {
                list.erase(list.begin() + i);
                cout << ">>> Xoa nhan vien thanh cong!\n";
                return;
            }
        }

        cout << ">>> Khong tim thay nhan vien!\n";
    }

    // Ham menu chinh
    void menu() {
        int choice;
        do {
            cout << "\n----- MENU -----\n";
            cout << "1. Them nhan vien\n";
            cout << "2. Hien thi danh sach\n";
            cout << "3. Cap nhat luong\n";
            cout << "4. Xoa nhan vien\n";
            cout << "5. Thoat\n";
            cout << "----------------\n";
            cout << "Chon chuc nang: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addEmployee();
                    break;
                case 2:
                    showAll();
                    break;
                case 3:
                    updateSalaryById();
                    break;
                case 4:
                    deleteById();
                    break;
                case 5:
                    cout << ">>> Thoat chuong trinh!\n";
                    break;
                default:
                    cout << ">>> Lua chon khong hop le!\n";
            }
        } while (choice != 5);
    }
};

// ======================= HAM MAIN ======================= */
int main() {
    EmployeeManager manager; 
    manager.menu();          
    return 0;
}

