
#include "GetGpu.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpu
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpu::CmdName = "GetGpu";
    const char* const GetGpu::Documentation = "Get the GPU associated with a RF output of a modulation target.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------\n"
      "Output int    Output index (zero based)\n"
      "Id     string Target identifier";
    const char* const GetGpu::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpu);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpu);


    GetGpu::GetGpu()
      : CommandBase(CmdName, TargetId)
    {}

    GetGpu::GetGpu(int output, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setOutput(output);
      setId(id);
    }

    GetGpuPtr GetGpu::create(int output, const std::string& id)
    {
      return std::make_shared<GetGpu>(output, id);
    }

    GetGpuPtr GetGpu::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpu>(ptr);
    }

    bool GetGpu::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Output"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGpu::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpu::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Output", "Id"}; 
      return names; 
    }


    int GetGpu::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpu::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void GetGpu::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpu::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGpu::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
