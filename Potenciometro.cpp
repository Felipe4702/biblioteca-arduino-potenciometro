#include "Potenciometro.h"

Potenciometro::Potenciometro(uint8_t pinoAnalogico) {
    pino = pinoAnalogico;
    pinMode(pino, INPUT); 
}

int Potenciometro::lerBruto() {
    return analogRead(pino);
}


float Potenciometro::lerTensao() {
    return lerBruto() * (5.0 / 1023.0);
}

float Potenciometro::lerMapeado(float minDestino, float maxDestino) {
    return (lerBruto() / 1023.0) * (maxDestino - minDestino) + minDestino;
}

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
