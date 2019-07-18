#include "Cliente.h"
#include <string>
#include <iostream>

//CONSTRUTORES
Cliente::Cliente(std::string nome, std::string endereco, long long cpf, double divida){
	Nome = nome;
	Endereco = endereco;
	CPF = cpf;
	Divida = divida;
}
Cliente::Cliente(){
	
	Nome = "";
	Endereco = "";
	CPF = 00000000000;
	Divida = 0.0;
}
//GETTERS
std::string Cliente::getNome(){
	return Nome;
}
std::string Cliente::getEndereco(){
	return Endereco;
}
long long Cliente::getCpf(){
	return CPF;
}
double Cliente::getDivida(){
	return Divida;
}
//SETTERS
void Cliente::setNome(std::string nome){
	Nome = nome;
}
void Cliente::setEndereco(std::string endereco){
	Endereco = endereco;
}
void Cliente::setCpf(long cpf){
	CPF = cpf;
}
void Cliente::setDivida(double divida){
	Divida = divida;
}
//FUNCAO SHOWDADOS CLIENTE
void Cliente::showDadosCliente(){
	std::cout << "\n Nome - " << Cliente::Nome;
	std::cout << "\n Endereco - "<< Cliente::Endereco; ;
	std::cout << "\n CPF - " << Cliente::CPF;
	std::cout << "\n Divida - " << Cliente::Divida;
}

