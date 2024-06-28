
#include "GetVehiclePhasePatternOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehiclePhasePatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehiclePhasePatternOffset::CmdName = "GetVehiclePhasePatternOffset";
    const char* const GetVehiclePhasePatternOffset::Documentation = "Get the offset (in rad) for the antenna phase pattern of the band.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ------------------------------------------------------------------------------------\n"
      "Band        GNSSBand        Offset will be apply to this band. (\"L1\", \"L2\", \"L5\", \"E6\" or \"S\")\n"
      "AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna";
    const char* const GetVehiclePhasePatternOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehiclePhasePatternOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehiclePhasePatternOffset);


    GetVehiclePhasePatternOffset::GetVehiclePhasePatternOffset()
      : CommandBase(CmdName, TargetId)
    {}

    GetVehiclePhasePatternOffset::GetVehiclePhasePatternOffset(const Sdx::GNSSBand& band, const std::optional<std::string>& antennaName)
      : CommandBase(CmdName, TargetId)
    {

      setBand(band);
      setAntennaName(antennaName);
    }

    GetVehiclePhasePatternOffsetPtr GetVehiclePhasePatternOffset::create(const Sdx::GNSSBand& band, const std::optional<std::string>& antennaName)
    {
      return std::make_shared<GetVehiclePhasePatternOffset>(band, antennaName);
    }

    GetVehiclePhasePatternOffsetPtr GetVehiclePhasePatternOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehiclePhasePatternOffset>(ptr);
    }

    bool GetVehiclePhasePatternOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string GetVehiclePhasePatternOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehiclePhasePatternOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "AntennaName"}; 
      return names; 
    }


    int GetVehiclePhasePatternOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::GNSSBand GetVehiclePhasePatternOffset::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetVehiclePhasePatternOffset::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetVehiclePhasePatternOffset::antennaName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void GetVehiclePhasePatternOffset::setAntennaName(const std::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<std::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
