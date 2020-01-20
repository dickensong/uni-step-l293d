/*This is where you write the code you want to run*/
#include "Arduino.h"
#include "DVD_Sled.h"


Sled::Sled(int TopEnable, int BotEnable, int TopPos, int TopNeg, int BotPos, int BotNeg)
{
pinMode (TopEnable,OUTPUT);
pinMode (BotEnable,OUTPUT);
pinMode (TopPos,OUTPUT);
pinMode (TopNeg,OUTPUT);
pinMode (BotPos,OUTPUT);
pinMode (BotNeg,OUTPUT);

_TopEnable = TopEnable;
_BotEnable = BotEnable;
_TopPos = TopPos;
_TopNeg = TopNeg;
_BotPos = BotPos;
_BotNeg = BotNeg;

_CurStep = 0;

}


void Sled::Step(int NumOfSteps) 
{

_CurStep = _CurStep + NumOfSteps;

//                        Roll over if at top step -
if (_CurStep > 15) {
  _CurStep = 0;
  };
//                         Roll under if at bottom step  
if (_CurStep < 0) {
  _CurStep = 15;
};


//                        Set stepper driver pins based on which step we're on
 
switch (_CurStep) {
  case 0: // 
    digitalWrite(_TopEnable, HIGH);
    digitalWrite(_TopPos, HIGH);
    digitalWrite(_TopNeg, LOW);
    digitalWrite(_BotEnable, LOW);
    digitalWrite(_BotPos, LOW);
    digitalWrite(_BotNeg, LOW);
  break;
    case 1: // 
    digitalWrite(_TopEnable, HIGH);
    digitalWrite(_TopPos, HIGH);
    digitalWrite(_TopNeg, LOW);
    digitalWrite(_BotEnable, 128);
    digitalWrite(_BotPos, HIGH);
    digitalWrite(_BotNeg, LOW);
  break;
  case 2: // 
    digitalWrite(_TopEnable, HIGH);
    digitalWrite(_TopPos, HIGH);
    digitalWrite(_TopNeg, LOW);
    digitalWrite(_BotEnable, HIGH);
    digitalWrite(_BotPos, HIGH);
    digitalWrite(_BotNeg, LOW);
  break;
    case 3: // 
    digitalWrite(_TopEnable, 128);
    digitalWrite(_TopPos, HIGH);
    digitalWrite(_TopNeg, LOW);
    digitalWrite(_BotEnable, HIGH);
    digitalWrite(_BotPos, HIGH);
    digitalWrite(_BotNeg, LOW);
  break;
  case 4: // 
    digitalWrite(_TopEnable, LOW);
    digitalWrite(_TopPos, LOW);
    digitalWrite(_TopNeg, LOW);
    digitalWrite(_BotEnable, HIGH);
    digitalWrite(_BotPos, HIGH);
    digitalWrite(_BotNeg, LOW);
  break;
    case 5: // 
    digitalWrite(_TopEnable, 128);
    digitalWrite(_TopPos, LOW);
    digitalWrite(_TopNeg, HIGH);
    digitalWrite(_BotEnable, HIGH);
    digitalWrite(_BotPos, HIGH);
    digitalWrite(_BotNeg, LOW);
  break;
  case 6: // 
    digitalWrite(_TopEnable, HIGH);
    digitalWrite(_TopPos, LOW);
    digitalWrite(_TopNeg, HIGH);
    digitalWrite(_BotEnable, HIGH);
    digitalWrite(_BotPos, HIGH);
    digitalWrite(_BotNeg, LOW);
  break;
    case 7: // 
    digitalWrite(_TopEnable, HIGH);
    digitalWrite(_TopPos, HIGH);
    digitalWrite(_TopNeg, LOW);
    digitalWrite(_BotEnable, 128);
    digitalWrite(_BotPos, HIGH);
    digitalWrite(_BotNeg, LOW);
  break;
  case 8: // Coil 1 - Coil 2 0
    digitalWrite(_TopEnable, HIGH);
    digitalWrite(_TopPos, LOW);
    digitalWrite(_TopNeg, HIGH);
    digitalWrite(_BotEnable, LOW);
    digitalWrite(_BotPos, LOW);
    digitalWrite(_BotNeg, LOW);
  break;
    case 9: // 
    digitalWrite(_TopEnable, HIGH);
    digitalWrite(_TopPos, LOW);
    digitalWrite(_TopNeg, HIGH);
    digitalWrite(_BotEnable, 128);
    digitalWrite(_BotPos, LOW);
    digitalWrite(_BotNeg, HIGH);
  break;
  case 10: // Coil 1 - Coil 2 -
    digitalWrite(_TopEnable, HIGH);
    digitalWrite(_TopPos, LOW);
    digitalWrite(_TopNeg, HIGH);
    digitalWrite(_BotEnable, HIGH);
    digitalWrite(_BotPos, LOW);
    digitalWrite(_BotNeg, HIGH);
  break;
    case 11: // 
    digitalWrite(_TopEnable, 128);
    digitalWrite(_TopPos, LOW);
    digitalWrite(_TopNeg, HIGH);
    digitalWrite(_BotEnable, LOW);
    digitalWrite(_BotPos, LOW);
    digitalWrite(_BotNeg, LOW);
  break;
  case 12: // Coil 1 0 Coil 2 -
    digitalWrite(_TopEnable, LOW);
    digitalWrite(_TopPos, LOW);
    digitalWrite(_TopNeg, LOW);
    digitalWrite(_BotEnable, HIGH);
    digitalWrite(_BotPos, LOW);
    digitalWrite(_BotNeg, HIGH);
  break;
    case 13: // 
    digitalWrite(_TopEnable, 128);
    digitalWrite(_TopPos, HIGH);
    digitalWrite(_TopNeg, LOW);
    digitalWrite(_BotEnable, LOW);
    digitalWrite(_BotPos, LOW);
    digitalWrite(_BotNeg, LOW);
  break;
  case 14: // Coil 1 0 Coil 2 -
    digitalWrite(_TopEnable, HIGH);
    digitalWrite(_TopPos, HIGH);
    digitalWrite(_TopNeg, LOW);
    digitalWrite(_BotEnable, HIGH);
    digitalWrite(_BotPos, LOW);
    digitalWrite(_BotNeg, HIGH);
  break;
    case 15: // 
    digitalWrite(_TopEnable, HIGH);
    digitalWrite(_TopPos, HIGH);
    digitalWrite(_TopNeg, LOW);
    digitalWrite(_BotEnable, 128);
    digitalWrite(_BotPos, LOW);
    digitalWrite(_BotNeg, HIGH);
  break;
};
  
}
