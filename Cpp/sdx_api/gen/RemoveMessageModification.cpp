
#include "RemoveMessageModification.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveMessageModification
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveMessageModification::CmdName = "RemoveMessageModification";
    const char* const RemoveMessageModification::Documentation = "Please note the command RemoveMessageModification is deprecated since 21.3. You may use RemoveMessageModificationForSignal.\n"
      "\n"
      "Removes the signal for the message modification.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ---------------------------------------------------------------------------------------------------------\n"
      "Signal string Signal key, accepted values : \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                            \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B2a\", \"B1C\", \"B3I\",\n"
      "                                            \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1S\", \"NAVICL5\", \"NAVICS\", \"SBASL1\", \"SBASL5\",\n"
      "                                            \"PULSARXL\" and \"PULSARX1\"\n"
      "Id     string Unique identifier";
    const char* const RemoveMessageModification::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveMessageModification);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveMessageModification);


    RemoveMessageModification::RemoveMessageModification()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveMessageModification::RemoveMessageModification(const std::string& signal, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setId(id);
    }

    RemoveMessageModificationPtr RemoveMessageModification::create(const std::string& signal, const std::string& id)
    {
      return std::make_shared<RemoveMessageModification>(signal, id);
    }

    RemoveMessageModificationPtr RemoveMessageModification::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveMessageModification>(ptr);
    }

    bool RemoveMessageModification::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveMessageModification::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveMessageModification::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Id"}; 
      return names; 
    }


    int RemoveMessageModification::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveMessageModification::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void RemoveMessageModification::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RemoveMessageModification::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveMessageModification::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
