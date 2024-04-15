
#include "SetModulationTarget.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetModulationTarget
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetModulationTarget::CmdName = "SetModulationTarget";
    const char* const SetModulationTarget::Documentation = "Set a modulation target.\n"
      "If Id is not set, or if new, a new target is added.\n"
      "For setter : If the Id is already used, the corresponding target is updated.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ ------------------------------------------------------------------------------------------------------------------------------------\n"
      "Type            string Target type can be \"DTA-2115B\", \"File\", \"N310\", \"None\", \"NoneRT\", \"X300\" or \"Wavefront Controller\".\n"
      "Path            string File path. Optional, use only if type is \"File\".\n"
      "Address         string Optional. IP Address if type is \"N310\" or \"X300\".\n"
      "ClockIsExternal bool   Indicate 10 MHz reference clock is external (true) or internal (false). Optional, use only if type is \"DTA-2115B\", \"N310\" or \"X300\".\n"
      "Id              string Unique identifier automatically set by simulator";
    const char* const SetModulationTarget::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetModulationTarget);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetModulationTarget);


    SetModulationTarget::SetModulationTarget()
      : CommandBase(CmdName, TargetId)
    {}

    SetModulationTarget::SetModulationTarget(const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setType(type);
      setPath(path);
      setAddress(address);
      setClockIsExternal(clockIsExternal);
      setId(id);
    }

    SetModulationTargetPtr SetModulationTarget::create(const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id)
    {
      return std::make_shared<SetModulationTarget>(type, path, address, clockIsExternal, id);
    }

    SetModulationTargetPtr SetModulationTarget::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetModulationTarget>(ptr);
    }

    bool SetModulationTarget::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<std::string>::is_valid(m_values["Address"])
          && parse_json<bool>::is_valid(m_values["ClockIsExternal"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetModulationTarget::documentation() const { return Documentation; }

    const std::vector<std::string>& SetModulationTarget::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Type", "Path", "Address", "ClockIsExternal", "Id"}; 
      return names; 
    }


    int SetModulationTarget::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetModulationTarget::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void SetModulationTarget::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModulationTarget::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void SetModulationTarget::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModulationTarget::address() const
    {
      return parse_json<std::string>::parse(m_values["Address"]);
    }

    void SetModulationTarget::setAddress(const std::string& address)
    {
      m_values.AddMember("Address", parse_json<std::string>::format(address, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetModulationTarget::clockIsExternal() const
    {
      return parse_json<bool>::parse(m_values["ClockIsExternal"]);
    }

    void SetModulationTarget::setClockIsExternal(bool clockIsExternal)
    {
      m_values.AddMember("ClockIsExternal", parse_json<bool>::format(clockIsExternal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModulationTarget::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetModulationTarget::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
