#include <iostream>
#include <vector>
using namespace std;

class Transacao{
public:
string descricao;
double valor;
string categoria;
string data;

 Transacao(const string& descricao, const double& valor, string& categoria, string& data) : descricao(descricao), valor(valor), categoria(categoria), data(data){}
};


class GerenciadorFinancas{
private:
  vector<Transacao> transacoes;

public: 
void adicionartransacoes(Transacao transacao){
    transacoes.push_back(transacao);
}

void ExibirTransacoes(){

  if (transacoes.empty()){
    cout<< "Nenhuma Transação encontrada";
  }
  

  for (const auto& transacao : transacoes){
    cout << "Descricao:"<< transacao.descricao<<endl;
    cout << "Valor:"<< transacao.valor<<endl;
    cout << "Categoria:"<< transacao.categoria<<endl;
    cout << "Data:"<< transacao.data<< endl;
  }
}

  void obtertransacoes(vector<Transacao> & vetor_transacoes){
  vetor_transacoes= transacoes;
  }


  double Total_transacoes(){

  double total=0.0;

  for (const auto& transacao: transacoes){
    total+= transacao.valor;
  }
  return total;
}

  void removertransacao(string descricao){
    for (auto it= transacoes.begin(); it != transacoes.end(); it++){
      if (it->descricao==descricao){
        transacoes.erase(it);
        break;
      }
    }
  }
};
int main() {

  GerenciadorFinancas gerenciadorfinancas;

  char opcao;

  do{
   cout<< "================MENU=================================="<<endl;
   cout<<"1- Adicionar transação"<<endl;
   cout<<"2- Exibir transações:"<<endl;
   cout <<"3- Obter soma das transações:"<<endl;
   cout<< "4- Remover Transação:"<<endl;
   cout<< "5- SAIR."<< endl;
   cout<< "======================================================="<<endl;
   cout <<"Digite a opcao desejada:";
    
    cin >> opcao;
  switch(opcao){
    case '1':{
      string descricao, categoria, data;
      double valor;

      cout<< "Digite a descrição da transação:"<<endl;
      cin.ignore();
      getline(cin, descricao);

      cout<< "Digite a categoria da transação:"<<endl;
      
      cin.ignore();
      getline(cin, categoria);
      
      cout << "Digite a data da transacao"<<endl;

      cin.ignore();
      getline(cin, data);

      cout<< "Digite o valor da transação:"<<endl;
      cin >> valor;

     gerenciadorfinancas.adicionartransacoes(Transacao(descricao, valor, categoria, data));
      cout << "Transação adicionada com sucesso"<<endl;

      break;
    }

    case '2':{
      cout << "Exibindo Transações..."<<endl;
      gerenciadorfinancas.ExibirTransacoes();

      break;
    }

    case '3':{

      double soma_transacoes= gerenciadorfinancas.Total_transacoes();
      cout << "Valor Gasto: "<< soma_transacoes<<endl;

      break;
    }

    case '4':{
      string desc;
      cout << "Digite a descrição da transação que deseja remover:";
      cin.ignore();
      getline(cin, desc);

      gerenciadorfinancas.removertransacao(desc);

      break;
    }
    case '5':{
      cout<<"Saindo do programa"<<endl;
      break;
    }

    default:
        cout<< "Opção Inválida."<<endl;
  }

    

  } while (opcao!= '5');

}