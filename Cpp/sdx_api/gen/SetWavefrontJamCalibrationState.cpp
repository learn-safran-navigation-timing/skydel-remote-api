
#include "gen/SetWavefrontJamCalibrationState.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetWavefrontJamCalibrationState
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetWavefrontJamCalibrationState::CmdName = "SetWavefrontJamCalibrationState";
    const char* const SetWavefrontJamCalibrationState::Documentation = "Set whether the JAM Calibration output is transmitting.";

    REGISTER_COMMAND_FACTORY(SetWavefrontJamCalibrationState);


    SetWavefrontJamCalibrationState::SetWavefrontJamCalibrationState()
      : CommandBase(CmdName)
    {}

    SetWavefrontJamCalibrationState::SetWavefrontJamCalibrationState(bool state)
      : CommandBase(CmdName)
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
