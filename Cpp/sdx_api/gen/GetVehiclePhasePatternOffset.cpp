
#include "gen/GetVehiclePhasePatternOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehiclePhasePatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehiclePhasePatternOffset::CmdName = "GetVehiclePhasePatternOffset";
    const char* const GetVehiclePhasePatternOffset::Documentation = "Get the offset (in rad) for the antenna phase pattern of the band.";

    REGISTER_COMMAND_FACTORY(GetVehiclePhasePatternOffset);


    GetVehiclePhasePatternOffset::GetVehiclePhasePatternOffset()
      : CommandBase(CmdName)
    {}

    GetVehiclePhasePatternOffset::GetVehiclePhasePatternOffset(const Sdx::GNSSBand& band, const Sdx::optional<std::string>& antennaName)
      : CommandBase(CmdName)
    {

      setBand(band);
      setAntennaName(antennaName);
    }

    GetVehiclePhasePatternOffsetPtr GetVehiclePhasePatternOffset::create(const Sdx::GNSSBand& band, const Sdx::optional<std::string>& antennaName)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string GetVehiclePhasePatternOffset::documentation() const { return Documentation; }


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



    Sdx::optional<std::string> GetVehiclePhasePatternOffset::antennaName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void GetVehiclePhasePatternOffset::setAntennaName(const Sdx::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<Sdx::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
