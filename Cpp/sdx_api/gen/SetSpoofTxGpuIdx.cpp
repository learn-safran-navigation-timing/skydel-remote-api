
#include "gen/SetSpoofTxGpuIdx.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxGpuIdx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxGpuIdx::CmdName = "SetSpoofTxGpuIdx";
    const char* const SetSpoofTxGpuIdx::Documentation = "Set the GPU index on which this spoofer signal will be modulated.";

    REGISTER_COMMAND_FACTORY(SetSpoofTxGpuIdx);


    SetSpoofTxGpuIdx::SetSpoofTxGpuIdx()
      : CommandBase(CmdName)
    {}

    SetSpoofTxGpuIdx::SetSpoofTxGpuIdx(int gpuIdx, int signalId, const std::string& id)
      : CommandBase(CmdName)
    {

      setGpuIdx(gpuIdx);
      setSignalId(signalId);
      setId(id);
    }

    SetSpoofTxGpuIdxPtr SetSpoofTxGpuIdx::create(int gpuIdx, int signalId, const std::string& id)
    {
      return std::make_shared<SetSpoofTxGpuIdx>(gpuIdx, signalId, id);
    }

    SetSpoofTxGpuIdxPtr SetSpoofTxGpuIdx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxGpuIdx>(ptr);
    }

    bool SetSpoofTxGpuIdx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["GpuIdx"])
          && parse_json<int>::is_valid(m_values["SignalId"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetSpoofTxGpuIdx::documentation() const { return Documentation; }


    int SetSpoofTxGpuIdx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetSpoofTxGpuIdx::gpuIdx() const
    {
      return parse_json<int>::parse(m_values["GpuIdx"]);
    }

    void SetSpoofTxGpuIdx::setGpuIdx(int gpuIdx)
    {
      m_values.AddMember("GpuIdx", parse_json<int>::format(gpuIdx, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSpoofTxGpuIdx::signalId() const
    {
      return parse_json<int>::parse(m_values["SignalId"]);
    }

    void SetSpoofTxGpuIdx::setSignalId(int signalId)
    {
      m_values.AddMember("SignalId", parse_json<int>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofTxGpuIdx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxGpuIdx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
