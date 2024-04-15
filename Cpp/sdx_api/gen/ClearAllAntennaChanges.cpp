
#include "ClearAllAntennaChanges.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllAntennaChanges
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllAntennaChanges::CmdName = "ClearAllAntennaChanges";
    const char* const ClearAllAntennaChanges::Documentation = "Clear all antenna changes.";
    const char* const ClearAllAntennaChanges::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ClearAllAntennaChanges);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ClearAllAntennaChanges);


    ClearAllAntennaChanges::ClearAllAntennaChanges()
      : CommandBase(CmdName, TargetId)
    {

    }

    ClearAllAntennaChangesPtr ClearAllAntennaChanges::create()
    {
      return std::make_shared<ClearAllAntennaChanges>();
    }

    ClearAllAntennaChangesPtr ClearAllAntennaChanges::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllAntennaChanges>(ptr);
    }

    bool ClearAllAntennaChanges::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAllAntennaChanges::documentation() const { return Documentation; }

    const std::vector<std::string>& ClearAllAntennaChanges::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int ClearAllAntennaChanges::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
