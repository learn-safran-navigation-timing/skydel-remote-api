
#include "GetSignalFromIntTx.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSignalFromIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSignalFromIntTx::CmdName = "GetSignalFromIntTx";
    const char* const GetSignalFromIntTx::Documentation = "Get all signal ID from this interference transmitters and this signal type. If the signal type is invalid, get the IDs of CW type.\n"
      "\n"
      "Name          Type   Description\n"
      "------------- ------ ------------------------------------------------------------------------------------\n"
      "IdTransmitter string Transmitter unique identifier.\n"
      "SignalType    string Type of signal. Accepted signals are : \"CW\", \"Chirp\", \"Pulse\", \"BPSK\", \"BOC\", \"AWGN\"";
    const char* const GetSignalFromIntTx::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSignalFromIntTx);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSignalFromIntTx);


    GetSignalFromIntTx::GetSignalFromIntTx()
      : CommandBase(CmdName, TargetId)
    {}

    GetSignalFromIntTx::GetSignalFromIntTx(const std::string& idTransmitter, const std::string& signalType)
      : CommandBase(CmdName, TargetId)
    {

      setIdTransmitter(idTransmitter);
      setSignalType(signalType);
    }

    GetSignalFromIntTxPtr GetSignalFromIntTx::create(const std::string& idTransmitter, const std::string& signalType)
    {
      return std::make_shared<GetSignalFromIntTx>(idTransmitter, signalType);
    }

    GetSignalFromIntTxPtr GetSignalFromIntTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSignalFromIntTx>(ptr);
    }

    bool GetSignalFromIntTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["IdTransmitter"])
          && parse_json<std::string>::is_valid(m_values["SignalType"])
        ;

    }

    std::string GetSignalFromIntTx::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSignalFromIntTx::fieldNames() const 
    { 
      static const std::vector<std::string> names {"IdTransmitter", "SignalType"}; 
      return names; 
    }


    int GetSignalFromIntTx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSignalFromIntTx::idTransmitter() const
    {
      return parse_json<std::string>::parse(m_values["IdTransmitter"]);
    }

    void GetSignalFromIntTx::setIdTransmitter(const std::string& idTransmitter)
    {
      m_values.AddMember("IdTransmitter", parse_json<std::string>::format(idTransmitter, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSignalFromIntTx::signalType() const
    {
      return parse_json<std::string>::parse(m_values["SignalType"]);
    }

    void GetSignalFromIntTx::setSignalType(const std::string& signalType)
    {
      m_values.AddMember("SignalType", parse_json<std::string>::format(signalType, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
