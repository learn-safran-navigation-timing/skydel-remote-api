
#include "RemoveSignalFromIntTx.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveSignalFromIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveSignalFromIntTx::CmdName = "RemoveSignalFromIntTx";
    const char* const RemoveSignalFromIntTx::Documentation = "Removes the specified signal from the interference transmitter.\n"
      "\n"
      "Name          Type   Description\n"
      "------------- ------ ------------------------------\n"
      "TransmitterId string Transmitter unique identifier.\n"
      "SignalId      string Signal unique identifier.";
    const char* const RemoveSignalFromIntTx::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveSignalFromIntTx);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveSignalFromIntTx);


    RemoveSignalFromIntTx::RemoveSignalFromIntTx()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveSignalFromIntTx::RemoveSignalFromIntTx(const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName, TargetId)
    {

      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    RemoveSignalFromIntTxPtr RemoveSignalFromIntTx::create(const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<RemoveSignalFromIntTx>(transmitterId, signalId);
    }

    RemoveSignalFromIntTxPtr RemoveSignalFromIntTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveSignalFromIntTx>(ptr);
    }

    bool RemoveSignalFromIntTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string RemoveSignalFromIntTx::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveSignalFromIntTx::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TransmitterId", "SignalId"}; 
      return names; 
    }


    int RemoveSignalFromIntTx::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string RemoveSignalFromIntTx::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void RemoveSignalFromIntTx::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RemoveSignalFromIntTx::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void RemoveSignalFromIntTx::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
