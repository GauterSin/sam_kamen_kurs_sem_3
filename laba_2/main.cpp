#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include "ks.h"
#include "truba.h"
using namespace std;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

    Truba truba;
    Ks ks;
    bool wall = true;
    string sms;
    while (wall == true){
        cout<<"================"<<endl;
        cout<<"1.Добавить трубу"<<endl;
        cout<<"2.Удалить трубу"<<endl;
        cout<<"3.Редактировать трубу"<<endl;
        cout<<"4.Поиск труб"<<endl;
        cout<<"5.Показать трубы"<<endl;
        cout<<"================"<<endl;
        cout<<"6.Добавить кс"<<endl;
        cout<<"7.Удалить кс"<<endl;
        cout<<"8.Поиск кс"<<endl;
        cout<<"9.Показать кс"<<endl;
        cout<<"0.Выход"<<endl;
        cout<<""<<endl;
        cout<<"Введите цифру: ";
        cin>>sms;
        cout<<""<<endl;
        if (sms == "1"){
            truba.add();
        }

        if (sms == "2"){
            truba.del();
        }

        if (sms == "3"){
            truba.edit();
        }

        if (sms == "4"){
            truba.search();
        }

        if (sms == "5"){
            truba.show();
        }

        if (sms == "6"){
            ks.add();
        }


        if (sms == "7"){
            ks.del();
        }

        if (sms == "8"){
            ks.search();
        }

        if (sms == "9"){
            ks.show();
        }

        if (sms == "0"){
            wall = false;
        }
    }
                ofstream outf("laba_2_data.txt");
                outf << "Truba:"<< endl;
                for(int i = 0; i <= (truba.id.size() - 1); i++){
                  outf << "id = '" << truba.id[i] <<"' ";
                  outf << "rep = " << truba.repairs[i] <<endl;
                };
                outf << "Ks:" << endl;
                for(int i = 0; i <= (ks.id.size() - 1); i++){
                  outf << "id = '" << ks.id[i] <<"' ";
                  outf << "shop = " << ks.shop[i] << endl;
                };
                outf.close();
}
