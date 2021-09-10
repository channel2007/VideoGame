#include "GameControllers.h"

//shared pins between all controllers
const int LATCH_PIN  = 13;
const int CLOCK_PIN  = 14;
const int DATA_PIN_0 = 15;

GameControllers controllers;

void setup()
{
  Serial.begin(115200); //prepare serial for text output 
  
  //initialize shared pins
  controllers.init(LATCH_PIN, CLOCK_PIN); 
  //activate first controller ans set the type to SNES
  controllers.setController(0, GameControllers::SNES, DATA_PIN_0);

  Serial.println("GameControllers::SNES.");
}

void loop()
{
  controllers.poll(); //read all controllers at once
  if(controllers.pressed(0, GameControllers::START))  //check if Start was pressed since last loop
    Serial.println("Start was pressed.");
  if(controllers.pressed(0, GameControllers::SELECT))
    Serial.println("Select was pressed.");    

  if(controllers.down(0, GameControllers::UP))
    Serial.println("UP");
  if(controllers.down(0, GameControllers::DOWN))
    Serial.println("DOWN");
  if(controllers.down(0, GameControllers::LEFT))
    Serial.println("LEFT");
  if(controllers.down(0, GameControllers::RIGHT))
    Serial.println("RIGHT");
    
  if(controllers.pressed(0, GameControllers::A))  //check if A button it's currently pressed down
    Serial.println("A");
  if(controllers.pressed(0, GameControllers::B))  //check if B button it's currently pressed down
    Serial.println("B");
  if(controllers.pressed(0, GameControllers::X))  //check if X button it's currently pressed down
    Serial.println("X");
  if(controllers.pressed(0, GameControllers::Y))  //check if Y button it's currently pressed down
    Serial.println("Y");
  if(controllers.pressed(0, GameControllers::L))  //check if L button it's currently pressed down
    Serial.println("L");
  if(controllers.pressed(0, GameControllers::R))  //check if R button it's currently pressed down
    Serial.println("R");
    
  delay(50);  //read controller just ~20times a second
}
