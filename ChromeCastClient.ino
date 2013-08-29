/*
  ChromeCast client
 
 This sketch connects to a ChromeCast device and loads a YouTube video.
 This sketch requires an Arduino Ethernet shield.
 
 To customize this sketch for your own YouTube video:
 1. Determine the IP address of your ChromeCast device and change the chromecast variable value in the sketch.
 2. Get the YouTube ID from the web site. It will be the URL parameter value after "v" (e.g. for http://www.youtube.com/watch?v=GWXLPu8Ky9k, v is "GWXLPu8Ky9k").
 3. Put the YouTube ID in the youtube variable value.
 */

#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your ethernet shield (or keep the default value).
// Newer Ethernet shields have a MAC address printed on a sticker on the shield.
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// TODO Enter your ChromeCast device IP address:
IPAddress chromecast(192,168,0,22);

// TODO Change v parameter value to your YouTube video ID:
char youtube[] = "v=GWXLPu8Ky9k";

////////////////////////////////////////////////////////
// You shouldn't have to change anything below this line.

// Track if youtube video was loaded once
int done = 0;

// PIR sensor: http://www.ladyada.net/learn/sensors/pir.html
int ledPin = 7;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

// Ethernet library
EthernetClient client;

// Start of the sketch
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input

  // Open serial communications
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for the serial port to open
  }

  // Start the ethernet connection
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to get an IP address using DHCP");
    // Do nothing forever
    for(;;)
      ;
  }

  Serial.print("Arduino IP address: ");
  Serial.println(Ethernet.localIP());
  
  // Wait for the ethernet shield to initialize
  delay(1000);

  // Flash the LED to show ethernet is ready
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
}

// Keep running the sketch
void loop()
{
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    if (pirState == LOW) {
      digitalWrite(ledPin, HIGH);  // turn LED ON
      // We have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;

      if (done==0) {
        done = 1;   // just do it once
        Serial.println("Connecting to ChromeCast device...");
        // Connect to the ChromeCast web server on port 8008
        if (client.connect(chromecast, 8008)) {
          Serial.println("Connected to ChromeCast device");

          // Make a HTTP POST request to start the ChromeCast YouTube app
          client.println("POST /apps/YouTube HTTP/1.1");
          client.println("Host: www.arduino.cc");
          client.println("User-Agent: arduino-ethernet");
          client.println("Connection: close");
          client.println("Content-Type: application/x-www-form-urlencoded");
          client.print("Content-Length: ");
          client.println(strlen(youtube));
          client.println();
          client.println(youtube);
          client.println();

          client.stop();

          Serial.println("YouTube app started on ChromeCast device");
        }
      } 
      else {
        Serial.println("Connection to ChromeCast device failed");
      }
    }
  } 
  else {
    if (pirState == HIGH){
      digitalWrite(ledPin, LOW); // turn LED OFF
      // We have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}



