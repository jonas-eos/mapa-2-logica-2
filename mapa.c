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
// Dependência
// - const LINHA
// - const COLUNA
void preencherVendas() {
  int semana, diaDaSemana;
  double vendas[LINHA][COLUNA];
  for (semana = 0; semana < LINHA; semana++) {
    printf("Semana %i\n", semana);
    for (diaDaSemana = 0; diaDaSemana < 6; diaDaSemana++) {
      printf("Dia: %i", diaDaSemana);
      scanf("%lf", &vendas[semana][diaDaSemana]);
    }  // diaDaSemana
  }    // Semana
}

void exibirVendasDiaria(const double** __tabela) {
  int semana, diaDaSemana;
  for (semana = 0; semana < LINHA; semana++) {
    printf("Semana %i\n", semana);
    for (diaDaSemana = 0; diaDaSemana < 6; diaDaSemana++) {
      printf("Dia: %i R$: %.2f\n", diaDaSemana, __tabela[semana][diaDaSemana]););
    }  // diaDaSemana
  }    // Semana
}

//******************************************************************************
// Programa principal
int main() {
  preencherVendas();
  return 0;
}