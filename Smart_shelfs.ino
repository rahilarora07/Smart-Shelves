//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID "" //Your SSID
#define WIFI_PASSWORD "" 

#define IR D0
#define IR1 D2
#define IR2 D1
#define IR3 D3
bool ir;
bool ir1;
bool ir2;
bool ir3;

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  pinMode(IR,INPUT);
  pinMode(IR1,INPUT); 
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
}

int n = 0;

void loop() {
  // set value
  int t;
  ir=digitalRead(IR);
  ir1=digitalRead(IR1);
  ir2=digitalRead(IR2);
  ir3=digitalRead(IR3);

  if(ir==1 && ir1==1 && ir2==1 && ir3==1)
  {
    Serial.println("Items left on the shelf : 0");
    t=0;
    delay(200);
  }
  else if(ir==0 && ir1==1 && ir2==1 && ir3==1)
  {
    Serial.println("Items left on the shelf : 1");
    t=1;
    delay(200);
  }
    else if(ir==1 && ir1==0 && ir2==1 && ir3==1)
  {
    Serial.println("Items left on the shelf : 1");
    t=1;
    delay(200);
  }
    else if(ir==1 && ir1==1 && ir2==0 && ir3==1)
  {
    Serial.println("Items left on the shelf : 1");
    t=1;
    delay(200);
  }
  else if(ir==1 && ir1==1 && ir2==1 && ir3==0)
  {
    Serial.println("Items left on the shelf : 1");
    t=1;
    delay(200);
  }
  else if(ir==0 && ir1==0 && ir2==1 && ir3==1)
  {
    Serial.println("Items left on the shelf : 2");
    t=2;
    delay(200);
  }
  else if(ir==1 && ir1==0 && ir2==0 && ir3==1)
  {
    Serial.println("Items left on the shelf : 2");
    t=2;
    delay(200);
  }
  else if(ir==1 && ir1==1 && ir2==0 && ir3==0)
  {
    Serial.println("Items left on the shelf : 2");
    t=2;
    delay(200);
  }
  else if(ir==0 && ir1==1 && ir2==1 && ir3==0)
  {
    Serial.println("Items left on the shelf : 2");
    t=2;
    delay(200);
  }
  else if(ir==0 && ir1==1 && ir2==0 && ir3==1)
  {
    Serial.println("Items left on the shelf : 2");
    t=2;
    delay(200);
  }
  else if(ir==1 && ir1==0 && ir2==1 && ir3==0)
  {
    Serial.println("Items left on the shelf : 2");
    t=2;
    delay(200);
  }
  else if(ir==1 && ir1==0 && ir2==0 && ir3==0)
  {
    Serial.println("Items left on the shelf : 3");
    t=3;
    delay(200);
  }
  else if(ir==0 && ir1==1 && ir2==0 && ir3==0)
  {
    Serial.println("Items left on the shelf : 3");
    t=3;
    delay(200);
  }
  else if(ir==0 && ir1==0 && ir2==1 && ir3==0)
  {
    Serial.println("Items left on the shelf : 3");
    t=3;
    delay(200);
  }
  else if(ir==0 && ir1==0 && ir2==0 && ir3==1)
  {
    Serial.println("Items left on the shelf : 3");
    t=3;
    delay(200);
  }
  else if(ir==0 && ir1==0 && ir2==0 && ir3==0)
  {
    Serial.println("Shelf is full of items");
    t=4;
    delay(200);
  }
  Firebase.setInt("Items left on the shelf",t);
   
  // put your main code here, to run repeatedly:
   
  }
  
