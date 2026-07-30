
#include "GetGnssSignalTerrainObscurationRate.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGnssSignalTerrainObscurationRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGnssSignalTerrainObscurationRate::CmdName = "GetGnssSignalTerrainObscurationRate";
    const char* const GetGnssSignalTerrainObscurationRate::Documentation = "Get the rate (in Hz) at which line-of-sight between the receiver and satellites is evaluated for terrain obscuration.";
    const char* const GetGnssSignalTerrainObscurationRate::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGnssSignalTerrainObscurationRate);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGnssSignalTerrainObscurationRate);


    GetGnssSignalTerrainObscurationRate::GetGnssSignalTerrainObscurationRate()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetGnssSignalTerrainObscurationRatePtr GetGnssSignalTerrainObscurationRate::create()
    {
      return std::make_shared<GetGnssSignalTerrainObscurationRate>();
    }

    GetGnssSignalTerrainObscurationRatePtr GetGnssSignalTerrainObscurationRate::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGnssSignalTerrainObscurationRate>(ptr);
    }

    bool GetGnssSignalTerrainObscurationRate::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetGnssSignalTerrainObscurationRate::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGnssSignalTerrainObscurationRate::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetGnssSignalTerrainObscurationRate::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
