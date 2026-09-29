#include "Potenciometro.h"

// Construtor: inicializa o pino
Potenciometro::Potenciometro(uint8_t pinoAnalogico) {
    pino = pinoAnalogico;
    // Pinos analógicos não exigem obrigatoriamente o pinMode para leitura,
    // mas é uma boa prática declarar a intenção.
    pinMode(pino, INPUT); 
}

// 1. Lê o valor direto de 0 a 1023
int Potenciometro::lerBruto() {
    return analogRead(pino);
}

// 2. Converte para tensão de 0.0V a 5.0V
float Potenciometro::lerTensao() {
    return lerBruto() * (5.0 / 1023.0);
}

// 3. Mapeia o valor lido (0 a 1023) para um intervalo definido pelo usuário
float Potenciometro::lerMapeado(float minDestino, float maxDestino) {
    // Cálculo em float para permitir escalas com casas decimais
    return (lerBruto() / 1023.0) * (maxDestino - minDestino) + minDestino;
}

// 4. Imprime no Serial a leitura escolhida
void Potenciometro::imprimirNoSerial(TipoLeitura tipo, float minDestino, float maxDestino) {
    switch(tipo) {
        case BRUTO:
            Serial.print("Valor Bruto: ");
            Serial.println(lerBruto());
            break;
            
        case TENSAO:
            Serial.print("Tensao (V): ");
            Serial.println(lerTensao());
            break;
            
        case MAPEADO:
            Serial.print("Valor Mapeado: ");
            Serial.println(lerMapeado(minDestino, maxDestino));
            break;
    }
}
