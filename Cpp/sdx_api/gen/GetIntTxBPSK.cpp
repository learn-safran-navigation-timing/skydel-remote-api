
#include "GetIntTxBPSK.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxBPSK
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxBPSK::CmdName = "GetIntTxBPSK";
    const char* const GetIntTxBPSK::Documentation = "Get BPSK signal interference.\n"
      "\n"
      "Name          Type   Description\n"
      "------------- ------ ------------------------------\n"
      "TransmitterId string Transmitter unique identifier.\n"
      "SignalId      string BPSK unique identifier.";
    const char* const GetIntTxBPSK::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxBPSK);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxBPSK);


    GetIntTxBPSK::GetIntTxBPSK()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxBPSK::GetIntTxBPSK(const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName, TargetId)
    {

      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetIntTxBPSKPtr GetIntTxBPSK::create(const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetIntTxBPSK>(transmitterId, signalId);
    }

    GetIntTxBPSKPtr GetIntTxBPSK::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxBPSK>(ptr);
    }

    bool GetIntTxBPSK::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetIntTxBPSK::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxBPSK::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TransmitterId", "SignalId"}; 
      return names; 
    }


    int GetIntTxBPSK::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxBPSK::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxBPSK::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxBPSK::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxBPSK::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
