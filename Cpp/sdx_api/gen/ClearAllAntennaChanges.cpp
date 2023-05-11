
#include "gen/ClearAllAntennaChanges.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(ClearAllAntennaChanges);


    ClearAllAntennaChanges::ClearAllAntennaChanges()
      : CommandBase(CmdName)
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


    int ClearAllAntennaChanges::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
