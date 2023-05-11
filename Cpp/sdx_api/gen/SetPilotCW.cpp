
#include "gen/SetPilotCW.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPilotCW
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPilotCW::CmdName = "SetPilotCW";
    const char* const SetPilotCW::Documentation = "Set CW pilot added to signal";

    REGISTER_COMMAND_FACTORY(SetPilotCW);


    SetPilotCW::SetPilotCW()
      : CommandBase(CmdName)
    {}

    SetPilotCW::SetPilotCW(bool enabled, int outputIdx, double centralFreqOffset, double power, const std::string& pilotId)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
      setOutputIdx(outputIdx);
      setCentralFreqOffset(centralFreqOffset);
      setPower(power);
      setPilotId(pilotId);
    }

    SetPilotCWPtr SetPilotCW::create(bool enabled, int outputIdx, double centralFreqOffset, double power, const std::string& pilotId)
    {
      return std::make_shared<SetPilotCW>(enabled, outputIdx, centralFreqOffset, power, pilotId);
    }

    SetPilotCWPtr SetPilotCW::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPilotCW>(ptr);
    }

    bool SetPilotCW::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<int>::is_valid(m_values["OutputIdx"])
          && parse_json<double>::is_valid(m_values["CentralFreqOffset"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<std::string>::is_valid(m_values["PilotId"])
        ;

    }

    std::string SetPilotCW::documentation() const { return Documentation; }


    int SetPilotCW::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    bool SetPilotCW::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetPilotCW::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPilotCW::outputIdx() const
    {
      return parse_json<int>::parse(m_values["OutputIdx"]);
    }

    void SetPilotCW::setOutputIdx(int outputIdx)
    {
      m_values.AddMember("OutputIdx", parse_json<int>::format(outputIdx, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPilotCW::centralFreqOffset() const
    {
      return parse_json<double>::parse(m_values["CentralFreqOffset"]);
    }

    void SetPilotCW::setCentralFreqOffset(double centralFreqOffset)
    {
      m_values.AddMember("CentralFreqOffset", parse_json<double>::format(centralFreqOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPilotCW::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetPilotCW::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetPilotCW::pilotId() const
    {
      return parse_json<std::string>::parse(m_values["PilotId"]);
    }

    void SetPilotCW::setPilotId(const std::string& pilotId)
    {
      m_values.AddMember("PilotId", parse_json<std::string>::format(pilotId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
