#include "Potenciometro.h"

Potenciometro meuPotenciometro(A0);

void setup() {
    Serial.begin(9600);
}

void loop() {
    int valor1 = meuPotenciometro.lerBruto();
    float valor2 = meuPotenciometro.lerTensao();
    float valor3 = meuPotenciometro.lerMapeado(20.0, 40.0);

    meuPotenciometro.imprimirNoSerial(Potenciometro::BRUTO);
    meuPotenciometro.imprimirNoSerial(Potenciometro::TENSAO);
    meuPotenciometro.imprimirNoSerial(Potenciometro::MAPEADO, 20.0, 40.0);
    
    delay(1000);
}
