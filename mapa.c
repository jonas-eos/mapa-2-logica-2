#include <stdio.h>

enum indexes {

  /// Usado como guia para semanas
  LINHA = 4,

  /// Usado como guia para os dias da semana
  COLUNA = 6
};

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
  for (semana = 0; semana < LINHA; semana++) {
    printf("Semana %i\n", semana);
    for (diaDaSemana = 0; diaDaSemana < 6; diaDaSemana++) {
      printf("Dia: %i", diaDaSemana);
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
  for (semana = 0; semana < LINHA; semana++) {
    printf("Semana %i\n", semana);
    for (diaDaSemana = 0; diaDaSemana < 6; diaDaSemana++) {
      printf("Dia: %i R$: %.2f\n", diaDaSemana, __tabela[semana][diaDaSemana]);
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
  int acumulador = 0;
  for (semana = 0; semana < LINHA; semana++) {
    for (diaDaSemana = 0; diaDaSemana < COLUNA; diaDaSemana++) {
      acumulador += __tabela[semana][diaDaSemana];
    }  // diaDaSemana
  }    // Semana
  return (double)acumulador / (LINHA * COLUNA);
}

//******************************************************************************
// Programa principal
int main() {
  double vendas[LINHA][COLUNA];
  preencherVendas(vendas);
  exibirVendasDiaria(vendas);
  printf("Média de vedas do mês: %.2f\n", calcularMediaDoMes(vendas));
  return 0;
}