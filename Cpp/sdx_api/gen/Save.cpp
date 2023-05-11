
#include "gen/Save.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of Save
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const Save::CmdName = "Save";
    const char* const Save::Documentation = "Save configuration.";

    REGISTER_COMMAND_FACTORY(Save);


    Save::Save()
      : CommandBase(CmdName)
    {

    }

    SavePtr Save::create()
    {
      return std::make_shared<Save>();
    }

    SavePtr Save::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<Save>(ptr);
    }

    bool Save::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string Save::documentation() const { return Documentation; }


    int Save::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
