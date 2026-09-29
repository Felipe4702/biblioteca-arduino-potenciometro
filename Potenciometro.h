#ifndef POTENCIOMETRO_H
#define POTENCIOMETRO_H

#include <Arduino.h>

class Potenciometro {
  private:
    uint8_t pino;

  public:
    enum TipoLeitura { BRUTO, TENSAO, MAPEADO };

    Potenciometro(uint8_t pinoAnalogico);
    
    int lerBruto();
    float lerTensao();
    float lerMapeado(float minDestino, float maxDestino);
    
    void imprimirNoSerial(TipoLeitura tipo, float minDestino = 0.0, float maxDestino = 0.0);
};

#endif
