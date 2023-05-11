
#include "gen/GetIntTxPulse.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxPulse
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxPulse::CmdName = "GetIntTxPulse";
    const char* const GetIntTxPulse::Documentation = "Get pulse signal interference.";

    REGISTER_COMMAND_FACTORY(GetIntTxPulse);


    GetIntTxPulse::GetIntTxPulse()
      : CommandBase(CmdName)
    {}

    GetIntTxPulse::GetIntTxPulse(const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName)
    {

      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetIntTxPulsePtr GetIntTxPulse::create(const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetIntTxPulse>(transmitterId, signalId);
    }

    GetIntTxPulsePtr GetIntTxPulse::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxPulse>(ptr);
    }

    bool GetIntTxPulse::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetIntTxPulse::documentation() const { return Documentation; }


    int GetIntTxPulse::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxPulse::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxPulse::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxPulse::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxPulse::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
