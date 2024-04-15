
#include "IsDektecAdjustedNoiseEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsDektecAdjustedNoiseEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsDektecAdjustedNoiseEnabled::CmdName = "IsDektecAdjustedNoiseEnabled";
    const char* const IsDektecAdjustedNoiseEnabled::Documentation = "Indicates if noise level adjustment for Advanced Jammers on Dektec is enabled.";
    const char* const IsDektecAdjustedNoiseEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsDektecAdjustedNoiseEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsDektecAdjustedNoiseEnabled);


    IsDektecAdjustedNoiseEnabled::IsDektecAdjustedNoiseEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsDektecAdjustedNoiseEnabledPtr IsDektecAdjustedNoiseEnabled::create()
    {
      return std::make_shared<IsDektecAdjustedNoiseEnabled>();
    }

    IsDektecAdjustedNoiseEnabledPtr IsDektecAdjustedNoiseEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsDektecAdjustedNoiseEnabled>(ptr);
    }

    bool IsDektecAdjustedNoiseEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsDektecAdjustedNoiseEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsDektecAdjustedNoiseEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsDektecAdjustedNoiseEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
