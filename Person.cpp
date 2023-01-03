#include "Person.hpp"

Person::Person() {}
Person::Person(string name,string dob,string tel,string unit) {
    this->name = name;
    this->dob = dob;
    this->tel = tel;
    this->unit = unit;
}
Person::Person(const Person &temp) {
    this->name = temp.name;
    this->dob = temp.dob;
    this->tel = temp.tel;
    this->unit = temp.unit;
}
string Person::getDob() {
    return this->dob;
}
string Person::getUnit() {
    return this->unit;
}
string Person::getName() {
    return this->name;
}
string Person::getTel() {
    return this->tel;
}
long Person::salary() {return 0;}
void Person::display() {
    cout<<setw(20)<<std::left<<"\nHo va Ten"<<setw(10)<<std::left<<" |"
    <<setw(15)<<std::left<<"Ngay sinh"<<setw(5)<<std::left<<" |"
    <<setw(15)<<std::left<<"So dien thoai"<<setw(7)<<std::left<<" |"
    <<setw(10)<<std::left<<"Don vi"<<setw(10)<<std::left<<" |"<<endl;
    cout<<setw(20)<<std::left<<name<<setw(10)<<std::left<<"|"
    <<setw(15)<<std::left<<dob<<setw(5)<<std::left<<"|"
    <<setw(15)<<std::left<<tel<<setw(7)<<std::left<<"|"
    <<setw(10)<<std::left<<unit<<setw(14)<<std::left<<"|";
}
istream& operator >> (istream& in, Person& a) {
    cout << "Nhập tên của cán bộ: ";getline(in,a.name);
    cout << "Nhập ngày tháng năm sinh của cán bộ(theo định dạng dd/mm/yyyy): ";in >> a.dob;
    cout << "Nhập số điện thoại của cán bộ: ";in.ignore();in >> a.tel;
    cout << "Nhập đơn vị: ";in.ignore();getline(in,a.unit);
    return in;
}
