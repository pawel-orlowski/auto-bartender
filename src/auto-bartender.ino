#include <Arduino.h>
#include <PCF8574.h>
#include <Keypad.h>
#include <Key.h>
#include <Wire.h>
#include <LiquidCrystal.h>

const byte ROWS = 4;  // Number of lines in the keyboard
const byte COLS = 4;  // Number of columns in the keyboard
const int ONEML_DELAY = 250; // Dose duration (milliseconds)
const char CONFIRM_KEY = '#';
const char START_KEY = '*';

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'}, 
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}  
};

byte rowPins[ROWS] = {6, 7, 8, 9}; // Keyboard row pins connected to 6, 7, 8, 9 pins in Arduino
byte colPins[COLS] = {13, 12, 11, 10}; // Keyboard column pins connected to 13, 12, 11, 10 pins in Arduino

int vodkaPumpState = HIGH;  // Saving pump states in service mode
int blueCuracaoPumpState = HIGH;
int orangeJuicePumpState = HIGH;
int pomegranateJuicePumpState = HIGH;
int lemonJuicePumpState = HIGH;
int whiteRumPumpState = HIGH;
int grapefruitJuicePumpState = HIGH;
int spritePumpState = HIGH;

// Initialization of the keyboard
Keypad klawiatura = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


//Pumps pins
const int vodkaPump = 30;
const int blueCuracaoPump = 31;
const int orangeJuicePump = 32;
const int pomegranateJuicePump = 33;
const int lemonJuicePump = 22;
const int whiteRumPump = 23;
const int grapefruitJuicePump = 24;
const int spritePump = 25;

LiquidCrystal lcd(42, 44, 52, 50, 48, 46);

boolean serviceMode = false; // Service mode flag

void setup() {
    
  lcd.begin (20, 4);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("    Drinomat6000");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *"); // eng:"To choose click *"

 Serial.begin(9600);
  
// Statement of output pins

  digitalWrite(30, HIGH);
  digitalWrite(31, HIGH);
  digitalWrite(32, HIGH);
  digitalWrite(33, HIGH);
  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(24, HIGH);
  digitalWrite(25, HIGH);
  
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);

}

void loop() {

  char customKey = klawiatura.getKey();

// Operation of default and service modes
    if (customKey == 'A')
    {
      serviceMode = !serviceMode;  //Change modes when the 'A' button is pressed
      if (serviceMode) //Change to service mode
      {

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("   Tryb serwisowy   ");
      lcd.setCursor(0, 2);
      lcd.print(" Przycisk od 1 do 8 ");
      lcd.setCursor(0, 3);
      lcd.print("uruchomi dana pompke"); 

      }
      else  //Return to default mode
      {
      lcd.clear ();
      lcd.setCursor(0, 0);
      lcd.print("    Drinomat6000");
      lcd.setCursor(0, 2);
      lcd.print("Aby wybrac kliknij *");
      }
    }

 // Service mode operations
    if (serviceMode) {
    
      // Activation of pump 1 in service mode
      if (customKey == '1') 
      {
        if (vodkaPumpState == HIGH)
        {
        digitalWrite(30, LOW); // Set pin 30 low
        vodkaPumpState = LOW; // Saving the current state of pump 1
        } 
        else
        {
        digitalWrite(30, HIGH); // Set pin 30 high
        vodkaPumpState = HIGH; // Saving the current state of pump 1
        }
       }
            // Activation of pump 2 in service mode
      if (customKey == '2') 
      {
        if (blueCuracaoPumpState == HIGH)
        {
        digitalWrite(31, LOW);
        blueCuracaoPumpState = LOW;
        } 
        else
        {
        digitalWrite(31, HIGH);
        blueCuracaoPumpState = HIGH;
        }
       }
           // Activation of pump 3 in service mode
      if (customKey == '3') 
      {
        if (orangeJuicePumpState == HIGH)
        {
        digitalWrite(32, LOW);
        orangeJuicePumpState = LOW;
        } 
        else
        {
        digitalWrite(32, HIGH);
        orangeJuicePumpState = HIGH;
        }
       }
             // Activation of pump 4 in service mode
      if (customKey == '4') 
      {
        if (pomegranateJuicePumpState == HIGH)
        {
        digitalWrite(33, LOW);
        pomegranateJuicePumpState = LOW;
        } 
        else
        {
        digitalWrite(33, HIGH);
        pomegranateJuicePumpState = HIGH;
        }
       }
             // Activation of pump 5 in service mode
      if (customKey == '5') 
      {
        if (lemonJuicePumpState == HIGH)
        {
        digitalWrite(22, LOW);
        lemonJuicePumpState = LOW;
        } 
        else
        {
        digitalWrite(22, HIGH);
        lemonJuicePumpState = HIGH;
        }
       }
             // Activation of pump 6 in service mode
      if (customKey == '6') 
      {
        if (whiteRumPumpState == HIGH)
        {
        digitalWrite(23, LOW);
        whiteRumPumpState = LOW;
        } 
        else
        {
        digitalWrite(23, HIGH);
        whiteRumPumpState = HIGH;
        }
       }
             // Activation of pump 7 in service mode
      if (customKey == '7') 
      {
        if (grapefruitJuicePumpState == HIGH)
        {
        digitalWrite(24, LOW);
        grapefruitJuicePumpState = LOW;
        } 
        else
        {
        digitalWrite(24, HIGH);
        grapefruitJuicePumpState = HIGH;
        }
       }
             // Activation of pump 8 in service mode
      if (customKey == '8') 
      {
        if (spritePumpState == HIGH)
        {
        digitalWrite(25, LOW);
        spritePumpState = LOW;
        } 
        else
        {
        digitalWrite(25, HIGH);
        spritePumpState = HIGH;
        }
       }     
     }
    else {
      // Default mode opertions
      if (customKey && customKey == START_KEY){
        lcd.clear ();
        Serial.println(customKey);
        String selectedDrink = String("");
        char programKey = klawiatura.getKey();
        if (programKey)
        {
          selectedDrink += programKey;
        }
        while (programKey != CONFIRM_KEY)
        {
          programKey =  klawiatura.getKey();

          lcd.setCursor(0, 0);
          lcd.print("   Wybierz drink:   ");    // eng: "Choose a drink:"
          lcd.setCursor(0, 1);
          lcd.print("        " + selectedDrink + "          ");
          lcd.setCursor(0, 2);
          lcd.print("     1, 21, 22,     ");
          lcd.setCursor(0, 3);
          lcd.print("     31, 62, 75     ");
          
          if (programKey)
          {
            Serial.println(programKey);
            if (programKey != CONFIRM_KEY) 
            {
              selectedDrink += programKey;
            }
          }
        }
        
        Serial.println("Wybrany kod");    // eng: "Chosen code"
        Serial.println(selectedDrink);

        pourDrink(selectedDrink);
        
        }
      }
}

void stopPump(int portNumber)
{
  digitalWrite(portNumber, HIGH);
}

void startPump(int portNumber)
{
  digitalWrite(portNumber, LOW);
}

void stopAllPumps()
{
  stopPump(vodkaPump);
  stopPump(blueCuracaoPump);
  stopPump(orangeJuicePump);
  stopPump(pomegranateJuicePump);
  stopPump(lemonJuicePump);
  stopPump(whiteRumPump);
  stopPump(grapefruitJuicePump);
  stopPump(spritePump);
}

void pourDrink(String selectedDrink)
{
  if (selectedDrink.equals("1"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("      Kamikaze");
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");   // eng: "Please wait:"
    pourKamikaze();
  }
  else if (selectedDrink.equals("21"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("  Samba de Janeiro");
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");
    pourSambaDeJaneiro();
  }
  else if (selectedDrink.equals("31"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("   Casino Royal'e");
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");
    pourCasinoRoyale();
  }
  else if (selectedDrink.equals("22"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("      Bailamos");
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");
    pourBailamos();
  }
  else if (selectedDrink.equals("75"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("  Born In The USA!");
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");
    pourBornInTheUSA();
  }
  else if (selectedDrink.equals("62"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("   Private Dancer");
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");
    pourPrivateDancer();
  }
  else if (selectedDrink.equals("111"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("  Pompka 1 - 40 ml  ");    // eng: "Pump 1 - 40 ml"
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");
    pourPompka1();
  }
  else if (selectedDrink.equals("222"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("  Pompka 2 - 40 ml  ");
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");
    pourPompka2();
  }
  else if (selectedDrink.equals("333"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("  Pompka 3 - 40 ml  ");
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");
    pourPompka3();
  }
  else if (selectedDrink.equals("444"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("  Pompka 4 - 40 ml  ");
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");
    pourPompka4();
  }
  else if (selectedDrink.equals("555"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("  Pompka 5 - 40 ml  ");
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");
    pourPompka5();
  }
  else if (selectedDrink.equals("666"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("  Pompka 6 - 40 ml  ");
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");
    pourPompka6();
  }
  else if (selectedDrink.equals("777"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("  Pompka 7 - 40 ml  ");
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");
    pourPompka7();
  }
  else if (selectedDrink.equals("888"))
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("  Pompka 8 - 40 ml  ");
    lcd.setCursor(0, 2);
    lcd.print("   Prosze czekac:");
    pourPompka8();
  }

  else
  {
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("Wybierz jeszcze raz!");    // eng: "Choose again!"
    delay (1000);
    lcd.setCursor(0, 2);
    lcd.print("  Niepoprawny Kod!");    // eng: "Invalid Code!"
    delay (1000);
    lcd.setCursor(0, 2);
    lcd.print("                     ");
    delay (1000);
    lcd.setCursor(0, 2);
    lcd.print("  Niepoprawny Kod!");
    delay (1000);
    lcd.setCursor(0, 2);
    lcd.print("                      ");
    delay (1000);
    lcd.setCursor(0, 2);
    lcd.print("  Niepoprawny Kod!");
    delay (1000);
    lcd.setCursor(0, 2);
    lcd.print("                      ");
    delay (1000);
    lcd.setCursor(0, 2);
    lcd.print("  Niepoprawny Kod!");
    delay (1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Drinomat6000!");
    lcd.setCursor(0, 2);
    lcd.print("Aby wybrac kliknij *");

  }
}

void pourKamikaze()
{
  //40 ml vodka
  //40 ml curacao
  //40 ml lemon juice

  startPump(vodkaPump);
  startPump(blueCuracaoPump);
  startPump(lemonJuicePump);
  delay(40 * ONEML_DELAY);
  stopPump(vodkaPump);
  stopPump(blueCuracaoPump);
  stopPump(lemonJuicePump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");    // eng: "End of pouring"
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");    // eng: "Thank You !"
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");

}

void pourSambaDeJaneiro()
{
  //50 ml vodka
  //50 ml curacao
  //150 ml grapefruit juice
  Serial.println("Samba de Janeiro");

  startPump(vodkaPump);
  startPump(blueCuracaoPump);
  startPump(grapefruitJuicePump);
  delay(50 * ONEML_DELAY);
  stopPump(vodkaPump);
  stopPump(blueCuracaoPump);
  delay(100 * ONEML_DELAY);
  stopPump(grapefruitJuicePump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");

}

void pourCasinoRoyale()
{
  //50 ml vodka
  //30 ml curacao
  //100 ml orange juice

  startPump(vodkaPump);
  startPump(blueCuracaoPump);
  startPump(orangeJuicePump);
  delay(30 * ONEML_DELAY);
  stopPump(blueCuracaoPump);
  delay(20 * ONEML_DELAY);
  stopPump(vodkaPump);
  delay(50 * ONEML_DELAY);
  stopPump(orangeJuicePump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");
}

void pourBailamos()
{
  //50 ml vodka
  //100 ml pomegranate juice
  //100 ml orange juice

  startPump(vodkaPump);
  startPump(pomegranateJuicePump);
  startPump(orangeJuicePump);
  delay(50 * ONEML_DELAY);
  stopPump(vodkaPump);
  delay(50 * ONEML_DELAY);
  stopPump(orangeJuicePump);
  stopPump(pomegranateJuicePump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");
}

void pourBornInTheUSA()
{
  //50 ml white rum
  //50 ml curacao
  //70 ml  grapefruit juice

  startPump(whiteRumPump);
  startPump(grapefruitJuicePump);
  startPump(blueCuracaoPump);
  delay(50 * ONEML_DELAY);
  stopPump(whiteRumPump);
  stopPump(blueCuracaoPump);
  delay(20 * ONEML_DELAY);
  stopPump(grapefruitJuicePump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");
}

void pourPrivateDancer()
{
  //50 ml vodka
  //30 ml curacao
  //70 ml  lemon juice
  //70ml sprite

  startPump(spritePump);
  startPump(lemonJuicePump);
  startPump(vodkaPump);
  startPump(blueCuracaoPump);
  delay(30 * ONEML_DELAY);

  stopPump(blueCuracaoPump);
  delay(20 * ONEML_DELAY);

  stopPump(vodkaPump);
  delay(20 * ONEML_DELAY);
  stopPump(spritePump);
  stopPump(lemonJuicePump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");
}



//Testing the accuracy of a single pump

void pourPompka1()
{
  //40 ml vodka

  startPump(vodkaPump);
  delay(40 * ONEML_DELAY);
  stopPump(vodkaPump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");
}
void pourPompka2()
{
  //40 ml blueCuracao

  startPump(blueCuracaoPump);
  delay(40 * ONEML_DELAY);
  stopPump(blueCuracaoPump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");
}
void pourPompka3()
{
  //40 ml orangeJuice

  startPump(orangeJuicePump);
  delay(40 * ONEML_DELAY);
  stopPump(orangeJuicePump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");
}
void pourPompka4()
{
  //40 ml pomegranateJuice

  startPump(pomegranateJuicePump);
  delay(40 * ONEML_DELAY);
  stopPump(pomegranateJuicePump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");
}
void pourPompka5()
{
  //40 ml lemonJuice

  startPump(lemonJuicePump);
  delay(40 * ONEML_DELAY);
  stopPump(lemonJuicePump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");
}
void pourPompka6()
{
  //40 ml whiteRum

  startPump(whiteRumPump);
  delay(40 * ONEML_DELAY);
  stopPump(whiteRumPump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");
}
void pourPompka7()
{
  //40 ml grapefruitJuice

  startPump(grapefruitJuicePump);
  delay(40 * ONEML_DELAY);
  stopPump(grapefruitJuicePump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");
}
void pourPompka8()
{
  //40 ml sprite

  startPump(spritePump);
  delay(40 * ONEML_DELAY);
  stopPump(spritePump);
  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print("  Koniec nalewania");
  lcd.setCursor(0, 2);
  lcd.print("    Dziekujemy !");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Drinomat6000!");
  lcd.setCursor(0, 2);
  lcd.print("Aby wybrac kliknij *");
}
