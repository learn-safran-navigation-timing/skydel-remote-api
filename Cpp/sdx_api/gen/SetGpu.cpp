
#include "gen/SetGpu.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpu
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpu::CmdName = "SetGpu";
    const char* const SetGpu::Documentation = "Set the GPU associated with a RF output of a modulation target.";

    REGISTER_COMMAND_FACTORY(SetGpu);


    SetGpu::SetGpu()
      : CommandBase(CmdName)
    {}

    SetGpu::SetGpu(int gpuIdx, int output, const std::string& id)
      : CommandBase(CmdName)
    {

      setGpuIdx(gpuIdx);
      setOutput(output);
      setId(id);
    }

    SetGpuPtr SetGpu::create(int gpuIdx, int output, const std::string& id)
    {
      return std::make_shared<SetGpu>(gpuIdx, output, id);
    }

    SetGpuPtr SetGpu::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpu>(ptr);
    }

    bool SetGpu::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["GpuIdx"])
          && parse_json<int>::is_valid(m_values["Output"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetGpu::documentation() const { return Documentation; }


    int SetGpu::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGpu::gpuIdx() const
    {
      return parse_json<int>::parse(m_values["GpuIdx"]);
    }

    void SetGpu::setGpuIdx(int gpuIdx)
    {
      m_values.AddMember("GpuIdx", parse_json<int>::format(gpuIdx, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGpu::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void SetGpu::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetGpu::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetGpu::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
