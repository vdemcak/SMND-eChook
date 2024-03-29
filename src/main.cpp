#include <Arduino.h>

#include <Battery.hpp>
#include <Bluetooth.hpp>
#include <DataPacket.hpp>

void setup() {
  Bluetooth::init();
  Battery::init();
}

void loop() {
  DataPacket::setKey("totalVoltage", Battery::readTotalVoltage());
  DataPacket::setKey("cell1Voltage", Battery::readCellVoltage(1));
  DataPacket::setKey("cell2Voltage", Battery::readCellVoltage(2));

  String packet = DataPacket::getJSON();

  Bluetooth::sendData(packet);
  delay(5000);
}