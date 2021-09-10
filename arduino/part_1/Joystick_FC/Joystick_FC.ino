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
  controllers.setController(0, GameControllers::NES, DATA_PIN_0);

  Serial.println("GameControllers::NES.");
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
    
  //if(controllers.pressed(0, GameControllers::A, 20))  //if A button is hold down repeat after 20 loops
  if(controllers.pressed(0, GameControllers::A))
    Serial.println("A");
  //if(controllers.down(0, GameControllers::B))  //check if B button it's currently pressed down
  if(controllers.pressed(0, GameControllers::B))
    Serial.println("B");
  delay(50);  //read controller just ~20times a second
}
