
#include "IsSVEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSVEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSVEnabled::CmdName = "IsSVEnabled";
    const char* const IsSVEnabled::Documentation = "Get whether a satellite is enabled or disabled for this constellation.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------------------------------------------------------------------------------------\n"
      "System string The satellite's constellation. Can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId   int    The satellite's SV ID (use 0 for all SVs).";
    const char* const IsSVEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSVEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSVEnabled);


    IsSVEnabled::IsSVEnabled()
      : CommandBase(CmdName, TargetId)
    {}

    IsSVEnabled::IsSVEnabled(const std::string& system, int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
    }

    IsSVEnabledPtr IsSVEnabled::create(const std::string& system, int svId)
    {
      return std::make_shared<IsSVEnabled>(system, svId);
    }

    IsSVEnabledPtr IsSVEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSVEnabled>(ptr);
    }

    bool IsSVEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string IsSVEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSVEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId"}; 
      return names; 
    }


    int IsSVEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSVEnabled::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSVEnabled::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsSVEnabled::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsSVEnabled::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
