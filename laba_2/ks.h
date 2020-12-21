#ifndef KS_H
#define KS_H

#endif // KS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


class Ks{
    public:
        vector<string> id = {"ID_1", "ID_2", "ID_3"};
        vector<double> shop = {10, 0, 20};


        // добавляем кс
        void show(){
            cout<<"================"<<endl;
            for (int i = 0; i<=(id.size() - 1);i++){
                cout<<id[i]<<": ";
                cout<<shop[i]<<endl;
            }
        }
        void add(){

            cout<<"================"<<endl;
            double scales;
            cout<<"Ввeдите кол-во не работающих цехов"<<endl;
            cin>>scales;
            if(cin.fail()){
                cin.clear();
                cin.ignore(100000, '\n');
                cout<<"Mistake\n"<<endl;
            }else{
                cout<<""<<endl;
                // Оброботчик ошибок надо
                shop.push_back(scales);
                string name;
                    name = "ID_" + to_string(id.size() + 1);
                id.push_back(name);
                }
            };
        // удаляем кс
        void del(){
            cout<<"================"<<endl;
            for(int i = 0; i<=(id.size()-1); i++){
                cout<<id[i]<< " ";
            }
            cout<<""<<endl;
            string name;
            cout<<"Введите ID кс (необходимо ввести только цифру) = ";
            cin>>name;
            cout<<""<<endl;
            for (int i=0; i<=(id.size()-1);i++){
                if (("ID_" + name) == id[i]){
                    id.erase(id.cbegin() + i);
                    shop.erase(shop.cbegin() + i);
                    break;
                }
            }

        };

        // поиск по количеству цехов
        void search(){
            cout<<"================"<<endl;
            string scales;
            cout<<"1.Поиск по количеству цехов в работе"<<endl;
            cout<<"2.Поиск по названию"<<endl;
            cin>>scales;
            cout<<""<<endl;
            if (scales == "1"){

                double num;
                // оброботчик ошибок
                cout<<"Введите проценты "<<endl;
                cin>>num;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(100000, '\n');
                    cout<<"Mistake\n"<<endl;
                }else{
                    cout<<""<<endl;
                    for (int i = 0;i<=(id.size()-1);i++){
                        if (num == shop[i]){
                            cout<<id[i]<<endl;
                        }
                    }
                }
            }else{
                cout<<"Введите ID трубы(необходимо ввести только цифру)"<<endl;
                cin>>scales;
                cout<<""<<endl;
                scales = "ID_" + scales;

                for(int i = 0;i<=(id.size()-1);i++){
                    if (scales == id[i]){
                        cout<<id[i]<<": ";
                        cout<<shop[i]<<endl;

                        break;
                    }
                }
            }
        };
};
