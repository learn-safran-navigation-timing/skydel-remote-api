
#include "gen/GetModulationTarget.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetModulationTarget
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetModulationTarget::CmdName = "GetModulationTarget";
    const char* const GetModulationTarget::Documentation = "Get a modulation target.\nIf Id is not set, or if new, a new target is added.\nFor setter : If the Id is already used, the corresponding target is updated.";

    REGISTER_COMMAND_FACTORY(GetModulationTarget);


    GetModulationTarget::GetModulationTarget()
      : CommandBase(CmdName)
    {}

    GetModulationTarget::GetModulationTarget(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetModulationTargetPtr GetModulationTarget::create(const std::string& id)
    {
      return std::make_shared<GetModulationTarget>(id);
    }

    GetModulationTargetPtr GetModulationTarget::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetModulationTarget>(ptr);
    }

    bool GetModulationTarget::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetModulationTarget::documentation() const { return Documentation; }


    int GetModulationTarget::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetModulationTarget::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetModulationTarget::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
