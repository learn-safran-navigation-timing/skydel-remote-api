
#include "gen/ClearVehiculeTrajectory.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearVehiculeTrajectory
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearVehiculeTrajectory::CmdName = "ClearVehiculeTrajectory";
    const char* const ClearVehiculeTrajectory::Documentation = "Clear NMEA trajectory file";

    REGISTER_COMMAND_FACTORY(ClearVehiculeTrajectory);


    ClearVehiculeTrajectory::ClearVehiculeTrajectory()
      : CommandBase(CmdName)
    {

    }

    ClearVehiculeTrajectoryPtr ClearVehiculeTrajectory::create()
    {
      return std::make_shared<ClearVehiculeTrajectory>();
    }

    ClearVehiculeTrajectoryPtr ClearVehiculeTrajectory::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearVehiculeTrajectory>(ptr);
    }

    bool ClearVehiculeTrajectory::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearVehiculeTrajectory::documentation() const { return Documentation; }


    int ClearVehiculeTrajectory::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
