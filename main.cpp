#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct adress {
    std::string st;
    int house;
    int flat;
};
struct ctzn{
    std::string fio; // snp
    adress pol; // place of living
    char gender;
    int age;
};

void swap(ctzn& first, ctzn& second) {
    auto temp = first;
    first = second;
    second = temp;
}

int main() {
    std::vector <ctzn> people (5);
    people[0] = {"Voloshchenko Ivan Sergeevich", "Baumanskaya", 14, 13, 'm', 18};
    people[1] = {"Shapovalov Alexey Dmitrievich", "Adler", 1337, 88, 'f', 24};
    people[2] = {"Kashapov Albert Ildarovich", "Adler", 1337, 55, 'm', 19};
    people[3] = {"Milchenko Ivan Sergeevich", "Stromynka", 23, 34, 'm', 18};
    people[4] = {"Kolesnik Daniil Daniilovich", "Krasnoselskaya", 5, 109, 'm', 20};
    for (int i = 0; i < 5; i++)
        for (int j = i+1; j < 5; j++)
        {
                if (people[i].fio > people[j].fio)
                    swap (people[i] , people[j]);
        }
    for (int i = 0; i < people.size(); i++) {
        std::cout << people[i].fio << ", " << people[i].pol.st << ", " << people[i].pol.house << ", " << people[i].pol.flat << ", " << people[i].gender << ", " << people[i].age << ";" << std::endl;
    }
    //people from the same house
    std::string street;
        int num;
        int cm = 0; // count males
        int cf = 0; // count females
        std::cout << std::endl;
    std::cout << "Enter the the name of the street and number of the house" << std::endl;
    std::cout << "Street name: ";
        std::cin >> street;
    std::cout << "House number: ";
        std::cin >> num;
        std::cout << std::endl;
        for (int i = 0; i < people.size(); i++) {
            if (people[i].pol.st == street && people[i].pol.house == num) {
                std::cout << people[i].fio << ", " << people[i].pol.st << ", " << people[i].pol.house << ", " << people[i].pol.flat << ", " << people[i].gender << ", " << people[i].age << ";" << std::endl;
                if (people[i].gender == 'm')
                    cm++;
                else
                    cf++;
            }
        }
                std::cout << "Amount of males living in the house: " << cm << std::endl;
    std::cout << "Amount of females living in the house: " << cf << std::endl;
        return 0;
}