
#include "gen/ClearQzssL1SAugmentations.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(ClearQzssL1SAugmentations);


    ClearQzssL1SAugmentations::ClearQzssL1SAugmentations()
      : CommandBase(CmdName)
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


    int ClearQzssL1SAugmentations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
