#include <string>

class Aluguel{
	private:
		int idAluguel;
		std::string Placa;
		long long CPF;
		std::string DataInicial;
		std::string DataFinal;
	
	public:
		//CONSTRUTORES
		Aluguel();
		Aluguel(std::string placa, long long cpf, std::string dataInicial, std::string dataFinal, int tipoAlug);
		//GETTERS
		int getIdAluguel();
		std::string getPlacaAlug();
		long long getCPFAlug();
		std::string getDataInicial();
		std::string getDataFinal();
		//SETTERS
		void setIdAluguel(int tipo);
		void setDataInicial(std::string dataInicial);
		void setDataFinal(std::string dataFinal);
		//FUNCAO SHOWDADOS ALUGUEL
		void showDadosAluguel();		
};

