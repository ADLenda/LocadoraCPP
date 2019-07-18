#include <string>

class Cliente{
	private:
		std::string Nome, Endereco;
		long long CPF;
		double Divida;
		
	public:
		//CONSTRUTORES
		Cliente();
		Cliente(std::string nome, std::string endereco, long long cpf, double divida);
		//GETTERS
		std::string getNome();
		std::string getEndereco();
		long long getCpf();
		double getDivida();
		//SETTERS
		void setNome(std::string nome);
		void setEndereco(std::string endereco);
		void setCpf(long cpf);
		void setDivida(double divida);
		//FUNCAO SHOWDADOS CLIENTE
		void showDadosCliente();
};
