
#include "EnableIntTxSignal.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableIntTxSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableIntTxSignal::CmdName = "EnableIntTxSignal";
    const char* const EnableIntTxSignal::Documentation = "Change whether a signal is enabled or disabled\n"
      "\n"
      "Name          Type   Description\n"
      "------------- ------ ------------------------------------\n"
      "Enabled       bool   Whether the signal is enabled or not\n"
      "TransmitterId string Transmitter unique identifier.\n"
      "SignalId      string CW unique identifier.";
    const char* const EnableIntTxSignal::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableIntTxSignal);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableIntTxSignal);


    EnableIntTxSignal::EnableIntTxSignal()
      : CommandBase(CmdName, TargetId)
    {}

    EnableIntTxSignal::EnableIntTxSignal(bool enabled, const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    EnableIntTxSignalPtr EnableIntTxSignal::create(bool enabled, const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<EnableIntTxSignal>(enabled, transmitterId, signalId);
    }

    EnableIntTxSignalPtr EnableIntTxSignal::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableIntTxSignal>(ptr);
    }

    bool EnableIntTxSignal::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string EnableIntTxSignal::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableIntTxSignal::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "TransmitterId", "SignalId"}; 
      return names; 
    }


    int EnableIntTxSignal::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool EnableIntTxSignal::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableIntTxSignal::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string EnableIntTxSignal::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void EnableIntTxSignal::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string EnableIntTxSignal::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void EnableIntTxSignal::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
