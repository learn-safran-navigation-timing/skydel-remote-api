
#include "SetSignalPowerOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSignalPowerOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSignalPowerOffset::CmdName = "SetSignalPowerOffset";
    const char* const SetSignalPowerOffset::Documentation = "Set power offset default value for the signal given in argument\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------------------------------------------------------------------------------\n"
      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                    \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
      "                                    \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\",\n"
      "                                    \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\"\n"
      "Offset double Offset in dB (negative value will attenuate signal)";
    const char* const SetSignalPowerOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSignalPowerOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSignalPowerOffset);


    SetSignalPowerOffset::SetSignalPowerOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetSignalPowerOffset::SetSignalPowerOffset(const std::string& signal, double offset)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setOffset(offset);
    }

    SetSignalPowerOffsetPtr SetSignalPowerOffset::create(const std::string& signal, double offset)
    {
      return std::make_shared<SetSignalPowerOffset>(signal, offset);
    }

    SetSignalPowerOffsetPtr SetSignalPowerOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSignalPowerOffset>(ptr);
    }

    bool SetSignalPowerOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetSignalPowerOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSignalPowerOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Offset"}; 
      return names; 
    }


    int SetSignalPowerOffset::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string SetSignalPowerOffset::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void SetSignalPowerOffset::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSignalPowerOffset::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetSignalPowerOffset::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
