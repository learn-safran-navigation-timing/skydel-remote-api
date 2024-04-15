#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// The simulator sub-state.
  ///
  
  enum class SimulatorSubState : int { SubStateNone, Idle_ConfigNotValid, Idle_ConfigValid, Started_InitPlugins, Started_InitHardware, Started_Streaming, Started_SyncInit, Started_WorkerSync, Started_Armed, Started_SyncStartTime, Error, Started_HILSync, Started_SyncPPSReset, Started_SyncStart, Started_WFWorkerInit, Started_WFMainInit, Started_WFSyncPPSReset, Started_WFSyncStart };
}

template<>
struct parse_json<Sdx::SimulatorSubState>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::SimulatorSubState parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return static_cast<Sdx::SimulatorSubState>(value.GetInt());
  }
  static rapidjson::Value format(Sdx::SimulatorSubState value, rapidjson::Value::AllocatorType&) { return rapidjson::Value(static_cast<int>(value)); }
};

