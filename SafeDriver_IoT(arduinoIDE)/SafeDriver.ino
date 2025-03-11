/*
  Carro Inteligente com Modo Automático e Manual
  Controle de motores pelo navegador + Sensor Ultrassônico
*/


#include <WiFi.h>

// Credenciais WiFi 
const char* ssid = "";
const char* password = "";

// Define os pinos do sensor ultrassônico
#define TRIGGER_PIN 6
#define ECHO_PIN 7

// Define os pinos dos motores
#define MOTOR_ESQUERDO_FRENTE_PIN  2
#define MOTOR_ESQUERDO_RE_PIN      3
#define MOTOR_DIREITO_FRENTE_PIN   5
#define MOTOR_DIREITO_RE_PIN       4

// Variáveis de estado
bool isManualMode = true; // Inicia no modo manual
bool isMovingForward = false;

// Servidor WiFi
WiFiServer server(80);

// String para armazenar os dados da requisição HTTP
String header;

// Função para medir distância do sensor ultrassônico
float measureDistance() {
  // Gera pulso no Trigger
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Mede o tempo do Echo
  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // Timeout de 30ms (30.000 µs)

  // Verifica se houve falha na medição
  if (duration == 0) {
    return -1; // Retorna -1 em caso de erro
  }

  // Calcula a distância em centímetros
  return (duration * 0.034) / 2;
}

// Funções de movimento
void moveForward() {
  digitalWrite(MOTOR_ESQUERDO_FRENTE_PIN, HIGH);
  digitalWrite(MOTOR_DIREITO_FRENTE_PIN, HIGH);
  digitalWrite(MOTOR_ESQUERDO_RE_PIN, LOW);
  digitalWrite(MOTOR_DIREITO_RE_PIN, LOW);
  isMovingForward = true;
}

void moveBackward() {
  digitalWrite(MOTOR_ESQUERDO_FRENTE_PIN, LOW);
  digitalWrite(MOTOR_DIREITO_FRENTE_PIN, LOW);
  digitalWrite(MOTOR_ESQUERDO_RE_PIN, HIGH);
  digitalWrite(MOTOR_DIREITO_RE_PIN, HIGH);
  isMovingForward = false;
}

// Função de curva aprimorada
void turnLeft() {
  digitalWrite(MOTOR_ESQUERDO_FRENTE_PIN, LOW);  // Lado esquerdo para trás
  digitalWrite(MOTOR_ESQUERDO_RE_PIN, HIGH);
  digitalWrite(MOTOR_DIREITO_FRENTE_PIN, HIGH);  // Lado direito para frente
  digitalWrite(MOTOR_DIREITO_RE_PIN, LOW);
}

void turnRight() {
  digitalWrite(MOTOR_ESQUERDO_FRENTE_PIN, HIGH);  // Lado esquerdo para frente
  digitalWrite(MOTOR_ESQUERDO_RE_PIN, LOW);
  digitalWrite(MOTOR_DIREITO_FRENTE_PIN, LOW);    // Lado direito para trás
  digitalWrite(MOTOR_DIREITO_RE_PIN, HIGH);
}

void stopMotors() {
  digitalWrite(MOTOR_ESQUERDO_FRENTE_PIN, LOW);
  digitalWrite(MOTOR_DIREITO_FRENTE_PIN, LOW);
  digitalWrite(MOTOR_ESQUERDO_RE_PIN, LOW);
  digitalWrite(MOTOR_DIREITO_RE_PIN, LOW);
  isMovingForward = false;
}

void halfTurn() {
  // Executa uma meia-volta
  moveBackward();
  delay(500); // Anda para trás por meio segundo
  turnRight();
  delay(1000); // Gira para a direita por 1 segundo
  stopMotors();
}

// Modo automático
void automaticMode() {
  float distance = measureDistance();

  if (distance == -1) {
    Serial.println("Erro ao medir a distância");
    stopMotors();
    return;
  }

  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 15) {
    moveForward(); // Anda para frente se não houver obstáculo
  } else {
    Serial.println("Obstáculo detectado! Fazendo meia-volta...");
    halfTurn();
  }
}

// Configuração inicial
void setup() {
  // Inicializa o monitor serial
  Serial.begin(115200);

  // Configura os pinos do sensor
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Configura os pinos dos motores
  pinMode(MOTOR_ESQUERDO_FRENTE_PIN, OUTPUT);
  pinMode(MOTOR_ESQUERDO_RE_PIN, OUTPUT);
  pinMode(MOTOR_DIREITO_FRENTE_PIN, OUTPUT);
  pinMode(MOTOR_DIREITO_RE_PIN, OUTPUT);

  // Para os motores no início
  stopMotors();

  // Configura o WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Aguarda a conexão WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Conectado à rede WiFi: ");
  Serial.println(WiFi.SSID());
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  // Inicia o servidor
  server.begin();
}

// Loop principal
void loop() {
  // Verifica conexões do cliente HTTP
  WiFiClient client = server.accept();
  if (client) {
    Serial.println("Novo cliente conectado.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        header += c;

        // Verifica fim da requisição
        if (c == '\n') {
          if (currentLine.length() == 0) {
            // Envia a resposta HTTP
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // Página de controle
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<style>button { width: 200px; height: 50px; font-size: 18px; margin: 10px; }</style></head>");
            client.println("<body><h1>Controle do Carro Inteligente</h1>");
            client.println("<button onclick=\"fetch('/manual')\">Modo Manual</button>");
            client.println("<button onclick=\"fetch('/auto')\">Modo Automático</button>");
            client.println("<br><button onpointerdown=\"fetch('/forward')\" onpointerup=\"fetch('/stop')\">Frente</button>");
            client.println("<button onpointerdown=\"fetch('/backward')\" onpointerup=\"fetch('/stop')\">Ré</button>");
            client.println("<button onpointerdown=\"fetch('/left')\" onpointerup=\"fetch('/stop')\">Esquerda</button>");
            client.println("<button onpointerdown=\"fetch('/right')\" onpointerup=\"fetch('/stop')\">Direita</button>");
            client.println("</body></html>");
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }

    if (header.indexOf("GET /manual") >= 0) {
      isManualMode = true;
      stopMotors();
    } else if (header.indexOf("GET /auto") >= 0) {
      isManualMode = false;
    } else if (isManualMode) {
      if (header.indexOf("GET /forward") >= 0) moveForward();
      else if (header.indexOf("GET /backward") >= 0) moveBackward();
      else if (header.indexOf("GET /left") >= 0) turnLeft();
      else if (header.indexOf("GET /right") >= 0) turnRight();
      else if (header.indexOf("GET /stop") >= 0) stopMotors();
    }

    header = "";
    client.stop();
    Serial.println("Cliente desconectado.");
  }

  // Executa o modo automático se estiver ativado
  if (!isManualMode) {
    automaticMode();
  }
}
