#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[]) {

  vector<vector<string>> matrix = {
    {"KS_1", "ID_1", "ID_2", "0", "0", "0", "0", "0", "0", "0"},
    {"KS_3", "0", "-ID_2", "ID_3", "ID_5", "0", "0", "0", "0", "ID_9"},
    {"KS_2", "-ID_1", "0", "-ID_3", "0", "ID_4", "0", "0", "0", "0"},
    {"KS_4", "0", "0", "0", "-ID_5", "0", "ID_6", "ID_8", "0", "-ID_9"},
    {"KS_5", "0", "0", "0", "0", "-ID_4", "-ID_6", "0", "ID_7", "0"},
    {"KS_6", "0", "0", "0", "0", "0", "0", "-ID_8", "-ID_7", "0"},
  };
  vector<vector<float>> graf_2 = {
    {0, 1, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, -2, 3, 5, 0, 0, 0, 0, 9},
    {0, -1, 0, -3, 0, 4, 0, 0, 0, 0},
    {0, 0, 0, 0, -5, 0, 6, 8, 0, -9},
    {0, 0, 0, 0, 0, -4, -6, 0, 7, 0},
    {0, 0, 0, 0, 0, 0, 0, -8, -7, 0},
  };
  vector<float> l = {1, 4, 2};
  bool wall = false;

  string otkuda;
  string kuda;

  int a = 0;
  int b = matrix.size();
  int kolvo_1 = 0;
  int kolvo_2 = 0;
  int k = 0;
  vector<string> position_start;
  vector<string> position_finish;

  vector<int> mas_j;

  cout << "Откуда = ";
  cin >> otkuda;
  cout << "" << endl;
  cout << "Куда = ";
  cin >> kuda;
  cout << "" << endl;

  for(int i = 0; i < matrix.size(); i++){
    if(matrix[i][0] == ("KS_" + otkuda)){
      a = i;
      wall = true;
      for(int j = 1; j < matrix[i].size(); j++){
        if(matrix[i][j] != "0"){
          // position_finish.push_back();
          if(matrix[i][j][0] != '-'){
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
    if(matrix[i][0] == ("KS_" + kuda)){
      b = i;
      for(int j = 1; j < matrix[i].size(); j++){
        if(matrix[i][j] != "0"){
          // position_finish.push_back();
          if(matrix[i][j][0] != '-'){
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
      for(int j = 1; j < matrix[i].size(); j++){
        if(matrix[i][j] != "0"){
          // position_finish.push_back();
          if(matrix[i][j][0] != '-'){
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

//  wall = false;
  int j_pos = 0;
  int i_pos = 0;
  int finish_circle = -1;

  if(a > b){
    cout << "НЕ может прийти" << endl;
  }else{
    if(a == b){
      cout << "Путь равен НУЛЮ" << endl;
    }else{

      float dlina_1 = 0;
      vector<float> dlina_2;
      vector<int> branching;
      vector<float> len_t;
      vector<int> index_i;
      k = a;
      int remember_el;
      wall = false;
      for(int i = i_pos; i < mas_j.size(); i++){
        if(dlina_1 == 0){
          remember_el = k;
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
              dlina_1 = dlina_1 + graf_2[remember_el][mas_j[i]];
              cout << "Зашала в проверку на одинаковые элемы" << endl;
              cout << "i = " << i << endl;
              cout << "Значение J = " << j << endl;
              cout << "Значение K = " << k << endl;
              cout << "remember_el = " << remember_el << endl;
              cout << "Элемент графа = " << graf_2[remember_el][mas_j[i]] << endl;
              cout << "----------------"<< endl;
              i_pos = j;
              wall = true;
              if((j + 1)> (mas_j.size() - kolvo_2)){
                len_t.push_back(dlina_1);
                if(branching.size() == 0){
                  cout << "branching.size" << endl;
                  finish_circle = finish_circle + 1;
                  dlina_1 = 0;
                  k = a;
                  i_pos = finish_circle;
                  wall = false;
                }else{
                  cout << "Удаление элемента" << endl;
                  i_pos = branching[branching.size() - 1];
                  dlina_1 = dlina_2[dlina_2.size() - 1];
                  dlina_2.pop_back();
                  branching.pop_back();
                  k = index_i[index_i.size() - 1];
                  cout << "Значение K в Удаленииии = " << k << endl;
                  index_i.pop_back();
                }
              } // отвечает за продвижение старта
              i = i_pos;
              break;
            }
            //cout << "Значение стены = " << wall << endl;
            if((mas_j[j + 1] > 0) and (wall == true) and (mas_j[j] > 0)){
              cout << "Контейнер маркеров" << endl;
              branching.push_back(j); // size - 1
              index_i.push_back(k);
              dlina_2.push_back(dlina_1);
              cout << "branching: " << endl;
              for(int z = 0; z < branching.size(); z++){
                cout << branching[z] << " ";
              }
              cout << "" << endl;
              cout << "dlina_2: " << endl;
              for(int z = 0; z < dlina_2.size(); z++){
                cout << dlina_2[z] << " ";
              }
              cout << "" << endl;
              cout << "index_i: " << endl;
              for(int z = 0; z < index_i.size(); z++){
                cout << index_i[z] << " ";
              }
              cout << "" << endl;
              wall = false;
              cout << "----------------"<< endl;
              continue;
            }
          }
        }
        if(finish_circle == (kolvo_1 - 1)){
          break;
        }
      }
      cout << "Что-то = " << finish_circle << endl;

      for(int i = 0; i < len_t.size(); i++){
        cout << len_t[i] << " ";
      }
      cout << "" << endl;

    }
  }
}
