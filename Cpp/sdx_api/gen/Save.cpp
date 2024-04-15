
#include "Save.h"

#include "command_factory.h"
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
    const char* const Save::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(Save);
    REGISTER_COMMAND_TO_FACTORY_IMPL(Save);


    Save::Save()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& Save::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int Save::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
