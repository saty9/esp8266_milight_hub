//#include <Arduino.h>
#include <ArduinoJson.h>
#include "string"

#ifndef _ABOUT_STRING_HELPER_H
#define _ABOUT_STRING_HELPER_H

class AboutHelper {
public:
  static std::string generateAboutString(bool abbreviated = false);
  static void generateAboutObject(JsonDocument& obj, bool abbreviated = false);
};

#endif