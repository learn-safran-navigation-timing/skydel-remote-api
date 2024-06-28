
#include "IsSignalEnabledForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalEnabledForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalEnabledForSV::CmdName = "IsSignalEnabledForSV";
    const char* const IsSignalEnabledForSV::Documentation = "Tells if the signal is enabled or disabled.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------------------------------------------------------------------------------------------\n"
      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                    \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
      "                                    \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"
      "                                     \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\"\n"
      "SvId   int    The satellite's SV ID (use 0 for all constellation's satellites)";
    const char* const IsSignalEnabledForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSignalEnabledForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSignalEnabledForSV);


    IsSignalEnabledForSV::IsSignalEnabledForSV()
      : CommandBase(CmdName, TargetId)
    {}

    IsSignalEnabledForSV::IsSignalEnabledForSV(const std::string& signal, int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setSvId(svId);
    }

    IsSignalEnabledForSVPtr IsSignalEnabledForSV::create(const std::string& signal, int svId)
    {
      return std::make_shared<IsSignalEnabledForSV>(signal, svId);
    }

    IsSignalEnabledForSVPtr IsSignalEnabledForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalEnabledForSV>(ptr);
    }

    bool IsSignalEnabledForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string IsSignalEnabledForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSignalEnabledForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "SvId"}; 
      return names; 
    }


    int IsSignalEnabledForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSignalEnabledForSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsSignalEnabledForSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsSignalEnabledForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsSignalEnabledForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
