#ifndef POTENCIOMETRO_H
#define POTENCIOMETRO_H

#include <Arduino.h>

class Potenciometro {
  private:
    uint8_t pino; // Guarda o pino onde o potenciômetro está conectado

  public:
    // Opções para a função de impressão no Serial
    enum TipoLeitura { BRUTO, TENSAO, MAPEADO };

    // Construtor
    Potenciometro(uint8_t pinoAnalogico);
    
    // Funções requeridas
    int lerBruto();
    float lerTensao();
    float lerMapeado(float minDestino, float maxDestino);
    
    // Função que chama as outras dependendo da escolha do usuário
    void imprimirNoSerial(TipoLeitura tipo, float minDestino = 0.0, float maxDestino = 0.0);
};

#endif
