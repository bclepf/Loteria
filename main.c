#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int aposta[5];
    
    printf("\n===== Bem vindo a Loteria do Bil =====\n");
    printf("Faca sua aposta!!! Digite 5 numeros distintos entre 1 e 100 separados por espacos:\n");
    
    for (int i = 0; i < 5; i++) {
        scanf("%d", &aposta[i]);
        
        if (aposta[i] < 1 || aposta[i] > 100) {
            printf("Valores invalidos, por favor inisira apenas numeros dentro do intervalo determinado.\n");
            i--;
        }
        
        for (int j = 0; j < i; j++) {
            if (aposta[i] == aposta[j]) {
                printf("Nao se pode apostar duas vezes no mesmo numero, tente novamente.\n");
                i--;
                break;
            }
        }
    }

    int tentativas = 0;
    int acertos = 0;

    while (acertos < 5 && tentativas < 50) {
        int numerosSorteados[5];
        
        for (int i = 0; i < 5; i++) {
            int numeroSorteado;
            do {
                numeroSorteado = rand() % 100 + 1;
                int repetido = 0;
                for (int j = 0; j < i; j++) {
                    if (numeroSorteado == numerosSorteados[j]) {
                        repetido = 1;
                        break;
                    }
                }
                if (!repetido) {
                    numerosSorteados[i] = numeroSorteado;
                    break;
                }
            } while (1);
        }

        acertos = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (aposta[i] == numerosSorteados[j]) {
                    acertos++;
                    break;
                }
            }
        }

        tentativas++;

        if (acertos == 5) {
            printf("Eita!!! Parabens você ganhou na loteria do Bil\n");
        } else if (tentativas == 50) {
            printf("Nao foi dessa vez mas lembre-se, a casa sempre ganha HAHAHAHAHA.\n");
        }
    }

    printf("\nPara sair aperte qualquer tecla...");
    getchar();
    getchar();
    return 0;
}
