// includes start
#include <Arduino.h>
#include <BittyBuggy.h>

/*


    this code will not work on arduino ide because the global var &Serial1 is not defined in arduino ide, only in mdesigner, but is just transfer the code to mdesigner in mode offline and add the code.




*/


BittyBuggy Buggy(&Serial1);

void trackStop();
void BuggyToneTime(int _fre, float _time);
uint8_t playSound(uint8_t songNum);
void playingRest();
boolean playingStop();
boolean colorfind(uint8_t _AB, uint8_t _color);
void BuggyCarTime(int8_t _dir, uint8_t _speed, float _time);
void BuggyTurn(uint8_t _dir, uint8_t _speed, float _time);


#define SONG_SUM  11
uint16_t toneList[] = { 262, 294, 330, 349, 392, 440, 494, 523, 587, 659, 698, 784, 880, 988, 1046, 1175, 1318, 1397, 1568, 1760, 1967 };
uint8_t music_1[] = { 12, 10, 12, 10, 12, 10, 9, 10, 12, 12, 12, 10, 13, 12, 10, 12, 10, 9, 8, 9, 10, 12, 10, 9, 8, 9, 10, 0 };
uint8_t rhythm_1[] = { 4, 2, 4, 2, 2, 2, 2, 2, 8, 2, 4, 2, 4, 4, 2, 2, 2, 2, 4, 4, 4, 4, 2, 2, 2, 2, 8 };
uint8_t music_2[] = { 8, 9, 10, 8, 8, 9, 10, 8, 10, 11, 12, 10, 11, 12, 0 };
uint8_t rhythm_2[] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 4, 4, 8 };
uint8_t music_3[] = { 5, 8, 8, 10, 13, 10, 12, 12, 13, 12, 10, 11, 10, 9, 6, 9, 9, 11, 14, 14, 13, 12, 11, 11, 10, 6, 7, 8, 9 , 0 };
uint8_t rhythm_3[] = { 2, 1, 2, 1, 2, 1, 4, 2, 1, 2, 1, 2, 1, 4, 2, 1, 2, 1, 2, 1, 2, 1, 4, 2, 1, 2, 4, 2, 8 };
uint8_t music_4[] = { 5, 5, 6, 5, 8, 7, 5, 5, 6, 5, 9, 8, 5, 5, 12, 10, 8, 7, 6, 11, 11, 10, 8, 9, 8, 0 };
uint8_t rhythm_4[] = { 2, 2, 4, 4, 4, 8, 2, 2, 4, 4, 4, 8, 2, 2, 4, 4, 4, 4, 4, 2, 2, 4, 4, 4, 8 };
uint8_t music_5[] = { 12, 13, 12, 13, 12, 13, 12, 12, 15, 14, 13, 12, 13, 12, 12, 12, 10, 10, 12, 12, 10, 9, 11, 10, 9, 8, 9, 8, 0 };
uint8_t rhythm_5[] = { 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 4 };
uint8_t music_6[] = { 8, 8, 10, 8, 8, 10, 22, 13, 13, 13, 12, 13, 12, 8, 10, 22, 15, 13, 13, 12, 13, 12, 8, 9, 22, 14, 14, 12, 10, 12, 0 };
uint8_t rhythm_6[] = { 4, 4, 8, 2, 4, 4, 4, 4, 4, 2, 2, 4, 2, 4, 4, 4, 2, 2, 2, 2, 8, 2, 4, 4, 4, 4, 2, 2, 4, 16 };
uint8_t music_7[] = { 6, 8, 9, 10, 12, 10, 8, 9, 6, 22, 8, 9, 10, 12, 12, 13, 9, 10, 22, 10, 12, 13, 12, 13, 15, 14, 13, 12, 13, 10, 8, 9, 10, 12, 8, 6, 8, 9, 10, 13, 12 , 0 };
uint8_t rhythm_7[] = { 2, 2, 2, 4, 2, 2, 2, 4, 8, 2, 2, 2, 2, 4, 2, 4, 4, 8, 4, 2, 2, 8, 4, 2, 2, 1, 1, 2, 2, 4, 2, 2, 4, 2, 4, 4, 2, 2, 2, 2, 18 };
uint8_t music_8[] = { 10, 8, 9, 6, 10, 9, 8, 9, 6, 10, 8, 9, 9, 12, 10, 7, 8, 8, 7, 6, 7, 8, 9, 5, 13, 12, 10, 10, 9, 8, 9, 10, 9, 10, 9, 12, 12, 12, 12, 12, 12, 0 };
uint8_t rhythm_8[] = { 4, 4, 4, 4, 2, 2, 2, 2, 8, 4, 4, 4, 4, 2, 2, 4, 4, 2, 2, 4, 2, 2, 4, 4, 2, 2, 4, 4, 2, 4, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 4 };
uint8_t music_9[] = { 10, 12, 15, 13, 12, 10, 12, 13, 15, 12, 15, 17, 16, 15, 16, 15, 13, 15, 12 , 0 };
uint8_t rhythm_9[] = { 2, 2, 2, 2, 8, 2, 2, 2, 2, 8, 4, 2, 4, 4, 2, 2, 2, 2, 8 };
uint8_t music_10[] = { 10, 10, 10, 8, 5, 5, 22, 10, 10, 10, 8, 10, 22, 12, 12, 10, 8, 5, 5, 5, 6, 7, 8, 10, 9, 0 };
uint8_t rhythm_10[] = { 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 4 };
uint8_t music_11[] = {8, 9, 10, 8, 8, 9, 10, 8, 10, 11, 12, 10, 11, 12, 0};
uint8_t rhythm_11[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 4};
const uint8_t * Pmusic[SONG_SUM] = { music_1, music_2, music_3, music_4, music_5, music_6, music_7, music_8, music_9, music_10, music_11 };
const uint8_t * Prhythm[SONG_SUM] = { rhythm_1, rhythm_2, rhythm_3, rhythm_4, rhythm_5, rhythm_6, rhythm_7, rhythm_8, rhythm_9, rhythm_10, rhythm_11 };
uint32_t playTimer = 0;
int8_t songNumC = -1;
uint8_t songIndex;
uint8_t playIndex = 0;
int last_seen = 0;
void trackStop() {
	Buggy.setAllLED(0X000000);
	Buggy.setSpeed(0, 0);
}
void BuggyToneTime(int _fre, float _time) {
	if (_time > 0) {
		Buggy.tone(_fre);
		delay(_time * 1000);
		Buggy.noTone();
	} else {
		Buggy.noTone();
	}
	return false;
}
uint8_t playSound(uint8_t songNum) {
	songIndex = songNum;
	if (songNum > SONG_SUM - 1) {
		Buggy.noTone();
		return;
	}
	if (playIndex == 100 || songNumC != songNum) {
		playIndex = 0;
		songNumC = songNum;
	}
	if (millis() > playTimer && (*(Pmusic[songNum] + playIndex / 2))) {
		if (playIndex % 2 == 0) {
			if (*(Pmusic[songNum] + playIndex / 2) != 22) {
				Buggy.tone(toneList[*(Pmusic[songNum] + playIndex / 2) - 1]);
			} else {
				Buggy.noTone();
			}
			playTimer = millis() + *(Prhythm[songNum] + playIndex / 2) * 75;
		} else {
			Buggy.noTone();
			playTimer = millis() + 40;
		}
		playIndex++;
	}
}
void playingRest() {
	playIndex = 0;
}
boolean playingStop() {
	if (*(Pmusic[songIndex] + playIndex / 2)) {
		return false;
	} else {
		return true;
	}
}
boolean colorfind(uint8_t _AB, uint8_t _color) {
	if (_AB) {
		if (Buggy.getColorB() == _color) return true;
	} else {
		if (Buggy.getColorA() == _color) return true;
	}
	return false;
}
void BuggyCarTime(int8_t _dir, uint8_t _speed, float _time) {
	if (_time > 0) {
		Buggy.setSpeed(_dir * _speed, _dir * _speed);
		delay(_time * 1000);
		Buggy.setSpeed(0, 0);
	} else {
		Buggy.setSpeed(0, 0);
	}
}
void BuggyTurn(uint8_t _dir, uint8_t _speed, float _time) {
	if (_dir) {
		Buggy.setSpeed(_speed, 0);
	} else {
		Buggy.setSpeed(0, _speed);
	}
	if (_time > 0) {
		delay(_time * 1000);
		Buggy.setSpeed(0, 0);
	} else {
		Buggy.setSpeed(0, 0);
	}
}

void setup() {
	// setup define start
	while(!Buggy.begin());
	// setup define end
}

void loop() {
	while(1) {
		if(((analogRead(A0)) < 1000)) {
			Serial.println(analogRead(A0));
			trackStop();
			BuggyToneTime(1976, 2);
			delay(3 * 1000);
			if(((analogRead(A0)) < 1000)) {
				BuggyToneTime(1976, 1);
				delay(2 * 1000);
				if(((analogRead(A0)) < 1000)) {
					Buggy.setColorLEDB(0xffe900);
					Buggy.setColorLEDA(0xffe900);
					while (!playingStop()) {
						playSound(1-1);
					}
					playingRest();
					Buggy.setColorLEDA(0x34ff00);
					Buggy.setColorLEDB(0x34ff00);
					delay(120 * 1000);
				} else {

				}
			} else {

			}
		} else {
			if(((colorfind(0, 8)) && (colorfind(1, 8)))) {
				BuggyCarTime(1, 20, 0.5);
				last_seen = 0;
			} else {
				if(((colorfind(0, 8)) && (!(colorfind(1, 8))))) {
					BuggyTurn(0, 15, 0.5);
					last_seen = 1;
				} else {
					if(((colorfind(1, 8)) && (!(colorfind(0, 8))))) {
						BuggyTurn(1, 15, 0.5);
						last_seen = 2;
					} else {
						if(((last_seen) == 1)) {
							Buggy.setSpeedA(-10);
						} else {
							if(((last_seen) == 2)) {
								Buggy.setSpeedB(-10);
							} else {
								Buggy.setSpeed(-20, -20);
							}
						}
					}
				}
			}
		}
	}
}