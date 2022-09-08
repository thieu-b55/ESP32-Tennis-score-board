/*
MIT License

Copyright (c) 2022 thieu-b55

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
/*
 * ATTINY45
 * 3.3V 8 MHz internal
 */

#define INPUT_1       0
#define INPUT_2       1
#define ENABLE        2
#define OUTPUT_1      3
#define OUTPUT_2      4


void setup() {
 pinMode(INPUT_1, INPUT);
 pinMode(INPUT_2, INPUT);
 pinMode(OUTPUT_1, OUTPUT);
 pinMode(OUTPUT_2, OUTPUT);
 pinMode(ENABLE, INPUT);
 digitalWrite(OUTPUT_1, true);
 digitalWrite(OUTPUT_2, true);
}

void loop() {
  if((digitalRead(INPUT_1) == false) && (digitalRead(ENABLE) == true)){
    digitalWrite(OUTPUT_1, false);
    delay(2000);
    digitalWrite(OUTPUT_1, true);
  }
  if((digitalRead(INPUT_2) == false) && (digitalRead(ENABLE) == true)){
    digitalWrite(OUTPUT_2, false);
    delay(2000);
    digitalWrite(OUTPUT_2, true);
  }
}
