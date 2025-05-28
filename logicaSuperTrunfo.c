#include <stdio.h>
#include <string.h>

struct Carta {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

float obterValor(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return 0;
    }
}

const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

void exibirMenu(int excluir) {
    printf("Escolha um atributo:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Demográfica\n");
}

int main() {
    struct Carta carta1 = {"Brasil", 210000000, 8515767.0, 1868.0, 35, 24.66};
    struct Carta carta2 = {"Argentina", 45000000, 2780400.0, 637.0, 20, 16.18};

    int atributo1, atributo2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;

    printf("Comparando: %s x %s\n\n", carta1.nome, carta2.nome);

    // Primeiro atributo
    do {
        exibirMenu(0);
        printf("Escolha o PRIMEIRO atributo: ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5) printf("Atributo inválido. Tente novamente.\n");
    } while (atributo1 < 1 || atributo1 > 5);

    // Segundo atributo, diferente do primeiro
    do {
        exibirMenu(atributo1);
        printf("Escolha o SEGUNDO atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1)
            printf("Atributo inválido ou repetido. Tente novamente.\n");
    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    // Obtem valores dos atributos para as duas cartas
    valor1_c1 = obterValor(carta1, atributo1);
    valor1_c2 = obterValor(carta2, atributo1);
    valor2_c1 = obterValor(carta1, atributo2);
    valor2_c2 = obterValor(carta2, atributo2);

    printf("\n--- Comparando atributos ---\n");

    // Exibir valores
    printf("%s:\n  %s: %.2f\n  %s: %.2f\n", nomeAtributo(atributo1), carta1.nome, valor1_c1, carta2.nome, valor1_c2);
    printf("%s:\n  %s: %.2f\n  %s: %.2f\n", nomeAtributo(atributo2), carta1.nome, valor2_c1, carta2.nome, valor2_c2);

    // Comparar individualmente com inversão para densidade
    float soma1 = (atributo1 == 5 ? -valor1_c1 : valor1_c1) + (atributo2 == 5 ? -valor2_c1 : valor2_c1);
    float soma2 = (atributo1 == 5 ? -valor1_c2 : valor1_c2) + (atributo2 == 5 ? -valor2_c2 : valor2_c2);

    printf("\nSoma dos atributos:\n  %s: %.2f\n  %s: %.2f\n", carta1.nome, soma1, carta2.nome, soma2);

    // Resultado final
    if (soma1 > soma2)
        printf("Vencedor: %s\n", carta1.nome);
    else if (soma2 > soma1)
        printf("Vencedor: %s\n", carta2.nome);
    else
        printf("Empate!\n");

    return 0;
}