
#include "ClearVehiculeTrajectory.h"

#include "command_factory.h"
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
    const char* const ClearVehiculeTrajectory::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ClearVehiculeTrajectory);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ClearVehiculeTrajectory);


    ClearVehiculeTrajectory::ClearVehiculeTrajectory()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& ClearVehiculeTrajectory::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int ClearVehiculeTrajectory::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
