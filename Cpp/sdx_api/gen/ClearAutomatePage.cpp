
#include "gen/ClearAutomatePage.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAutomatePage
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAutomatePage::CmdName = "ClearAutomatePage";
    const char* const ClearAutomatePage::Documentation = "Clear automate page.";

    REGISTER_COMMAND_FACTORY(ClearAutomatePage);


    ClearAutomatePage::ClearAutomatePage()
      : CommandBase(CmdName)
    {

    }

    ClearAutomatePagePtr ClearAutomatePage::create()
    {
      return std::make_shared<ClearAutomatePage>();
    }

    ClearAutomatePagePtr ClearAutomatePage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAutomatePage>(ptr);
    }

    bool ClearAutomatePage::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAutomatePage::documentation() const { return Documentation; }


    int ClearAutomatePage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
