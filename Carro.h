#include <string>

class Carro {
	private:
		std::string Marca, Placa, Modelo;
		int Situacao;
		double TaxaKM, TaxaDiaria, KM;
	
	public:
		//CONSTRUTORES
		Carro(std::string marca, std::string placa, std::string modelo, int situacao, double taxaKM, double taxaDiaria, double Km);
		Carro();
		//GETTERS
		std::string getMarca();
		std::string getPlaca();
		std::string getModelo();
		int getSituacao();
		double getTaxaKm();
		double getTaxaDiaria();
		double getKM();
		//SETTERS
		void setMarca(std::string marca);
		void setPlaca(std::string placa);
		void setModelo(std::string modelo);
		void setSituacao(int situacao);
		void setTaxaKM(double taxaKm);
		void setTaxaDiaria(double taxaDiaria);
		void setKM(double Km);
		//FUNCAO SHOW DADOS
		
		void showDadosCarro();
		
		

};
