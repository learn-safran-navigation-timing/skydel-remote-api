
#include "ClearAllMessageModifications.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllMessageModifications
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllMessageModifications::CmdName = "ClearAllMessageModifications";
    const char* const ClearAllMessageModifications::Documentation = "Please note the command ClearAllMessageModifications is deprecated since 21.3. You may use ClearAllMessageModificationsForSignal.\n"
      "\n"
      "Clear the signal for all message modifications.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ---------------------------------------------------------------------------------------------------------\n"
      "Signal string Signal key, accepted values : \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                            \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B2a\", \"B1C\", \"B3I\",\n"
      "                                            \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1S\", \"NAVICL5\", \"NAVICS\", \"SBASL1\", \"SBASL5\",\n"
      "                                            \"PULSARXL\", \"PULSARX1\" and \"PULSARX5\"";
    const char* const ClearAllMessageModifications::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ClearAllMessageModifications);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ClearAllMessageModifications);


    ClearAllMessageModifications::ClearAllMessageModifications()
      : CommandBase(CmdName, TargetId)
    {}

    ClearAllMessageModifications::ClearAllMessageModifications(const std::string& signal)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
    }

    ClearAllMessageModificationsPtr ClearAllMessageModifications::create(const std::string& signal)
    {
      return std::make_shared<ClearAllMessageModifications>(signal);
    }

    ClearAllMessageModificationsPtr ClearAllMessageModifications::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllMessageModifications>(ptr);
    }

    bool ClearAllMessageModifications::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string ClearAllMessageModifications::documentation() const { return Documentation; }

    const std::vector<std::string>& ClearAllMessageModifications::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal"}; 
      return names; 
    }


    int ClearAllMessageModifications::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ClearAllMessageModifications::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void ClearAllMessageModifications::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
