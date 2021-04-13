// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;

void LineManipulations(vector<bool>& people_line, int& num_of_operations) { //функция для манипуляции очередью
    string command;
    int argument = 0;
    while (num_of_operations > 0) {
        cin >> command;
        if (command == "COME") { //когда значение command равняется "COME"
            cin >> argument; //считывается аргумент
            if (argument > 0) {
                while (argument > 0) {
                    people_line.push_back(0);  //затем добавляется человек в конец очереди
                    argument--; //и уменьшается счетчик
                }
            }
            else {
                while (argument < 0) { //когда аргумент меньше нуля
                    people_line.pop_back(); //удаляются люди из конца очереди
                    argument++; //аргумент стремится к нулю с каждой итерацией цикла
                }
            }
        }
        else {
            if (command == "WORRY") { //когда команда "WORRY", считывается аргумент(место человека в очереди от начала)
                cin >> argument;
                people_line[argument] = true; //присваивается статус true, значит человек беспокоится
                argument = 0; //обнуление аргумента на случай, если дальше будет использоваться команда WORRY_COUNT
            }
            else {
                if (command == "WORRY_COUNT") { //когда команда "WORRY_COUNT", аргумент выступает в качестве счетчика, который выводится на экран, а затем обнуляется
                    for (auto a : people_line) {
                        if (a == true) {
                            argument++;
                        }
                    }
                    cout << argument << endl;
                    argument = 0;
                }
                else {
                    if (command == "QUIET") { //когда команда "QUIET", аргумент выступает в качестве указателя на беспокойного человека, он успокаивается (ставится флаг false)
                        cin >> argument;
                        people_line[argument] = false;
                        argument = 0;
                    }
                }
            }
            
        }
        num_of_operations--;
    }
}

int main()
{  
    int num_of_operations;
    vector<bool> people_line;

    cin >> num_of_operations;

    LineManipulations(people_line, num_of_operations);

    return 0;
}

