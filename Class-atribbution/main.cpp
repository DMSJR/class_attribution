/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: marqu
 *
 * Created on 16 de julho de 2022, 21:57
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <valarray>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 
 */

struct prof {
    string nome;
    int turma[10];
};

bool isNumber(string str) {
    int i;
    for (i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == 0) return false;
    }
    return true;
}

int main(int argc, char** argv) {
    int num, i, k, j, m, x, q, tam_matriz;
    int cont_prof = 0;
    

    i = 0;
    string vetor[100];
    prof professores[10];
    stringstream ss;
    for (int j =0; j<10; j++){
    for (int i =0; i<10; i++){
        professores[j].turma[i] = 0;
    }
    }

    fstream arquivo;

    arquivo.open("arquivo.txt");
    if (arquivo.is_open()) {
        do {
            getline(arquivo, vetor[i], '\n');

            i = i + 1;

        } while (!arquivo.eof());
    } else {
        cout << "arquivo nao pode ser aberto";
    }
    ss << vetor [0];
    ss >> num;

    for (k = 0; k < i - 1; k++) {
        vetor[k] = vetor[k].erase(vetor[k].length() - 1);
        
    }

    k = 0;
    j = 0;

    for (m = 1; vetor[m] != "$"; m++) {

        if (isNumber(vetor[m])) {
            
            stringstream ss;
            ss << vetor [m];

            ss >> x;

            professores[k].turma[j] = x;
            

            j = j + 1;
            if (!isNumber(vetor[m + 1])) {
                k = k + 1;
            }
        } else {
            professores[k].nome = vetor[m];
           
            cont_prof++;


            j = 0;

        }

    }

    if (vetor[m] == "$") {

        ss << vetor [m + 1];

        ss >> tam_matriz;
        
    }
    int matriz[tam_matriz + 1][tam_matriz + 1];
    int indices_colunas[tam_matriz + 1];
    for (int i = 0; i < tam_matriz; i++) {
        for (int j = 0; j < tam_matriz; j++) {
            matriz[i][j] = 0;
        }
    }

    int linhas = 0;
    for (m; m <= i; m++) {
        if (vetor[m] == "%") {


            int coluna = 0;


            for (q = m + 1; vetor[q] != "%"; q++) {
                if (vetor[q] == "#")
                    break;
                stringstream ss;
                ss << vetor[q];
                ss >> matriz[linhas][coluna];

                
                if (coluna == tam_matriz) {
                    break;
                }
                coluna++;


            }
            m = q - 1;


            indices_colunas[linhas] = coluna - 1;
            linhas++;




        }
    }
   

    bool verifica = true;
    bool verifica2 = true;
    prof resultado[cont_prof];
    
    for (int i = 0; i < cont_prof; i++) {
        for (int j = 0; j < 10; j++) {
            resultado[i].turma[j] = 0;
        }
    }


    int turma, turmaC, proff;
    for (int i = 0; i < linhas; i++) {
       
        for (int j = 1; j <= indices_colunas[i]; j++) {

            
            turma = matriz[i][j];
            
            for (int r = 0; r < cont_prof; r++) {
                
                for (int b = 0; b < 10; b++) {
                    if ((professores[r].turma[b] == turma)) {
                        verifica2 = false;
                        
                    }
                }
                
                
                verifica = true;
                for (int n = 0; n < 10; n++) {
                    if (verifica2 == false)
                                verifica = false;


                    turmaC = resultado[r].turma[n];
                    
                    
                    for (int k = 0; k < (indices_colunas[i]); k++) {
                        

                        if (matriz[i][k + 1] == turmaC) {

                            verifica = false;
                            



                        }

                    }
                }

                proff = r;
                
                if (verifica == true)
                    break;
                verifica = true;
                verifica2 = true;
            }

            if (resultado[proff].turma[0] == 0) {
                resultado[proff].turma[0] = turma;



            } else {

                for (int p = 9; p >= 0; p--) {

                    if (resultado[proff].turma[p] != 0) {

                        resultado[proff].turma[p + 1] = turma;
                        break;
                    }

                }

            }
            verifica = true;

        }
    }





    for (int j = 0; j < 3; j++) {
        cout <<professores[j].nome<<": ";
        for (int i = 0; i < 10; i++) {
            if (resultado[j].turma[i] == 0)
                break;
            cout << resultado[j].turma[i] << "\t";

        }
        cout << endl;
    }
    return 0;
}

