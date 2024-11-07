#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLE)
#error Bluetooth is not enabled! Please run 'make menuconfig' to and enable it
#endif

BluetoothSerial Esp;

void setup(){
  Serial.begin(115200);
  Esp.begin("BracoRobotico")
  Serial.println("Dispositivo iniciado, agora você pode conectar com o bluetooth!");

}

void loop(){
  if (Serial.available()){
    Esp.write(Serial.read());
  }
  if(Esp.available()){
    char recebido = Esp.read();
    Serial.write(recebido);
  }
  delay(20);
}