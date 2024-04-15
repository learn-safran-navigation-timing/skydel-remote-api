
#include "ClearQzssL1SAugmentations.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearQzssL1SAugmentations
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearQzssL1SAugmentations::CmdName = "ClearQzssL1SAugmentations";
    const char* const ClearQzssL1SAugmentations::Documentation = "Clears all QZSS L1S augmentations.";
    const char* const ClearQzssL1SAugmentations::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ClearQzssL1SAugmentations);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ClearQzssL1SAugmentations);


    ClearQzssL1SAugmentations::ClearQzssL1SAugmentations()
      : CommandBase(CmdName, TargetId)
    {

    }

    ClearQzssL1SAugmentationsPtr ClearQzssL1SAugmentations::create()
    {
      return std::make_shared<ClearQzssL1SAugmentations>();
    }

    ClearQzssL1SAugmentationsPtr ClearQzssL1SAugmentations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearQzssL1SAugmentations>(ptr);
    }

    bool ClearQzssL1SAugmentations::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearQzssL1SAugmentations::documentation() const { return Documentation; }

    const std::vector<std::string>& ClearQzssL1SAugmentations::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int ClearQzssL1SAugmentations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
