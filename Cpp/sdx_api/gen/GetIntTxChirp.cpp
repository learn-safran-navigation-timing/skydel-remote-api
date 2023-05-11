
#include "gen/GetIntTxChirp.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxChirp
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxChirp::CmdName = "GetIntTxChirp";
    const char* const GetIntTxChirp::Documentation = "Get informations about the Chirp signal of the transmitter.";

    REGISTER_COMMAND_FACTORY(GetIntTxChirp);


    GetIntTxChirp::GetIntTxChirp()
      : CommandBase(CmdName)
    {}

    GetIntTxChirp::GetIntTxChirp(const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName)
    {

      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetIntTxChirpPtr GetIntTxChirp::create(const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetIntTxChirp>(transmitterId, signalId);
    }

    GetIntTxChirpPtr GetIntTxChirp::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxChirp>(ptr);
    }

    bool GetIntTxChirp::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetIntTxChirp::documentation() const { return Documentation; }


    int GetIntTxChirp::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxChirp::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxChirp::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxChirp::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxChirp::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
