
#include "GetSignalPowerOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSignalPowerOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSignalPowerOffset::CmdName = "GetSignalPowerOffset";
    const char* const GetSignalPowerOffset::Documentation = "Get power offset default value for the signal given in argument\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------------------------------------------------------------------------\n"
      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                    \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
      "                                    \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\",\n"
      "                                    \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\",\n"
      "                                    \"PULSARXL\", \"PULSARX1\"";
    const char* const GetSignalPowerOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSignalPowerOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSignalPowerOffset);


    GetSignalPowerOffset::GetSignalPowerOffset()
      : CommandBase(CmdName, TargetId)
    {}

    GetSignalPowerOffset::GetSignalPowerOffset(const std::string& signal)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
    }

    GetSignalPowerOffsetPtr GetSignalPowerOffset::create(const std::string& signal)
    {
      return std::make_shared<GetSignalPowerOffset>(signal);
    }

    GetSignalPowerOffsetPtr GetSignalPowerOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSignalPowerOffset>(ptr);
    }

    bool GetSignalPowerOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string GetSignalPowerOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSignalPowerOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal"}; 
      return names; 
    }


    int GetSignalPowerOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSignalPowerOffset::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetSignalPowerOffset::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
