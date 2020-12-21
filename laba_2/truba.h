#ifndef TRUBA_H
#define TRUBA_H

#endif // TRUBA_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


// В public отправляюься все наши функции
// в Private отправляются все локальные переменные

class Truba{
    public:
        vector<string> id = {"ID_1", "ID_2", "ID_3"};
        vector<string> repairs = {"В_ремонте", "Исправна", "Исправна"};

        // добавляем трубу
        void show(){
            cout<<"================"<<endl;
            for (int i = 0; i<=(id.size() - 1);i++){
                cout<<id[i]<<": ";
                cout<<repairs[i]<<endl;
            }
        }
        void add(){

            cout<<"================"<<endl;
            string scales;
            cout<<"Ремонтируется или нет?"<<endl;
            cout<<"1.В ремонте"<<endl;
            cout<<"2.Исправна"<<endl;
            cin>>scales;
            cout<<""<<endl;

            if (scales == "1"){
                repairs.push_back("В_ремонте");

                string name;
                    name = "ID_" + to_string(id.size() + 1);
                id.push_back(name);
            }
            if (scales == "2"){
                repairs.push_back("Исправна");

                string name;
                    name = "ID_" + to_string(id.size() + 1);
                id.push_back(name);
            }
            if((scales != "1") and (scales != "2")){
                cout<<"Ошибочка вышла((((((((("<<endl;
            }

        };
        // удаляем трубу
        void del(){
            cout<<"================"<<endl;
            for (int i = 0; i<=(id.size()-1); i++){
                cout<<id[i]<< " ";
            }
            cout<<""<<endl;
            string name;
            cout<<"Введите ID трубы(необходимо ввести только цифру) = ";
            cin>>name;
            cout<<""<<endl;
            for (int i=0; i<=(id.size()-1);i++){
                if (("ID_" + name) == id[i]){
                    id.erase(id.cbegin() + i);
                    repairs.erase(repairs.cbegin() + i);
                    break;
                }
            }

        };
        // редактирую количество труб
        void edit(){
            int wall = true;
            string scales;
            string name;
            cout<<"================"<<endl;
            while (wall == true){
                cout<<"Введите ID_(необходимо ввести только цифру"<<endl;
                cout<<"Если хотите закончить введите exit"<<endl;
                cin>>scales;
                cout<<""<<endl;
                name = "ID_" + scales;
                if (scales == "exit"){
                    wall = false;
                }else{
                    cout<<"Введите изменение: "<<endl;
                    cout<<"1.В_ремонте"<<endl;
                    cout<<"2.Исправна"<<endl;
                    cout<<"Ввод: ";
                    cin>>scales;
                    cout<<""<<endl;
                    if (scales == "1"){
                        scales = "В_ремонте";
                        for (int i = 0;i<=(id.size()-1);i++){
                            if (name == id[i]){
                                    repairs[i] = scales;
                                    cout<<id[i]<<": "<<repairs[i]<<endl;
                                    break;
                            }

                        }
                    }
                    if (scales == "2"){
                        scales = "Исправна";
                        for (int i = 0;i<=(id.size()-1);i++){
                            if (name == id[i]){
                                repairs[i] = scales;
                                cout<<id[i]<<": "<<repairs[i]<<endl;
                                break;
                            }
                        }
                    }
                }
            }
        };
        // поиск труб по названию/признаку
        void search(){
            cout<<"================"<<endl;
            string scales;
            cout<<"1.Поиск труб по признаку 'В_ремонте'"<<endl;
            cout<<"2.Поиск по названию"<<endl;
            cin>>scales;
            cout<<""<<endl;
            if (scales == "1"){
                cout<<"1.Вывести все не работающие трубы"<<endl;
                cout<<"2.Вывести все работающие трубы"<<endl;
                cin>>scales;
                cout<<""<<endl;
                if(scales == "1"){
                    scales = "В_ремонте";
                    for (int i = 0; i<=(id.size()-1);i++){
                        if (scales == repairs[i]){
                            cout<<id[i]<< " ";
                        }
                    }
                    cout<<""<<endl;
                }else{
                    scales = "Исправна";
                    for (int i = 1;i<=(id.size()-1);i++){
                        if (scales == repairs[i]){
                            cout<<id[i]<<" ";
                        }
                    }
                    cout<<""<<endl;
                }

            }else{
                cout<<"Введите ID трубы(необходимо ввести только цифру)"<<endl;
                cin>>scales;
                cout<<""<<endl;
                scales = "ID_" + scales;

                for(int i = 0;i<=(id.size()-1);i++){
                    if (scales == id[i]){
                        cout<<id[i]<<": "<<repairs[i]<<endl;
                        break;
                    }
                }
            }
        };
};
