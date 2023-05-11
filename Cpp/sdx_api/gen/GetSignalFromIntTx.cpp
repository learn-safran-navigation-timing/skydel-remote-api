
#include "gen/GetSignalFromIntTx.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSignalFromIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSignalFromIntTx::CmdName = "GetSignalFromIntTx";
    const char* const GetSignalFromIntTx::Documentation = "Get all signal ID from this interference transmitters and this signal type. If the signal type is invalid, get the IDs of CW type.";

    REGISTER_COMMAND_FACTORY(GetSignalFromIntTx);


    GetSignalFromIntTx::GetSignalFromIntTx()
      : CommandBase(CmdName)
    {}

    GetSignalFromIntTx::GetSignalFromIntTx(const std::string& idTransmitter, const std::string& signalType)
      : CommandBase(CmdName)
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
