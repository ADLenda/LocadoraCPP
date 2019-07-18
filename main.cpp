#include "Carro.h"
#include "Cliente.h"
#include "Aluguel.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//SALVAMENTOS DAS LISTAS EM ARQUIVOS TXT	
void SalvaAluguel(std::vector<Aluguel> alug){
			std::ofstream SalvaAluguel; 
 			SalvaAluguel.open("Aluguel.txt");
			int endAlug = alug.size();
			for(int i=0;i < endAlug;i++){
			SalvaAluguel << alug[i].getPlacaAlug();
			SalvaAluguel << "\n";
			SalvaAluguel << alug[i].getCPFAlug();
			SalvaAluguel << "\n";
			SalvaAluguel << alug[i].getDataInicial();
			SalvaAluguel << "\n";
			SalvaAluguel << alug[i].getDataFinal();
			SalvaAluguel << "\n";
			SalvaAluguel << alug[i].getIdAluguel();
			SalvaAluguel << "\n";
			}
			cout << "ALUGUEIS GRAVADOS!" << endl;
			SalvaAluguel.close();
}
void SalvaCliente(std::vector<Cliente> cliente){
			//SALVA A LISTA CLIENTE NO TXT
			std::ofstream SalvaCliente; 
 			SalvaCliente.open("Cliente.txt");
	
			int endFile = cliente.size();
			for(int i=0;i < endFile;i++){
			SalvaCliente << cliente[i].getNome();
			SalvaCliente << "\n";
			SalvaCliente << cliente[i].getEndereco();
			SalvaCliente << "\n";
			SalvaCliente << cliente[i].getCpf();
			SalvaCliente << "\n";
			SalvaCliente << cliente[i].getDivida();
			SalvaCliente << "\n";
			}
			cout << "CLIENTES GRAVADOS!";
			SalvaCliente.close();
}
void SalvaCarro(std::vector<Carro> car){
		//SALVA A LISTA CARRO NO TXT
			std::ofstream SalvaCarro; 
 			SalvaCarro.open("Carro.txt");
 			Carro CarAux3;
			int endFileCar = car.size();
			for(int i=0;i < endFileCar;i++){
			CarAux3 = car[i];
			SalvaCarro << car[i].getMarca();
			SalvaCarro << "\n"; 
			SalvaCarro << CarAux3.getPlaca();
			SalvaCarro << "\n";
			SalvaCarro << CarAux3.getModelo();
			SalvaCarro << "\n";
			SalvaCarro << CarAux3.getSituacao();
			SalvaCarro << "\n";
			SalvaCarro << CarAux3.getTaxaKm();
			SalvaCarro << "\n";
			SalvaCarro << CarAux3.getTaxaDiaria();
			SalvaCarro << "\n";
			SalvaCarro << CarAux3.getKM();
			SalvaCarro << "\n";
			}
			cout << "CARROS GRAVADOS!" << endl;
			SalvaCarro.close();
}
//FUNCOES DE BUSCA NA LISTA 
int BuscaCliente(std::vector<Cliente> list, long long cpf){
	int i=0;
	for(Cliente c: list){
		if(c.getCpf() == cpf){
			return i;
		}
		i++;
	}	
	return -1;
}
int BuscaCarro(std::vector<Carro> list, std::string placa){
	int i=0;
	for(Carro c: list){
		if(c.getPlaca() == placa){
			return i;
		}
		i++;
	}	
	return -1;
}
int BuscaAluguel(std::vector<Aluguel> list, std::string placa, long long CPFa){
	int i=0;
	for(Aluguel al: list){
		if((al.getPlacaAlug() == placa) && (al.getCPFAlug() == CPFa)){
			return i;
		}
		i++;
	}
	return -1;
}
int BuscaAluguelDataIni(std::vector<Aluguel> list, std::string dataIni){
	int i=0;
	for(Aluguel al: list){
		if(al.getDataInicial() == dataIni){
			return i;
		}
		i++;
	}
	return -1;
}

//FUNCOES CONVERTE DATA
string ConverteData(int dia, int mes, int ano){
	
		std::string dataConvertida = std::to_string(dia) + "/" + std::to_string(mes)+ "/" + std::to_string(ano);
		return dataConvertida;
	
}
int pegaDia(string data){
		string dia = data.substr(0,2);
		int DiaAux = stoi(dia);
		return DiaAux;
		}
int pegaMes(string data){
		string mes = data.substr(2,2);
  		int MesAux = std::stoi (mes);
		return MesAux;
		}
int pegaAno(string data){
		string ano = data.substr(6);
		int AnoAux = stoi(ano);
		return AnoAux;
		}

int main(){
	
	std::vector<Cliente> listaCliente;
	std::vector<Carro> listaCarro;
	std::vector<Aluguel> listaAluguel;

	//FUNCAO QUE CARREGA CLIENTES DA LISTA TXT PARA O VECTOR CLIENTE
	std::ifstream CarregaCliente;
	CarregaCliente.open("Cliente.txt",ios::in);
	string aNome, aEnd;
	long long aCPF;
	double aDivida;
	
	if(CarregaCliente.is_open()){
		
		while(!CarregaCliente.eof()){
			getline(CarregaCliente,aNome);	
			if(aNome != ""){
			getline(CarregaCliente,aEnd);
			CarregaCliente >> aCPF;
			CarregaCliente >> aDivida;
			CarregaCliente.ignore();
			Cliente CliAux(aNome,aEnd,aCPF,aDivida);
			listaCliente.push_back(CliAux);
			//CliAux.showDadosCliente();
			
			}else{
				CarregaCliente.close();
			}
			
			}
	
	}else{
		CarregaCliente.close();
	}	
	//FIM DA FUNCAO CARREGACLIENTE	
	
	//FUNCAO QUE CARREGA CARROS DA LISTA TXT PARA O VECTOR CARRO

	std::ifstream CarregaCarro;
	CarregaCarro.open("Carro.txt");
	
	string aMarca, aPlaca, aModelo;
	int aSituacao;
	double aTaxaKM, aTaxaDiaria, aKM;
	
	while(!CarregaCarro.eof()){
		
		getline(CarregaCarro,aMarca);
		
		if(aMarca != ""){
		getline(CarregaCarro,aPlaca);
		getline(CarregaCarro, aModelo);
		CarregaCarro >> aSituacao;
		CarregaCarro >> aTaxaKM;
		CarregaCarro >> aTaxaDiaria;
		CarregaCarro >> aKM;
		
		Carro CarAux(aMarca,aPlaca,aModelo,aSituacao,aTaxaKM,aTaxaDiaria,aKM);
		listaCarro.push_back(CarAux);
		}
	}
	CarregaCarro.close();
	//FIM DA FUNCAO CARREGACARRO
	
	//FUNCAO QUE CARREGA ALUGUEIS DA LISTA TXT PARA O VECTOR ALUGUEL
	std::ifstream CarregaAluguel;
	CarregaAluguel.open("Aluguel.txt");
	string aPlacaAlug, aDataInicial, aDataFinal;
	long long aCPFAlug;
	int tipoALUG;
	while(!CarregaAluguel.eof()){
		
		getline(CarregaAluguel,aPlacaAlug);
		
		if(aPlacaAlug != ""){
		CarregaAluguel >> aCPFAlug;
		CarregaAluguel.ignore();
		getline(CarregaAluguel,aDataInicial);
		getline(CarregaAluguel,aDataFinal);
		CarregaAluguel >> tipoALUG;
		CarregaCliente.ignore();
		Aluguel AlugAux(aPlacaAlug,aCPFAlug,aDataInicial,aDataFinal,tipoALUG);
		listaAluguel.push_back(AlugAux);
		//AlugAux.showDadosAluguel();
		}
	}
	CarregaAluguel.close();
	

	//MENU PRINCIPAL	
	bool control = true;
	while(control){
	
	int op;
	cout << "************************* \n";
	cout << "   ALUGUEL DE CARROS    " << endl;
	cout << "         MENU           " << endl;
	cout << "1 - Cadastrar Carro     " << endl;
	cout << "2 - Cadastrar Cliente   " << endl;
	cout << "3 - Fazer Aluguel       " << endl;
	cout << "4 - Relatorios          " << endl;
	cout << "5 - Fazer Devolucao     " << endl;
	cout << "6 - Pagar Divida        " << endl;
	cout << "0 - Sair                " << endl;
	cout << "************************* \n";
	cout << "Digite a opcao desejada - ";
	cin >> op;
	switch(op){
		
		//CADASTRO DE CARRO
		case 1:{
			
			std::string marca, placa, modelo;
			int situacao;
			double taxaKm, taxaDiaria, Km;
			cout << "\n - CADASTRO DE CARROS - \n";
			cout << "\n Digite a marca do carro: ";
			cin.ignore();
			getline(cin,marca);
			cout << "\n Digite o modelo do carro: ";
			getline(cin,modelo);
			cout << "\n Digite a placa do carro: ";
			getline(cin,placa);
			cout << "\n Digite a taxa por KM do carro: ";
			cin >> taxaKm;
			cout << "\n Digite a taxa Diaria do carro: ";
			cin >> taxaDiaria;
			cout << "\n Digite a Kilometragem do carro: ";
			cin >> Km;
			
			Carro car(marca,placa,modelo,0,taxaKm,taxaDiaria,Km);
			listaCarro.push_back(car);			
			cout << "\n CARRO ADICIONADO COM SUCESSO!";
			break;
		}
		//CADASTRO DE CLIENTE
		case 2:{
			string nome;
			string end;
			long long cpf;
			double divida = 0.0;
			
			cout << "\n - CADASTRO DE CLIENTE - \n";
			cout << "\n Digite o CPF do cliente: ";
			cin >> cpf;
			int info;
			info = BuscaCliente(listaCliente,cpf);
			if(info == -1){
				cout << "\n Digite o nome do cliente: ";
				cin.ignore();
				getline(cin,nome);
				cout << "\n Digite o endereco do cliente: ";
				getline(cin,end);
			}else{
				cout << "CLIENTE JA CADASTRADO!";
			}
			Cliente cli(nome,end,cpf,divida);
			//cli.showDadosCliente();	
			listaCliente.push_back(cli);
			cout << "\n CLIENTE ADICIONADO COM SUCESSO!" << endl;
			break;
		}
		//FAZER ALUGUEL
		case 3:{
			long long CPFaux;
			std::string PLACAaux, dataIniAUX, dataFinAUX;
			
			cout << "Digite o CPF do Cliente: ";				
			cin >> CPFaux;
			int info;
			info = BuscaCliente(listaCliente,CPFaux);
			if(info != -1){
					cout << "CLIENTE EXISTE" << endl;
					if(listaCliente[info].getDivida() == 0){
					
					cout << "Digite a Placa do Carro: ";
					cin >> PLACAaux;
					int info2;
					info2 = BuscaCarro(listaCarro,PLACAaux);
					if(info2 != -1){
						cout << "Carro Cadastrado..." << endl;
						cout << "Verificando Situacao..." << endl;
						if(listaCarro[info2].getSituacao() == 0){
							cout << "Carro Disponivel" << endl;
							int Dia, Mes, Ano, tipoAlug;
							cout << "\n SELECIONE O TIPO DE ALUGUEL " << endl;
							cout << "\n 1 - Aluguel por KM" << endl;
							cout << "\n 2 - Aluguel por Dias" << endl;
							cout << "\n Digite o tipo de aluguel: " << endl;
							cin >> tipoAlug;
							cout << "\n DATA DE INICIO DO ALUGUEL " << endl;
							cout << "\n Digite o dia: ";
							cin >> Dia;
							cout << "\n Digite o mes: ";
							cin >> Mes;
							cout << "\n Digite o ano: ";
							cin >> Ano;
							string dataIniAUX = ConverteData(Dia,Mes,Ano);
							//SETA A DATA FINAL COMO ZERO PQ O ALUGUEL NAO FOI FINALIZADO
							Dia =00;
							Mes= 00;
							Ano = 0000;
							string dataFinAUX = ConverteData(Dia,Mes,Ano);
							listaCarro[info2].setSituacao(1);
							Aluguel alug(PLACAaux,CPFaux,dataIniAUX,dataFinAUX,tipoAlug);
							listaAluguel.push_back(alug);
							alug.showDadosAluguel();
							
							cout << "\n ALUGUEL CADASTRADO COM SUCESSO!" << endl;
						}else{
							cout << "\n CLIENTE COM DIVIDA!" << endl;
						}		
						
						}else{
							cout << "\n CARRO JA ALUGADO!" << endl;
							break;
						}
					}else{
						cout << "\n CARRO NAO CADASTRADO!" << endl;
						break;
					}
			}else{
				cout << "\n CLIENTE NAO CADASTRADO!" << endl;
				break;
			}
		
			break;
		}
		
		//RELATORIOS E PESQUISAS
		case 4:{
			bool opt2 = true;
			while(opt2){
			
			int option2;

			cout << "\n********************************* \n";
			cout << "\n*     RELATORIOS E PESQUISAS    * \n";
			cout << "\n* 1 - Mostrar todos os clientes *";
			cout << "\n* 2 - Mostrar todos os carros   *";
			cout << "\n* 3 - Mostrar todos os alugueis *";
			cout << "\n* 4 - Pesquisar cliente         *";
			cout << "\n* 5 - Pesquisar carro           *";
			cout << "\n* 6 - Alugueis por periodo      *";
			cout << "\n* 7 - Pesquisar Aluguel         *";
			cout << "\n* 0 - Voltar                    *";
			cout << "\n********************************* \n";
			cout << "\n Digite a opção desejada: ";
			cin >> option2;
			switch(option2){
				//MOSTRAR TODOS OS CLIENTES CADASTRADOS
				case 1:{
					cout << "\nLISTA DE TODOS OS CLIENTES CADASTRADOS" << endl;
					cout << "\nQuantidade de Clientes Cadastrados: " << listaCliente.size() << endl;
					int i=0;
					int endFile = listaCliente.size();
					for(i;i < endFile;i++){
					listaCliente[i].showDadosCliente();
					cout << endl; 
					}
					cout << endl; 
					cout << endl;
					break;
				}
				//MOSTRAR TODOS OS CARROS CADASTRADOS
				case 2:{
					cout << "\n LISTA DE TODOS OS CARROS CADASTRADOS" << endl;
					cout << "\n Quantidade de Carros Cadastrados: " << listaCarro.size() << endl;
					int i=0;
					int endFile = listaCarro.size();
					for(i;i < endFile;i++){
					listaCarro[i].showDadosCarro();
					cout << endl;
					}
					cout << endl; 
					cout << endl;
					break;
				}
				//MOSTRAR TODOS OS ALUGUEIS REALIZADOS
				case 3: {
					cout << "\nLISTA DE TODOS OS ALUGUEIS REALIZADOS" << endl;
					cout << "\nQuantidade de Alugueis Realizados: " << listaAluguel.size() << endl;
					int i=0;
					int endFile = listaAluguel.size();
					for(i;i < endFile;i++){
					listaAluguel[i].showDadosAluguel();
					cout << endl; 
					}
					cout << endl; 
					cout << endl;
					break;
				}
				//PESQUISA DE CLIENTE
				case 4:{	
					long long cpfAux;
					cout << "\n* PESQUISAR CLIENTE *";
					cout << "\nDigite o cpf do cliente";
					cin >> cpfAux;
					int inf = BuscaCliente(listaCliente,cpfAux);
					if (inf != -1){
						cout << "\nCLIENTE ENCONTRADO! " << endl;
						listaCliente[inf].showDadosCliente();
					}else{
						cout << "\nCLIENTE NÃO CADASTRADO"  << endl;
					}
					break;
				}
				//PESQUISA DE CARRO
				case 5:{
					string placaAux;
					cout << "\n* PESQUISAR CARRO *";
					cout << "\nDigite a placa do carro: ";
					cin >> placaAux;
					int inf = BuscaCarro(listaCarro,placaAux);
					if(inf != -1){
						cout << "\nCARRO ENCONTRADO! " << endl;
						listaCarro[inf].showDadosCarro();
					}else{
						cout << "\n CARRO NÃO CADASTRADO!" << endl;
					}
					break;
				}
				//PESQUISA DE ALUGUEIS
				case 6:{
					int mesIni, mesFim;
					cout << "Digite o Mes Inicial:";
					cin >> mesIni;
					cout << "Digite o Mes Final:";
					cin >> mesFim;
					int endLIsta = listaAluguel.size();
					if(mesIni <= mesFim){
						for(int i=0; i < endLIsta; i++){
							int mes = pegaMes(listaAluguel[i].getDataInicial());
								if(mesIni < mesFim){
								if(mes >= mesIni && mes <= mesFim){
									listaAluguel[i].showDadosAluguel();
									}
								}else{
									cout << "\n Periodo Invalido!" << endl;
								}
						}
					}
					break;
				}
				case 7:{
						string placaAux;
						long long CPFaux;
						cout << "*  BUSCA DE ALUGEL POR CPF E PLACA  *" << endl;
						cout << "\n Digite a placa do carro: ";
						cin >> placaAux;
						cout <<"\n Digite o CPF do cliente: ";
						cin >> CPFaux;
						int infoALUG = BuscaAluguel(listaAluguel,placaAux,CPFaux);
						if(infoALUG != -1){
							listaAluguel[infoALUG].showDadosAluguel();
						}else{
							cout << "\n ALUGUEL NAO ENCONTRADO! "<< endl;
						}
					break;
				}
				
				
				case 0:{
					opt2 = false;
					break;
				}	
				}
		}
		break;
		}
		//FAZER A DEVOLUÇÃO DO CARRO
		case 5:{
		
		string placaAux;
		long long CPFaux;
		cout << "\n*     DEVOLUÇÃO    *";
		cout << "\n Digite a placa do carro: ";
		cin >> placaAux;
		int infoCAR = BuscaCarro(listaCarro,placaAux);
		if(listaCarro[infoCAR].getSituacao() == 1){
		
		cout <<"\n Digite o CPF do cliente: ";
		cin >> CPFaux;
		int infoALUG = BuscaAluguel(listaAluguel,placaAux,CPFaux);
		int infoCLI = BuscaCliente(listaCliente,CPFaux);
		
			if(infoALUG != -1){
				cout << "\n DEVOLUÇÃO DO CARRO " << endl;
				
				int tipoAluguel = listaAluguel[infoALUG].getIdAluguel();
				
				if(tipoAluguel == 1){
				//PRECO POR KM
				double KMRodado, KMFinal, Divida;
				cout << "\n Digite o KM atual do carro : ";
				cin >> KMFinal;
				 
				KMRodado = KMFinal - listaCarro[infoCAR].getKM();
				Divida = KMRodado * listaCarro[infoCAR].getTaxaKm();
				 
				listaCarro[infoCAR].setKM(KMFinal);
				listaCarro[infoCAR].setSituacao(0);
				listaCliente[infoCLI].setDivida(Divida);
				
				int Dia, Mes, Ano;
				cout << "\n Digite o dia, mes e ano da devolucao do carro: ";
				cin >> Dia >> Mes >> Ano;
				string DataFinal = ConverteData(Dia,Mes,Ano);
				listaAluguel[infoALUG].setDataFinal(DataFinal);
				
				cout << "\n Voce rodou " << KMRodado << " kms com o carro." << endl;
				cout << "\n Portanto sua divida e de " << Divida <<" Reais !" << endl;
				cout << "\n Divida computada com sucesso! \n" << endl;
				 
				}else if(tipoAluguel == 2){
				//PRECO POR DIA
				double KMRodado, KMFinal, Divida;
				int Dias;
				cout << "\n Digite o KM atual do carro : ";
				cin >> KMFinal;
				cout << "\n Digite quantos dias ficou com o caro: ";
				cin >> Dias;
				
				Divida = listaCarro[infoCAR].getTaxaDiaria() * Dias;
				
				listaCarro[infoCAR].setKM(KMFinal);
				listaCarro[infoCAR].setSituacao(0);
				listaCliente[infoCLI].setDivida(Divida);
				

				int Dia, Mes, Ano;
				cout << "\n Digite o dia, mes e ano da devolucao do carro: ";
				cin >> Dia >> Mes >> Ano;
				string DataFinal = ConverteData(Dia,Mes,Ano);
				
				cout << "\n Voce ficou " << Dias << " dias com o carro." << endl;
				cout << "\n Portanto sua divida e de " << Divida <<" Reais !" << endl;
				cout << "\n Divida computada com sucesso! \n" << endl;
				break;
				}else{
					cout << "\n ERRO NO ALUGUEL!" << endl;
					break;
				}

			}		
		}else {
			cout << "\n CARRO NAO ALUGADO! " << endl;
			break;
		}	
		}
		//PAGAMENTO DE DIVIDAS DO CLIENTE
		case 6:{
			
			long long CPFaux;
			
			cout << "\n*    Pagamento de Dívidas    *"<< endl;
			cout << "\n Digite o CPF do Cliente: ";
			cin >> CPFaux;
			int infoCLI = BuscaCliente(listaCliente,CPFaux);
			if(infoCLI != -1){
				
				
				int OPT;
				cout << "\n Cliente " << listaCliente[infoCLI].getNome();
				cout << "\n A divida e de : " << listaCliente[infoCLI].getDivida() << endl;
				cout << "\n Deseja efetuar o pagamento total ou parcial da Divida ? "<< endl;
				cout << "\n Digite 1 para total e 2 para parcial" << endl;
				cin >> OPT;
				if(OPT == 1){
					double Divida;
					
					int conf;
					cout << "\n Digite 1 para confirmar o PAGAMENTO TOTAL da divida " << endl;
					cin >> conf;
					if (conf == 1){
						
						listaCliente[infoCLI].setDivida(0);
						
						cout << "\n PAGAMENTO TOTAL DA DIVIDA NO VALOR DE " <<
						listaCliente[infoCLI].getDivida() << " R$ CONFIRMADO!" << endl;
						break;
					}else {
						cout << "\n Pagamento total nao confirmado!" ;
						break;
					}
				}else if(OPT == 2){
					double Pagamento, Divida;
					
					cout << "Digite o valor a ser pago: ";
					cin >> Pagamento;
					
					int confirma;
					cout << "\n Digite 1 para confimar o pagamento do valor de " << Pagamento << " R$ ";
					cin >> confirma;
					if(confirma == 1){
						
						Divida = listaCliente[infoCLI].getDivida() - Pagamento;
						listaCliente[infoCLI].setDivida(Divida);
						
						cout << "\n O pagamento de " << Pagamento << " R$ foi realizado com sucesso! " << endl;
						cout << "\n Ainda resta " << listaCliente[infoCLI].getDivida() << " R$ de Divida" << endl;	
						break;
					}else{
						cout << "\n PAGAMENTO NAO CONFIRMADO! " << endl;
						break;
					}
				}	
			}else{
				cout << "\n CLIENTE NÃO CADASTRADO! " << endl;
				break;
			}
			break;
		}
			
		//SALVA LISTAS EM ARQUIVOS TXT AO SAIR DO PROGRAMA
		case 0:{
			
			
			//SALVA A LISTA ALUGUEL NO TXT
			SalvaAluguel(listaAluguel);
			SalvaCliente(listaCliente);
			SalvaCarro(listaCarro);
			cout << "SAINDO..." << endl;
			control = false;
			
			
		}	
		}
		
	}
	
}
