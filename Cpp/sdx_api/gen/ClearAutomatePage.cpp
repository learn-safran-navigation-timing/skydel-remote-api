
#include "ClearAutomatePage.h"

#include "command_factory.h"
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
    const char* const ClearAutomatePage::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ClearAutomatePage);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ClearAutomatePage);


    ClearAutomatePage::ClearAutomatePage()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& ClearAutomatePage::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int ClearAutomatePage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
