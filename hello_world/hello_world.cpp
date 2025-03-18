#include <stdio.h>
#include <stdlib.h>

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir o menu de operações
void exibirMenu() {
    printf("\n=== Calculadora ===\n");
    printf("1. Soma\n");
    printf("2. Subtracao\n");
    printf("3. Multiplicacao\n");
    printf("4. Divisao\n");
    printf("0. Sair\n");
    printf("Escolha uma operacao: ");
}

// Função para ler um número float com validação
float lerNumero(const char* mensagem) {
    float numero;
    char input[100];
    int valido;

    do {
        valido = 1;
        printf("%s", mensagem);

        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Tenta converter a entrada para float
            if (sscanf_s(input, "%f", &numero) != 1) {
                printf("Erro: Digite um numero válido!\n");
                valido = 0;
            }
        }
        else {
            printf("Erro de leitura!\n");
            valido = 0;
            limparBuffer();
        }
    } while (!valido);

    return numero;
}

// Função principal que implementa a calculadora
int main() {
    int opcao;
    float num1, num2, resultado;
    char input[100];

    printf("Bem-vindo à Calculadora!\n");

    do {
        exibirMenu();

        // Lê a opção com validação
        if (fgets(input, sizeof(input), stdin) == NULL || sscanf_s(input, "%d", &opcao) != 1) {
            printf("Erro: Digite uma opcao valida!\n");
            limparBuffer();
            continue;
        }

        // Verifica se a opção é válida
        if (opcao < 0 || opcao > 4) {
            printf("Opcao invalida! Por favor, escolha uma opcao entre 0 e 4.\n");
            continue;
        }

        // Se escolheu sair, encerra o programa
        if (opcao == 0) {
            printf("Encerrando a calculadora. Ate logo!\n");
            break;
        }

        // Lê os números para a operação
        num1 = lerNumero("Digite o primeiro numero: ");
        num2 = lerNumero("Digite o segundo numero: ");

        // Realiza a operação escolhida
        switch (opcao) {
        case 1: // Soma
            resultado = num1 + num2;
            printf("\nResultado: %.2f + %.2f = %.2f\n", num1, num2, resultado);
            break;

        case 2: // Subtração
            resultado = num1 - num2;
            printf("\nResultado: %.2f - %.2f = %.2f\n", num1, num2, resultado);
            break;

        case 3: // Multiplicação
            resultado = num1 * num2;
            printf("\nResultado: %.2f * %.2f = %.2f\n", num1, num2, resultado);
            break;

        case 4: // Divisão
            if (num2 == 0) {
                printf("\nErro: Divisao por zero nao e permitida!\n");
            }
            else {
                resultado = num1 / num2;
                printf("\nResultado: %.2f / %.2f = %.2f\n", num1, num2, resultado);
            }
            break;
        }

    } while (1);

    return 0;
}
