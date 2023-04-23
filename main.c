#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * INSTRUÇÕES DO MEU GRUPO:
 * | lb | sb | sub | and | ori | srl | beq |
*/
enum {
    OPCODE = 0,
    FUNCT3 = 2,
    FUNCT7 = 5,
};




void separa_imm_B(char* convertidoBin, char im_separado_tipo_B[4][100]);
void reg_em_binario_B(char vet[50][50],char vetBin[8][100], int t, char* convertidoBin);
void printa_binario_I(char binario[5][100]);
void immediate_to_bin(char im[100], char convertidoBin[100]) {
    int im_inteiro, i  = 0, j;
    im_inteiro = atoi(im);
    if (im_inteiro >= 0) {
        while (im_inteiro > 0) {
            convertidoBin[i++] = (im_inteiro % 2) + '0';
            im_inteiro /= 2;
        }
        while (i < 12) {
            convertidoBin[i++] = '0';
        }
        convertidoBin[i] = '\0';

        for (j = 0; j < i / 2; j++) {
            char temp = convertidoBin[j];
            convertidoBin[j] = convertidoBin[i - j - 1];
            convertidoBin[i - j - 1] = temp;
        }
    } else {
        int complemento = 4096 - (-1 * im_inteiro);
        while (complemento > 0) {
            convertidoBin[i++] = (complemento % 2) + '0';
            complemento /= 2;
        }
        while (i < 12) {
            convertidoBin[i++] = '1';
        }
        convertidoBin[i] = '\0';

        for (j = 0; j < i / 2; j++) {
            char temp = convertidoBin[j];
            convertidoBin[j] = convertidoBin[i - j - 1];
            convertidoBin[i - j - 1] = temp;
        }
    }
}
void printa_binario_B(char binario[8][100]) {
    printf("\n");
    for (int i = 7; i >= 0; i--) {
        printf("%s", binario[i]);
    }
}

void printa_binario_R(char binario[6][100]) {
    printf("\n");
    for (int i = 5; i >= 0; i--) {
        printf("%s", binario[i]);
    }
}

void printa_binario_I(char binario[5][100]) {
    printf("\n");
    for (int i = 4; i >= 0; i--) {
        printf("%s", binario[i]);
    }
}

void reg_em_binario_I_paren(char vet[50][50],char vetBin[6][100], int t, char* convertidoBin)
{
    char* registradores[] = {"x0", "x1", "x2", "x3", "x4", "x5", "x6","x7","x8","x9","x10","x11","x12","x13","x14","x15","x16","x17","x18","x19","x20","x21","x22","x23","x24","x25","x26","x27","x28","x29","x30","x31"};
    char* apelido[] = {"zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "s0", "s1","a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "s2", "s3","s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", "t3","t4", "t5", "t6"};
    char* registradores_em_binario[] = {"00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111", "01000", "01001", "01010", "01011", "01100", "01101", "01110", "01111", "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111", "11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111"};

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 32; j++) {
            if (!strcmp(vet[i], registradores[j]) || !strcmp(vet[i], apelido[j])) {
                if (i == 1) {
                    strcpy(vetBin[1], registradores_em_binario[j]);
                }
                else if (i == 3) {
                    strcpy(vetBin[3], registradores_em_binario[j]);
                }
            }
            if (i == 2) {
                immediate_to_bin(vet[2], convertidoBin);
                strcpy(vetBin[4], convertidoBin);
            }
        }
    }
}

void reg_em_binario_I(char vet[50][50],char vetBin[6][100], int t, char* convertidoBin)
{
    char* registradores[] = {"x0", "x1", "x2", "x3", "x4", "x5", "x6","x7","x8","x9","x10","x11","x12","x13","x14","x15","x16","x17","x18","x19","x20","x21","x22","x23","x24","x25","x26","x27","x28","x29","x30","x31"};
    char* apelido[] = {"zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "s0", "s1","a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "s2", "s3","s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", "t3","t4", "t5", "t6"};
    char* registradores_em_binario[] = {"00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111", "01000", "01001", "01010", "01011", "01100", "01101", "01110", "01111", "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111", "11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111"};

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 32; j++) {
            if (!strcmp(vet[i], registradores[j]) || !strcmp(vet[i], apelido[j])) {
                if (i == 1) {
                    strcpy(vetBin[1], registradores_em_binario[j]);
                }
                else if (i == 2) {
                    strcpy(vetBin[3], registradores_em_binario[j]);
                }
            }
            if (i == 3) {
                immediate_to_bin(vet[3], convertidoBin);
                strcpy(vetBin[4], convertidoBin);
            }
        }
    }
}

void reg_em_binario(char vet[50][50],char vetBin[6][100], int t)
{
    char* registradores[] = {"x0", "x1", "x2", "x3", "x4", "x5", "x6","x7","x8","x9","x10","x11","x12","x13","x14","x15","x16","x17","x18","x19","x20","x21","x22","x23","x24","x25","x26","x27","x28","x29","x30","x31"};
    char* apelido[] = {"zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "s0", "s1","a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "s2", "s3","s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", "t3","t4", "t5", "t6"};
    char* registradores_em_binario[] = {"00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111", "01000", "01001", "01010", "01011", "01100", "01101", "01110", "01111", "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111", "11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111"};

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 32; j++) {
            if (!strcmp(vet[i], registradores[j]) || !strcmp(vet[i], apelido[j])) {
                if (i < 2) {
                    strcpy(vetBin[1], registradores_em_binario[j]);
                }
                else if (i < 3) {
                    strcpy(vetBin[3], registradores_em_binario[j]);
                }
                else if (i < 4) {
                    strcpy(vetBin[4], registradores_em_binario[j]);
                }
            }
        }
    }
}
int main() {
    FILE * instrucoesAssembly;
    instrucoesAssembly = fopen("../instrucoes.txt", "r");
    char linha[200];
    char * token;
    char vetInstruLinha[50][50];
    char binario_R[6][100];
    char binario_I[5][100];
    char binario_B[8][100];
    char im_convertido[100];
    char linhaProcessada[200];
    int cont = 0;

    do {
        fgets(linha, 200, instrucoesAssembly);
        linha[strcspn(linha, "\n")] = '\0';

        for (int i = 0; i < strlen(linha); i++) {
            if (linha[i] == ',' || linha[i] == '(' || linha[i] == ')') {
                linhaProcessada[i] = ' ';
            } else {
                linhaProcessada[i] = linha[i];
            }
        }
        linhaProcessada[strlen(linha)] = '\0';

        token = strtok(linhaProcessada, " ");
        while (token != NULL) {
            strcpy(vetInstruLinha[cont], token);
            token = strtok(NULL, " ");
            cont++;
        }

    } while (!feof(instrucoesAssembly));

    for (int i = 0; i < cont; i++) {
        printf("[%s]", vetInstruLinha[i]);
    }

    for (int a = 0; a < cont; a++) {
        if (!strcmp(vetInstruLinha[a], "add")) {
            strcpy(binario_R[OPCODE], "0110011");
            strcpy(binario_R[FUNCT3], "000");
            strcpy(binario_R[FUNCT7], "0000000");
            reg_em_binario(&vetInstruLinha[a], binario_R, 4);
            printa_binario_R(binario_R);
        }

        if (!strcmp(vetInstruLinha[a], "sub")) {
            strcpy(binario_R[OPCODE], "0110011");
            strcpy(binario_R[FUNCT3], "000");
            strcpy(binario_R[FUNCT7], "0100000");
            reg_em_binario(&vetInstruLinha[a], binario_R, 4);
            printa_binario_R(binario_R);
        }

        if (!strcmp(vetInstruLinha[a], "addi")) {
            strcpy(binario_I[OPCODE], "0010011");
            strcpy(binario_I[FUNCT3], "000");
            reg_em_binario_I(&vetInstruLinha[a], binario_I, 4, im_convertido);
            printa_binario_I(binario_I);
        }

        if (!strcmp(vetInstruLinha[a], "lb")) {
            strcpy(binario_I[OPCODE], "0000011");
            strcpy(binario_I[FUNCT3], "000");
            reg_em_binario_I_paren(&vetInstruLinha[a], binario_I, 4, im_convertido);
            printa_binario_I(binario_I);
        }
        if (!strcmp(vetInstruLinha[a], "sb")) {
            strcpy(binario_I[OPCODE], "0100011");
            strcpy(binario_I[FUNCT3], "000");
            reg_em_binario_I_paren(&vetInstruLinha[a], binario_I, 4, im_convertido);
            printa_binario_I(binario_I);
        }

        if (!strcmp(vetInstruLinha[a], "beq")) {
            strcpy(binario_B[OPCODE], "1100111");
            strcpy(binario_B[3], "000");
            reg_em_binario_B(&vetInstruLinha[a], binario_B, 4, im_convertido);
            printa_binario_B(binario_B);
        }
    }
    return 0;
}

void reg_em_binario_B(char vet[50][50],char vetBin[6][100], int t, char* convertidoBin) {
    char* registradores[] = {"x0", "x1", "x2", "x3", "x4", "x5", "x6","x7","x8","x9","x10","x11","x12","x13","x14","x15","x16","x17","x18","x19","x20","x21","x22","x23","x24","x25","x26","x27","x28","x29","x30","x31"};
    char* apelido[] = {"zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "s0", "s1","a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "s2", "s3","s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", "t3","t4", "t5", "t6"};
    char* registradores_em_binario[] = {"00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111", "01000", "01001", "01010", "01011", "01100", "01101", "01110", "01111", "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111", "11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111"};
    char im_separado_tipo_B[4][100];
    for (int b = 0; b < 4; b++) {
        strcpy(im_separado_tipo_B[b], "1");
    }

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 32; j++) {
            if (!strcmp(vet[i], registradores[j]) || !strcmp(vet[i], apelido[j])) {
                if (i == 1) {
                    strcpy(vetBin[4], registradores_em_binario[j]);
                }
                else if (i == 2) {
                    strcpy(vetBin[5], registradores_em_binario[j]);
                }
            }
            if (i == 3) {
                immediate_to_bin(vet[3], convertidoBin);
                separa_imm_B(convertidoBin, vetBin);
                break;
            }
        }
    }
}

void separa_imm_B(char* convertidoBin, char vetBin[8][100]) {

    int cont = 0;
    char novaString1[10];
    char newStr[12];
    char charUnico;
    charUnico = convertidoBin[1];
    sprintf(vetBin[1],"%c", charUnico);
    for (int a = 8; a <= 11; a++) {
        novaString1[cont] = convertidoBin[a];
        cont++;
    }
    strcpy(vetBin[2], novaString1);

    char novaString2[10];
    cont = 0;
    for (int b = 2; b <= 7; b++) {
        sprintf(newStr, "%c", convertidoBin[b]);
        novaString2[cont] = convertidoBin[b];
        cont++;
    }

    strcpy(vetBin[6], novaString2);

    charUnico = convertidoBin[0];
    sprintf(vetBin[7], "%c", charUnico);
}