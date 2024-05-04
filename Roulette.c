#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roulette();

int main() {
  int scelta = 0;
  int numero_tiri = 0;
  int numero_pari = 0;
  int numero_dispari = 0;
  int numero_zero = 0;
  float frequenza_pari = 0;
  float frequenza_dispari = 0;
  float frequenza_zero = 0;

  srand(time(NULL));
  printf("Benvenuto al nostro casinò, giocherai alla roulette!(perderai un sacco di soldi)\n");

  do {
    printf("\nCosa vuoi fare?\n");
    printf("1. Giocare\n");
    printf("2. Uscire \n");
    printf("Scelta: ");
    scanf("%d", &scelta);

    switch (scelta) {
      case 1:
        printf("Quanti tiri? ");
        scanf("%d", &numero_tiri);
        
        for (int i = 0; i < numero_tiri; i++) {
          int numero = roulette();
          if (numero == 0) {
            numero_zero++;
          } 
          else if (numero % 2 == 0) {
            numero_pari++;
          } 
          else {
            numero_dispari++;
          }
        }
        printf("\nRisultati:\n");
        printf("Numero di tiri: %d\n", numero_tiri);
        printf("Numeri pari (nero): %d\n", numero_pari);
        printf("Numeri dispari (rosso): %d\n", numero_dispari);
        printf("Numeri zero: %d\n", numero_zero);

        frequenza_pari=(float)numero_pari/numero_tiri;
        frequenza_dispari=(float)numero_dispari/numero_tiri;
        frequenza_zero=(float)numero_zero/numero_tiri;
        printf("Frequenza dei numeri pari: %.3f\n", frequenza_pari);
        printf("Frequenza dei numeri dispari: %.3f\n", frequenza_dispari);
        printf("Frequenza dei numeri zero: %.3f\n", frequenza_zero);
        float somma_frequenza=frequenza_pari+frequenza_dispari+frequenza_zero;
        printf("Somma delle frequenze: %.3f\n", somma_frequenza);
        break;
        
      case 2:
        printf("Bye Bye!\n");
        break;
      default:
        printf("Scelta non valida, riprova.\n");
        break;
    }
  } while (scelta != 2);

  return 0;
}

int roulette() {
  int numero = rand() % 37;
  if (numero == 0) {
    printf("0 ");
  } 
  else if (numero % 2 == 0) {
    printf("%d (nero) ", numero);
  } 
  else {
    printf("%d (rosso) ", numero);
  }
  return numero;
}





