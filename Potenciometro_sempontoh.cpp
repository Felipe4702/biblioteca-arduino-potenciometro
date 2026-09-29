class Potenciometro {
  private:
    uint8_t pino;

  public:

    enum TipoLeitura { BRUTO, TENSAO, MAPEADO };

    Potenciometro(uint8_t pinoAnalogico) {
        pino = pinoAnalogico;
        pinMode(pino, INPUT); 
    }


    int lerBruto() {
        return analogRead(pino);
    }


    float lerTensao() {
        return lerBruto() * (5.0 / 1023.0);
    }


    float lerMapeado(float minDestino, float maxDestino) {
        return (lerBruto() / 1023.0) * (maxDestino - minDestino) + minDestino;
    }


    void imprimirNoSerial(TipoLeitura tipo, float minDestino = 0.0, float maxDestino = 0.0) {
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
};


Potenciometro meuPotenciometro(A0);

void setup() {
    Serial.begin(9600);
}

void loop() {
    meuPotenciometro.imprimirNoSerial(Potenciometro::BRUTO);
    meuPotenciometro.imprimirNoSerial(Potenciometro::TENSAO);
    meuPotenciometro.imprimirNoSerial(Potenciometro::MAPEADO, 20.0, 40.0); // Mapeando de 0-5V para 20-40
    
    Serial.println("-------------------");
    delay(1000);
}
