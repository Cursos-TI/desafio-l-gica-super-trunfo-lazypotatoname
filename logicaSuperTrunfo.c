 #include <stdio.h>
#include <string.h>

// Definindo a estrutura da carta
struct Carta {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular densidade populacional e PIB per capita
void calcularDados(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para imprimir uma carta (para visualização)
void imprimirCarta(struct Carta carta) {
    printf("Cidade: %s (%s)\n", carta.nomeCidade, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
    printf("--------------------------\n");
}

int main() {
    // Cadastro das cartas (pré-definidas)
    struct Carta carta1 = {
        "SP", "C001", "São Paulo",
        12300000, 1521.0, 700.0, 25
    };

    struct Carta carta2 = {
        "RJ", "C002", "Rio de Janeiro",
        6710000, 1200.0, 350.0, 20
    };

    // Calcula dados derivados
    calcularDados(&carta1);
    calcularDados(&carta2);

    // Exibe as cartas
    printf("=== Cartas Cadastradas ===\n");
    imprimirCarta(carta1);
    imprimirCarta(carta2);

    // Comparação de atributo: POPULAÇÃO
    printf("=== Comparação de Cartas (Atributo: População) ===\n");
    printf("Carta 1 - %s (%s): %d habitantes\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
