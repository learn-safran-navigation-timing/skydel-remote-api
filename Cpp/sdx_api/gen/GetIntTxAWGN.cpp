
#include "gen/GetIntTxAWGN.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxAWGN
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxAWGN::CmdName = "GetIntTxAWGN";
    const char* const GetIntTxAWGN::Documentation = "Get AWGN signal interference.";

    REGISTER_COMMAND_FACTORY(GetIntTxAWGN);


    GetIntTxAWGN::GetIntTxAWGN()
      : CommandBase(CmdName)
    {}

    GetIntTxAWGN::GetIntTxAWGN(const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName)
    {

      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetIntTxAWGNPtr GetIntTxAWGN::create(const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetIntTxAWGN>(transmitterId, signalId);
    }

    GetIntTxAWGNPtr GetIntTxAWGN::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxAWGN>(ptr);
    }

    bool GetIntTxAWGN::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetIntTxAWGN::documentation() const { return Documentation; }


    int GetIntTxAWGN::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxAWGN::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxAWGN::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxAWGN::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxAWGN::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
