
#include "RemoveAllMultipathForSignal.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllMultipathForSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllMultipathForSignal::CmdName = "RemoveAllMultipathForSignal";
    const char* const RemoveAllMultipathForSignal::Documentation = "Disable all multipath in all satellites but only for the specified signal.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"NAVICL5\", \"PULSARXL\"\n"
      "Reset  bool   Reset attributes (PSR offset, power loss, Doppler shift and carrier phase offset are set to zero)";
    const char* const RemoveAllMultipathForSignal::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveAllMultipathForSignal);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveAllMultipathForSignal);


    RemoveAllMultipathForSignal::RemoveAllMultipathForSignal()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveAllMultipathForSignal::RemoveAllMultipathForSignal(const std::string& signal, bool reset)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setReset(reset);
    }

    RemoveAllMultipathForSignalPtr RemoveAllMultipathForSignal::create(const std::string& signal, bool reset)
    {
      return std::make_shared<RemoveAllMultipathForSignal>(signal, reset);
    }

    RemoveAllMultipathForSignalPtr RemoveAllMultipathForSignal::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllMultipathForSignal>(ptr);
    }

    bool RemoveAllMultipathForSignal::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["Reset"])
        ;

    }

    std::string RemoveAllMultipathForSignal::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveAllMultipathForSignal::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Reset"}; 
      return names; 
    }


    int RemoveAllMultipathForSignal::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveAllMultipathForSignal::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void RemoveAllMultipathForSignal::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool RemoveAllMultipathForSignal::reset() const
    {
      return parse_json<bool>::parse(m_values["Reset"]);
    }

    void RemoveAllMultipathForSignal::setReset(bool reset)
    {
      m_values.AddMember("Reset", parse_json<bool>::format(reset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
