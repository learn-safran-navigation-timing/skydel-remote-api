
#include "GetModulationTargetInterferences.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetModulationTargetInterferences
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetModulationTargetInterferences::CmdName = "GetModulationTargetInterferences";
    const char* const GetModulationTargetInterferences::Documentation = "Get the specified target and output index to a group of interferences.\n"
      "An interference transmitter is mapped to a specific RF output by using the same Interference Group Number.\n"
      "Skydel tries to keep the sampling rate as low as possible,\n"
      "but it is possible to set constaints with MinRate and MaxRate.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------\n"
      "Output int    Output index (zero based)\n"
      "Id     string Target identifier";
    const char* const GetModulationTargetInterferences::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetModulationTargetInterferences);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetModulationTargetInterferences);


    GetModulationTargetInterferences::GetModulationTargetInterferences()
      : CommandBase(CmdName, TargetId)
    {}

    GetModulationTargetInterferences::GetModulationTargetInterferences(int output, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setOutput(output);
      setId(id);
    }

    GetModulationTargetInterferencesPtr GetModulationTargetInterferences::create(int output, const std::string& id)
    {
      return std::make_shared<GetModulationTargetInterferences>(output, id);
    }

    GetModulationTargetInterferencesPtr GetModulationTargetInterferences::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetModulationTargetInterferences>(ptr);
    }

    bool GetModulationTargetInterferences::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Output"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetModulationTargetInterferences::documentation() const { return Documentation; }

    const std::vector<std::string>& GetModulationTargetInterferences::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Output", "Id"}; 
      return names; 
    }


    int GetModulationTargetInterferences::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetModulationTargetInterferences::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void GetModulationTargetInterferences::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetModulationTargetInterferences::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetModulationTargetInterferences::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
