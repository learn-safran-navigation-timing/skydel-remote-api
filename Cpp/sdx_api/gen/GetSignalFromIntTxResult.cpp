
#include "GetSignalFromIntTxResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSignalFromIntTxResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSignalFromIntTxResult::CmdName = "GetSignalFromIntTxResult";
    const char* const GetSignalFromIntTxResult::Documentation = "Result of GetSignalFromIntTx.\n"
      "\n"
      "Name          Type         Description\n"
      "------------- ------------ ------------------------------------------------------------------------------------\n"
      "IdTransmitter string       Transmitter unique identifier.\n"
      "SignalType    string       Type of signal. Accepted signals are : \"CW\", \"Chirp\", \"Pulse\", \"BPSK\", \"BOC\", \"AWGN\"\n"
      "IdsSignal     array string List of signal ID for this interferences transmitter and this signal type.";
    const char* const GetSignalFromIntTxResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSignalFromIntTxResult);


    GetSignalFromIntTxResult::GetSignalFromIntTxResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSignalFromIntTxResult::GetSignalFromIntTxResult(const std::string& idTransmitter, const std::string& signalType, const std::vector<std::string>& idsSignal)
      : CommandResult(CmdName, TargetId)
    {

      setIdTransmitter(idTransmitter);
      setSignalType(signalType);
      setIdsSignal(idsSignal);
    }

    GetSignalFromIntTxResult::GetSignalFromIntTxResult(CommandBasePtr relatedCommand, const std::string& idTransmitter, const std::string& signalType, const std::vector<std::string>& idsSignal)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIdTransmitter(idTransmitter);
      setSignalType(signalType);
      setIdsSignal(idsSignal);
    }


    GetSignalFromIntTxResultPtr GetSignalFromIntTxResult::create(const std::string& idTransmitter, const std::string& signalType, const std::vector<std::string>& idsSignal)
    {
      return std::make_shared<GetSignalFromIntTxResult>(idTransmitter, signalType, idsSignal);
    }

    GetSignalFromIntTxResultPtr GetSignalFromIntTxResult::create(CommandBasePtr relatedCommand, const std::string& idTransmitter, const std::string& signalType, const std::vector<std::string>& idsSignal)
    {
      return std::make_shared<GetSignalFromIntTxResult>(relatedCommand, idTransmitter, signalType, idsSignal);
    }

    GetSignalFromIntTxResultPtr GetSignalFromIntTxResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSignalFromIntTxResult>(ptr);
    }

    bool GetSignalFromIntTxResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["IdTransmitter"])
          && parse_json<std::string>::is_valid(m_values["SignalType"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["IdsSignal"])
        ;

    }

    std::string GetSignalFromIntTxResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSignalFromIntTxResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"IdTransmitter", "SignalType", "IdsSignal"}; 
      return names; 
    }


    std::string GetSignalFromIntTxResult::idTransmitter() const
    {
      return parse_json<std::string>::parse(m_values["IdTransmitter"]);
    }

    void GetSignalFromIntTxResult::setIdTransmitter(const std::string& idTransmitter)
    {
      m_values.AddMember("IdTransmitter", parse_json<std::string>::format(idTransmitter, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSignalFromIntTxResult::signalType() const
    {
      return parse_json<std::string>::parse(m_values["SignalType"]);
    }

    void GetSignalFromIntTxResult::setSignalType(const std::string& signalType)
    {
      m_values.AddMember("SignalType", parse_json<std::string>::format(signalType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetSignalFromIntTxResult::idsSignal() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["IdsSignal"]);
    }

    void GetSignalFromIntTxResult::setIdsSignal(const std::vector<std::string>& idsSignal)
    {
      m_values.AddMember("IdsSignal", parse_json<std::vector<std::string>>::format(idsSignal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
