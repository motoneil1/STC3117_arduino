#include "Wire.h"
#include "stc3117_Driver.h"


STC3117_BatteryData_TypeDef *battery1 = new STC3117_BatteryData_TypeDef;
STC3117_ConfigData_TypeDef *config1 = new STC3117_ConfigData_TypeDef;

template <typename T>
Print& operator<<(Print& printer, T value)
{
    printer.print(value);
    return printer;
}

void setup() {
  Serial.begin(9600);
  Serial.print("\nProgram starting \n");
  Wire.begin();

  delay (50);
  

  // GasGauge_Initialization(config1, battery1);
}

void loop() {

  delay(2000);

  GasGauge_Task(config1, battery1);


  Serial << "The Vmode is " << (*config1).Vmode << "\n";
  Serial << "The status word is " << (*battery1).StatusWord << "\n";
  Serial << "The HRSOC is " << (*battery1).HRSOC << "%\n";
  Serial << "The SOC is " << (*battery1).SOC << "%\n";
  Serial << "The voltage is " << (*battery1).Voltage << "mV\n";
  Serial << "The current is " << (*battery1).Current * 10 << "mA\n";
  Serial << "The Temperature is " << (*battery1).Temperature / 10 << "C\n";
  Serial << "The ConvCounter is " << (*battery1).ConvCounter << "\n";
  Serial << "The OCV is " << (*battery1).OCV << "mV\n";
  Serial << "The Presence is " << (*battery1).Presence << "\n";
  Serial << "The remaining charge is " << (*battery1).ChargeValue * 10 << "mAh\n";
  Serial << "The remaining time is " << (*battery1).RemTime * 10 << "\n\n\n";


}