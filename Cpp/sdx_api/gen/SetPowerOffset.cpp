
#include "SetPowerOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPowerOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPowerOffset::CmdName = "SetPowerOffset";
    const char* const SetPowerOffset::Documentation = "Please note the command SetPowerOffset is deprecated since 21.7. You may use SetSignalPowerOffset.\n"
      "\n"
      "Set power offset default value for the signal given in argument\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------------------------------------------------------------------------\n"
      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                    \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
      "                                    \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\",\n"
      "                                    \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\",\n"
      "                                    \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"\n"
      "Offset double Offset in dB (negative value will attenuate signal)";
    const char* const SetPowerOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPowerOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPowerOffset);


    SetPowerOffset::SetPowerOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetPowerOffset::SetPowerOffset(const std::string& signal, double offset)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setOffset(offset);
    }

    SetPowerOffsetPtr SetPowerOffset::create(const std::string& signal, double offset)
    {
      return std::make_shared<SetPowerOffset>(signal, offset);
    }

    SetPowerOffsetPtr SetPowerOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPowerOffset>(ptr);
    }

    bool SetPowerOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetPowerOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPowerOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Offset"}; 
      return names; 
    }


    int SetPowerOffset::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string SetPowerOffset::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void SetPowerOffset::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPowerOffset::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetPowerOffset::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
