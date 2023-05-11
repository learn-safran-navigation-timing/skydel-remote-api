
#include "gen/RemoveAllSignalsFromIntTx.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllSignalsFromIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllSignalsFromIntTx::CmdName = "RemoveAllSignalsFromIntTx";
    const char* const RemoveAllSignalsFromIntTx::Documentation = "Removes all signals from the interference transmitter.";

    REGISTER_COMMAND_FACTORY(RemoveAllSignalsFromIntTx);


    RemoveAllSignalsFromIntTx::RemoveAllSignalsFromIntTx()
      : CommandBase(CmdName)
    {}

    RemoveAllSignalsFromIntTx::RemoveAllSignalsFromIntTx(const std::string& transmitterId)
      : CommandBase(CmdName)
    {

      setTransmitterId(transmitterId);
    }

    RemoveAllSignalsFromIntTxPtr RemoveAllSignalsFromIntTx::create(const std::string& transmitterId)
    {
      return std::make_shared<RemoveAllSignalsFromIntTx>(transmitterId);
    }

    RemoveAllSignalsFromIntTxPtr RemoveAllSignalsFromIntTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllSignalsFromIntTx>(ptr);
    }

    bool RemoveAllSignalsFromIntTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
        ;

    }

    std::string RemoveAllSignalsFromIntTx::documentation() const { return Documentation; }


    int RemoveAllSignalsFromIntTx::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string RemoveAllSignalsFromIntTx::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void RemoveAllSignalsFromIntTx::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
