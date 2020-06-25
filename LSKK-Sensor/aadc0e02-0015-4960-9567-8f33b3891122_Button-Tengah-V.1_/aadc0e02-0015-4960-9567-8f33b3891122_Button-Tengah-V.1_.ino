/*
    Develop by      : Fahmi Nurfadilah 
    Email           : fahmi.nurfadilah1412@gmail.com
    Project         : LSKK HomeAutomation
    Version         : 2.1
*/

#include <PubSubClient.h>
#include <ESP8266WiFi.h>

// Update these with values suitable for your network.

const char* ssid = "RuangIOT";
const char* password = "lskkiot2019";
const char* mqtt_server = "192.168.0.5";
const char* mqtt_user = "/Homeauto:homeauto";
const char* mqtt_pass = "homeauto12345!";
const char* CL = "LSKK-HA-Saklar-2";
const char* mqtt_pub_topic = "Sensor";

String statusDevice[8] = {"1", "1", "1", "1", "1", "1", "1", "1"};

int input1 = D1 ;
int input2 = D2 ;
int input3 = D3 ;
int input4 = D4 ;
int input5 = D5 ;
int input6 = D6 ;
int input7 = D7 ;
int input8 = D8 ;

int instate1 = 0;
int instate2 = 0;
int instate3 = 0;
int instate4 = 0;
int instate5 = 0;
int instate6 = 0;
int instate7 = 0;
int instate8 = 0;

int prevState1 = 0;
int prevState2 = 0;
int prevState3 = 0;
int prevState4 = 0;
int prevState5 = 0;
int prevState6 = 0;
int prevState7 = 0;
int prevState8 = 0;

char message [100];

WiFiClient espClient;
PubSubClient client(espClient);

byte mac[6];
String MACAddress;

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

String mac2String(byte ar[]) {
  String s;
  for (byte i = 0; i < 6; ++i)
  {
    char buf[3];
    sprintf(buf, "%2X", ar[i]);
    s += buf;
    if (i < 5) s += ':';
  }
  return s;
}

void printMACAddress() {
  WiFi.macAddress(mac);
  MACAddress = mac2String(mac);
  Serial.println(MACAddress);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  printMACAddress();
  const char* CL;
  CL = MACAddress.c_str();
  Serial.println(CL);
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(CL, mqtt_user, mqtt_pass)) {
      Serial.println("connected");
    } else {Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      ESP.restart();
      delay(5000);

    }
  }
}

void setup()
{
  Serial.begin(115200);
  //pinMode(input, INPUT);
  pinMode(input1, INPUT_PULLUP);
  pinMode(input2, INPUT_PULLUP);
  pinMode(input3, INPUT_PULLUP);
  pinMode(input4, INPUT_PULLUP);
  pinMode(input5, INPUT_PULLUP);
  pinMode(input6, INPUT_PULLUP);
  pinMode(input7, INPUT_PULLUP);
  pinMode(input8, INPUT_PULLUP);
  setup_wifi();
  printMACAddress();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}
void loop() {
  String pubmsg = "";
  String value = String(statusDevice[0] + statusDevice[1] + statusDevice[2] + statusDevice[3] + statusDevice[4] + statusDevice[5] + statusDevice[6] + statusDevice[7]);
  String input_guid = "aadc0e02-0015-4960-9567-8f33b3891122";
  String input_value = value;
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  instate1 = digitalRead(input1);
  instate2 = digitalRead(input2);
  instate3 = digitalRead(input3);
  instate4 = digitalRead(input4);
  instate5 = digitalRead(input5);
  instate6 = digitalRead(input6);
  instate7 = digitalRead(input7);
  instate8 = digitalRead(input8);
  
  //Serial.print("Publish message: ");
  //pubmsg = input_guid + "#" + input_value;
  //Serial.println(pubmsg);
  //client.publish(mqtt_pub_topic, pubmsg.c_str());
  if (instate1 == 1) {
    if(prevState1 != instate1){
      statusDevice[0] = "0";
      Serial.println("Input detected!");
      pubmsg = input_guid + "#" + input_value;
      Serial.println(pubmsg);
      client.publish(mqtt_pub_topic, pubmsg.c_str());
      Serial.println("Success send to RMQ");
      prevState1 = instate1;
    }
  }
  if (instate1 == 0) {
    if(prevState1 != instate1){
      statusDevice[0] = "1";
      Serial.println("Input not detected!");
      pubmsg = input_guid + "#" + input_value;
      Serial.println(pubmsg);
      client.publish(mqtt_pub_topic, pubmsg.c_str());
      Serial.println("Success send to RMQ");
      prevState1 = instate1;
  }
}
if (instate2 == 1) {
    if(prevState2 != instate2){
      statusDevice[1] = "0";
      Serial.println("Input detected!");
      pubmsg = input_guid + "#" + input_value;
      Serial.println(pubmsg);
      client.publish(mqtt_pub_topic, pubmsg.c_str());
      Serial.println("Success send to RMQ");
      prevState2 = instate2;
    }
  }
  if (instate2 == 0) {
    if(prevState2 != instate2){
      statusDevice[1] = "1";
      Serial.println("Input not detected!");
      pubmsg = input_guid + "#" + input_value;
      Serial.println(pubmsg);
      client.publish(mqtt_pub_topic, pubmsg.c_str());
      Serial.println("Success send to RMQ");
      prevState2 = instate2;
  }
}
if (instate3 == 1) {
    if(prevState3 != instate3){
      statusDevice[2] = "0";
      Serial.println("Input detected!");
      pubmsg = input_guid + "#" + input_value;
      Serial.println(pubmsg);
      client.publish(mqtt_pub_topic, pubmsg.c_str());
      Serial.println("Success send to RMQ");
      prevState3 = instate3;
    }
  }
  if (instate3 == 0) {
    if(prevState3 != instate3){
      statusDevice[2] = "1";
      Serial.println("Input not detected!");
      pubmsg = input_guid + "#" + input_value;
      Serial.println(pubmsg);
      client.publish(mqtt_pub_topic, pubmsg.c_str());
      Serial.println("Success send to RMQ");
      prevState3 = instate3;
  }
}
if (instate4 == 1) {
    if(prevState4 != instate4){
      statusDevice[3] = "0";
      Serial.println("Input detected!");
      pubmsg = input_guid + "#" + input_value;
      Serial.println(pubmsg);
      client.publish(mqtt_pub_topic, pubmsg.c_str());
      Serial.println("Success send to RMQ");
      prevState4 = instate4;
    }
  }
  if (instate4 == 0) {
    if(prevState4 != instate4){
      statusDevice[3] = "1";
      Serial.println("Input not detected!");
      pubmsg = input_guid + "#" + input_value;
      Serial.println(pubmsg);
      client.publish(mqtt_pub_topic, pubmsg.c_str());
      Serial.println("Success send to RMQ");
      prevState4 = instate4;
  }
}
}
