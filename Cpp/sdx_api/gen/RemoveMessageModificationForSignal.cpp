
#include "RemoveMessageModificationForSignal.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveMessageModificationForSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveMessageModificationForSignal::CmdName = "RemoveMessageModificationForSignal";
    const char* const RemoveMessageModificationForSignal::Documentation = "Removes the signal for the message modification.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Signal string Signal key, accepted values : \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B2a\", \"B1C\", \"B3I\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1S\", \"NAVICL5\", \"SBASL1\", \"SBASL5\" and \"PULSARXL\"\n"
      "Id     string Unique identifier";
    const char* const RemoveMessageModificationForSignal::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveMessageModificationForSignal);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveMessageModificationForSignal);


    RemoveMessageModificationForSignal::RemoveMessageModificationForSignal()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveMessageModificationForSignal::RemoveMessageModificationForSignal(const std::string& signal, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setId(id);
    }

    RemoveMessageModificationForSignalPtr RemoveMessageModificationForSignal::create(const std::string& signal, const std::string& id)
    {
      return std::make_shared<RemoveMessageModificationForSignal>(signal, id);
    }

    RemoveMessageModificationForSignalPtr RemoveMessageModificationForSignal::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveMessageModificationForSignal>(ptr);
    }

    bool RemoveMessageModificationForSignal::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveMessageModificationForSignal::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveMessageModificationForSignal::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Id"}; 
      return names; 
    }


    int RemoveMessageModificationForSignal::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveMessageModificationForSignal::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void RemoveMessageModificationForSignal::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RemoveMessageModificationForSignal::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveMessageModificationForSignal::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
