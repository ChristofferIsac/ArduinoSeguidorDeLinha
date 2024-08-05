// DEFINIÇÕES DE PINOS DO SENSOR DE LINHA
#define pinSensorDir 4  // Define o pino do sensor direito
#define pinSensorEsq 12 // Define o pino do sensor esquerdo

// DEFINIÇÕES DE PINOS DO SENSOR DE ULTRASSOM
#define pinEcho 2 // Define o Echo
#define pinTrig 3 // Define o Trig

#define dirFrente 6  // Define o pino do motor direito para frente
#define dirTras   5  // Define o pino do motor direito para trás
#define esqFrente 10 // Define o pino do motor esquerdo para frente
#define esqTras   11 // Define o pino do motor esquerdo para trás

// DEFINIÇÕES
#define LINHA HIGH  // Define que a linha é representada por HIGH (alto)
#define FRENTE  1  // Define o valor para mover para frente
#define PARADO  0  // Define o valor para parar
#define TRAS   -1  // Define o valor para mover para trás

// DECLARAÇÃO DE FUNÇÕES DOS MOTORES
void configMotor(); // Função para configurar os pinos dos motores
void motorEsq(int direcao, byte velocidade = 120); // Função para controlar o motor esquerdo
void motorDir(int direcao, byte velocidade = 120); // Função para controlar o motor direito

// DECLARAÇÃO DE FUNÇÕES DO SENSOR ULTRASSOM
long medeDistancia(); // Função para medir a distância com o sensor ultrassom

// DECLARAÇÃO DE VARIÁVEIS DOS SENSORES DE LINHA
bool leituraEsquerda; // Variável para armazenar a leitura do sensor esquerdo
bool leituraDireita;  // Variável para armazenar a leitura do sensor direito

void setup() {
  //Serial.begin(9600); // Inicializa a comunicação serial (comentada)
  
  // Configuração dos pinos dos sensores de linha
  pinMode(pinSensorDir, INPUT); // Configura o pino do sensor direito como entrada
  pinMode(pinSensorEsq, INPUT); // Configura o pino do sensor esquerdo como entrada
  
  // Configuração dos pinos do sensor de ultrassom
  pinMode(pinTrig, OUTPUT); // Configura o pino do Trig como saída
  pinMode(pinEcho, INPUT);  // Configura o pino do Echo como entrada
  
  configMotor(); // Chama a função para configurar os pinos dos motores
}

void loop() {
  // Lê os valores dos sensores de linha
  bool valE = digitalRead(pinSensorEsq); // Lê o valor do sensor esquerdo
  bool valD = digitalRead(pinSensorDir); // Lê o valor do sensor direito
  
  // Mede a distância com o sensor de ultrassom
  long distancia = medeDistancia();
  
  // Se detectar um obstáculo a menos de 20 cm
  if (distancia < 20) {
    motorEsq(PARADO); // Para o motor esquerdo
    motorDir(PARADO); // Para o motor direito
    delay(1000); // Espera por 1 segundo
    motorEsq(TRAS, 150); // Move o motor esquerdo para trás
    motorDir(TRAS, 150); // Move o motor direito para trás
    delay(500); // Espera por 0.5 segundo
    motorEsq(PARADO); // Para o motor esquerdo
    motorDir(PARADO); // Para o motor direito
  } else {
    // Controle baseado nos sensores de linha
    if (valE == LINHA && valD == LINHA) {
      motorEsq(PARADO); // Para o motor esquerdo
      motorDir(PARADO); // Para o motor direito
      delay(300); // Espera por 300 ms
      motorEsq(TRAS); // Move o motor esquerdo para trás
      motorDir(TRAS); // Move o motor direito para trás
      delay(150); // Espera por 150 ms
      motorEsq(PARADO); // Para o motor esquerdo
      motorDir(PARADO); // Para o motor direito
      delay(3000); // Espera por 3 segundos
    } else if (valD == LINHA) { // Se apenas o sensor direito detectar a linha
      motorEsq(FRENTE, 150); // Move o motor esquerdo para frente com velocidade 150
      motorDir(TRAS, 150); // Move o motor direito para trás com velocidade 150
    } else if (valE == LINHA) { // Se apenas o sensor esquerdo detectar a linha
      motorEsq(TRAS, 150); // Move o motor esquerdo para trás com velocidade 150
      motorDir(FRENTE, 150); // Move o motor direito para frente com velocidade 150
    } else { // Se nenhum sensor detectar a linha
      motorEsq(FRENTE); // Move o motor esquerdo para frente com velocidade padrão
      motorDir(FRENTE); // Move o motor direito para frente com velocidade padrão
    }
  }
}

// IMPLEMENTO DE FUNÇÕES

void configMotor() {
  pinMode(dirFrente,  OUTPUT); // Configura o pino do motor direito para frente como saída
  pinMode(dirTras,    OUTPUT); // Configura o pino do motor direito para trás como saída
  pinMode(esqFrente,  OUTPUT); // Configura o pino do motor esquerdo para frente como saída
  pinMode(esqTras,    OUTPUT); // Configura o pino do motor esquerdo para trás como saída

  // Inicializa os pinos dos motores como LOW (desligado)
  digitalWrite(dirFrente,  LOW);
  digitalWrite(dirTras,    LOW);
  digitalWrite(esqFrente,  LOW);
  digitalWrite(esqTras,    LOW);
}

void motorEsq(int direcao, byte velocidade = 120) {
  switch (direcao) {
    case -1: { // Se a direção for para trás
        digitalWrite(esqFrente,  LOW); // Desliga o motor para frente
        analogWrite (esqTras,    velocidade); // Liga o motor para trás com a velocidade definida
        break;
      }
    case 0: { // Se a direção for parar
        digitalWrite(esqFrente,  HIGH); // Liga o motor para frente
        digitalWrite(esqTras,    HIGH); // Liga o motor para trás (parando o motor)
        break;
      }
    case 1: { // Se a direção for para frente
        analogWrite (esqFrente,  velocidade); // Liga o motor para frente com a velocidade definida
        digitalWrite(esqTras,    LOW); // Desliga o motor para trás
        break;
      }
  }
}

void motorDir(int direcao, byte velocidade = 120) {
  switch (direcao) {
    case -1: { // Se a direção for para trás
        digitalWrite(dirFrente,  LOW); // Desliga o motor para frente
        analogWrite (dirTras,    velocidade); // Liga o motor para trás com a velocidade definida
        break;
      }
    case 0: { // Se a direção for parar
        digitalWrite(dirFrente,  HIGH); // Liga o motor para frente
        digitalWrite(dirTras,    HIGH); // Liga o motor para trás (parando o motor)
        break;
      }
    case 1: { // Se a direção for para frente
        analogWrite (dirFrente,  velocidade); // Liga o motor para frente com a velocidade definida
        digitalWrite(dirTras,    LOW); // Desliga o motor para trás
        break;
      }
  }
}

long medeDistancia() {
  // Envia um pulso de trigger
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  // Lê o tempo do pulso de echo
  long duracao = pulseIn(pinEcho, HIGH);

  // Calcula a distância em centímetros
  long distancia = duracao * 0.034 / 2;

  return distancia;
}
