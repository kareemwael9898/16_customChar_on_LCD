#include <LiquidCrystal.h>
#define rs 12
#define en 10
#define d4 8
#define d5 6
#define d6 4
#define d7 2

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/*********************************************/
byte sentence[][8] = {

  { B00000, B00000, B00000, B00000, B00000, B00100, B00100, B00111 },
  { B00000, B00000, B00000, B00000, B00001, B11111, B01000, B11010 },
  { B00000, B00000, B01000, B00010, B00010, B11111, B00000, B00000 },
  { B00000, B10100, B10100, B10100, B10100, B10101, B00101, B00101 },
  { B00000, B00001, B00001, B00001, B00001, B00111, B00010, B11110 },
  { B00000, B00000, B00000, B00100, B01000, B11110, B00000, B00000 },
  { B00001, B00010, B00111, B10000, B11111, B00000, B00000, B00000 },
  { B01000, B01000, B01000, B01000, B11010, B00010, B00100, B11000 },
  { B00000, B10000, B10000, B10000, B10010, B11110, B00000, B00100 },
  { B00000, B00000, B00000, B01000, B10100, B01001, B10001, B00001 },
  { B00000, B00000, B00000, B00000, B00000, B00111, B00010, B11110 },
  { B00000, B00100, B00100, B00100, B00101, B11111, B00000, B00000 },
  { B00000, B00000, B00000, B00100, B01010, B11110, B00000, B00000 },
  { B00000, B00000, B00000, B00100, B01010, B01111, B10000, B10000 },
  { B00000, B00000, B00000, B00100, B01010, B11111, B01010, B00100 },
  { B00000, B00101, B10101, B10101, B10101, B11101, B00001, B00001 }

};
/*********************************************/

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int startDelay = 350;
  int scrollDelay = 600;

  // The position of first char on the lcd
  int startPos = 15;  // It dependes on size of SENTENCE & Must be >= Number of custom characters
  int currentPos = startPos;
  int firstChar = sizeof(sentence) / sizeof(sentence[0]) - 1;  // Get the number of custom characters

  for (currentPos; firstChar >= 0 && currentPos >= 0; currentPos--) {
    if (startPos - currentPos < 8) {
      lcd.createChar(currentPos, sentence[firstChar--]);
      lcd.setCursor(currentPos, 0);
      lcd.write(currentPos);
      delay(startDelay);
    } else {
      // If character is out of borders /**\ borders is 8 chars only
      lcd.createChar((currentPos + 8), sentence[firstChar--]);  // Store the new char and remove the old one
      lcd.setCursor(currentPos, 0);
      lcd.write(currentPos + 8);
      lcd.scrollDisplayRight();
      delay(scrollDelay);
    }
  }
  delay(2000);
  lcd.clear();
};
