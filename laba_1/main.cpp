#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;




int main() {



    vector<float> l = { 1,2,3 };
    vector<float> d = { 1,2,3 };
    vector<string> id_truba = { "id 1", "id 2", "id 3" };
    vector<bool> repaies = { true, false, true };
    int schet_t = 3;


    vector<float> ceh{ 1,2,3 };
    vector<float> jober{ 1,2,3 };
    vector<string> id_ks{ "id 1","id 2","id 3" };
    int schet_k = 3;




    string ves;
    float chiki;

    cout << "337.Menu" << endl;
    cout << "1.add truba" << endl;
    cout << "2.add ks" << endl;
    cout << "3.get truba, ks" << endl;
    cout << "4.eddit truba" << endl;
    cout << "5.eddit ks" << endl;
    cout << "6.get diametr, lenght " << endl;
    cout << "7.get jober " << endl;
    cout << "0.exit" << endl;

    bool jir = true;

            while (jir == true) {
                cout << "input: ";
                cin >> ves;
                if (ves == "1") {
                    cout << "--------------------" << endl;
                    cout << "input id: ";
                    cin >> ves;
                    id_truba.push_back(ves);
                    schet_t = schet_t + 1;
                    cout << "diametr: " << endl;
                    cin >> chiki;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100000, '\n');
                        cout << "Mistake\n" << endl;
                        continue;
                    }
                    else {
                        d.push_back(chiki);
                        cout << "lenght: " << endl;

                    };
                    cin >> chiki;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100000, '\n');
                        cout << "Mistake\n" << endl;
                    }
                    else
                    {
                        l.push_back(chiki);
                    };
                };
                if (ves == "2") {
                    cout << "--------------------" << endl;
                    cout << "input id: ";
                    cin >> ves;
                    cout << "" << endl;
                    id_ks.push_back(ves);
                    schet_k = schet_k + 1;
                    cout << "input jober: ";
                    cin >> chiki;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100000, '\n');
                        cout << "Mistake\n" << endl;
                        continue;
                    }
                    else {

                        jober.push_back(chiki);
                    };
                    cout << "" << endl;

                };
                if (ves == "3") {
                    cout << "--------------------" << endl;
                    for (int i = 0; i <= (schet_t - 1); i++) {
                        cout << "Truba: " << id_truba[i] << " ";
                    };
                    cout << "" << endl;
                    cout << "--------------------" << endl;

                    for (int i = 0; i <= (schet_k - 1); i++) {
                        cout << "KS: " << id_ks[i] << " ";
                    };
                    cout << "" << endl;
                };
                if (ves == "4") {
                    cout << "--------------------" << endl;
                    cout << "1.diametr: " << endl;
                    cout << "2.radius: " << endl;
                    cout << "input = ";
                    cin >> ves;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100000, '\n');
                        cout << "Mistake\n" << endl;
                        continue;
                    }
                    else {

                    };

                    if (ves == "1") {
                        cout << "input id =" << endl;
                        cin >> ves;
                        cout << "diametr = " << endl;
                        cin >> chiki;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(100000, '\n');
                            cout << "Mistake\n" << endl;
                            continue;
                        }
                        else {

                            for (int i = 0; i <= (schet_t - 1); i++) {
                                if (id_truba[i] == ves) {
                                    d[i] = chiki;
                                };
                            };

                        };

                    };
                    if (ves == "2") {
                        cout << "--------------------" << endl;

                        cout << "input id= " << endl;
                        cin >> ves;
                        cout << "lenght = " << endl;
                        cin >> chiki;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(100000, '\n');
                            cout << "Mistake\n" << endl;
                            continue;
                        }
                        else {

                            for (int i = 0; i <= (schet_t - 1); i++) {
                                if (id_truba[i] == ves) {
                                    l[i] = chiki;
                                };
                            };
                        };




                    };
                };
                if (ves == "5") {
                    cout << "--------------------" << endl;
                    cout << "id ks: ";
                    cin >> ves;
                    cout << "kol-vo jober: ";
                    cin >> chiki;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100000, '\n');
                        cout << "Mistake\n" << endl;
                        continue;
                    }
                    else {

                        for (int i = 0; i <= (schet_k - 1); i++) {
                            if (id_ks[i] == ves) {
                                jober.push_back(chiki);
                            };
                        };
                    };




                };
                if (ves == "6") {
                    cout << "--------------------" << endl;
                    cout << "Diametr: " << endl;
                    for (int i = 0; i <= (schet_t - 1); i++) {
                        cout << d[i] << " ";
                    };
                    cout << "" << endl;
                    cout << "--------------------" << endl;
                    cout << "Lenght: " << endl;
                    for (int i = 0; i <= (schet_t - 1); i++) {
                        cout << l[i] << " ";
                    };
                    cout << "" << endl;
                };
                if (ves == "7") {
                    cout << "--------------------" << endl;
                    cout << "Jober: " << endl;
                    for (int i = 0; i <= (schet_t - 1); i++) {
                        cout << jober[i] << " ";
                    };
                    cout << "" << endl;
                };
                if (ves == "0") {
                    jir = false;
                };
                if (ves == "337") {

                    cout << "337.Menu" << endl;
                    cout << "1.add truba" << endl;
                    cout << "2.add ks" << endl;
                    cout << "3.get truba, ks" << endl;
                    cout << "4.eddit truba" << endl;
                    cout << "5.eddit ks" << endl;
                    cout << "6.get diametr, lenght " << endl;
                    cout << "7.get jober " << endl;
                    cout << "0.exit" << endl;

                };

            };
                ofstream outf("laba_1_data.txt");
                outf << "Truba:"<< endl;
                for(int i = 0; i <= (schet_t - 1); i++){
                  outf << "id = '" << id_truba[i] <<"' ";
                  outf << "l = " << l[i] << " ";
                  outf << "d = "<< d[i]<<endl;
                };
                outf << "Ks:" << endl;
                for(int i = 0; i <= (schet_k - 1); i++){
                  outf << "id = '" << id_ks[i] <<"' ";
                  outf << "ceh = " << ceh[i] << " ";
                  outf << "jober = "<< jober[i]<<endl;
                };
                outf.close();
        };
