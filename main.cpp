#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct adress {
    string st;
    int house;
    int flat;
};
struct ctzn{
    string fio; // snp
    adress pol; // place of living
    char gender;
    int age;
};

void swap(ctzn& first, ctzn& second) {
    auto temp = first;
    first = second;
    second = temp;
}

ostream& operator << (ostream& output, ctzn& person) {  // перегрузка оператора вывода для одного жителя
    output << "Full name: " << person.fio << endl;
    output << "Street: " << person.pol.st << endl;
    output << "House: " << person.pol.house << endl;
    output << "Flat: " << person.pol.flat << endl;
    output << "Gender: " << person.gender << endl;
    output << "Age: " << person.age << endl << endl;
    return output;
}

ostream& operator << (ostream& output, const vector<ctzn>& person) { // перегрузка для вывода нескольких жителей
    for (auto i : person) {
        output << "Full name: " << i.fio << endl;
        output << "Street: " << i.pol.st << endl;
        output << "House: " << i.pol.house << endl;
        output << "Flat: " << i.pol.flat << endl;
        output << "Gender: " << i.gender << endl;
        output << "Age: " << i.age << endl << endl;
    }
}

void output(ofstream& output, const vector<ctzn>& people, int cm, int cf)
{
    output << "People list: \n";
    output << people;
    output << endl;
    output << "Amount of males living in the house: " << cm << endl;
    output << "Amount of females living in the house: " << cf << endl;
}

int main() {
    vector <ctzn> people (5); // всех людей добавляем в вектор
    people[0] = {"Voloshchenko Ivan Sergeevich", "Baumanskaya", 14, 13, 'm', 18};
    people[1] = {"Shapovalov Alexey Dmitrievich", "Adler", 1337, 88, 'f', 24};
    people[2] = {"Kashapov Albert Ildarovich", "Adler", 1337, 55, 'm', 19};
    people[3] = {"Milchenko Ivan Sergeevich", "Stromynka", 23, 34, 'm', 18};
    people[4] = {"Kolesnik Daniil Daniilovich", "Krasnoselskaya", 5, 109, 'm', 20};
    for (int i = 0; i < 5; i++) // sorting people by snp
        for (int j = i+1; j < 5; j++)
        {
                if (people[i].fio > people[j].fio)
                    swap (people[i] , people[j]);
        }
    for (int i = 0; i < people.size(); i++) {
        cout << people[i];
    }
    //people from the same house
    string street;
        int num;
        int cm = 0; // count males
        int cf = 0; // count females
        cout << endl;
    cout << "Enter the the name of the street and number of the house" << std::endl;
    cout << "Street name: ";
        cin >> street;
    cout << "House number: ";
        cin >> num;
        cout << std::endl;
        for (int i = 0; i < people.size(); i++) {
            if (people[i].pol.st == street && people[i].pol.house == num) {
                cout << people[i];
                if (people[i].gender == 'm')
                    cm++;
                else
                    cf++;
            }
        }

    ofstream OutputFile("text.text", ios::out);    // запись в файл
    output(OutputFile, people, cm, cf);
    for (int i = 0; i < 4; i++)
        for (auto i = 0; i < people.size(); i++) {
            if (people[i].pol.st == street && people[i].pol.house == num)
                OutputFile << people[i];
        }
    OutputFile.close();

    vector<ctzn> vec_for_input;  // из файла
    cout << "Reading text from file: \n";
    cout << "=======================================\n";
    ifstream InputFile("Text.txt", std::ios::in);
    InputFile >> vec_for_input;

    for (int i = 0; i < vec_for_input.size(); i++)
        std::cout << vec_for_input[i];

    InputFile.close();
    std::cout << "=======================================\n";
        return 0;
}
