#include <ModbusMaster.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Arduino_JSON.h>
#include <FS.h>
#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

#define MAX485_TX_ENABLE  12
#include "index.h"
#define FIREBASE_HOST "biit-aff4a.firebaseio.com"
#define FIREBASE_AUTH "rt2DOU9GHhq4mvCzyoaTGyfUvx3wkprJriSMSOgq"

const char* ssid = "HPL_IITB_2F";
const char* password = "hpl_iitb";
int myInts[6];
ModbusMaster node;
ESP8266WebServer server(80); //Server on port 80

void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(100, "text/html", s); //Send web page
}

void preTransmission(){
  digitalWrite(MAX485_TX_ENABLE, 1);
}

void postTransmission(){
  digitalWrite(MAX485_TX_ENABLE, 0);
}

void setup(){
  //Serial.begin(9600);
  Serial.begin(9600, SERIAL_8N1);
  pinMode(MAX485_TX_ENABLE, OUTPUT);
  digitalWrite(MAX485_TX_ENABLE, 0);

  WiFi.begin(ssid, password);
  Serial.println("");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(){
  server.handleClient();
  uint16_t k = 0,Status;
  node.begin(1, Serial); //Slave ID = 1?
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission); 
  Status = node.readHoldingRegisters(0x0023, 1); //Since address is 40023 to 40027
  if ( (Status == node.ku8MBSuccess) ){
    Serial.print("\nIDK: ");
    //Serial.println(node.getResponseBuffer(0));
    for (k = 0; k <= 1; k++ ){
      Status = node.readHoldingRegisters(k, 1);
      Serial.println(node.getResponseBuffer(0));
      Firebase.pushFloat("X/X1", node.getResponseBuffer(0));
    }
  }
  delay(6000);
}
