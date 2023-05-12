///
/// TODO: redrawPlayer();
///       collisions();
///       jablka();
///       spawnRules();
///       score();
///       start and end screens
///
///       cleanup the code
///       comments
///       
///       upload to github
///       foto documentation
///       demo video
///



#include <TFT.h>
#include <SPI.h>
#include <Esplora.h>

/// <summary>
/// VARIABLES
/// </summary>
int screenWidth = EsploraTFT.width();
int screenHeight = EsploraTFT.height();
int rectWidth = int(screenWidth - 4);
int rectHeight = int(screenHeight - 4);

int oldOrientation = 0;
int howIsApple = 0;
int squareCount = 1;
String whenMuchApple = "Score  ";

int squareSize = 8; // size of each square

int middleX = EsploraTFT.width() / 2 - 1; // x position of the middle of the screen minus 1
int middleY = EsploraTFT.height() / 2 - 1; // y position of the middle of the screen minus 1

int playerPosX = middleX - squareSize;
int playerPosY = middleY - squareSize;
int lastPosX = playerPosX;
int lastPosY = playerPosY;

int karel = 0;
int iveta = 0;
int orientation = 4;
int btnPressed = 0;

/// <summary>
/// METHODS BELOW
/// </summary>
void controlButtons() {
    int button1State = 0;
    int button2State = 0;
    int button3State = 0;
    int button4State = 0;

    button1State = Esplora.readButton(SWITCH_1);    //DOWN
    switch (button1State) {
    case LOW:
        Serial.println("bottom_button is down");
        if (orientation != 1) {
          iveta = 1;
          oldOrientation = orientation;
        }
        orientation = 1;
        karel = 3;
        break;
    }

    button2State = Esplora.readButton(SWITCH_2);    //LEFT
    switch (button2State) {
    case LOW:
        Serial.println("left_button is down");
        if (orientation != 2) {
          iveta = 1;
          oldOrientation = orientation;
        }
        orientation = 2;
        karel = 3;
        break;
    }

    button3State = Esplora.readButton(SWITCH_3);    //UP
    switch (button3State) {
    case LOW:
        Serial.println("top_button is down");
        if (orientation != 3) {
          iveta = 1;
          oldOrientation = orientation;
        }
        orientation = 3;
        karel = 3;
        break;
    }

    button4State = Esplora.readButton(SWITCH_4);    //RIGHT
    switch (button4State) {
    case LOW:
        Serial.println("right_button is down");
        if (orientation != 4) {
          iveta = 1;
          oldOrientation = orientation;
        }
        orientation = 4;
        karel = 3;
        break;
    }
}   

void redrawPlayer() {
    EsploraTFT.stroke(0, 255, 0);
    EsploraTFT.fill(0, 0, 0);
    switch (orientation)
    {
    case 1:
      switch (oldOrientation) {
        Serial.println("redraw 1");
        case 2:
          EsploraTFT.rect(lastPosX + squareSize * 2, lastPosY - squareSize * 2, squareSize, squareSize);
          break;
        case 4:
          EsploraTFT.rect(lastPosX + squareSize, lastPosY - squareSize * 4, squareSize, squareSize);
          break;
        case 0:
          EsploraTFT.rect(lastPosY + squareSize * 2, lastPosY - squareSize * 2, squareSize, squareSize);
          break;
      }
    case 2:
      switch (oldOrientation) {
        Serial.println("redraw 2");
        case 1:
          EsploraTFT.rect(lastPosX + squareSize * 3, lastPosY, squareSize, squareSize);
          break;
        case 3:
          EsploraTFT.rect(lastPosX + squareSize * 3, lastPosY, squareSize, squareSize);
          break;
        case 0:
          EsploraTFT.rect(lastPosX + squareSize * 3, lastPosY, squareSize, squareSize);
          break;
      }
    case 3:
      switch (oldOrientation) {
        Serial.println("redraw 3");
        case 2:
          EsploraTFT.rect(lastPosX + squareSize * 2, lastPosY + squareSize, squareSize, squareSize);
          break;
        case 4:
          EsploraTFT.rect(lastPosX + squareSize, lastPosY + squareSize, squareSize, squareSize);
          break;
        case 0:
          EsploraTFT.rect(lastPosX, lastPosY, squareSize, squareSize);
          break;
      }
    case 4:
      switch (oldOrientation) {
        Serial.println("redraw 4");
        case 1:
          EsploraTFT.rect(lastPosX, lastPosY - squareSize, squareSize, squareSize);
          break;
        case 3:
          EsploraTFT.rect(lastPosX, lastPosY, squareSize, squareSize);
          break;
        case 0:
          EsploraTFT.rect(lastPosX + squareSize, lastPosY, squareSize, squareSize);
          break;
      }
    default:
        Serial.println("redrawPlayer error: orientation not set");
        break;
    }

}

void updatePlayer() {
    EsploraTFT.stroke(0, 0, 0);
    EsploraTFT.fill(60, 20, 255);
    switch (orientation) {
    case 1:
      if (oldOrientation != 1) {
        Serial.println("update 1");
        switch (oldOrientation){
        case 2:
          EsploraTFT.rect(playerPosX + squareSize * 2, playerPosY, squareSize, squareSize);
          lastPosX = playerPosX;
          lastPosY = playerPosY;
          playerPosY += squareSize;
          
          break;
        case 4:
          EsploraTFT.rect(playerPosX + squareSize, playerPosY + squareSize, squareSize, squareSize);
          lastPosX = playerPosX;
          lastPosY = playerPosY;
          playerPosY += squareSize;
          
          break;
        case 0:
          EsploraTFT.rect(playerPosX + squareSize * 2, playerPosY + squareSize, squareSize, squareSize);
          lastPosX = playerPosX;
          lastPosY = playerPosY;
          playerPosY += squareSize;
          
          break;
        }
      }
      break;
    case 2:
      if (oldOrientation != 4){
        Serial.println("update 2");
        switch (oldOrientation){
        case 3:
          EsploraTFT.rect(playerPosX + squareSize, playerPosY, squareSize, squareSize);
          lastPosX = playerPosX;
          lastPosY = playerPosY;
          playerPosX -= squareSize;
          
          break;
        case 1:
          EsploraTFT.rect(playerPosX + squareSize, playerPosY, squareSize, squareSize);
          lastPosX = playerPosX;
          lastPosY = playerPosY;
          playerPosX -= squareSize;
          
          break;
        case 0:
          EsploraTFT.rect(playerPosX - squareSize, playerPosY, squareSize, squareSize);
          lastPosX = playerPosX;
          lastPosY = playerPosY;
          playerPosX -= squareSize;
          
          break;
        }
      }
      break;
    case 3:
      if (oldOrientation != 1) {
        Serial.println("update 3");
        switch (oldOrientation){
        case 2:
          EsploraTFT.rect(playerPosX + squareSize * 2, playerPosY - squareSize, squareSize, squareSize);
          lastPosX = playerPosX;
          lastPosY = playerPosY;
          playerPosY -= squareSize;
          
          break;
        case 4:
          EsploraTFT.rect(playerPosX + squareSize, playerPosY - squareSize, squareSize, squareSize);
          lastPosX = playerPosX;
          lastPosY = playerPosY;
          playerPosY -= squareSize;
          
          break;
        case 0:
          EsploraTFT.rect(playerPosX + squareSize * 2, playerPosY - squareSize, squareSize, squareSize);
          lastPosX = playerPosX;
          lastPosY = playerPosY;
          playerPosY -= squareSize;
          
          break;
        }
      }
      break;
    case 4:
      if (oldOrientation != 2) {
        Serial.println("update 4");
        switch (oldOrientation){
        case 1:
          EsploraTFT.rect(playerPosX + squareSize * 2, playerPosY - squareSize, squareSize, squareSize);
          lastPosX = playerPosX;
          lastPosY = playerPosY;
          playerPosX += squareSize;
          
          break;
        case 3:
          EsploraTFT.rect(playerPosX + squareSize * 2, playerPosY, squareSize, squareSize);
          lastPosX = playerPosX;
          lastPosY = playerPosY;
          playerPosX += squareSize;
          
          break;
        case 0:
          EsploraTFT.rect(playerPosX + squareSize * 3, playerPosY, squareSize, squareSize);
          lastPosX = playerPosX;
          lastPosY = playerPosY;
          playerPosX += squareSize;
          
          break;
        }
      }
      break;
    default:
        Serial.println("updatePlayer error: orientation not set");
        break;
    }
}

void initPlayer() {
    EsploraTFT.fill(255, 255, 255);
    EsploraTFT.stroke(0, 0, 0);
    EsploraTFT.rect(playerPosX, middleY - squareSize, squareSize, squareSize);
    EsploraTFT.rect(playerPosX + squareSize, middleY - squareSize, squareSize, squareSize);
    EsploraTFT.rect(playerPosX + squareSize * 2, middleY - squareSize, squareSize, squareSize);
}

void innit() {
    EsploraTFT.background(0, 0, 0);
    initPlayer();
}

void border() {
  int borderX = playerPosX;
  int borderY = playerPosY;
  switch(borderX){
    case -41 :
      playerPosX = 183;
      break;
    case 191 :
      playerPosX = -33;
      break;
  }
  switch(borderY){
    case -25 :
      playerPosY = 111;
      break;
    case 127 :
      playerPosY = -9;
      break;
  }
}

void debug() {
    Serial.print("Debug, lastPosX: ");
    Serial.println(lastPosX);
    Serial.print("Debug, lastPosY: ");
    Serial.println(lastPosY);
    Serial.print("Debug, playerPosX: ");
    Serial.println(playerPosX);
    Serial.print("Debug, playerPosY: ");
    Serial.println(playerPosY);
    Serial.print("Debug, oldOrientation: ");
    Serial.println(oldOrientation);
}

void setup() {
    Serial.begin(9600);
    EsploraTFT.begin();
    EsploraTFT.background(0, 0, 0);
    innit();
}

void loop() {
    controlButtons();
    redrawPlayer();
    updatePlayer();
    border();
    debug();
    delay(200);
}
