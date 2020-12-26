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
  vector<float> l = {1, 4, 2};
  bool wall = false;

  string otkuda;
  string kuda;

  int a = 0;
  int b = matrix.size();
  int kolvo_1 = 0;
  int kolvo_2 = 0;
  vector<string> position_start;
  vector<string> position_finish;

  vector<string> len_t;
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
            kolvo_1 = kolvo_1 + 1;
            mas_j.push_back(j);
          }else{
            kolvo_1 = kolvo_1 + 1;
            mas_j.push_back(j * (-1));
          }
        }
      }
    }
    if(matrix[i][0] == ("KS_" + kuda)){
      b = i;
      for(int j = 1; j < matrix[i].size(); j++){
        if(matrix[i][j] != "0"){
          // position_finish.push_back();
          if(matrix[i][j][0] != '-'){
            kolvo_2 = kolvo_2 + 1;
            mas_j.push_back(j);
          }else{
            kolvo_2 = kolvo_2 + 1;
            mas_j.push_back(j * (-1));
          }
        }
      }
    }
    if((wall == true) and (i > a) and (i < b)){
      for(int j = 1; j < matrix[i].size(); j++){
        if(matrix[i][j] != "0"){
          // position_finish.push_back();
          if(matrix[i][j][0] != '-'){
            mas_j.push_back(j);
          }else{
            mas_j.push_back(j * (-1));
          }
        }
      }
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
  cout << "Количество_1 = " << kolvo_1 << endl;
  cout << "Количество_2 = " << kolvo_2 << endl;
  cout << "Длина массива = " << mas_j.size() << endl;
  vector<int> branching;
  if(a > b){
    cout << "НЕ может прийти" << endl;
  }else{
    if(a == b){
      cout << "Путь равен НУЛЮ" << endl;
    }else{
      // for(int i = i_pos; i < (mas_j.size() - kolvo_2); i++){
      //   if(mas_j[i] > 0){
      //     j_pos = i + 1;
      //     for(int j = j_pos; j < mas_j.size(); j++){
      //       if(mas_j[i] == (mas_j[j] * (-1))){
      //       //  wall = true;
      //         if((j + 1) > (mas_j.size() - kolvo_2)){
      //           for(int z = 0; z < mas_x.size(); z++){ // как-то пройтись по остатку
      //             if(mas_j[j] == (mas_x[z] * (-1))){
      //               k = k + 1;
      //               i_pos = k;
      //               break;
      //             }
      //           }
      //         }
      //         i_pos = j;
      //         break;
      //       }
      //     }
      //   }
      //   if(k == kolvo_1){
      //     break;
      //   }
      // }

      // wall = true;
      wall = false;

      for(int i = i_pos; i < mas_j.size(); i++){
        cout << "i = " << i << endl;
        if(mas_j[i] > 0){
          j_pos = i;
          if(mas_j[i+1] < 0){
            wall = false;
          }
          cout << "j_pos = " << j_pos << endl;
          for(int j = j_pos; j < mas_j.size(); j++){
            cout << "ХУЕТА = " << j << endl;
            if(mas_j[i] == (mas_j[j] * (-1))){
              cout << "Зашала в проверку на одинаковые элемы" << endl;
              i_pos = j;
              cout << "i_pos_posle = " << i_pos << endl;
              wall = true;
              if((j + 1)> (mas_j.size() - kolvo_2)){
                if(branching.size() == 0){
                  cout << "branching.size" << endl;
                  finish_circle = finish_circle + 1;
                  i_pos = finish_circle;
                  wall = false;
                }else{
                  cout << "Удаление элемента" << endl;
                  i_pos = branching[branching.size() - 1];
                  branching.pop_back();
                }
              } // отвечает за продвижение старта
              i = i_pos;
              break;
            }
            //cout << "Значение стены = " << wall << endl;
            if((mas_j[j + 1] > 0) and (wall == true) and (mas_j[j] > 0)){
              cout << "Контейнер маркеров" << endl;
              branching.push_back(j); // size - 1
              for(int z = 0; z < branching.size(); z++){
                cout << branching[z] << " ";
              }
              cout << "" << endl;

              wall = false;
              continue;
            }
          }
        }
        if(finish_circle == (kolvo_1 - 1)){
          break;
        }
      }
      cout << "Что-то = " << finish_circle << endl;
    }
  }
}
