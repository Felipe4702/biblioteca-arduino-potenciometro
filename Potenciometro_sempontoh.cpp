// Definição e implementação da classe Potenciometro
class Potenciometro {
  private:
    uint8_t pino;

  public:
    // Opções para a função de impressão no Serial
    enum TipoLeitura { BRUTO, TENSAO, MAPEADO };

    // Construtor
    Potenciometro(uint8_t pinoAnalogico) {
        pino = pinoAnalogico;
        pinMode(pino, INPUT); 
    }

    // 1. Lê o valor direto de 0 a 1023
    int lerBruto() {
        return analogRead(pino);
    }

    // 2. Converte para tensão de 0.0V a 5.0V
    float lerTensao() {
        return lerBruto() * (5.0 / 1023.0);
    }

    // 3. Mapeia o valor lido (0 a 1023) para um intervalo definido pelo usuário
    float lerMapeado(float minDestino, float maxDestino) {
        return (lerBruto() / 1023.0) * (maxDestino - minDestino) + minDestino;
    }

    // 4. Imprime no Serial a leitura escolhida
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
