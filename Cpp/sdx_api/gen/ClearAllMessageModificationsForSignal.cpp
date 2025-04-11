
#include "ClearAllMessageModificationsForSignal.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllMessageModificationsForSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllMessageModificationsForSignal::CmdName = "ClearAllMessageModificationsForSignal";
    const char* const ClearAllMessageModificationsForSignal::Documentation = "Clear the signal for all message modifications.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ---------------------------------------------------------------------------------------------------------\n"
      "Signal string Signal key, accepted values : \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                            \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B2a\", \"B1C\", \"B3I\",\n"
      "                                            \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1S\", \"NAVICL5\", \"NAVICS\", \"SBASL1\", \"SBASL5\",\n"
      "                                            \"PULSARXL\", \"PULSARX1\" and \"PULSARX5\"";
    const char* const ClearAllMessageModificationsForSignal::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ClearAllMessageModificationsForSignal);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ClearAllMessageModificationsForSignal);


    ClearAllMessageModificationsForSignal::ClearAllMessageModificationsForSignal()
      : CommandBase(CmdName, TargetId)
    {}

    ClearAllMessageModificationsForSignal::ClearAllMessageModificationsForSignal(const std::string& signal)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
    }

    ClearAllMessageModificationsForSignalPtr ClearAllMessageModificationsForSignal::create(const std::string& signal)
    {
      return std::make_shared<ClearAllMessageModificationsForSignal>(signal);
    }

    ClearAllMessageModificationsForSignalPtr ClearAllMessageModificationsForSignal::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllMessageModificationsForSignal>(ptr);
    }

    bool ClearAllMessageModificationsForSignal::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string ClearAllMessageModificationsForSignal::documentation() const { return Documentation; }

    const std::vector<std::string>& ClearAllMessageModificationsForSignal::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal"}; 
      return names; 
    }


    int ClearAllMessageModificationsForSignal::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ClearAllMessageModificationsForSignal::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void ClearAllMessageModificationsForSignal::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
