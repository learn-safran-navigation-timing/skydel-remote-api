
#include "GetModulationTargetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetModulationTargetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetModulationTargetResult::CmdName = "GetModulationTargetResult";
    const char* const GetModulationTargetResult::Documentation = "Result of GetModulationTarget.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ ------------------------------------------------------------------------------------------------------------------------------------\n"
      "Type            string Target type can be \"DTA-2115B\", \"File\", \"N310\", \"None\", \"NoneRT\", \"X300\" or \"Wavefront Controller\".\n"
      "Path            string File path. Optional, use only if type is \"File\".\n"
      "Address         string Optional. IP Address if type is \"N310\" or \"X300\".\n"
      "ClockIsExternal bool   Indicate 10 MHz reference clock is external (true) or internal (false). Optional, use only if type is \"DTA-2115B\", \"N310\" or \"X300\".\n"
      "Id              string Unique identifier automatically set by simulator";
    const char* const GetModulationTargetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetModulationTargetResult);


    GetModulationTargetResult::GetModulationTargetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetModulationTargetResult::GetModulationTargetResult(const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setType(type);
      setPath(path);
      setAddress(address);
      setClockIsExternal(clockIsExternal);
      setId(id);
    }

    GetModulationTargetResult::GetModulationTargetResult(CommandBasePtr relatedCommand, const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setType(type);
      setPath(path);
      setAddress(address);
      setClockIsExternal(clockIsExternal);
      setId(id);
    }


    GetModulationTargetResultPtr GetModulationTargetResult::create(const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id)
    {
      return std::make_shared<GetModulationTargetResult>(type, path, address, clockIsExternal, id);
    }

    GetModulationTargetResultPtr GetModulationTargetResult::create(CommandBasePtr relatedCommand, const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id)
    {
      return std::make_shared<GetModulationTargetResult>(relatedCommand, type, path, address, clockIsExternal, id);
    }

    GetModulationTargetResultPtr GetModulationTargetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetModulationTargetResult>(ptr);
    }

    bool GetModulationTargetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<std::string>::is_valid(m_values["Address"])
          && parse_json<bool>::is_valid(m_values["ClockIsExternal"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetModulationTargetResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetModulationTargetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Type", "Path", "Address", "ClockIsExternal", "Id"}; 
      return names; 
    }


    std::string GetModulationTargetResult::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void GetModulationTargetResult::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetModulationTargetResult::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void GetModulationTargetResult::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetModulationTargetResult::address() const
    {
      return parse_json<std::string>::parse(m_values["Address"]);
    }

    void GetModulationTargetResult::setAddress(const std::string& address)
    {
      m_values.AddMember("Address", parse_json<std::string>::format(address, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetModulationTargetResult::clockIsExternal() const
    {
      return parse_json<bool>::parse(m_values["ClockIsExternal"]);
    }

    void GetModulationTargetResult::setClockIsExternal(bool clockIsExternal)
    {
      m_values.AddMember("ClockIsExternal", parse_json<bool>::format(clockIsExternal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetModulationTargetResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetModulationTargetResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
