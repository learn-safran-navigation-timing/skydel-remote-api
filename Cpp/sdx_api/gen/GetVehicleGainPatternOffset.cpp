
#include "GetVehicleGainPatternOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleGainPatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleGainPatternOffset::CmdName = "GetVehicleGainPatternOffset";
    const char* const GetVehicleGainPatternOffset::Documentation = "Get the offset (in dB) for the antenna gain pattern of the band.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ------------------------------------------------------------------------------------\n"
      "Band        GNSSBand        Offset will be apply to this band.\n"
      "AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna";
    const char* const GetVehicleGainPatternOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleGainPatternOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleGainPatternOffset);


    GetVehicleGainPatternOffset::GetVehicleGainPatternOffset()
      : CommandBase(CmdName, TargetId)
    {}

    GetVehicleGainPatternOffset::GetVehicleGainPatternOffset(const Sdx::GNSSBand& band, const std::optional<std::string>& antennaName)
      : CommandBase(CmdName, TargetId)
    {

      setBand(band);
      setAntennaName(antennaName);
    }

    GetVehicleGainPatternOffsetPtr GetVehicleGainPatternOffset::create(const Sdx::GNSSBand& band, const std::optional<std::string>& antennaName)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string GetVehicleGainPatternOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleGainPatternOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "AntennaName"}; 
      return names; 
    }


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



    std::optional<std::string> GetVehicleGainPatternOffset::antennaName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void GetVehicleGainPatternOffset::setAntennaName(const std::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<std::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
