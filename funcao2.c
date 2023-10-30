#include <stdio.h>

float calcularDesconto(float total) {
    return total * 0.10;
}

float calcularParcelas(float total, int numParcelas) {
    if (total > 100.00 && numParcelas >= 3 && numParcelas <= 10) {
        float juros = total * 0.03;
        return (total + juros) / numParcelas;
    } else if (numParcelas == 2) {
        return total / 2;
    } else {
        return total;
    }
}

int imprimirOpcoes() {
    int opcao;
    printf("Escolha a opção de pagamento:\n");
    printf("1) À vista com 10%% de desconto\n");
    printf("2) Em duas vezes (preço da etiqueta)\n");
    printf("3) De 3 até 10 vezes com 3%% de juros ao mês (para compras acima de R$100.00)\n");
    scanf("%d", &opcao);
    return opcao;
}

int main() {
    float total;
    printf("Digite o total gasto pelo cliente: R$");
    scanf("%f", &total);
    int opcao = imprimirOpcoes();

    switch (opcao) {
        case 1:
            printf("Opção escolhida: À vista com 10%% de desconto\n");
            total -= calcularDesconto(total);
            break;
        case 2:
            printf("Opção escolhida: Em duas vezes (preço da etiqueta)\n");
            break;
        case 3:
            printf("Opção escolhida: De 3 até 10 vezes com 3%% de juros ao mês (para compras acima de R$100.00)\n");
            int numParcelas;
            printf("Digite o número de parcelas desejado (3 a 10): ");
            scanf("%d", &numParcelas);
            total = calcularParcelas(total, numParcelas);
            break;
        default:
            printf("Opção inválida.\n");
            return 1;
    }

    printf("Valor total das prestações: R$%.2f\n", total);
    return 0;
}


#include <stdio.h>

void calcularLocacoesGratuitas(int A[], int locacoes_gratuitas[]) {
    for (int i = 0; i < 500; i++) {
        locacoes_gratuitas[i] = A[i] / 15;
    }
}

int main() {
    int A[500]; // Suponha que o vetor A esteja preenchido com a quantidade de filmes retirados por cada cliente.
    int locacoes_gratuitas[500];
    calcularLocacoesGratuitas(A, locacoes_gratuitas);
    
    
    return 0;
}

#include <stdio.h>

void realizarTrocas(int A[10][10]) {
    int temp;

    // Trocar linha 2 com linha 8
    for (int i = 0; i < 10; i++) {
        temp = A[1][i];
        A[1][i] = A[7][i];
        A[7][i] = temp;
    }

    for (int i = 0; i < 10; i++) {
        temp = A[i][3];
        A[i][3] = A[i][9];
        A[i][9] = temp;
    }

    for (int i = 0; i < 10; i++) {
        temp = A[i][i];
        A[i][i] = A[i][9 - i];
        A[i][9 - i] = temp;
    }

    // Trocar linha 5 com coluna 10
    for (int i = 0; i < 10; i++) {
        temp = A[4][i];
        A[4][i] = A[i][9];
        A[i][9] = temp;
    }
}

int main() {
    int A[10][10]; // Suponha que a matriz A[10][10] esteja preenchida.

    realizarTrocas(A);

    
    return 0;
}

#include <stdio.h>

void somarColunas(int A[61][10]) {
    for (int j = 0; j < 10; j++) {
        int soma = 0;
        for (int i = 0; i < 61; i++) {
            soma += A[i][j];
        }
        A[60][j] = soma;
    }
}

int main() {
    int A[61][10]; // Suponha que a matriz A[61][10] esteja preenchida.

    somarColunas(A);

    // A matriz agora contém a soma individual das colunas na 61ª linha.
    
    return 0;
}



#include <stdio.h>

void calcularIdade(int diaNascimento, int mesNascimento, int anoNascimento, int *dias, int *meses, int *anos) {
    // Suponha que a data atual seja dia 30, mês 10, ano 2023 (valores de exemplo).
    int diaAtual = 30;
    int mesAtual = 10;
    int anoAtual = 2023;

    *anos = anoAtual - anoNascimento;
    *meses = mesAtual - mesNascimento;
    *dias = diaAtual - diaNascimento;

    if (*dias < 0) {
        *meses -= 1;
        *dias += 30; // Supondo um mês com 30 dias.
    }

    if (*meses < 0) {
        *anos -= 1;
        *meses += 12;
    }
}

int main() {
    int diaNascimento, mesNascimento, anoNascimento;
    printf("Digite a data de nascimento (dia mês ano): ");
    scanf("%d %d %d", &diaNascimento, &mesNascimento, &anoNascimento);

    int dias, meses, anos;
    calcularIdade(diaNascimento, mesNascimento, anoNascimento, &dias, &meses, &anos);

    printf("Idade: %d anos, %d meses,