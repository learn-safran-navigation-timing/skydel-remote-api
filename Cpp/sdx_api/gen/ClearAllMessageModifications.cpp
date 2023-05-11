
#include "gen/ClearAllMessageModifications.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllMessageModifications
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllMessageModifications::CmdName = "ClearAllMessageModifications";
    const char* const ClearAllMessageModifications::Documentation = "Please note the command ClearAllMessageModifications is deprecated since 21.3. You may use ClearAllMessageModificationsForSignal.\n\nClear the signal for all message modifications.";

    REGISTER_COMMAND_FACTORY(ClearAllMessageModifications);


    ClearAllMessageModifications::ClearAllMessageModifications()
      : CommandBase(CmdName)
    {}

    ClearAllMessageModifications::ClearAllMessageModifications(const std::string& signal)
      : CommandBase(CmdName)
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
