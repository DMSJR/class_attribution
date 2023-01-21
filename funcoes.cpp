/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   funcoes.cpp
 * Author: marqu
 * 
 * Created on 3 de dezembro de 2022, 09:01
 */

#include "funcoes.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

funcoes::funcoes() {
}

funcoes::funcoes(const funcoes& orig) {
}

funcoes::~funcoes() {
}

void funcoes::zerar_prof() {
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            this->professores[j].turma[i] = 0;

        }
    }
}

void funcoes::zerar_resultado() {
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            this->resultado[j].turma[i] = 0;

        }
    }
}

void funcoes::zerar_not_attributed(){
    this->not_attributed.nome = "not attributed";
    for (int i =0; i<10; i++){
        this->not_attributed.turma[i] = 0;
    }
}

bool funcoes::isNumber(string str) {
    int i;
    for (i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == 0) return false;
    }
    return true;
}

void funcoes::arquivo_man() {
    fstream arquivo;
    this->cont_linhas = 0;
    int num = 0;


    arquivo.open("arquivo.txt");
    if (arquivo.is_open()) {
        do {
            getline(arquivo, vetor[cont_linhas], '\n');

            cont_linhas += 1;

        } while (!arquivo.eof());
    } else {
        cout << "arquivo nao pode ser aberto";
    }
    stringstream ss;
    ss << vetor [0];
    ss >> this->cont_prof;

    for (int k = 0; k < cont_linhas - 1; k++) {
        vetor[k] = vetor[k].erase(vetor[k].length() - 1);

    }

    int k = 0;
    int j = 0;
    int m;
    for (m = 1; vetor[m] != "$"; m++) {

        if (isNumber(vetor[m])) {
            stringstream ss;
            ss << vetor [m];
            ss >> professores[k].turma[j];
            j = j + 1;

            if (!isNumber(vetor[m + 1])) {
                k = k + 1;
            }
        } else {
            professores[k].nome = vetor[m];
            this->cont_prof++;
            j = 0;
        }

    }
    /*for (int i =0; i <3; i++){
        for (int j = 0; j < 10; j++){
            cout <<this->professores[i].turma[j]<<" ";
        }
        cout <<endl;
    }*/
    this->linhas_matriz = 0;
    for (m; vetor[m] != "#"; m++) {

        if (this->vetor[m] == "%") {
            int coluna = 0;
            int q;
            for (q = m + 1; vetor[q] != "%"; q++) {
                if (this->vetor[q] == "#")
                    break;
                stringstream ss;
                ss << this->vetor[q];
                ss >> this->matriz[this->linhas_matriz][coluna];


                if (coluna == 9) {
                    break;
                }
                coluna++;
            }
            m = q - 1;
            this->indice_colunas[this->linhas_matriz] = coluna - 1;
            this->linhas_matriz++;
        }


    }
    
    for (m++; vetor[m] != "!"; m++){
        if (!isNumber(this->vetor[m])){
            for (k = 0; k < this->cont_prof; k++){
                if (this->vetor[m] == professores[k].nome){
                    
                    int i = 0;
                    int n;
                    for (n = m + 1; isNumber(this->vetor[n]); n++ ){
                        stringstream ss;
                        ss << this->vetor[n];
                        ss >>this->resultado[k].turma[i];
                        
                        
                        i++;
                         
                       
                    
                }
            }
        }
    }
    


}
}

void funcoes::zerar_matriz() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            this->matriz[i][j] = 0;
        }
    }
}

void funcoes::grafo() {
    bool verifica = true;
    bool verifica2 = true;
    bool verifica3 = true;





    int turma, turmaC, proff, w = 0;
    
    for (int i = 0; i < this->linhas_matriz; i++) {

        for (int j = 1; j <= this->indice_colunas[i]; j++) {


            turma = matriz[i][j];

            for (int r = 0; r < this->cont_prof; r++) {

                for (int b = 0; b < 10; b++) {
                    if ((this->professores[r].turma[b] == turma)) {
                        verifica2 = false;

                    }
                }
                verifica = true;
                for (int n = 0; n < 10; n++) {
                    if (verifica2 == false)
                        verifica = false;


                    turmaC = this->resultado[r].turma[n];


                    for (int k = 0; k < (this->indice_colunas[i]); k++) {
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
            if (this->resultado[proff].turma[0] == 0) {
                this->resultado[proff].turma[0] = turma;
                verifica3 = false;
            } else {
                for (int p = 9; p >= 0; p--) {
                    if (this->resultado[proff].turma[p] != 0) {
                        this->resultado[proff].turma[p + 1] = turma;
                        verifica3 = false;
                        break;
                    }
                }
            }
            verifica = true;
            if (verifica3 == true){
                this->not_attributed.turma[w] = turma;
                w++;
            }
            
        }
    }

}

void funcoes::imprime_resultado() {
    for (int j = 0; j < 3; j++) {
        cout << this->professores[j].nome << ": ";
        for (int i = 0; i < 10; i++) {
            if (this->resultado[j].turma[i] == 0)
                break;
            cout << this->resultado[j].turma[i] << "\t";

        }
        cout << endl;
    }
}