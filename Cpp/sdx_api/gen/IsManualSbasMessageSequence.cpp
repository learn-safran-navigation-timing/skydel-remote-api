
#include "IsManualSbasMessageSequence.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsManualSbasMessageSequence
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsManualSbasMessageSequence::CmdName = "IsManualSbasMessageSequence";
    const char* const IsManualSbasMessageSequence::Documentation = "Indicates whether a manually imported SBAS message sequence is being used.";
    const char* const IsManualSbasMessageSequence::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsManualSbasMessageSequence);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsManualSbasMessageSequence);


    IsManualSbasMessageSequence::IsManualSbasMessageSequence()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsManualSbasMessageSequencePtr IsManualSbasMessageSequence::create()
    {
      return std::make_shared<IsManualSbasMessageSequence>();
    }

    IsManualSbasMessageSequencePtr IsManualSbasMessageSequence::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsManualSbasMessageSequence>(ptr);
    }

    bool IsManualSbasMessageSequence::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsManualSbasMessageSequence::documentation() const { return Documentation; }

    const std::vector<std::string>& IsManualSbasMessageSequence::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsManualSbasMessageSequence::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
