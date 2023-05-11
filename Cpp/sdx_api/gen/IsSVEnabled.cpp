
#include "gen/IsSVEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSVEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSVEnabled::CmdName = "IsSVEnabled";
    const char* const IsSVEnabled::Documentation = "Get whether a satellite is enabled or disabled for this constellation.";

    REGISTER_COMMAND_FACTORY(IsSVEnabled);


    IsSVEnabled::IsSVEnabled()
      : CommandBase(CmdName)
    {}

    IsSVEnabled::IsSVEnabled(const std::string& system, int svId)
      : CommandBase(CmdName)
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
