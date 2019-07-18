#include "Carro.h"
#include <string>
#include <iostream>


//CONSTRUTOR
Carro::Carro(std::string marca, std::string placa, std::string modelo, int situacao, double taxaKm, double taxaDiaria, double Km){
	Marca = marca;
	Placa = placa;
	Modelo = modelo;
	Situacao = situacao;
	TaxaKM = taxaKm;
	TaxaDiaria = taxaDiaria;
	KM = Km;
}
Carro::Carro(){
	Marca = "";
	Placa = "";
	Modelo = "";
	Situacao = 0;
	TaxaKM = 0.0;
	TaxaDiaria = 0.0;
	KM = 0.0;
}

//GETTERS
std::string Carro::getMarca(){
	return Marca;
}
std::string Carro::getPlaca(){
	return Placa;
}
std::string Carro::getModelo(){
	return Modelo;
}
int Carro::getSituacao(){
	return Situacao;
}
double Carro::getTaxaDiaria(){
	return TaxaDiaria;
}
double Carro::getTaxaKm(){
	return TaxaKM;
}
double Carro::getKM(){
	return KM;
}
//SETTERS
void Carro::setMarca(std::string marca){
	Marca = marca;
}
void Carro::setPlaca(std::string placa){
	Placa = placa;
}
void Carro::setModelo(std::string modelo){
	Modelo = modelo;
}
void Carro::setSituacao(int situacao){
	Situacao = situacao;
}
void Carro::setTaxaDiaria(double taxaDiaria){
	TaxaDiaria = taxaDiaria;
}
void Carro::setTaxaKM(double taxaKm){
	TaxaKM = taxaKm;
}
void Carro::setKM(double Km){
	KM = Km;
}

//FUNCAO SHOWDADOS CARRO
void Carro::showDadosCarro(){
	std::cout << "\n Marca - " << Carro::Marca;
	std::cout << "\n Modelo - " << Carro::Modelo;
	std::cout << "\n Placa - " << Carro::Placa;
	std::cout << "\n Situacao - " << Carro::Situacao;
	std::cout << "\n Taxa Diaria - " << Carro::TaxaDiaria;
	std::cout << "\n Taxa por KM - " << Carro::TaxaKM;
	std::cout << "\n Kilometragem - " << Carro::KM;
}

