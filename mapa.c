#include <stdio.h>
#include <stdlib.h>

//##############################################################################
// Definição de dados

/// Tipo lógico, retorno falso ou verdadeiro
typedef enum valores_logico { FALSO, VERDADEIRO } logico;

//##############################################################################
// Constantes

/// Constante inicializadora
const int INICIALIZADOR = 0;

/// Identificadores das opções válidas no programa principal
enum opcoes { CADASTRAR = 1, EXIBIR_VENDAS = 2, CALCULAR_MEDIA = 3 };

/// Identificadores dos indexes para controlar as posições da tabela de vendas
enum indexes {

  /// Usado como guia para semanas
  LINHA = 4,

  /// Usado como guia para os dias da semana
  COLUNA = 6
};

/// Identificadores dos dias da semana
enum dia_semana { SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO };

//##############################################################################
// Variáveis globais
logico cadastroRealizado;

//##############################################################################
// Prototipos dos métodos

// Descrição
// - Retorna qual o dia da semana correspondente ao código informado
// Parâmetro
// - __cod_data: o código da data que a função precisa para fornecer o dia da
//    semana correspondente
// Dependência
// - enum dia_semana: onde consta a tabela dos dias da semanas correspondnete
char* obterDiaDaSemana(int __cod_data);

// Descrição
// - preenche uma matriz de vendas.
// Parâmetros
// - __tabela: referencia da tabela onde será salvo as vendas
// Dependência
// - const LINHA
// - const COLUNA
void preencherVendas(double __tabela[LINHA][COLUNA]);

// Descrição
// - exibi todas as vendas de todos os dias e de todas as semanas
// Parâmetros
// __tabela: tabela onde tem os preços salvos
// Depêndencia
// const LINHA
// const COLUNA
void exibirVendasDiaria(const double __tabela[LINHA][COLUNA]);

// Descrição
// - Calcula a média de vendas do mês e retorna seu valor
// Parâmetros
// - __tabela: tabela base onde estã salvo as vendas realizadas
// Dependência
// - const LINHA
// - const COLUNA
double calcularMediaDoMes(const double __tabela[LINHA][COLUNA]);

// Descrição
// - Menu principal do programa
unsigned short int menu();

//##############################################################################
// Programa principal
int main() {
  cadastroRealizado = FALSO;
  double vendas[LINHA][COLUNA] = {INICIALIZADOR};
  logico finalizarPrograma = FALSO;
  do {
    system("clear||cls");
    switch (menu()) {
      case CADASTRAR:
        preencherVendas(vendas);
        cadastroRealizado = VERDADEIRO;
        break;
      case EXIBIR_VENDAS:
        if (cadastroRealizado)
          exibirVendasDiaria(vendas);
        else
          puts("Não existe preços de vendas neste mês!");
        break;
      case CALCULAR_MEDIA:
        if (cadastroRealizado)
          printf("Média de vedas do mês: %.2f\n", calcularMediaDoMes(vendas));
        else
          puts("Não existe preços de vendas neste mês!");
        break;
      default:
        finalizarPrograma = VERDADEIRO;
    }
    if (!finalizarPrograma)
      system("pause");
  } while (!finalizarPrograma);
  return EXIT_SUCCESS;
}

//##############################################################################
// Definições dos métodos

//******************************************************************************
void preencherVendas(double __tabela[LINHA][COLUNA]){
  int semana, diaDaSemana;
  for (semana = INICIALIZADOR; semana < LINHA; semana++) {
    printf("Semana %i\n", semana + 1);
    for (diaDaSemana = INICIALIZADOR; diaDaSemana < COLUNA; diaDaSemana++) {
      printf("Dia %s: ", obterDiaDaSemana(diaDaSemana));
      scanf("%lf", &__tabela[semana][diaDaSemana]);
    }  // diaDaSemana
  }    // Semana
}

//******************************************************************************
void exibirVendasDiaria(const double __tabela[LINHA][COLUNA]) {
  int semana, diaDaSemana;
  for (semana = INICIALIZADOR; semana < LINHA; semana++) {
    printf("Semana %i\n", semana + 1);
    for (diaDaSemana = INICIALIZADOR; diaDaSemana < COLUNA; diaDaSemana++) {
      printf("Dia %s R$: %.2f\n", obterDiaDaSemana(diaDaSemana),
             __tabela[semana][diaDaSemana]);
    }  // diaDaSemana

    // Pausar a tela se a semana for anterior á ultima
    // semana definida pela constante LINHA
    if (semana < LINHA - 1)
      system("pause");
  }  // Semana
}

//******************************************************************************
double calcularMediaDoMes(const double __tabela[LINHA][COLUNA]) {
  int semana, diaDaSemana;
  int acumulador = INICIALIZADOR;
  for (semana = INICIALIZADOR; semana < LINHA; semana++) {
    for (diaDaSemana = INICIALIZADOR; diaDaSemana < COLUNA; diaDaSemana++) {
      acumulador += __tabela[semana][diaDaSemana];
    }  // diaDaSemana
  }    // Semana
  return (double)acumulador / (LINHA * COLUNA);
}

//******************************************************************************
unsigned short int menu() {
  unsigned short int opcao;
  system("cls");
  puts("***********************-MENU-***********************");
  puts("* Informe a operação desejada:                     *");
  puts("* 1 - Cadastrar vendas                             *");
  puts("* 2 - Exibir as vendas do mês                      *");
  puts("* 3 - Média monetaria de vendas realizada no mês   *");
  puts("* outro - Sair                                     *");
  puts("****************************************************");
  scanf("%u", &opcao);
  return opcao;
}

//******************************************************************************
char* obterDiaDaSemana(int __cod_data) {
  switch (__cod_data) {
    case SEGUNDA:
      return "Segunda";
    case TERCA:
      return "Terça";
    case QUARTA:
      return "Quarta";
    case QUINTA:
      return "Quinta";
    case SEXTA:
      return "Sexta";
    case SABADO:
      return "Sabado";
  }
}