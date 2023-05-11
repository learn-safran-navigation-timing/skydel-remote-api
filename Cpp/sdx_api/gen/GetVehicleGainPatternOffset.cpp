
#include "gen/GetVehicleGainPatternOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleGainPatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleGainPatternOffset::CmdName = "GetVehicleGainPatternOffset";
    const char* const GetVehicleGainPatternOffset::Documentation = "Get the offset (in dB) for the antenna gain pattern of the band.";

    REGISTER_COMMAND_FACTORY(GetVehicleGainPatternOffset);


    GetVehicleGainPatternOffset::GetVehicleGainPatternOffset()
      : CommandBase(CmdName)
    {}

    GetVehicleGainPatternOffset::GetVehicleGainPatternOffset(const Sdx::GNSSBand& band, const Sdx::optional<std::string>& antennaName)
      : CommandBase(CmdName)
    {

      setBand(band);
      setAntennaName(antennaName);
    }

    GetVehicleGainPatternOffsetPtr GetVehicleGainPatternOffset::create(const Sdx::GNSSBand& band, const Sdx::optional<std::string>& antennaName)
    {
      return std::make_shared<GetVehicleGainPatternOffset>(band, antennaName);
    }

    GetVehicleGainPatternOffsetPtr GetVehicleGainPatternOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleGainPatternOffset>(ptr);
    }

    bool GetVehicleGainPatternOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string GetVehicleGainPatternOffset::documentation() const { return Documentation; }


    int GetVehicleGainPatternOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::GNSSBand GetVehicleGainPatternOffset::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetVehicleGainPatternOffset::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetVehicleGainPatternOffset::antennaName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void GetVehicleGainPatternOffset::setAntennaName(const Sdx::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<Sdx::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
