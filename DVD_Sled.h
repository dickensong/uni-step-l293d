/*This file is what the .cpp file looks for when it runs*/

#ifndef DVD_Sled_h
#define DVD_Sled_h

#include "Arduino.h"


class Sled
{

	public:
		Sled(int TopEnable, int BotEnable, int TopPos, int TopNeg, int BotPos, int BotNeg);
		void Step(int NumOfSteps);
	private:
		int _TopEnable;
		int _BotEnable;
		int _TopPos;
		int _TopNeg;
		int _BotPos;
		int _BotNeg;
		int _CurStep;

};


#endif
