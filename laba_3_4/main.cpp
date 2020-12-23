#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdlib.h>
using namespace std;


class Truba{
    public:
        vector<string> id = {"ID_1", "ID_2", "ID_3"};
        vector<string> repairs = {"В_ремонте", "Исправна", "Исправна"};
        vector<float> l = {10,11.2,9};

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
        // пои�к труб по названию/признаку
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

class Ks{
    public:
        vector<string> id = {"KS_1", "KS_2", "KS_3"};
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
                if (("KS_" + id[i]) == name){
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
                scales = "KS_" + scales;

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


void topolog_sort(vector<vector<string>> graf){

  vector<string> top_sort_mas;
  vector<int> trubs;
  int kolvo = 0;
  vector<vector<string>> matrix = {graf;

  for(int i = 0; i < matrix.size(); i++){
    for(int j = 1; j < matrix[i].size(); j++){
      if(matrix[i][j][0] == '-'){
        trubs.clear();
        break;
      }else{
        if(matrix[i][j] != "0"){
          trubs.push_back(j);
        }else{
          kolvo = kolvo + 1;
        }
      }
    }
    if((trubs.size() + 1) == (matrix[i].size() - kolvo)){
      top_sort_mas.push_back(matrix[i][0]);
      matrix.erase(matrix.cbegin() + i);
      if(matrix.size() == 0){
        break;
      }
      for(int z = 0; z < matrix.size(); z++){
        kolvo = 0;
        for(auto b : trubs){
          matrix[z].erase(matrix[z].cbegin() + b);
          kolvo = kolvo + 1;
        }
      }
      i = 0;
    }
  }
}





int main()
{
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    Truba truba;
    vector<vector<string>> graf;
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

        if (sms == "10"){ // создание вектора
            vector<string> matrix;
            string otkuda;
            string kuda;
            string t;
            string bb;
            bool wall = true;
            bool wall_1 = false;
            bool wall_2 = false;


            while(wall == true){
                for(int i = 0; i < graf.size(); i++){
                    for(int j = 0; j < graf[i].size(); j++){
                        cout << graf[i][j] << " ";
                    }
                    cout << "" << endl;
                }
                cout << "Для завершения: 0; Для продолжения: 1 = ";
                cin >> bb;
                cout << "" << endl;
                if(bb == "0"){
                    break;
                }
                cout << "" << endl;
                cout << "Откуда Ks_";
                cin >> otkuda;
                cout << "" << endl;
                cout << "Куда Ks_";
                cin >> kuda;

                if(otkuda == kuda){
                    cout << "Станция сама в себя не может идти" << endl;
                    continue;
                }

                for(int i = 0; i < ks.id.size(); i++){
                    if(("KS_" + otkuda) == ks.id[i]){
                        wall_1 = true;
                    }
                    if(("KS_" + kuda) == ks.id[i]){
                        wall_2 = true;
                    }
                }

                if((wall_1 == false) or (wall_2 == false)){
                    cout << "Ошибка при выборе станции" << endl;
                    continue;
                }

                bool wall_1 = false;
                bool wall_2 = false;
                cout << "Truba_";
                cin >> t;
                cout << "" << endl;

                if(graf.size() == 0){
                    matrix.push_back("KS_" + otkuda);
                    graf.push_back(matrix);
                    matrix.clear();
                    graf[0].push_back("ID_" + t);
                    matrix.push_back("KS_" + kuda);
                    graf.push_back(matrix);
                    graf[1].push_back("-ID_" + t);
                    matrix.clear();
                    continue;
                }
                int a = graf[0].size();
                int b = graf[1].size();
                for(int i = 0; i < (graf.size() - 1); i++){
                  if(a > b){
                    b = graf[i].size();
                  }else{
                    a = graf[i+1].size();
                  }
                }
                if (a < b){
                  a = b;
                }

                for(int i = 0; i < graf.size(); i++){
                  if(("KS_" + otkuda) == graf[i][0]){
                    while(graf[i].size() < a){
                      graf[i].push_back("0");
                    }
                    wall_1 = true;
                    graf[i].push_back("ID_" + t);
                  }
                  if(("KS_" + kuda) == graf[i][0]){
                    while(graf[i].size() < a){
                      graf[i].push_back("0");
                    }
                    wall_2 = true;
                    graf[i].push_back("-ID_" + t);
                  }
                }
                if(wall_1 == false){
                  graf.push_back({"KS_" + otkuda});
                  while(graf[graf.size() - 1].size() < a){
                    graf[graf.size() - 1].push_back("0");
                  }
                  graf[graf.size() - 1].push_back("ID_" + t);
                }
                if(wall_2 == false){
                  graf.push_back({"KS_" + kuda});
                  while(graf[graf.size() - 1].size() < a){
                    graf[graf.size() - 1].push_back("0");
                  }
                  graf[graf.size() - 1].push_back("-ID_" + t);
                }
                a = graf[0].size();
                b = graf[1].size();
                for(int i = 0; i < (graf.size() - 1); i++){
                  if(a > b){
                    b = graf[i].size();
                  }else{
                    a = graf[i+1].size();
                  }
                }
                if (a < b){
                  a = b;
                }
                for(int i = 0; i < graf.size(); i++){
                  while(graf[i].size() < a){
                    graf[i].push_back("0");
                  }
                }
              }
            }
        if (sms == "0"){
            wall = false;
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

}
