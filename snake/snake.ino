#include <LedControl.h>


typedef struct Snake Snake;
struct Snake{
  int head[2];     
  int body[40][2]; 
  int len;        
  int dir[2];      
};

typedef struct Apple Apple;
struct Apple{
  int rPos; 
  int cPos; 
};