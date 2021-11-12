#include <iostream>
#include<vector>

using namespace std;

class NoteBook;
class Abonent {
    friend NoteBook;
    int id;

    string SName, PNumber;

public:
    Abonent(){
        cout << "Вызываем конструктор Abonent" << endl;
    }
    Abonent(int Vid, string VSName, string VPNumaber) {
        id = Vid;
        SName = VSName;
        PNumber = VPNumaber;
        cout << "Вызываем конструктор с параметрами Abonent" << endl;
    }
    ~Abonent() {
        cout << "Вызываем деструктор Abonent" << endl;
    }
};

class NoteBook {
    friend Abonent;
public:
    NoteBook(){
        
    }
    ~NoteBook() {
        
    }
    void change(Abonent &a, string nPNumber) {
        a.PNumber = nPNumber;
    }
    void show(Abonent &a) {
        cout << a.id << ", "
            << a.PNumber << ", "
            << a.SName << endl;
    }
    void showt(Abonent &a, int i) {
        cout << i + 1 << " Абонент. Его Индекс, Номер и Фамилия: " << a.id <<", " << a.PNumber <<", " << a.SName << endl;
    }
};


int main() {
    setlocale(LC_ALL, "ru");
    int N = 0, id;
    string sname, pnumber;
    vector <Abonent> mass;
    vector <NoteBook> zmass;
    cout << "Введите кол-во абонентов: ";
    cin >> N;
    for (int i = 0; i < N; i++) {
        cout << "Введите фамилию и номер телефона " << i + 1<< " Абонента: ";
        cin >> sname >> pnumber;
        Abonent ab(i, sname, pnumber);
        mass.push_back(ab);
        NoteBook zap;
        zmass.push_back(zap);
        if (i + 1 == N) {
            cout << "Введите индивидуальный индекc(id), нужного вам абонента: ";
            cin >> id;
            zmass[id].show(mass[id]);
            zmass[id].change(mass[id], "45678904567");
            zmass[id].show(mass[id]);
            cout << endl;
        }
    }
}
