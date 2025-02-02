#include <iostream>
#include <fstream>
#include "Person.cpp"
#include "Doctor.cpp"
#include "Nurse.cpp"

using namespace std;

vector<Person*> listPerson;
fstream MyFile;

void displayMenu() {
    cout << "==================================================================== \n";
    cout << " \t\t\t  QUẢN LÍ BỆNH VIỆN \t \n";
    cout << "==================================================================== \n";
    cout << " 1.Thêm một cán bộ\n";
    cout << " 2.Chỉnh sửa thông tin cán bộ\n";
    cout << " 3.Xoá một cán bộ \n";
    cout << " 4.Tìm kiếm cán bộ theo tên \n";
    cout << " 5.Danh sách cán bộ có lương hàng tháng lớn hơn X(nghìn vnd) \n";
    cout << " 6.Danh sách và thông tin cán bộ của bệnh viện trong tháng X\n";
    cout << " 7.In danh sách cán bộ\n";
    cout << " 0.Thoát!";
}

void addPerson() {
    Person temp;
    cin >> temp;
    MyFile.open("data.txt",ios::app);
    if (temp.getUnit()=="Bác sĩ") {
        int tempDayDr,tempSur;
        cout << "Nhập số ngày làm việc: ";
        cin >> tempDayDr;
        cout << "Nhập số ca phẫu thuật thực hiện: ";
        cin >> tempSur; cin.ignore();
        Person *p = new Doctor(temp.getName(),temp.getDob(),temp.getTel(),temp.getUnit(),tempDayDr,tempSur);
        MyFile << p->getName() << ";" << p->getDob() << ";" << p->getTel() << ";" << p->getUnit() <<";" << "Số ngày làm việc: " << tempDayDr << ";" << "Số ca phẫu thuật thực hiện: " << tempSur << endl;
        listPerson.push_back(p);
    } else if (temp.getUnit()=="Y tá") {
        int tempDayNs,tempShift;
        cout << "Nhập số ngày làm việc: ";
        cin >> tempDayNs;
        cout << "Nhập số ca trực đêm: ";
        cin >> tempShift; cin.ignore();
        Person *p = new Nurse(temp.getName(),temp.getDob(),temp.getTel(),temp.getUnit(),tempDayNs,tempShift);
        MyFile << p->getName() << ";" << p->getDob() << ";" << p->getTel() << ";" << p->getUnit() <<";" << "Số ngày làm việc: " << tempDayNs << ";" << "Số ca phẫu thuật thực hiện: " << tempShift << endl;
        listPerson.push_back(p);
    } else {
        Person *p = new Person(temp);
        MyFile << p->getName() << ";" << p->getDob() << ";" << p->getTel() << ";" << p->getUnit() << endl;
        listPerson.push_back(p);
    }
    MyFile.close();
}

void deletePerson() {}
void FindPersonHaveSalaryHigherThanX() {
    long long X;
    cout << "Nhập số tiền bạn muốn so sánh(vnđ): ";cin >> X;
    vector<Person*> result;
    for (int i=0;i<listPerson.size();i++) {
        if (listPerson[i]->salary()>X) {
            result.push_back(listPerson[i]);
        }
    }
    if (result.size()==0) {
        cout << "Không có ai có tiền lương lớn hơn: " << X << "(vnđ)"<<endl;
    } else {
        for (int i=0;i<result.size();i++) {
            result[i]->display();
        }
    }
}

void printlistPerson() {
    if (listPerson.size()==0) {
        cout << "Danh sách cán bộ rỗng\n";
    } else {
        cout <<"DANH SÁCH CÁN BỘ\n";
        for (int i=0;i<listPerson.size();i++) {
            cout <<"STT: " << i+1 << endl;
            listPerson[i]->display();
        }
    }
}

int main() {
    for (int i=0;i<3;i++) {
        addPerson();
    }
}