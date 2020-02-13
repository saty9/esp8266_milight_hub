#pragma once

#include <json.hpp>

enum MiLightStatus {
  ON = 0,
  OFF = 1
};

MiLightStatus parseMilightStatus(nlohmann::json s);