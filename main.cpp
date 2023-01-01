#include <iostream>
#include <fstream>
#include "Person.cpp"
#include "Doctor.cpp"
#include "Nurse.cpp"

using namespace std;

vector<Person*> listPerson;
fstream MyFile;


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
        MyFile << p->getName() << ";" << p->getDob() << ";" << p->getTel() << ";" << p->getUnit() << ";" << tempDayDr << ";" << tempSur << endl;
        listPerson.push_back(p);
    } else if (temp.getUnit()=="Y tá") {
        int tempDayNs,tempShift;
        cout << "Nhập số ngày làm việc: ";
        cin >> tempDayNs;
        cout << "Nhập số ca trực đêm: ";
        cin >> tempShift; cin.ignore();
        Person *p = new Nurse(temp.getName(),temp.getDob(),temp.getTel(),temp.getUnit(),tempDayNs,tempShift);
        MyFile << p->getName() << ";" << p->getDob() << ";" << p->getTel() << ";" << p->getUnit() << ";" << tempDayNs << ";" << tempShift << endl;
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
    system("chcp 65001");

    int option;
    while(1){

        cout<<"\tCHƯƠNG TRÌNH QUẢN LÝ BỆNH VIỆN.\t"<<endl;;
		cout<<"========================MENU=======================================\n";
		cout<<"==                                                               ==\n";
		cout<<"==        1.Thêm một cán bộ                                      ==\n";
		cout<<"==        2.Chỉnh sửa thông tin cán bộ.                          ==\n";
		cout<<"==        3.Xóa một cán bộ.                                      ==\n";
		cout<<"==        4.Tìm kiếm cán bộ theo tên.                            ==\n";
		cout<<"==        5.Tìm kiếm cán bộ theo ngày sinh.                      ==\n";
		cout<<"==        6.Tìm kiếm cán bộ theo đơn vị.                         ==\n";
		cout<<"==        7.Cán bộ có lương tháng lơn hơn X(vnd).                ==\n";
		cout<<"==        8.Danh sách và thông tin cán bộ trong tháng X.         ==\n";
		cout<<"==        9.In danh sách cán bộ                                  ==\n";
		cout<<"==        10.Exit.                                               ==\n";
		cout<<"===================================================================\n";
	    cout<<" \t Nhập lựa chọn của bạn: ";cin>>option;
    switch(option){
        case 1:
            addPerson();
            system("\npause");
            break;

        case 2:

        case 3:

        case 4:

        case 5:

        case 6:

        case 7:
            FindPersonHaveSalaryHigherThanX();
            system("\npause");
            break;

      	case 8:


        case 9:
            printlistPerson();
            system("\npause");
            break;
        case 10:
            exit(0);
        default:
            cout << "Không tìm tháy dữ liệu bạn nhập, xin mời nhập lại.";
    }
    }
}
