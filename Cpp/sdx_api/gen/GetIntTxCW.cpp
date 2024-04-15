
#include "GetIntTxCW.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxCW
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxCW::CmdName = "GetIntTxCW";
    const char* const GetIntTxCW::Documentation = "Get informations about the CW signal of the transmitter.\n"
      "\n"
      "Name          Type   Description\n"
      "------------- ------ ------------------------------\n"
      "TransmitterId string Transmitter unique identifier.\n"
      "SignalId      string CW unique identifier.";
    const char* const GetIntTxCW::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxCW);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxCW);


    GetIntTxCW::GetIntTxCW()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxCW::GetIntTxCW(const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName, TargetId)
    {

      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetIntTxCWPtr GetIntTxCW::create(const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetIntTxCW>(transmitterId, signalId);
    }

    GetIntTxCWPtr GetIntTxCW::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxCW>(ptr);
    }

    bool GetIntTxCW::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetIntTxCW::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxCW::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TransmitterId", "SignalId"}; 
      return names; 
    }


    int GetIntTxCW::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxCW::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxCW::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxCW::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxCW::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
