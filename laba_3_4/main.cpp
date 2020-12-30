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
        vector<float> l = {1,2,3};
        vector<float> diametr = {10, 20, 30};

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
            float b;
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

            cout<<"Длина?"<<endl;
            cout<<"l = "<<endl;
            cin >> b;
            if(cin.fail()){
                cin.clear();
                cin.ignore(100000, '\n');
                id.pop_back();
                repairs.pop_back();
                cout<<"Mistake\n"<<endl;
            }else{
              cout << "" << endl;
              l.push_back(b);
              cout<<"Производительность?"<<endl;
              cout<<"diametr = "<<endl;
              cin >> b;
              if(cin.fail()){
                  cin.clear();
                  cin.ignore(100000, '\n');
                  id.pop_back();
                  repairs.pop_back();
                  l.pop_back();
                  cout<<"Mistake\n"<<endl;
              }else{
                cout << "" << endl;
                diametr.push_back(b);
              }
            }


        };
        // удаляем трубу
        string del(){
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
                    l.erase(l.cbegin() + i);
                    diametr.erase(diametr.cbegin() + i);
                    break;
                }
            }

            return name;

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
        string del(){
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
            return name;

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


vector<string> topolog_sort(vector<vector<string>> graf){

  vector<string> top_sort_mas;
  vector<int> trubs;
  int kolvo = 0;
  vector<vector<string>> matrix = graf;
  for(int i = 0; i < matrix.size(); i++){
    for(int j = 1; j < matrix[i].size(); j++){
      if(matrix[i][j][0] == '-'){
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
      if(kolvo > trubs.size()){
        kolvo = 0;
        trubs.clear();
        continue;
      }
      top_sort_mas.push_back(matrix[i][0]);
      matrix.erase(matrix.cbegin() + i);
      if(matrix.size() == 0){
        break;
      }
      for(int z = 0; z < matrix.size(); z++){
        kolvo = 0;
        for(auto b : trubs){
          matrix[z].erase(matrix[z].cbegin() + b - kolvo);
          kolvo = kolvo + 1;
        }
      }
      i = -1;
    }
    kolvo = 0;
    trubs.clear();
  }
  return top_sort_mas;
}





int main()
{
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    Truba truba;
    Ks ks;
    bool wall = true;
    string sms;

    vector<string> matrix;
    string otkuda;
    string kuda;
    string t;
    string bb;
    bool wall_1 = false;
    bool wall_2 = false;
    vector<vector<string>> graf;
    vector<vector<float>> graf_L;
    vector<vector<float>> graf_proizvod;
    vector<vector<string>> graf_2 = graf;


    vector<int> mas_j;






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
            string name_1 = "ID_" + truba.del();

            int chislochek;

            cout << "ЭТО имя = " << name_1 << endl;
            for(int i = 0; i < graf.size(); i++){
              for(int j = 0; j < graf[i].size(); j++){
                if(graf[i][j] == name_1){
                  chislochek = j;
                }
              }
            }
            for(int i = 0; i < graf.size(); i++){
              graf[i].erase(graf[i].begin() + chislochek);
              graf_L[i].erase(graf_L[i].begin() + chislochek);
              graf_proizvod[i].erase(graf_proizvod[i].begin() + chislochek);
            }
            for(int i = 0; i < graf.size(); i++){
              for(int j = 0; j < graf[i].size(); j++){
                cout << graf[i][j] << " ";
              }
              cout << "" << endl;
            }
            graf_2 = graf;
            matrix = topolog_sort(graf);


            for(int i = 0; i < graf_2.size(); i++){
              for(int j = 0; j < matrix.size(); j++){
                if(graf_2[i][0] == matrix[j]){
                  graf[i] = graf_2[j];
                }
              }
            }

            for(int i = 0; i < graf.size(); i++){
              for(int j = 0; j < graf[i].size(); j++){
                cout << graf[i][j] << " ";
              }
              cout << "" << endl;
            }
            matrix.clear();
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
          string name = "KS_" + ks.del();

          cout << "ЭТО имя = " << name << endl;

          vector<int> plus;

          int schitala = 0;

          for(int i = 0; i < graf.size(); i++){
              if(name == graf[i][0]){
                for(int j = 1; j < graf[i].size(); j++){
                  if(graf[i][j] != "0"){
                    plus.push_back(j);
                  }
                }
                graf.erase(graf.begin() + i);
                graf_L.erase(graf_L.begin() + i);
                graf_proizvod.erase(graf_proizvod.begin() + i);
              }
            }

            for(int i = 0; i < graf.size(); i++){
              for(auto j : plus){
                graf[i].erase(graf[i].begin() + j - schitala);
                graf_L[i].erase(graf_L[i].begin() + j - schitala);
                graf_proizvod[i].erase(graf_proizvod[i].begin() + j - schitala);
                schitala = schitala + 1;
              }
              schitala = 0;
            }
            for(int i = 0; i < graf.size(); i++){
              for(int j = 0; j < graf[i].size(); j++){
                cout << graf[i][j] << " ";
              }
              cout << "" << endl;
            }
            graf_2 = graf;
            matrix = topolog_sort(graf);


            for(int i = 0; i < graf_2.size(); i++){
              for(int j = 0; j < matrix.size(); j++){
                if(graf_2[i][0] == matrix[j]){
                  graf[i] = graf_2[j];
                }
              }
            }

            for(int i = 0; i < graf.size(); i++){
              for(int j = 0; j < graf[i].size(); j++){
                cout << graf[i][j] << " ";
              }
              cout << "" << endl;
            }
            matrix.clear();
          }

        if (sms == "8"){
            ks.search();
        }

        if (sms == "9"){
            ks.show();
        }

        if (sms == "10"){ // создание вектора

          graf.clear();
          graf_L.clear();
          graf_2.clear();

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

                wall_1 = false;
                wall_2 = false;
                bool truba_bool = false;
                cout << "Truba_";
                cin >> t;
                cout << "" << endl;

                for(auto i : truba.id){
                  if(("ID_" + t) == i ){
                    truba_bool = true;
                  }
                }
                if(truba_bool == false){
                  cout << "Нема такой трубы" << endl;
                  continue;
                }



                for(int i = 0; i < graf.size(); i++){
                  for(int j = 0; j < graf[i].size(); j++){
                    if(("ID_" + t) == graf[i][j]){
                      truba_bool = false;
                    }
                  }
                }
                if(truba_bool == false){
                  cout << "Эта труба уже используется" << endl;
                  continue;
                }




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

              for(int i = 0; i < graf.size(); i++){
                for(int j = 0; j < graf[i].size(); j++){
                  cout << graf[i][j] << " ";
                }
                cout << "" << endl;
              }
              cout << "" << endl;


              graf_2 = graf;
              matrix = topolog_sort(graf);


              for(int i = 0; i < graf_2.size(); i++){
                for(int j = 0; j < matrix.size(); j++){
                  if(graf_2[i][0] == matrix[j]){
                    graf[i] = graf_2[j];
                  }
                }
              }

              for(int i = 0; i < graf.size(); i++){
                for(int j = 0; j < graf[i].size(); j++){
                  cout << graf[i][j] << " ";
                }
                cout << "" << endl;
              }



              for(int i = 0; i < graf.size(); i++){
                graf_L.push_back({0});
                graf_proizvod.push_back({0});
                for(int j = 1; j < graf[i].size(); j++){
                  if(graf[i][j] == "0"){
                    graf_L[i].push_back(0);
                    graf_proizvod[i].push_back(0);
                  }else{
                    if(graf[i][j][0] != '-'){
                      for(int z = 0; z < truba.id.size(); z++){
                        if(graf[i][j] == truba.id[z]){
                          graf_L[i].push_back(truba.l[z]);
                          graf_proizvod[i].push_back(pow(truba.diametr[z], 5) / truba.l[z]);
                        }
                      }
                    }else{
                      graf_L[i].push_back(0);
                      graf_proizvod[i].push_back(0);
                    }
                  }
                }
              }

              for(int i = 0; i < graf.size(); i++){
                for(int j = 0; j < graf[i].size(); j++){
                  cout << graf_L[i][j] << " ";
                }
                cout << "" << endl;
              }
              cout << "--------------" << endl;
              for(int i = 0; i < graf.size(); i++){
                for(int j = 0; j < graf[i].size(); j++){
                  cout << graf_proizvod[i][j] << " ";
                }
                cout << "" << endl;
              }
              matrix.clear();
            }

          if(sms == "11"){
            matrix = topolog_sort(graf);
            for(auto i : matrix){
              cout << i << " ";
            }
            cout << "" << endl;
            matrix.clear();
          }
          if(sms == "12"){

            wall = false;

            int a = 0;
            graf_2 = graf;
            int b = graf_2.size();
            int kolvo_1 = 0;
            int kolvo_2 = 0;
            int k = 0;
            float dlina_1 = 0;
            vector<float> dlina_2;
            vector<int> branching;
            vector<float> len_t;
            vector<int> index_i;
            mas_j.clear();
            len_t.clear();
            index_i.clear();
            dlina_2.clear();
            branching.clear();
            int j_pos = 0;
            int i_pos = 0;
            int finish_circle = -1;

            graf_2 = graf;


            cout << "Откуда = ";
            cin >> otkuda;
            cout << "" << endl;
            cout << "Куда = ";
            cin >> kuda;
            cout << "" << endl;

            for(int i = 0; i < graf_2.size(); i++){
              if(graf_2[i][0] == ("KS_" + otkuda)){
                a = i;
                wall = true;
                for(int j = 1; j < graf_2[i].size(); j++){
                  if(graf_2[i][j] != "0"){
                    if(graf_2[i][j][0] != '-'){
                      k++;
                      kolvo_1 = kolvo_1 + 1;
                      mas_j.push_back(j);
                    }else{
                      kolvo_1 = kolvo_1 + 1;
                      mas_j.insert(mas_j.begin() + mas_j.size() - k, j * (-1));
                    }
                  }
                }
                k = 0;
              }
              if(graf_2[i][0] == ("KS_" + kuda)){
                b = i;
                for(int j = 1; j < graf_2[i].size(); j++){
                  if(graf_2[i][j] != "0"){
                    if(graf_2[i][j][0] != '-'){
                      k++;
                      kolvo_2 = kolvo_2 + 1;
                      mas_j.push_back(j);
                    }else{
                      kolvo_2 = kolvo_2 + 1;
                      mas_j.insert(mas_j.begin() + mas_j.size() - k, j * (-1));
                    }
                  }
                }
                k = 0;
              }
              if((wall == true) and (i > a) and (i < b)){
                for(int j = 1; j < graf_2[i].size(); j++){
                  if(graf_2[i][j] != "0"){
                    if(graf_2[i][j][0] != '-'){
                      k++;
                      mas_j.push_back(j);
                    }else{
                      mas_j.insert(mas_j.begin() + mas_j.size() - k, j * (-1));
                    }
                  }
                }
                k = 0;
              }
            }
            for(int i = 0; i < mas_j.size(); i++){
              cout << mas_j[i] << " ";
            }
            cout << "" << endl;

            if(a > b){
              cout << "НЕ может прийти" << endl;
            }else{
              if(a == b){
                cout << "Путь равен НУЛЮ" << endl;
              }else{

                k = a;
                int remember_el;
                wall = false;
                bool wall_2 = false;
                for(int i = i_pos; i < mas_j.size(); i++){
                  if((dlina_1 == 0) or (wall_2 == true)){
                    remember_el = k;
                    wall_2 = false;
                  }else{
                    remember_el = k + 1;
                  }
                  if(mas_j[i] > 0){
                    j_pos = i;
                    if(mas_j[i+1] < 0){
                      wall = false;
                    }
                    for(int j = j_pos; j < mas_j.size(); j++){
                      if((mas_j[j - 1] < 0) and (mas_j[j] > 0)){
                        k = k + 1;
                      }
                      if(mas_j[i] == (mas_j[j] * (-1))){
                        dlina_1 = dlina_1 + graf_L[remember_el][mas_j[i]];
                        i_pos = j;
                        wall = true;
                        if((j + 1)> (mas_j.size() - kolvo_2)){
                          len_t.push_back(dlina_1);
                          if(branching.size() == 0){
                            finish_circle = finish_circle + 1;
                            dlina_1 = 0;
                            k = a;
                            i_pos = finish_circle;
                            wall = false;
                          }else{
                            i_pos = branching[branching.size() - 1];
                            dlina_1 = dlina_2[dlina_2.size() - 1];
                            dlina_2.pop_back();
                            branching.pop_back();
                            k = index_i[index_i.size() - 1];
                            index_i.pop_back();
                            wall_2 = true;
                          }
                        } // отвечает за продвижение старта
                        i = i_pos;
                        break;
                      }
                      if((mas_j[j + 1] > 0) and (wall == true) and (mas_j[j] > 0)){
                        branching.push_back(j); // size - 1
                        index_i.push_back(k);
                        dlina_2.push_back(dlina_1);
                        wall = false;
                        continue;
                      }
                    }
                  }
                  if(finish_circle == (kolvo_1 - 1)){
                    break;
                  }
                }

                for(int i = 0; i < len_t.size(); i++){
                  cout << len_t[i] << " ";
                }
                cout << "" << endl;
                i_pos = len_t[0];
                for(int i = 0; i < len_t.size(); i++){
                  if(len_t[i] < i_pos){
                    i_pos = len_t[i];
                  }
                }
                cout << i_pos << endl;

              }
            }
            wall = true;

          }

          if(sms == "13"){
            if(graf.size() > 0){
              float cheese = graf_proizvod[0][0];
              for(int i = 0; i < graf_proizvod.size(); i++){
                for(int j = 0; j < graf_proizvod[i].size(); j++){
                  if(graf_proizvod[i][j] > cheese){
                    cheese = graf_proizvod[i][j];
                  }
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
