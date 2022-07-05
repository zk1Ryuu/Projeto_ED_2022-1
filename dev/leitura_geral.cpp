#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>

using namespace std;

struct Binario{
	
	int campo_1_id;
	char campo_2_name[40];
	char campo_3_job[54];
	float campo_4_base_pay;
	float campo_5_overtime_pay;
	float campo_6_other_pay;
	float campo_7_benefits;
	float campo_8_total_pay;
	float campo_9_total_pay_benefits;
	int campo_10_year;
	int campo_11_posicao;
	
	Binario();
};

Binario::Binario(){
	
	campo_1_id = -1;
	memset(campo_2_name, 0, sizeof(campo_2_name));
	memset(campo_3_job, 0, sizeof(campo_3_job));
	campo_4_base_pay = 0;
	campo_5_overtime_pay = 0;
	campo_6_other_pay = 0;
	campo_7_benefits = 0;
	campo_8_total_pay = 0;
	campo_9_total_pay_benefits = 0;
	campo_10_year = 0;
	campo_11_posicao = -1;
};

int main(){
	
	ifstream arq("dados_convertidos.bin", ios::binary);
	
	if(arq){
		
		arq.seekg(0, arq.end);
		int tamanho_arquivo_binario = arq.tellg();
		
		int quantidade_linhas = tamanho_arquivo_binario / sizeof(Binario);
		
		Binario *leitura = new Binario[quantidade_linhas];
		
		arq.seekg(0, arq.beg);
		
		char opcao;
		bool controle = true, primeiro = false;
		int aux_quant = quantidade_linhas;
		
		do{
			
			int cont = 100;
			
			if(aux_quant >= 1 and aux_quant <= cont)
				cont = aux_quant;
			
			for(int i = 0; i < cont; i++){
				
				arq.read((char*)(&leitura[i]), sizeof(Binario));
				
				cout << leitura[i].campo_1_id << '\n'
				<< leitura[i].campo_2_name << '\n'
				<< leitura[i].campo_3_job << '\n'
				<< leitura[i].campo_4_base_pay << '\n'
				<< leitura[i].campo_5_overtime_pay << '\n'
				<< leitura[i].campo_6_other_pay << '\n'
				<< leitura[i].campo_7_benefits << '\n'
				<< leitura[i].campo_8_total_pay << '\n'
				<< leitura[i].campo_9_total_pay_benefits << '\n'
				<< leitura[i].campo_10_year << '\n'
				<< leitura[i].campo_11_posicao << '\n' << endl;
				
				aux_quant--;
			}
			
			cout << "Linhas restantes: " << aux_quant << endl;
			
			cout << "Se desejar ver os resultados do ponto anterior até esse ponto, rode para cima" << endl;
			
			if(aux_quant == 0){
				
				cout << "Fim da aplicação, pressione enter para retornar" << endl;
				
				controle = false;
				
				cin.get();
			}
			
			else{
				
				cout << "Se deseja sair da aplicação, pressione q e enter, se não aperte enter para continuar" << endl;
				
				while(opcao != '\n'){
					
					opcao = getchar();
					
					if((!primeiro) and (opcao == 'q'))
						controle = false;
						
					primeiro = true;
				}
				
				opcao = ' ';
				primeiro = false;
			}
			
			system("clear");
			system("clear");
			
		}while(controle);
		
		arq.close();
		delete[] leitura;
	}
	
	else{
		
		cout << "Não há arquivo convertido" << endl;
	}
	
	return 0;
}