/*
 * ESP32-RGB64x32MatrixPanel-I2S-DMA-master librarie
 * ESP32-RGB64x32MatrixPanel-I2S-DMA.h
 * #define MATRIX_WIDTH                128  voor 2 panelen
 * https://github.com/peteroden/ESP32Matrix
 * 
 * ESP32 Dev Module 
 */
#include <Preferences.h>
#include <ESP32-RGB64x32MatrixPanel-I2S-DMA.h>

Preferences pref;
RGB64x32MatrixPanel_I2S_DMA ledscherm;

#define R1_PIN  25
#define G1_PIN  26
#define B1_PIN  27
#define R2_PIN  14
#define G2_PIN  12
#define B2_PIN  13
#define A_PIN   23
#define B_PIN   19 
#define C_PIN   5
#define D_PIN   17
#define E_PIN   -1
#define LAT_PIN 4
#define OE_PIN  15
#define CLK_PIN 16

#define SPELER_1_PLUS   18
#define SPELER_2_PLUS   22
#define ATTINY_ENABLE   21

#define SCORE_RESET     34

int set_nu;
  
int games_set_1_speler_1;
int games_set_2_speler_1;
int games_set_3_speler_1;
int games_set_4_speler_1;
int games_set_5_speler_1;

int games_set_1_speler_2;
int games_set_2_speler_2;
int games_set_3_speler_2;
int games_set_4_speler_2;
int games_set_5_speler_2;

int punten_game_speler_1;
int punten_game_speler_2;

int tiebreak_set;

int tiebreak_set_1_speler_1;
int tiebreak_set_2_speler_1;
int tiebreak_set_3_speler_1;
int tiebreak_set_4_speler_1;
int tiebreak_set_5_speler_1;

int tiebreak_set_1_speler_2;
int tiebreak_set_2_speler_2;
int tiebreak_set_3_speler_2;
int tiebreak_set_4_speler_2;
int tiebreak_set_5_speler_2;

bool ad_1;
bool ad_2;
bool tiebreak;
bool tiebreak_set_1;
bool tiebreak_set_2;
bool tiebreak_set_3;
bool tiebreak_set_4;
bool tiebreak_set_5;
bool afgewerkt = false;
bool interrupt_gezet = false;
bool gedaan;
bool data_bewaren = false;

long millis_vorig;

void beginscherm(){
  ledscherm.setTextSize(1);
  ledscherm.setTextColor(ledscherm.color333(0, 0, 255));
  ledscherm.setCursor(82, 0);
  ledscherm.println("thieu");
  ledscherm.setCursor(85, 8);
  ledscherm.println("2020");
}

void IRAM_ATTR scherm(){
  ledscherm.setTextSize(1);
  ledscherm.setTextWrap(false);
  ledscherm.setTextColor(ledscherm.color333(255,0,255));
  ledscherm.clearScreen();
  switch(set_nu){
    case 1:
      ledscherm.setCursor(4, 7);
      ledscherm.println(games_set_1_speler_1);
      ledscherm.setCursor(4, 18);
      ledscherm.println(games_set_1_speler_2);
      break;
    case 2:
      if(tiebreak_set_1 == true){
        ledscherm.setCursor(4, 0);
        ledscherm.println(games_set_1_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_1_speler_1 < 10){
          ledscherm.setCursor(4, 8);
        }
        else{
          ledscherm.setCursor(0, 8);
        }
        ledscherm.println(tiebreak_set_1_speler_1);
        if(tiebreak_set_1_speler_2 < 10){
          ledscherm.setCursor(4, 16);
        }
        else{
          ledscherm.setCursor(0, 16);
        }
        ledscherm.println(tiebreak_set_1_speler_2);
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(4, 24);
        ledscherm.println(games_set_1_speler_2);
      }
      else{
        ledscherm.setCursor(4, 7);
        ledscherm.println(games_set_1_speler_1);
        ledscherm.setCursor(4, 18);
        ledscherm.println(games_set_1_speler_2);
      }
      ledscherm.setCursor(17, 7);
      ledscherm.println(games_set_2_speler_1);
      ledscherm.setCursor(17, 18);
      ledscherm.println(games_set_2_speler_2);
      break;
    case 3:
      if(tiebreak_set_1 == true){
        ledscherm.setCursor(4, 0);
        ledscherm.println(games_set_1_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_1_speler_1 < 10){
          ledscherm.setCursor(4, 8);
        }
        else{
          ledscherm.setCursor(0, 8);
        }
        ledscherm.println(tiebreak_set_1_speler_1);
        if(tiebreak_set_1_speler_2 < 10){
          ledscherm.setCursor(4, 16);
        }
        else{
          ledscherm.setCursor(0, 16);
        }
        ledscherm.println(tiebreak_set_1_speler_2);
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(4, 24);
        ledscherm.println(games_set_1_speler_2);
      }
      else{
        ledscherm.setCursor(4, 7);
        ledscherm.println(games_set_1_speler_1);
        ledscherm.setCursor(4, 18);
        ledscherm.println(games_set_1_speler_2);
      }
      if(tiebreak_set_2 == true){
        ledscherm.setCursor(17, 0);
        ledscherm.println(games_set_2_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_2_speler_1 < 10){
          ledscherm.setCursor(17, 8);
        }
        else{
          ledscherm.setCursor(13, 8);
        }
        ledscherm.println(tiebreak_set_2_speler_1);
        if(tiebreak_set_2_speler_2 < 10){
          ledscherm.setCursor(17, 16);
        }
        else{
          ledscherm.setCursor(13, 16);
        }
        ledscherm.println(tiebreak_set_2_speler_2);
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(17, 24);
        ledscherm.println(games_set_2_speler_2);
      }
      else{
        ledscherm.setCursor(17, 7);
        ledscherm.println(games_set_2_speler_1);
        ledscherm.setCursor(17, 18);
        ledscherm.println(games_set_2_speler_2);
      }
      ledscherm.setCursor(30, 7);
      ledscherm.println(games_set_3_speler_1);
      ledscherm.setCursor(30, 18);
      ledscherm.println(games_set_3_speler_2);
      break;
    case 4:
      if(tiebreak_set_1 == true){
        ledscherm.setCursor(4, 0);
        ledscherm.println(games_set_1_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_1_speler_1 < 10){
          ledscherm.setCursor(4, 8);
        }
        else{
          ledscherm.setCursor(0, 8);
        }
        ledscherm.println(tiebreak_set_1_speler_1);
        if(tiebreak_set_1_speler_2 < 10){
          ledscherm.setCursor(4, 16);
        }
        else{
          ledscherm.setCursor(0, 16);
        }
        ledscherm.println(tiebreak_set_1_speler_2);
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(4, 24);
        ledscherm.println(games_set_1_speler_2);
      }
      else{
        ledscherm.setCursor(4, 7);
        ledscherm.println(games_set_1_speler_1);
        ledscherm.setCursor(4, 18);
        ledscherm.println(games_set_1_speler_2);
      }
      if(tiebreak_set_2 == true){
        ledscherm.setCursor(17, 0);
        ledscherm.println(games_set_2_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_2_speler_1 < 10){
          ledscherm.setCursor(17, 8);
        }
        else{
          ledscherm.setCursor(13, 8);
        }
        ledscherm.println(tiebreak_set_2_speler_1);
        if(tiebreak_set_2_speler_2 < 10){
          ledscherm.setCursor(17, 16);
        }
        else{
          ledscherm.setCursor(13, 16);
        }
        ledscherm.println(tiebreak_set_2_speler_2);;
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(17, 24);
        ledscherm.println(games_set_2_speler_2);
      }
      else{
        ledscherm.setCursor(17, 7);
        ledscherm.println(games_set_2_speler_1);
        ledscherm.setCursor(17, 18);
        ledscherm.println(games_set_2_speler_2);
      }
      if(tiebreak_set_3 == true){
        ledscherm.setCursor(30, 0);
        ledscherm.println(games_set_3_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_3_speler_1 < 10){
          ledscherm.setCursor(30, 8);
        }
        else{
          ledscherm.setCursor(26, 8);
        }
        ledscherm.println(tiebreak_set_3_speler_1);
        if(tiebreak_set_3_speler_2 < 10){
          ledscherm.setCursor(30, 16);
        }
        else{
          ledscherm.setCursor(26, 16);
        }
        ledscherm.println(tiebreak_set_3_speler_2);
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(30, 24);
        ledscherm.println(games_set_3_speler_2);
      }
      else{
        ledscherm.setCursor(30, 7);
        ledscherm.println(games_set_3_speler_1);
        ledscherm.setCursor(30, 18);
        ledscherm.println(games_set_3_speler_2);
      }
      ledscherm.setCursor(43, 7);
      ledscherm.println(games_set_4_speler_1);
      ledscherm.setCursor(43, 18);
      ledscherm.println(games_set_4_speler_2);
      break;
    case 5:
      if(tiebreak_set_1 == true){
        ledscherm.setCursor(4, 0);
        ledscherm.println(games_set_1_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_1_speler_1 < 10){
          ledscherm.setCursor(4, 8);
        }
        else{
          ledscherm.setCursor(0, 8);
        }
        ledscherm.println(tiebreak_set_1_speler_1);
        if(tiebreak_set_1_speler_2 < 10){
          ledscherm.setCursor(4, 16);
        }
        else{
          ledscherm.setCursor(0, 16);
        }
        ledscherm.println(tiebreak_set_1_speler_2);
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(4, 24);
        ledscherm.println(games_set_1_speler_2);
      }
      else{
        ledscherm.setCursor(4, 7);
        ledscherm.println(games_set_1_speler_1);
        ledscherm.setCursor(4, 18);
        ledscherm.println(games_set_1_speler_2);
      }
      if(tiebreak_set_2 == true){
        ledscherm.setCursor(17, 0);
        ledscherm.println(games_set_2_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_2_speler_1 < 10){
          ledscherm.setCursor(17, 8);
        }
        else{
          ledscherm.setCursor(13, 8);
        }
        ledscherm.println(tiebreak_set_2_speler_1);
        if(tiebreak_set_2_speler_2 < 10){
          ledscherm.setCursor(17, 16);
        }
        else{
          ledscherm.setCursor(13, 16);
        }
        ledscherm.println(tiebreak_set_2_speler_2);;
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(17, 24);
        ledscherm.println(games_set_2_speler_2);
      }
      else{
        ledscherm.setCursor(17, 7);
        ledscherm.println(games_set_2_speler_1);
        ledscherm.setCursor(17, 18);
        ledscherm.println(games_set_2_speler_2);
      }
      if(tiebreak_set_3 == true){
        ledscherm.setCursor(30, 0);
        ledscherm.println(games_set_3_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_3_speler_1 < 10){
          ledscherm.setCursor(30, 8);
        }
        else{
          ledscherm.setCursor(26, 8);
        }
        ledscherm.println(tiebreak_set_3_speler_1);
        if(tiebreak_set_3_speler_2 < 10){
          ledscherm.setCursor(30, 16);
        }
        else{
          ledscherm.setCursor(26, 16);
        }
        ledscherm.println(tiebreak_set_3_speler_2);
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(30, 24);
        ledscherm.println(games_set_3_speler_2);
      }
      else{
        ledscherm.setCursor(30, 7);
        ledscherm.println(games_set_3_speler_1);
        ledscherm.setCursor(30, 18);
        ledscherm.println(games_set_3_speler_2);
      }
      if(tiebreak_set_4 == true){
        ledscherm.setCursor(43, 0);
        ledscherm.println(games_set_4_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_4_speler_1 < 10){
          ledscherm.setCursor(43, 8);
        }
        else{
          ledscherm.setCursor(39, 8);
        }
        ledscherm.println(tiebreak_set_4_speler_1);
        if(tiebreak_set_4_speler_2 < 10){
          ledscherm.setCursor(43, 16);
        }
        else{
          ledscherm.setCursor(39, 16);
        }
        ledscherm.println(tiebreak_set_4_speler_2);
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(43, 24);
        ledscherm.println(games_set_4_speler_2);
      }
      else{
        ledscherm.setCursor(43, 7);
        ledscherm.println(games_set_4_speler_1);
        ledscherm.setCursor(43, 18);
        ledscherm.println(games_set_4_speler_2);
      }
      ledscherm.setCursor(56, 7);
      ledscherm.println(games_set_5_speler_1);
      ledscherm.setCursor(56, 18);
      ledscherm.println(games_set_5_speler_2);
      break;
    case 6:
      if(tiebreak_set_1 == true){
        ledscherm.setCursor(4, 0);
        ledscherm.println(games_set_1_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_1_speler_1 < 10){
          ledscherm.setCursor(4, 8);
        }
        else{
          ledscherm.setCursor(0, 8);
        }
        ledscherm.println(tiebreak_set_1_speler_1);
        if(tiebreak_set_1_speler_2 < 10){
          ledscherm.setCursor(4, 16);
        }
        else{
          ledscherm.setCursor(0, 16);
        }
        ledscherm.println(tiebreak_set_1_speler_2);
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(4, 24);
        ledscherm.println(games_set_1_speler_2);
      }
      else{
        ledscherm.setCursor(4, 7);
        ledscherm.println(games_set_1_speler_1);
        ledscherm.setCursor(4, 18);
        ledscherm.println(games_set_1_speler_2);
      }
      if(tiebreak_set_2 == true){
        ledscherm.setCursor(17, 0);
        ledscherm.println(games_set_2_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_2_speler_1 < 10){
          ledscherm.setCursor(17, 8);
        }
        else{
          ledscherm.setCursor(13, 8);
        }
        ledscherm.println(tiebreak_set_2_speler_1);
        if(tiebreak_set_2_speler_2 < 10){
          ledscherm.setCursor(17, 16);
        }
        else{
          ledscherm.setCursor(13, 16);
        }
        ledscherm.println(tiebreak_set_2_speler_2);;
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(17, 24);
        ledscherm.println(games_set_2_speler_2);
      }
      else{
        ledscherm.setCursor(17, 7);
        ledscherm.println(games_set_2_speler_1);
        ledscherm.setCursor(17, 18);
        ledscherm.println(games_set_2_speler_2);
      }
      if(tiebreak_set_3 == true){
        ledscherm.setCursor(30, 0);
        ledscherm.println(games_set_3_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_3_speler_1 < 10){
          ledscherm.setCursor(30, 8);
        }
        else{
          ledscherm.setCursor(26, 8);
        }
        ledscherm.println(tiebreak_set_3_speler_1);
        if(tiebreak_set_3_speler_2 < 10){
          ledscherm.setCursor(30, 16);
        }
        else{
          ledscherm.setCursor(26, 16);
        }
        ledscherm.println(tiebreak_set_3_speler_2);
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(30, 24);
        ledscherm.println(games_set_3_speler_2);
      }
      else{
        ledscherm.setCursor(30, 7);
        ledscherm.println(games_set_3_speler_1);
        ledscherm.setCursor(30, 18);
        ledscherm.println(games_set_3_speler_2);
      }
      if(tiebreak_set_4 == true){
        ledscherm.setCursor(43, 0);
        ledscherm.println(games_set_4_speler_1);
        ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_4_speler_1 < 10){
          ledscherm.setCursor(43, 8);
        }
        else{
          ledscherm.setCursor(39, 8);
        }
        ledscherm.println(tiebreak_set_4_speler_1);
        if(tiebreak_set_4_speler_2 < 10){
          ledscherm.setCursor(43, 16);
        }
        else{
          ledscherm.setCursor(39, 16);
        }
        ledscherm.println(tiebreak_set_4_speler_2);
        ledscherm.setTextColor(ledscherm.color333(255,0,255));
        ledscherm.setCursor(43, 24);
        ledscherm.println(games_set_4_speler_2);
      }
      else{
        ledscherm.setCursor(43, 7);
        ledscherm.println(games_set_4_speler_1);
        ledscherm.setCursor(43, 18);
        ledscherm.println(games_set_4_speler_2);
      }
      ledscherm.setCursor(56, 0);
      ledscherm.println(games_set_5_speler_1);
      ledscherm.setTextColor(ledscherm.color333(0,0,255));
        if(tiebreak_set_5_speler_1 < 10){
          ledscherm.setCursor(56, 8);
        }
        else{
          ledscherm.setCursor(52, 8);
        }
        ledscherm.println(tiebreak_set_5_speler_1);
        if(tiebreak_set_5_speler_2 < 10){
          ledscherm.setCursor(56, 16);
        }
        else{
          ledscherm.setCursor(52, 16);
        }
        ledscherm.println(tiebreak_set_5_speler_2);
      ledscherm.setTextColor(ledscherm.color333(255,0,255));
      ledscherm.setCursor(56, 24);
      ledscherm.println(games_set_5_speler_2);
  }
  if(gedaan == true){
    ledscherm.setTextSize(1);
    ledscherm.setTextColor(ledscherm.color333(255, 0, 0));
    ledscherm.setCursor(76, 0);
    ledscherm.println("May the");
    ledscherm.setCursor(82, 8);
    ledscherm.println("Force");
    ledscherm.setCursor(76, 16);
    ledscherm.println("be with");
    ledscherm.setCursor(87, 24);
    ledscherm.println("you");
  }
  else{
    if(tiebreak == true){
      ledscherm.setTextSize(1);
      ledscherm.setTextColor(ledscherm.color333(255,255,0));
      ledscherm.setCursor(64, 5);
      ledscherm.print("t");
      ledscherm.setCursor(64, 13);
      ledscherm.print("i");
      ledscherm.setCursor(64, 21);
      ledscherm.print("e");
      ledscherm.setCursor(122, 5);
      ledscherm.print("b");
      ledscherm.setCursor(122, 13);
      ledscherm.print("r");
      ledscherm.setCursor(122, 21);
      ledscherm.print("k");
      ledscherm.setTextSize(2);
      ledscherm.setTextColor(ledscherm.color333(0,255,255));
      switch(tiebreak_set){
        case 1:
          if(tiebreak_set_1_speler_1 < 10){
            ledscherm.setCursor(91, 0);
          }
          else{
            ledscherm.setCursor(84, 0);
          }
          ledscherm.print(tiebreak_set_1_speler_1);
          if(tiebreak_set_1_speler_2 < 10){
            ledscherm.setCursor(91, 17);
          }
          else{
            ledscherm.setCursor(84, 17);
          }
          ledscherm.print(tiebreak_set_1_speler_2);
          break;
        case 2:
          if(tiebreak_set_2_speler_1 < 10){
            ledscherm.setCursor(91, 0);
          }
          else{
            ledscherm.setCursor(84, 0);
          }
          ledscherm.print(tiebreak_set_2_speler_1);
          if(tiebreak_set_2_speler_2 < 10){
            ledscherm.setCursor(91, 17);
          }
          else{
            ledscherm.setCursor(84, 17);
          }
          ledscherm.print(tiebreak_set_2_speler_2);
          break;
        case 3:
          if(tiebreak_set_3_speler_1 < 10){
            ledscherm.setCursor(91, 0);
          }
          else{
            ledscherm.setCursor(84, 0);
          }
          ledscherm.print(tiebreak_set_3_speler_1);
          if(tiebreak_set_3_speler_2 < 10){
            ledscherm.setCursor(91, 17);
          }
          else{
            ledscherm.setCursor(84, 17);
          }
          ledscherm.print(tiebreak_set_3_speler_2);
          break;
        case 4:
          if(tiebreak_set_4_speler_1 < 10){
            ledscherm.setCursor(91, 0);
          }
          else{
            ledscherm.setCursor(84, 0);
          }
          ledscherm.print(tiebreak_set_4_speler_1);
          if(tiebreak_set_4_speler_2 < 10){
            ledscherm.setCursor(91, 17);
          }
          else{
            ledscherm.setCursor(84, 17);
          }
          ledscherm.print(tiebreak_set_4_speler_2);
          break;
        case 5:
          if(tiebreak_set_5_speler_1 < 10){
            ledscherm.setCursor(91, 0);
          }
          else{
            ledscherm.setCursor(84, 0);
          }
          ledscherm.print(tiebreak_set_5_speler_1);
          if(tiebreak_set_5_speler_2 < 10){
            ledscherm.setCursor(91, 17);
          }
          else{
            ledscherm.setCursor(84, 17);
          }
          ledscherm.print(tiebreak_set_5_speler_2);
      }
    }
    else{
      ledscherm.setTextColor(ledscherm.color333(255,255,255));
      ledscherm.setTextSize(2);
      if(punten_game_speler_1 == 0){
        ledscherm.setCursor(81, 0);
      }
      else{
        ledscherm.setCursor(69, 0);
      }
      ledscherm.println(punten_game_speler_1);
      if(ad_1 == true){
        ledscherm.setCursor(97, 0);
        ledscherm.setTextColor(ledscherm.color333(255,255,0));
        ledscherm.println("AD");
        ledscherm.setTextColor(ledscherm.color333(255,255,255));
      }
      if(punten_game_speler_2 == 0){
        ledscherm.setCursor(81, 17);
      }
      else{
        ledscherm.setCursor(69, 17);
      }
      ledscherm.println(punten_game_speler_2);
      if(ad_2 == true){
        ledscherm.setCursor(97, 17);
        ledscherm.setTextColor(ledscherm.color333(255,255,0));
        ledscherm.println("AD");
        ledscherm.setTextColor(ledscherm.color333(255,255,255));
      }
    }
  }
}

void IRAM_ATTR plus_1(){
  digitalWrite(ATTINY_ENABLE, LOW);
  
  interrupt_gezet = false;
  afgewerkt = false;
  data_bewaren = true;
  
  millis_vorig = millis();
  
  if(tiebreak == true){
    switch(tiebreak_set){
      case 1:
        tiebreak_set_1_speler_1 ++;
        if((tiebreak_set_1_speler_1 > 6) && ((tiebreak_set_1_speler_1 - tiebreak_set_1_speler_2) > 1)){
          tiebreak = false;
          games_set_1_speler_1 ++;
          set_nu ++;
        }
        break;
      case 2:
        tiebreak_set_2_speler_1 ++;
        if((tiebreak_set_2_speler_1 > 6) && ((tiebreak_set_2_speler_1 - tiebreak_set_2_speler_2) > 1)){
          tiebreak = false;
          games_set_2_speler_1 ++;
          set_nu ++;
        }
        break;
      case 3:
        tiebreak_set_3_speler_1 ++;
        if((tiebreak_set_3_speler_1 > 6) && ((tiebreak_set_3_speler_1 - tiebreak_set_3_speler_2) > 1)){
          tiebreak = false;
          games_set_3_speler_1 ++;
          set_nu ++;
        }
        break;
      case 4:
        tiebreak_set_4_speler_1 ++;
        if((tiebreak_set_4_speler_1 > 6) && ((tiebreak_set_4_speler_1 - tiebreak_set_4_speler_2) > 1)){
          tiebreak = false;
          games_set_4_speler_1 ++;
          set_nu ++;
        }
        break;
      case 5:
        tiebreak_set_5_speler_1 ++;
        if((tiebreak_set_5_speler_1 > 6) && ((tiebreak_set_5_speler_1 - tiebreak_set_5_speler_2) > 1)){
          tiebreak = false;
          games_set_5_speler_1 ++;
          set_nu ++;
          gedaan = true;
        }
    }
  }
  else{
    if((ad_1 == true) || ((punten_game_speler_1 == 40) && (punten_game_speler_2 != 40))){
      ad_1 = false;
      punten_game_speler_1 = 0;
      punten_game_speler_2 = 0;
      switch(set_nu){
        case 1:
          games_set_1_speler_1 ++;
          if((games_set_1_speler_1 > 5) && ((games_set_1_speler_1 - games_set_1_speler_2) > 1)){
            set_nu ++;
          }
          if((games_set_1_speler_1 == 6) && (games_set_1_speler_2 == 6)){
            tiebreak_set_1 = true;
            tiebreak_set = 1;
            tiebreak = true;
          }
          break;
        case 2:
          games_set_2_speler_1 ++;
          if((games_set_2_speler_1 > 5) && ((games_set_2_speler_1 - games_set_2_speler_2) > 1)){
            set_nu ++;
          }
          if((games_set_2_speler_1 == 6) && (games_set_2_speler_2 == 6)){
            tiebreak_set_2 = true;
            tiebreak_set = 2;
            tiebreak = true;
          }
          break;
        case 3:
          games_set_3_speler_1 ++;
          if((games_set_3_speler_1 > 5) && ((games_set_3_speler_1 - games_set_3_speler_2) > 1)){
            set_nu ++;
          }
            if((games_set_3_speler_1 == 6) && (games_set_3_speler_2 == 6)){
            tiebreak_set_3 = true;
            tiebreak_set = 3;
            tiebreak = true;
          }
          break;
        case 4:
          games_set_4_speler_1 ++;
          if((games_set_4_speler_1 > 5) && ((games_set_4_speler_1 - games_set_4_speler_2) > 1)){
            set_nu ++;
          }
          if((games_set_4_speler_1 == 6) && (games_set_4_speler_2 == 6)){
            tiebreak_set_4 = true;
            tiebreak_set = 4;
            tiebreak = true;
          }
          break;
        case 5:
          games_set_5_speler_1 ++;
          if((games_set_5_speler_1 > 5) && ((games_set_5_speler_1 - games_set_5_speler_2) > 1)){
            gedaan = true;
          }
          if((games_set_5_speler_1 == 6) && (games_set_5_speler_2 == 6)){
            tiebreak_set_5 = true;
            tiebreak_set = 5;
            tiebreak = true;
          }
      }
      afgewerkt = true;
    }
    if((ad_2 == true) && (afgewerkt == false)){
      ad_2 = false;
      afgewerkt = true;
    }
    if((punten_game_speler_1 == 40) && (afgewerkt == false)){
        ad_1 = true;
        afgewerkt = true;
    }
    if((punten_game_speler_1 == 30) && (afgewerkt == false)){
      punten_game_speler_1 = 40;
      afgewerkt = true;
    }
    if((punten_game_speler_1 == 15) && (afgewerkt == false)){
      punten_game_speler_1 = 30;
      afgewerkt = true;
    }
  
    if((punten_game_speler_1 == 0) && (afgewerkt == false)){
      punten_game_speler_1 = 15;
      afgewerkt = true;
    }
    if(tiebreak == true){
      punten_game_speler_1 = 0;
      punten_game_speler_2 = 0;
    }
  }
  //scherm();
}

void IRAM_ATTR plus_2(){
  digitalWrite(ATTINY_ENABLE, LOW);
  
  interrupt_gezet = false;
  afgewerkt = false;
  data_bewaren = true;
  
  millis_vorig = millis();
  
  if(tiebreak == true){
    switch(tiebreak_set){
      case 1:
        tiebreak_set_1_speler_2 ++;
        if((tiebreak_set_1_speler_2 > 6) && ((tiebreak_set_1_speler_2 - tiebreak_set_1_speler_1) > 1)){
          tiebreak = false;
          games_set_1_speler_2 ++;
          set_nu ++;
        }
        break;
      case 2:
        tiebreak_set_2_speler_2 ++;
        if((tiebreak_set_2_speler_2 > 6) && ((tiebreak_set_2_speler_2 - tiebreak_set_2_speler_1) > 1)){
          tiebreak = false;
          games_set_2_speler_2 ++;
          set_nu ++;
        }
        break;
      case 3:
        tiebreak_set_3_speler_2 ++;
        if((tiebreak_set_3_speler_2 > 6) && ((tiebreak_set_3_speler_2 - tiebreak_set_3_speler_1) > 1)){
          tiebreak = false;
          games_set_3_speler_2 ++;
          set_nu ++;
        }
        break;
      case 4:
        tiebreak_set_4_speler_2 ++;
        if((tiebreak_set_4_speler_2 > 6) && ((tiebreak_set_4_speler_2 - tiebreak_set_4_speler_1) > 1)){
          tiebreak = false;
          games_set_4_speler_2 ++;
          set_nu ++;
        }
        break;
      case 5:
        tiebreak_set_5_speler_2 ++;
        if((tiebreak_set_5_speler_2 > 6) && ((tiebreak_set_5_speler_2 - tiebreak_set_5_speler_1) > 1)){
          tiebreak = false;
          games_set_5_speler_2 ++;
          ;
          set_nu ++;
          gedaan = true;
        }
    }
  }
  else{
    if((ad_2 == true) || ((punten_game_speler_2 == 40) && (punten_game_speler_1 != 40))){
      ad_2 = false;
      punten_game_speler_1 = 0;
      punten_game_speler_2 = 0;
      switch(set_nu){
        case 1:
          games_set_1_speler_2 ++;
          if((games_set_1_speler_2 > 5) && ((games_set_1_speler_2 - games_set_1_speler_1) > 1)){
            set_nu ++;
          }
          if((games_set_1_speler_2 == 6) && (games_set_1_speler_1 == 6)){
            tiebreak_set_1 = true;
            tiebreak_set = 1;
            tiebreak = true;
          }
          break;
        case 2:
          games_set_2_speler_2 ++;
          if((games_set_2_speler_2 > 5) && ((games_set_2_speler_2 - games_set_2_speler_1) > 1)){
            set_nu ++;
          }
          if((games_set_2_speler_2 == 6) && (games_set_2_speler_1 == 6)){
            tiebreak_set_2 = true;
            tiebreak_set = 2;
            tiebreak = true;
          }
          break;
        case 3:
          games_set_3_speler_2 ++;
          if((games_set_3_speler_2 > 5) && ((games_set_3_speler_2 - games_set_3_speler_1) > 1)){
            set_nu ++;
          }
          if((games_set_3_speler_2 == 6) && (games_set_3_speler_1 == 6)){
            tiebreak_set_3 = true;
            tiebreak_set = 3;
            tiebreak = true;
          }
          break;
        case 4:
          games_set_4_speler_2 ++;
          if((games_set_4_speler_2 > 5) && ((games_set_4_speler_2 - games_set_4_speler_1) > 1)){
            set_nu ++;
          }
          if((games_set_4_speler_2 == 6) && (games_set_4_speler_1 == 6)){
            tiebreak_set_4 = true;
            tiebreak_set = 4;
            tiebreak = true;
          }
          break;
        case 5:
          games_set_5_speler_2 ++;
          if((games_set_5_speler_2 > 5) && ((games_set_5_speler_2 - games_set_5_speler_1) > 1)){
            gedaan = true;
          }
          if((games_set_5_speler_2 == 6) && (games_set_5_speler_1 == 6)){
            tiebreak_set_5 = true;
            tiebreak_set = 5;
            tiebreak = true;
          }
      }
      afgewerkt = true;
    }
    if((ad_1 == true) && (afgewerkt == false)){
      ad_1 = false;
      afgewerkt = true;
    }
    if((punten_game_speler_2 == 40) && (afgewerkt == false)){
      ad_2 = true;
      afgewerkt = true;
    }
    if((punten_game_speler_2 == 30) && (afgewerkt == false)){
      punten_game_speler_2 = 40;
      afgewerkt = true;
    }
    if((punten_game_speler_2 == 15) && (afgewerkt == false)){
      punten_game_speler_2 = 30;
      afgewerkt = true;
    }
    if((punten_game_speler_2 == 0)  && (afgewerkt == false)){
      punten_game_speler_2 = 15;
      afgewerkt = true;
    }
    if(tiebreak == true){
      punten_game_speler_1 = 0;
      punten_game_speler_2 = 0;
      
    }
  }
  //scherm();
}

void setup() {
  ledscherm.begin(R1_PIN, G1_PIN, B1_PIN, R2_PIN, G2_PIN, B2_PIN, A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, LAT_PIN, OE_PIN, CLK_PIN );
  
  pinMode(SPELER_1_PLUS, INPUT);
  pinMode(SPELER_2_PLUS, INPUT);
  pinMode(SCORE_RESET, INPUT);
  pinMode(ATTINY_ENABLE, OUTPUT);
  digitalWrite(ATTINY_ENABLE, LOW);
  Serial.begin(115200);
  
  pref.begin("score", false);
  
  if(digitalRead(SCORE_RESET) == false){
    pref.putInt("s_n", 1);
    pref.putInt("g_s_1_s_1", 0);
    pref.putInt("g_s_2_s_1", 0);
    pref.putInt("g_s_3_s_1", 0);
    pref.putInt("g_s_4_s_1", 0);
    pref.putInt("g_s_5_s_1", 0);
    
    pref.putInt("g_s_1_s_2", 0);
    pref.putInt("g_s_2_s_2", 0);
    pref.putInt("g_s_3_s_2", 0);
    pref.putInt("g_s_4_s_2", 0);
    pref.putInt("g_s_5_s_2", 0);
  
    pref.putInt("p_g_s_1", 0);
    pref.putInt("p_g_s_2", 0);
    
    pref.putInt("t_s", 0);
    
    pref.putInt("t_s_1_s_1", 0);
    pref.putInt("t_s_2_s_1", 0);
    pref.putInt("t_s_3_s_1", 0);
    pref.putInt("t_s_4_s_1", 0);
    pref.putInt("t_s_5_s_1", 0);
    
    pref.putInt("t_s_1_s_2", 0);
    pref.putInt("t_s_2_s_2", 0);
    pref.putInt("t_s_3_s_2", 0);
    pref.putInt("t_s_4_s_2", 0);
    pref.putInt("t_s_5_s_2", 0);
    
    pref.putBool("a_1", false);
    pref.putBool("a_2", false);
  
    pref.putBool("pref.tiebreak", false);
    pref.putBool("t_s_1", false);
    pref.putBool("t_s_2", false);
    pref.putBool("t_s_3", false);
    pref.putBool("t_s_4", false);
    pref.putBool("t_s_5", false);
    pref.putBool("g", false);
  } 
  
  set_nu = pref.getInt("s_n");
        
  games_set_1_speler_1 = pref.getInt("g_s_1_s_1");
  games_set_2_speler_1 = pref.getInt("g_s_2_s_1");
  games_set_3_speler_1 = pref.getInt("g_s_3_s_1");
  games_set_4_speler_1 = pref.getInt("g_s_4_s_1");
  games_set_5_speler_1 = pref.getInt("g_s_5_s_1");

  games_set_1_speler_2 = pref.getInt("g_s_1_s_2");
  games_set_2_speler_2 = pref.getInt("g_s_2_s_2");
  games_set_3_speler_2 = pref.getInt("g_s_3_s_2");
  games_set_4_speler_2 = pref.getInt("g_s_4_s_2");
  games_set_5_speler_2 = pref.getInt("g_s_5_s_2");

  punten_game_speler_1 = pref.getInt("p_g_s_1");
  punten_game_speler_2 = pref.getInt("p_g_s_2");

  tiebreak_set = pref.getInt("t_s");
  
  tiebreak_set_1_speler_1 = pref.getInt("t_s_1_s_1");
  tiebreak_set_2_speler_1 = pref.getInt("t_s_2_s_1");  
  tiebreak_set_3_speler_1 = pref.getInt("t_s_3_s_1");
  tiebreak_set_4_speler_1 = pref.getInt("t_s_4_s_1");
  tiebreak_set_5_speler_1 = pref.getInt("t_s_5_s_1");

  tiebreak_set_1_speler_2 = pref.getInt("t_s_1_s_2");
  tiebreak_set_2_speler_2 = pref.getInt("t_s_2_s_2");  
  tiebreak_set_3_speler_2 = pref.getInt("t_s_3_s_2");
  tiebreak_set_4_speler_2 = pref.getInt("t_s_4_s_2");
  tiebreak_set_5_speler_2 = pref.getInt("t_s_5_s_2");
  
  ad_1 = pref.getBool("a_1");
  ad_2 = pref.getBool("a_2");
  
  tiebreak  = pref.getBool("t");
  tiebreak_set_1 = pref.getBool("t_s_1");
  tiebreak_set_2 = pref.getBool("t_s_2");
  tiebreak_set_3 = pref.getBool("t_s_3"); 
  tiebreak_set_4 = pref.getBool("t_s_4");
  tiebreak_set_5 = pref.getBool("t_s_5");
  gedaan = pref.getBool("g");
  
  beginscherm();
  
  millis_vorig = millis();
  while((millis() - millis_vorig) < 2500){
  }
  
  scherm();

  millis_vorig = millis();

  attachInterrupt(SPELER_1_PLUS, plus_1, FALLING);
  attachInterrupt(SPELER_2_PLUS, plus_2, FALLING);
}

void loop() {
  if(data_bewaren == true){
    data_bewaren = false;
    pref.putInt("t_s_1_s_1", tiebreak_set_1_speler_1);
    pref.putInt("t_s_2_s_1", tiebreak_set_2_speler_1);
    pref.putInt("t_s_3_s_1", tiebreak_set_3_speler_1);
    pref.putInt("t_s_4_s_1", tiebreak_set_4_speler_1);
    pref.putInt("t_s_5_s_1", tiebreak_set_5_speler_1);
    pref.putBool("t_s_1", tiebreak_set_1);
    pref.putBool("t_s_2", tiebreak_set_2);
    pref.putBool("t_s_3", tiebreak_set_3);
    pref.putBool("t_s_4", tiebreak_set_4);
    pref.putBool("t_s_5", tiebreak_set_5);
    pref.putInt("g_s_1_s_1", games_set_1_speler_1);
    pref.putInt("g_s_2_s_1", games_set_2_speler_1);
    pref.putInt("g_s_3_s_1", games_set_3_speler_1);
    pref.putInt("g_s_4_s_1", games_set_4_speler_1);
    pref.putInt("g_s_5_s_1", games_set_5_speler_1);
    pref.putInt("p_g_s_1", punten_game_speler_1);
    pref.putInt("p_g_s_2", punten_game_speler_2);
    pref.putBool("t", tiebreak);
    pref.putInt("s_n", set_nu);
    pref.putBool("g", gedaan);
    pref.putBool("a_1", ad_1);
    pref.putBool("a_2", ad_2);
    pref.putInt("t_s", tiebreak_set);
    pref.putInt("t_s_1_s_2", tiebreak_set_1_speler_2);
    pref.putInt("t_s_2_s_2", tiebreak_set_2_speler_2);
    pref.putInt("t_s_3_s_2", tiebreak_set_3_speler_2);
    pref.putInt("t_s_4_s_2", tiebreak_set_4_speler_2);
    pref.putInt("t_s_5_s_2", tiebreak_set_5_speler_2);
    pref.putInt("g_s_1_s_2", games_set_1_speler_2);
    pref.putInt("g_s_2_s_2", games_set_2_speler_2);
    pref.putInt("g_s_3_s_2", games_set_3_speler_2);
    pref.putInt("g_s_4_s_2", games_set_4_speler_2);
    pref.putInt("g_s_5_s_2", games_set_5_speler_2);
    scherm();
  }
  if(((millis() - millis_vorig) > 2500) && (interrupt_gezet == false)){
    digitalWrite(ATTINY_ENABLE, HIGH);
    interrupt_gezet = true;
  }
}
