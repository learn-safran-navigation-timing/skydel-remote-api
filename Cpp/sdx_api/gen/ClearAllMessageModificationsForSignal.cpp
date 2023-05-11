
#include "gen/ClearAllMessageModificationsForSignal.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllMessageModificationsForSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllMessageModificationsForSignal::CmdName = "ClearAllMessageModificationsForSignal";
    const char* const ClearAllMessageModificationsForSignal::Documentation = "Clear the signal for all message modifications.";

    REGISTER_COMMAND_FACTORY(ClearAllMessageModificationsForSignal);


    ClearAllMessageModificationsForSignal::ClearAllMessageModificationsForSignal()
      : CommandBase(CmdName)
    {}

    ClearAllMessageModificationsForSignal::ClearAllMessageModificationsForSignal(const std::string& signal)
      : CommandBase(CmdName)
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
