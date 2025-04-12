// includes start
#include <Arduino.h>
#include <BittyBuggy.h>

/*


    this code will not work on arduino ide because the global var &Serial1 is not defined in arduino ide, only in mdesigner, but is just transfer the code to mdesigner in mode offline and add the code.




*/

BittyBuggy Buggy(&Serial1);
// includes end
// definition start
boolean colorfind(uint8_t _AB, uint8_t _color);
void BuggyCarTime(int8_t _dir, uint8_t _speed, float _time);
void BuggyTurn(uint8_t _dir, uint8_t _speed, float _time);
// definition end

int last_seen = 0;
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