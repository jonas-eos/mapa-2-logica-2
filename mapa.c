#include <stdio.h>
#include <stdlib.h>

/// Constante inicializadora
const int INICIALIZADOR = 0;
enum opcoes { CADASTRAR = 1, EXIBIR_VENDAS = 2, CALCULAR_MEDIA = 3 };
enum indexes {

  /// Usado como guia para semanas
  LINHA = 4,

  /// Usado como guia para os dias da semana
  COLUNA = 6
};

/// Tipo lógico, retorno falso ou verdadeiro
typedef enum valores_logico { FALSO, VERDADEIRO } logico;
typedef enum dia_semana {
  SEGUNDA,
  TERCA,
  QUARTA,
  QUINTA,
  SEXTA,
  SABADO
} dataSemana;

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

//******************************************************************************
// Descrição
// - preenche uma matriz de vendas.
// Parâmetros
// - __tabela: referencia da tabela onde será salvo as vendas
// Dependência
// - const LINHA
// - const COLUNA
void preencherVendas(double __tabela[LINHA][COLUNA]) {
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
// Descrição
// - exibi todas as vendas de todos os dias e de todas as semanas
// Parâmetros
// __tabela: tabela onde tem os preços salvos
// Depêndencia
// const LINHA
// const COLUNA
void exibirVendasDiaria(const double __tabela[LINHA][COLUNA]) {
  int semana, diaDaSemana;
  for (semana = INICIALIZADOR; semana < LINHA; semana++) {
    printf("Semana %i\n", semana + 1);
    for (diaDaSemana = INICIALIZADOR; diaDaSemana < COLUNA; diaDaSemana++) {
      printf("Dia %s R$: %.2f\n", obterDiaDaSemana(diaDaSemana),
             __tabela[semana][diaDaSemana]);
    }  // diaDaSemana
  }    // Semana
}

//******************************************************************************
// Descrição
// - Calcula a média de vendas do mês e retorna seu valor
// Parâmetros
// - __tabela: tabela base onde estã salvo as vendas realizadas
// Dependência
// - const LINHA
// - const COLUNA
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
// Descrição
// - Menu principal do programa
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
// Programa principal
int main() {
  double vendas[LINHA][COLUNA] = {INICIALIZADOR};
  logico finalizarPrograma = FALSO;
  do {
    switch (menu()) {
      case CADASTRAR:
        preencherVendas(vendas);
        break;
      case EXIBIR_VENDAS:
        exibirVendasDiaria(vendas);
        break;
      case CALCULAR_MEDIA:
        printf("Média de vedas do mês: %.2f\n", calcularMediaDoMes(vendas));
        break;
      default:
        finalizarPrograma = VERDADEIRO;
    }
    system("pause");
  } while (!finalizarPrograma);
  return EXIT_SUCCESS;
}