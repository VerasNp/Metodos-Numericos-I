#include "NewtonRaphson.hpp"
#include <stdexcept>


NewtonRaphson::NewtonRaphson(int max_iteracoes, double erro, Polinomio funcao) {
    this->set_max_iteracoes(max_iteracoes);
    this->set_erro(erro);
    this->set_funcao(funcao);
    this->set_raiz_valida(true);
}

int NewtonRaphson::get_max_iteracoes() const {
    return this->max_iteracoes;
}

void NewtonRaphson::set_max_iteracoes(int m) {
    this->max_iteracoes = m;
}

bool NewtonRaphson::get_raiz_valida() const {
    return this->raiz_valida;
}

void NewtonRaphson::set_raiz_valida(bool r) {
    this->raiz_valida = r;
}

int NewtonRaphson::get_num_passos() const {
    return this->num_passos;
}

void NewtonRaphson::set_num_passos(int n) {
    this->num_passos = n;
}

double NewtonRaphson::get_erro() const {
    return this->erro;
}

void NewtonRaphson::set_erro(double e) {
    this->erro = e;
}

Polinomio NewtonRaphson::get_funcao() const {
    return this->funcao;
}

void NewtonRaphson::set_funcao(Polinomio f) {
    this->funcao = funcao;
}

double NewtonRaphson::get_raiz() {
    if (!(this->raiz_valida)) {
        throw std::logic_error("Erro: raiz inválida, pois o método estorou o número máximo de iterações.");
    }

    if (this->iteracoes_de_x.size() < 1) {
        throw std::domain_error("Erro: raiz não calculada, chame calcula_raiz antes de acessar a raiz");
    }

    return this->iteracoes_de_x.back();
}

void NewtonRaphson::calcula_raiz(double x0) {
    /* TODO: Ismael */
}
