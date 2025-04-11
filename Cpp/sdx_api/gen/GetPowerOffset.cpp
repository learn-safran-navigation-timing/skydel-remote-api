
#include "GetPowerOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPowerOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPowerOffset::CmdName = "GetPowerOffset";
    const char* const GetPowerOffset::Documentation = "Please note the command GetPowerOffset is deprecated since 21.7. You may use GetSignalPowerOffset.\n"
      "\n"
      "Get power offset default value for the signal given in argument\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------------------------------------------------------------------------\n"
      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                    \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
      "                                    \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\",\n"
      "                                    \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\",\n"
      "                                    \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"";
    const char* const GetPowerOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPowerOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPowerOffset);


    GetPowerOffset::GetPowerOffset()
      : CommandBase(CmdName, TargetId)
    {}

    GetPowerOffset::GetPowerOffset(const std::string& signal)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
    }

    GetPowerOffsetPtr GetPowerOffset::create(const std::string& signal)
    {
      return std::make_shared<GetPowerOffset>(signal);
    }

    GetPowerOffsetPtr GetPowerOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPowerOffset>(ptr);
    }

    bool GetPowerOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string GetPowerOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPowerOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal"}; 
      return names; 
    }


    int GetPowerOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPowerOffset::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetPowerOffset::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
