#include <iostream>
#include <cstdio>
#include <cctype> 

int main() {
    
    char reserva[10][6] = { 
        {' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' '}
    };

    int fileira = -1, acento = -1;
    char poltrona = ' ';
    char tipoPassagem;

    
    while (true) {
        printf("\nescolha o tipo de passagem (e para executiva, c para economica): ");
        scanf(" %c", &tipoPassagem);

        
        if (tipoPassagem != 'e' && tipoPassagem != 'c') {
            printf("Tipo de passagem invalido. Tente novamente.\n");
            continue; // Retorna ao início do laço se inválido
        }

        
        while (true) {
            printf("\nDigite a fileira (1-10): ");
            scanf("%d", &fileira);

            
            if (fileira < 1 || fileira > 10) {
                printf("Fileira invalida. Tente novamente.\n");
                continue; 
            }

            printf("Digite a poltrona [A][B][C][D][E][F]: ");
            scanf(" %c", &poltrona);
            poltrona = std::toupper(poltrona); 

            
            switch (poltrona) {
                case 'A': acento = 0; break;
                case 'B': acento = 1; break;
                case 'C': acento = 2; break;
                case 'D': acento = 3; break;
                case 'E': acento = 4; break;
                case 'F': acento = 5; break;
                default:
                    printf("Poltrona invalida.\n");
                    continue; 
            }

            
            if (reserva[fileira - 1][acento] == 'x') {
                printf("Esse assento ja esta reservado. Por favor, escolha outro.\n");
                continue; // Retorna ao início do laço se já reservado
            }

            
            if (tipoPassagem == 'c' && (poltrona == 'A' || poltrona == 'F')) {
                printf("As poltronas A e F sao exclusivas para passagens Executivas. Escolha outra poltrona.\n");
                continue; 
            }

            
            reserva[fileira - 1][acento] = 'x';

            
            printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
            for (int x = 0; x < 10; x++) {
                printf("\n\t%02d\t", x + 1);
                for (int y = 0; y < 6; y++) {
                    printf("[%c] ", reserva[x][y]);
                    if (y == 2) {
                        printf("\t"); 
                    }
                }
            }
            printf("\n");

            
            char resposta;
            printf("Deseja realizar outra reserva? (s/n): ");
            scanf(" %c", &resposta);
            if (resposta == 'n' || resposta == 'N') {
                printf("Encerrando o sistema de reservas...\n");
                return 0; 
            } else {
                break; 
            }
        }
    }
    return 0;
}
