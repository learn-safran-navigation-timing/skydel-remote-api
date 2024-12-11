
#include "IsSignalEnabledForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalEnabledForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalEnabledForEachSV::CmdName = "IsSignalEnabledForEachSV";
    const char* const IsSignalEnabledForEachSV::Documentation = "Tells if the signal is enabled or disabled for each satellite.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------------------------------------------------------\n"
      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                    \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
      "                                    \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"
      "                                    \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\",\n"
      "                                    \"PULSARXL\", \"PULSARX1\"";
    const char* const IsSignalEnabledForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSignalEnabledForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSignalEnabledForEachSV);


    IsSignalEnabledForEachSV::IsSignalEnabledForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    IsSignalEnabledForEachSV::IsSignalEnabledForEachSV(const std::string& signal)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
    }

    IsSignalEnabledForEachSVPtr IsSignalEnabledForEachSV::create(const std::string& signal)
    {
      return std::make_shared<IsSignalEnabledForEachSV>(signal);
    }

    IsSignalEnabledForEachSVPtr IsSignalEnabledForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalEnabledForEachSV>(ptr);
    }

    bool IsSignalEnabledForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string IsSignalEnabledForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSignalEnabledForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal"}; 
      return names; 
    }


    int IsSignalEnabledForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSignalEnabledForEachSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsSignalEnabledForEachSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
