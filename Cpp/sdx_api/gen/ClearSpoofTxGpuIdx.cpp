
#include "ClearSpoofTxGpuIdx.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearSpoofTxGpuIdx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearSpoofTxGpuIdx::CmdName = "ClearSpoofTxGpuIdx";
    const char* const ClearSpoofTxGpuIdx::Documentation = "Reset the spoofer's signal GPU index to default.\n"
      "\n"
      "Name     Type   Description\n"
      "-------- ------ -------------------------------\n"
      "SignalId int    Spoofer output number, 0-based.\n"
      "Id       string Transmitter unique identifier.";
    const char* const ClearSpoofTxGpuIdx::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ClearSpoofTxGpuIdx);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ClearSpoofTxGpuIdx);


    ClearSpoofTxGpuIdx::ClearSpoofTxGpuIdx()
      : CommandBase(CmdName, TargetId)
    {}

    ClearSpoofTxGpuIdx::ClearSpoofTxGpuIdx(int signalId, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setSignalId(signalId);
      setId(id);
    }

    ClearSpoofTxGpuIdxPtr ClearSpoofTxGpuIdx::create(int signalId, const std::string& id)
    {
      return std::make_shared<ClearSpoofTxGpuIdx>(signalId, id);
    }

    ClearSpoofTxGpuIdxPtr ClearSpoofTxGpuIdx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearSpoofTxGpuIdx>(ptr);
    }

    bool ClearSpoofTxGpuIdx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SignalId"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string ClearSpoofTxGpuIdx::documentation() const { return Documentation; }

    const std::vector<std::string>& ClearSpoofTxGpuIdx::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalId", "Id"}; 
      return names; 
    }


    int ClearSpoofTxGpuIdx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int ClearSpoofTxGpuIdx::signalId() const
    {
      return parse_json<int>::parse(m_values["SignalId"]);
    }

    void ClearSpoofTxGpuIdx::setSignalId(int signalId)
    {
      m_values.AddMember("SignalId", parse_json<int>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ClearSpoofTxGpuIdx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ClearSpoofTxGpuIdx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
