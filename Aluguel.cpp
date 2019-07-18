#include "Carro.h"
#include "Cliente.h"
#include "Aluguel.h"
#include <string>
#include <iostream>

Aluguel::Aluguel(std::string placa, long long cpf,std::string dataInicial, std::string dataFinal,int tipoAlug){
	
	Placa = placa;
	CPF = cpf;
	DataInicial = dataInicial;
	DataFinal = dataFinal;
	idAluguel = tipoAlug;
}
Aluguel::Aluguel(){
	
	Placa = " ";
	CPF = 00000000000;
	DataInicial = " ";
	DataFinal = " ";
	idAluguel = 0;
}
//GETTERS
int Aluguel::getIdAluguel(){
	return idAluguel;
}
std::string Aluguel::getPlacaAlug(){
	return Placa;
}
long long Aluguel::getCPFAlug(){
	return CPF;
}
std::string Aluguel::getDataFinal(){
	return DataFinal;
}
std::string Aluguel::getDataInicial(){
	return DataInicial;
}
//SETTERS
void Aluguel::setIdAluguel(int tipo){
	idAluguel = tipo;
}
void Aluguel::setDataFinal(std::string dataFinal){
	DataFinal = dataFinal;
}
void Aluguel::setDataInicial(std::string dataInicial){
	DataInicial = dataInicial;
}
//FUNCAO SHOWDADOS ALUGUEL
void Aluguel::showDadosAluguel(){
	std::cout << "\n Placa - " << Aluguel::Placa;
	std::cout << "\n CPF - " << Aluguel::CPF;
	std::cout << "\n Tipo do Aluguel - " << Aluguel::idAluguel;
	std::cout << "\n Alugado em - " << Aluguel::DataInicial;
	std::cout << "\n Devolvido em - " << Aluguel::DataFinal;
}
