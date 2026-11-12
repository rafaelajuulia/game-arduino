#include <LedControl.h>


typedef struct Snake Snake;
struct Snake {
  int head[2];
  int body[40][2];
  int len;
  int dir[2];
};

typedef struct Apple Apple;
struct Apple {
  int rPos;
  int cPos;
};


const int DIN = 12;
const int CS = 11;
const int CLK = 10;
LedControl lc = LedControl(DIN, CLK, CS, 1);

byte pic[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

Snake snake = { { 1, 5 }, { { 0, 5 }, { 1, 5 } }, 2, { 1, 0 } };
Apple apple = { 0, 0 };

int lastDir[2] = { 1, 0 };

float oldTime = 0;
float timer = 0;
float updateRate = 3;

int i, j;

void setup() {
  Serial.begin(9600);

  lc.shutdown(0, false);

  lc.setIntensity(0, 8);

  lc.clearDisplay(0);


  randomSeed(analogRead(A0));
  apple.rPos = random(0, 8);
  apple.cPos = random(0, 8);
}
float calculateDeltaTime() {
  float currentTime = millis();
  float dt = currentTime - oldTime;
  oldTime = currentTime;
  return dt;
}
void reset() {
  for (int j = 0; j < 8; j++) {
    pic[j] = 0;
  }
}

void removeFirst() {
  for (j = 1; j < snak.len ; j++) {
    snake, body[j-1][0] = snake.body [j][0];
    snakw, body[j-1][1] = snake.body [j][1];
  }
}

void Update() {
  // Reset (Clear) the 8x8 LED matrix
  reset();

  // Guarda a direção usada neste movimento
  lastDir[0] = snake.dir[0];
  lastDir[1] = snake.dir[1];

  // Calcula a posição da nova cabeça com base na direção atual
  int newHead[2] = {
    snake.head[0] + snake.dir[0],
    snake.head[1] + snake.dir[1]
  };

  // Handle Borders (Tratamento de bordas / tela infinita)
  if (newHead[0] == 8) {
    newHead[0] = 0;
  } else if (newHead[0] == -1) {
    newHead[0] = 7;
  } else if (newHead[1] == 8) {
    newHead[1] = 0;
  } else if (newHead[1] == -1) {
    newHead[1] = 7;
  }

  // Check If The Snake hits itself
  for (j = 0; j < snake.len; j++) {
    if (snake.body[j][0] == newHead[0] && snake.body[j][1] == newHead[1]) {
      // Pause the game for 1 sec then Reset it
      delay(1000);
      snake = { { 1, 5 }, { { 0, 5 }, { 1, 5 } }, 2, { 1, 0 } }; // Reinitialize the snake object

      lastDir[0] = 1;
      lastDir[1] = 0;
      apple.rPos = random(0, 8);
      apple.cPos = random(0, 8);
      return;
    }
  }

  //Check if The snake ate the apple
  bool comeu = (newHead[0] == apple.rPos && newHead[1] == apple.cPos);

  // Limite de 40 para não estourar o vetor body[40]
  if (comeu && snake.len < 40) {
    snake.len = snake.len + 1;
  } else {
    removeFirst();
  }

  if (comeu) {
    apple.rPos = random(0, 8);
    apple.cPos = random(0, 8);
  }

  snake.body[snake.len - 1][0] = newHead[0];
  snake.body[snake.len - 1][1] = newHead[1];

  snake.head[0] = newHead[0];
  snake.head[1] = newHead[1];

  }
}

