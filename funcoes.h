/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   funcoes.h
 * Author: marqu
 *
 * Created on 3 de dezembro de 2022, 09:01
 */

#ifndef FUNCOES_H
#define FUNCOES_H
#include <string>
#include <cstring>
using namespace std;
 struct prof {
    string nome;
    int turma[10];
};

class funcoes {
    
   


public:
    funcoes();
    funcoes(const funcoes& orig);
    virtual ~funcoes();
    
    void zerar_prof();
    void zerar_resultado ();
    bool isNumber (string str);
    void arquivo_man();
    void zerar_matriz();
    
    void grafo();
    void imprime_resultado();
    
private:
    prof professores[10], resultado[10];
    string vetor[100];
    int cont_prof, cont_linhas, matriz[10][10], indice_colunas[10], linhas_matriz;

};

#endif /* FUNCOES_H */

