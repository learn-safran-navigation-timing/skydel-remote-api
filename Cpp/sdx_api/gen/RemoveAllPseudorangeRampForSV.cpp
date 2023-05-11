
#include "gen/RemoveAllPseudorangeRampForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllPseudorangeRampForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllPseudorangeRampForSV::CmdName = "RemoveAllPseudorangeRampForSV";
    const char* const RemoveAllPseudorangeRampForSV::Documentation = "Remove all PSR Ramps for the specified system's satellite.";

    REGISTER_COMMAND_FACTORY(RemoveAllPseudorangeRampForSV);


    RemoveAllPseudorangeRampForSV::RemoveAllPseudorangeRampForSV()
      : CommandBase(CmdName)
    {}

    RemoveAllPseudorangeRampForSV::RemoveAllPseudorangeRampForSV(const std::string& system, int svId)
      : CommandBase(CmdName)
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
