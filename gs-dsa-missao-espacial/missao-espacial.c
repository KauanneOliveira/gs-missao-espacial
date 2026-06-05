#include <stdio.h>


// VARIAVEIS (CONSTANTE, GLOBAIS, VETORES) 
// ====================================
#define MAX_LEITURAS 5

float temperatura;
float energia;
int comunicacao;
int dadosInseridos = 0;
int totalLeituras = 0;

float histTemperatura[MAX_LEITURAS];
float histEnergia[MAX_LEITURAS];

// FUNCOES 
// ====================================

// menu
// ------------------------------------
void exibirMenu(void) {
    printf("\n-----------------------------------------------------\n");
    printf("\tSISTEMA DE MONITORAMENTO ESPACIAL");
    printf("\n-----------------------------------------------------\n");
    printf(" 1. Inserir dados\n");
    printf(" 2. Visualizar status\n");
    printf(" 3. Executar analise\n");
    printf(" 4. Estatisticas e picos\n");
    printf(" 5. Encerrar sistema\n");
    printf("-----------------------------------------------------\n");
    printf(" Opcao: ");
}

// cadastrar dados
// ------------------------------------
void cadastrarDados() {
    printf("\n\tCADASTRO DE DADOS\n");

    printf("Temperatura (graus C): ");
    scanf("%f", &temperatura);

    printf("Nivel de energia (%%): ");
    scanf("%f", &energia);
 
    printf("Comunicacao (1 = OK / 0 = Falha): ");
    scanf("%d", &comunicacao);

    if (totalLeituras < MAX_LEITURAS) {
        histTemperatura[totalLeituras] = temperatura;
        histEnergia[totalLeituras] = energia;
        totalLeituras++;
    } else {
        int i;
        for (i = 0; i < MAX_LEITURAS - 1; i++) {
            histTemperatura[i] = histTemperatura[i + 1];
            histEnergia[i] = histEnergia[i + 1];
        }
        histTemperatura[MAX_LEITURAS - 1] = temperatura;
        histEnergia[MAX_LEITURAS - 1] = energia;
    }
 
    dadosInseridos = 1;
    printf("\nCadastro realizado com sucesso!\n");
}

// status da missao
// ------------------------------------
void visualizarStatus() {
    printf("\n\tSTATUS DA MISSAO\n");
    printf("Temperatura: %.1f graus C\n", temperatura);
    printf("Energia: %.1f%%\n", energia);
 
    if (comunicacao == 1) {
        printf("Comunicacao: OK\n");
    } else {
        printf("Comunicacao: FALHA\n");
    }
}

// analise do sistema
// ------------------------------------
void executarAnalise() {
    int alertas = 0;
 
    printf("\n\tANALISE DO SISTEMA\n");
 
    if (temperatura > 80) {
        printf("[ALERTA] Superaquecimento! Temperatura: %.1f C\n", temperatura);
        alertas++;
    }
 
    if (energia < 20) {
        printf("[ALERTA] Economia de energia! Nivel: %.1f%%\n", energia);
        alertas++;
    }
 
    if (comunicacao == 0) {
        printf("[ALERTA] Falha de comunicacao!\n");
        alertas++;
    }
 
    if (alertas == 0) {
        printf("Todos os sistemas operando normalmente\n");
    } else {
        printf("Alertas nesta analise: %d\n", alertas);
    }
 
    if (alertas == 0) {
        printf("Status geral da missao: NORMAL\n");
    } else if (alertas == 1) {
        printf("Status geral da missao: ATENCAO\n");
    } else {
        printf("Status geral da missao: CRITICA\n");
    }
}

// estatisticas do sistema
// ------------------------------------
void exibirEstatisticas() {
    int i;
    float somaTemp = 0;
    float somaEnergia = 0;
    float picoTemp;
    float picoEnergia;
 
    if (totalLeituras == 0) {
        printf("\nNenhuma leitura registrada ainda.\n");
        return;
    }
 
    picoTemp = histTemperatura[0];
    picoEnergia = histEnergia[0];
 
    for (i = 0; i < totalLeituras; i++) {
        somaTemp += histTemperatura[i];
        somaEnergia += histEnergia[i];
 
        if (histTemperatura[i] > picoTemp) 
            picoTemp = histTemperatura[i];

        if (histEnergia[i] > picoEnergia) 
            picoEnergia = histEnergia[i];
    }
 
    printf("\n\tESTATISTICAS (%d leituras)\n", totalLeituras);
    printf("Temperatura  | Media: %.1f C  | Pico: %.1f C\n", somaTemp / totalLeituras, picoTemp);
    printf("Energia      | Media: %.1f%%   | Pico: %.1f%%\n", somaEnergia / totalLeituras, picoEnergia);
}


// MAIN 
// ====================================
int main(void) {
    int opcao;
 
    do {
        exibirMenu();
        scanf("%d", &opcao);
 
        switch (opcao) {
            case 1:
                cadastrarDados();
                break;
            case 2:
                if (dadosInseridos == 0) {
                    printf("\nCadastre os dados primeiro (opcao 1).\n");
                } else {
                    visualizarStatus();
                }
                break;
            case 3:
                if (dadosInseridos == 0) {
                    printf("\nCadastre os dados primeiro (opcao 1).\n");
                } else {
                    executarAnalise();
                }
                break;
            case 4:
                exibirEstatisticas();
                break;
            case 5:
                printf("\nEncerrando sistema...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
 
    } while (opcao != 5);
 
    return 0;
}