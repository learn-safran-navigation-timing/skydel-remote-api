
#include "GetQzssL1SAugmentations.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1SAugmentations
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1SAugmentations::CmdName = "GetQzssL1SAugmentations";
    const char* const GetQzssL1SAugmentations::Documentation = "Get all QZSS L1S augmentation's IDs.";
    const char* const GetQzssL1SAugmentations::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssL1SAugmentations);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssL1SAugmentations);


    GetQzssL1SAugmentations::GetQzssL1SAugmentations()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetQzssL1SAugmentationsPtr GetQzssL1SAugmentations::create()
    {
      return std::make_shared<GetQzssL1SAugmentations>();
    }

    GetQzssL1SAugmentationsPtr GetQzssL1SAugmentations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1SAugmentations>(ptr);
    }

    bool GetQzssL1SAugmentations::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetQzssL1SAugmentations::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssL1SAugmentations::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetQzssL1SAugmentations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
