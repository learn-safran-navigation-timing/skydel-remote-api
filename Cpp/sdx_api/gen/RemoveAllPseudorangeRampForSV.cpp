
#include "RemoveAllPseudorangeRampForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllPseudorangeRampForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllPseudorangeRampForSV::CmdName = "RemoveAllPseudorangeRampForSV";
    const char* const RemoveAllPseudorangeRampForSV::Documentation = "Remove all PSR Ramps for the specified system's satellite.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId   int    The satellite's SV ID (use 0 for all SVs).";
    const char* const RemoveAllPseudorangeRampForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveAllPseudorangeRampForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveAllPseudorangeRampForSV);


    RemoveAllPseudorangeRampForSV::RemoveAllPseudorangeRampForSV()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveAllPseudorangeRampForSV::RemoveAllPseudorangeRampForSV(const std::string& system, int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
    }

    RemoveAllPseudorangeRampForSVPtr RemoveAllPseudorangeRampForSV::create(const std::string& system, int svId)
    {
      return std::make_shared<RemoveAllPseudorangeRampForSV>(system, svId);
    }

    RemoveAllPseudorangeRampForSVPtr RemoveAllPseudorangeRampForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllPseudorangeRampForSV>(ptr);
    }

    bool RemoveAllPseudorangeRampForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string RemoveAllPseudorangeRampForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveAllPseudorangeRampForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId"}; 
      return names; 
    }


    int RemoveAllPseudorangeRampForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveAllPseudorangeRampForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void RemoveAllPseudorangeRampForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int RemoveAllPseudorangeRampForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void RemoveAllPseudorangeRampForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
