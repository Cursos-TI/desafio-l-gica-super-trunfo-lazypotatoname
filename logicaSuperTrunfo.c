 #include <stdio.h>
#include <string.h>

// Estrutura da carta do Super Trunfo
struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para calcular a densidade demográfica
void calcularDensidade(struct Carta *c) {
    c->densidadeDemografica = c->populacao / c->area;
}

// Função para exibir informações de uma carta
void exibirCarta(struct Carta c) {
    printf("País: %s\n", c.nomePais);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", c.densidadeDemografica);
    printf("-----------------------------\n");
}

int main() {
    // Cartas pré-definidas
    struct Carta carta1 = {"Brasil", 213000000, 8516000.0, 2000.0, 30};
    struct Carta carta2 = {"Argentina", 46000000, 2780000.0, 500.0, 15};

    // Calcular densidade para ambas
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int escolha;

    printf("===== Super Trunfo: Comparação de Países =====\n\n");
    printf("Carta 1:\n"); exibirCarta(carta1);
    printf("Carta 2:\n"); exibirCarta(carta2);

    // Loop do menu
    do {
        printf("\nEscolha um atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &escolha);

        printf("\n===== Resultado da Comparação =====\n");

        switch (escolha) {
            case 1:
                printf("Atributo: População\n");
                printf("%s: %d\n", carta1.nomePais, carta1.populacao);
                printf("%s: %d\n", carta2.nomePais, carta2.populacao);
                if (carta1.populacao > carta2.populacao)
                    printf("Vencedor: %s!\n", carta1.nomePais);
                else if (carta2.populacao > carta1.populacao)
                    printf("Vencedor: %s!\n", carta2.nomePais);
                else
                    printf("Empate!\n");
                break;

            case 2:
                printf("Atributo: Área\n");
                printf("%s: %.2f km²\n", carta1.nomePais, carta1.area);
                printf("%s: %.2f km²\n", carta2.nomePais, carta2.area);
                if (carta1.area > carta2.area)
                    printf("Vencedor: %s!\n", carta1.nomePais);
                else if (carta2.area > carta1.area)
                    printf("Vencedor: %s!\n", carta2.nomePais);
                else
                    printf("Empate!\n");
                break;

            case 3:
                printf("Atributo: PIB\n");
                printf("%s: %.2f bilhões\n", carta1.nomePais, carta1.pib);
                printf("%s: %.2f bilhões\n", carta2.nomePais, carta2.pib);
                if (carta1.pib > carta2.pib)
                    printf("Vencedor: %s!\n", carta1.nomePais);
                else if (carta2.pib > carta1.pib)
                    printf("Vencedor: %s!\n", carta2.nomePais);
                else
                    printf("Empate!\n");
                break;

            case 4:
                printf("Atributo: Pontos Turísticos\n");
                printf("%s: %d\n", carta1.nomePais, carta1.pontosTuristicos);
                printf("%s: %d\n", carta2.nomePais, carta2.pontosTuristicos);
                if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                    printf("Vencedor: %s!\n", carta1.nomePais);
                else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
                    printf("Vencedor: %s!\n", carta2.nomePais);
                else
                    printf("Empate!\n");
                break;

            case 5:
                printf("Atributo: Densidade Demográfica\n");
                printf("%s: %.2f hab/km²\n", carta1.nomePais, carta1.densidadeDemografica);
                printf("%s: %.2f hab/km²\n", carta2.nomePais, carta2.densidadeDemografica);
                if (carta1.densidadeDemografica < carta2.densidadeDemografica)
                    printf("Vencedor: %s!\n", carta1.nomePais); // menor vence
                else if (carta2.densidadeDemografica < carta1.densidadeDemografica)
                    printf("Vencedor: %s!\n", carta2.nomePais);
                else
                    printf("Empate!\n");
                break;

            case 0:
                printf("Saindo do jogo...\n");
                break;

            default:
                printf("Opção inválida. Escolha um número entre 0 e 5.\n");
        }

    } while (escolha != 0);

    return 0;
}
