
#include "SetWavefrontJamCalibrationState.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetWavefrontJamCalibrationState
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetWavefrontJamCalibrationState::CmdName = "SetWavefrontJamCalibrationState";
    const char* const SetWavefrontJamCalibrationState::Documentation = "Set whether the JAM Calibration output is transmitting.\n"
      "\n"
      "Name  Type Description\n"
      "----- ---- ------------------------------------------------------------------------------\n"
      "State bool True for the signal to go through the JAM Calibration output, False otherwise.";
    const char* const SetWavefrontJamCalibrationState::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetWavefrontJamCalibrationState);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetWavefrontJamCalibrationState);


    SetWavefrontJamCalibrationState::SetWavefrontJamCalibrationState()
      : CommandBase(CmdName, TargetId)
    {}

    SetWavefrontJamCalibrationState::SetWavefrontJamCalibrationState(bool state)
      : CommandBase(CmdName, TargetId)
    {

      setState(state);
    }

    SetWavefrontJamCalibrationStatePtr SetWavefrontJamCalibrationState::create(bool state)
    {
      return std::make_shared<SetWavefrontJamCalibrationState>(state);
    }

    SetWavefrontJamCalibrationStatePtr SetWavefrontJamCalibrationState::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetWavefrontJamCalibrationState>(ptr);
    }

    bool SetWavefrontJamCalibrationState::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["State"])
        ;

    }

    std::string SetWavefrontJamCalibrationState::documentation() const { return Documentation; }

    const std::vector<std::string>& SetWavefrontJamCalibrationState::fieldNames() const 
    { 
      static const std::vector<std::string> names {"State"}; 
      return names; 
    }


    int SetWavefrontJamCalibrationState::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    bool SetWavefrontJamCalibrationState::state() const
    {
      return parse_json<bool>::parse(m_values["State"]);
    }

    void SetWavefrontJamCalibrationState::setState(bool state)
    {
      m_values.AddMember("State", parse_json<bool>::format(state, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
