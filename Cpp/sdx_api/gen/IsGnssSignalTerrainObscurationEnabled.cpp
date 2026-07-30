
#include "IsGnssSignalTerrainObscurationEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsGnssSignalTerrainObscurationEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsGnssSignalTerrainObscurationEnabled::CmdName = "IsGnssSignalTerrainObscurationEnabled";
    const char* const IsGnssSignalTerrainObscurationEnabled::Documentation = "Tells whether GNSS signals obscuration by terrain is enabled.";
    const char* const IsGnssSignalTerrainObscurationEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsGnssSignalTerrainObscurationEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsGnssSignalTerrainObscurationEnabled);


    IsGnssSignalTerrainObscurationEnabled::IsGnssSignalTerrainObscurationEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsGnssSignalTerrainObscurationEnabledPtr IsGnssSignalTerrainObscurationEnabled::create()
    {
      return std::make_shared<IsGnssSignalTerrainObscurationEnabled>();
    }

    IsGnssSignalTerrainObscurationEnabledPtr IsGnssSignalTerrainObscurationEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsGnssSignalTerrainObscurationEnabled>(ptr);
    }

    bool IsGnssSignalTerrainObscurationEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsGnssSignalTerrainObscurationEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsGnssSignalTerrainObscurationEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsGnssSignalTerrainObscurationEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
