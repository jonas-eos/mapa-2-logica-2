#include <stdio.h>

enum indexes {

  /// Usado como guia para semanas
  LINHA = 4,

  /// Usado como guia para os dias da semana
  COLUNA = 6
};

void preencherVendas() {
  int semana, diaDaSemana;
  double vendas[LINHA][COLUNA];
  for (semana = 0; semana < LINHA; semana++) {
    printf("Semana %i\n", semana);
    for (diaDaSemana = 0; diaDaSemana < 6; diaDaSemana++) {
      prinf("Dia: %i", diaDaSemana);
      scanf("%lf", &vendas[semana][diaDaSemana]);
    }  // diaDaSemana
  }    // Semana
}

int main() {
  return 0;
}