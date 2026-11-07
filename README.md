**-- Jogo da cobrinha com arduino a placa led --**

Projeto desenvolvido para a disciplina de Microcontroladores e Microprocessadores Uninassau Paulista

**-- Sobre o jogo --**
O jogo foi feito com um Arduino UNO e uma matriz de LED 8x8. Você controla a cobra com as setas do teclado do notebook e o jogo aparece na matriz de LED.

**-- Componentes --**
- Arduino Uno
- Matriz de LED 8x8 (módulo MAX7219)
- Jumpers
- Cabo USB
  
**-- Ligações --**

 Matriz LED | Arduino 
  VCC      =     5V      
  GND      =     GND     
  DIN      =     12      
  CS       =     11      
  CLK      =     10      

**-- Controles --**

 Tecla | Ação     

 ↑    =  Cima     
 ↓    =  Baixo    
 ←    =  Esquerda 
 →    =  Direita  
 ESC  =  Sair do script 

**-- Objetivo --** 
Comer as maçãs (LEDs que aparecem em posições aleatórias) para crescer sem bater no próprio corpo.

**-- Regras --**
- A cobra anda sozinha e você só escolhe a direção.
- Cada maçã comida aumenta o tamanho da cobra.
- Ao chegar em uma borda, a cobra reaparece do lado oposto da matriz.
- Se a cobra bater no próprio corpo, o jogo reinicia.


**-- Equipe --**

- [Rafaela Júlia]
- [Rayanne Marília]
- [Eshiley Letícia]
- [Davi Lucas]
- [Jean Witor]
