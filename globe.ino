#include <SoftwareSerial.h>


#include <Servo.h>;
Servo srv;
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

SoftwareSerial bluetoothSerial(8, 7);  // RX, TX pins of HC-05


int currDeg;
bool timerOn;
bool spinMode = false;
int fullTime180 = 2195;

int fullTime113 = 2195;
float time113 = fullTime113 / 360;

float time180 = fullTime180 / 360;
int currRot;


int brightness = 0;        // Current brightness value
int fadeAmount = 5;        // Fade increment value
int targetBrightness = 0;  // Target brightness value

void fadeToColor(int targetRed, int targetGreen, int targetBlue) {
  // Fade to the target color
  while (brightness < 255) {
    targetBrightness = map(brightness, 0, 255, 0, 255);
    analogWrite(redPin, map(targetBrightness, 0, 255, 0, targetRed));
    analogWrite(greenPin, map(targetBrightness, 0, 255, 0, targetGreen));
    analogWrite(bluePin, map(targetBrightness, 0, 255, 0, targetBlue));
    brightness += fadeAmount;
    delay(30);
  }

  // Fade back to black
  while (brightness > 0) {
    targetBrightness = map(brightness, 0, 255, 0, 255);
    analogWrite(redPin, map(targetBrightness, 0, 255, 0, targetRed));
    analogWrite(greenPin, map(targetBrightness, 0, 255, 0, targetGreen));
    analogWrite(bluePin, map(targetBrightness, 0, 255, 0, targetBlue));
    brightness -= fadeAmount;
    delay(30);
  }
}
void writeRGB(byte red, byte green, byte blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
void rgbIndia() {
  // Fade from black to saffron
  fadeToColor(255, 140, 0);

  // Fade from black to white
  fadeToColor(255, 255, 255);

  // Fade from black to green
  fadeToColor(0, 128, 0);
}




void spinSrv() {
  if (spinMode) {
    srv.write(113);
    timerOn = true;
    timer(time113);
    // rgbIndia();
    // Serial.println(currDeg);
  }
}
void moveLong(int Degr) {
  while (currDeg != map(Degr, -180, 180, 0, 360)) {
    spinMode = true;
    spinSrv();
  };
  spinMode = false;
  srv.write(90);
  // srv.write(113);
  // delay(map(Degr, -180, 180, 0, 360) * time180);
  // currDeg = currDeg + map(Degr, -180, 180, 0, 360);
  // srv.write(90);
  // Serial.println(map(Degr, -180, 180, 0, 360) * time180);
}
void timer(unsigned long time) {
  if (timerOn) {
    delay(time);
    currDeg = currDeg + 1;
    if (currDeg == 360) { currDeg = 0; }
    Serial.println(currDeg);
  }
}


void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  bluetoothSerial.begin(9600);  // Initialize Bluetooth communication
  srv.attach(9);
  Serial.begin(9600);
}

void loop() {

  spinSrv();

  if (bluetoothSerial.available()) {
    char receivedChar = bluetoothSerial.read();
    Serial.println(receivedChar);
    if (isDigit(receivedChar)) {
      spinMode = true;
    } else if (isAlpha(receivedChar)) {

      spinMode = false;
      srv.write(90);
      char chVal = receivedChar;
      // Serial.print(chVal + "_Character Value; ");
      // country specific code
      if (chVal == 'A') {
        // Argentina featuring color Green
        moveLong(-65);
        writeRGB(0, 153, 51);
      }

      else if (chVal == 'U') {
        // Australia featuring color Blue
        moveLong(134);
        writeRGB(0, 51, 153);
      }

      else if (chVal == 'B') {
        // Brazil featuring color Green
        moveLong(-54);
        writeRGB(0, 220, 20);
      }

      else if (chVal == 'C') {
        // Canada featuring color Red
        moveLong(-97);
        writeRGB(249, 17, 18);
      }

      else if (chVal == 'H') {
        // China featuring color Red
        moveLong(104);
        writeRGB(252, 11, 22);
      }

      else if (chVal == 'F') {
        // France featuring color Blue
        moveLong(3);
        writeRGB(0, 85, 254);
      }

      else if (chVal == 'G') {
        // Germany featuring color Yellow
        moveLong(10);
        writeRGB(255, 206, 0);
      }

      else if (chVal == 'I') {
        // India featuring color Orange
        moveLong(83);
        writeRGB(255, 69, 0);
      }

      else if (chVal == 'N') {
        // Indonesia featuring color RED
        moveLong(117);
        writeRGB(255, 12, 0);
      }

      else if (chVal == 'T') {
        // Italy featuring color Green
        moveLong(12);
        writeRGB(20, 246, 0);
      }

      else if (chVal == 'J') {
        // Japan featuring color Red
        moveLong(138);
        writeRGB(187, 0, 0);
      }

      else if (chVal == 'M') {
        // Mexico featuring color Red
        moveLong(-102);
        writeRGB(6, 107, 0);
      }

      else if (chVal == 'R') {
        // Russia featuring color Red
        moveLong(100);
        writeRGB(213, 43, 30);
      }

      else if (chVal == 'S') {
        // Saudi Arabia featuring color Blue
        moveLong(45);
        writeRGB(0, 200, 0);
      }

      else if (chVal == 'Z') {
        // South Africa featuring color Red
        moveLong(25);
        writeRGB(35, 200, 35);
      }

      else if (chVal == 'K') {
        // South Korea featuring color Red
        moveLong(127);
        writeRGB(237, 10, 23);
      }

      else if (chVal == 'Y') {
        // Turkey featuring color Red
        moveLong(36);
        writeRGB(255, 0, 0);
      }

      else if (chVal == 'E') {
        // United Kingdom featuring color Red
        moveLong(-2);
        writeRGB(205, 32, 31);
      }

      else if (chVal == 'Q') {
        // United States featuring color Blue
        moveLong(-120);
        writeRGB(0, 56, 168);
      }

      else if (chVal == 'O') {
        // make return to home in app
        // make controls hide on locate long press
        while (currDeg != 0) {
          spinMode = true;
          spinSrv();
        };
        spinMode = false;
        srv.write(90);
        writeRGB(0, 0, 0);
      }

      //motor control
      else if (chVal == 'W') {
        //motor fine tuning forward
        srv.write(113);
        delay(500);
        srv.write(90);
      } else if (chVal == 'V') {
        //motor fine tuning backward
        srv.write(0);
        delay(time180 * 10);
        srv.write(90);
      } else if (chVal == 'X') {
        //motor reset
        currDeg = 0;
        writeRGB(0, 0, 0);
      } else if (chVal == 'D') {
        srv.write(0);
        delay(20000);
        srv.write(90);
        writeRGB(0, 0, 0);
      }
    }//country specific code ends
  
  }
}