
#include "GetVehicleGainPatternOffsetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleGainPatternOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleGainPatternOffsetResult::CmdName = "GetVehicleGainPatternOffsetResult";
    const char* const GetVehicleGainPatternOffsetResult::Documentation = "Result of GetVehicleGainPatternOffset.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ------------------------------------------------------------------------------------\n"
      "Band        GNSSBand        Offset will be apply to this band.\n"
      "Offset      double          Power offset\n"
      "AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna";
    const char* const GetVehicleGainPatternOffsetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleGainPatternOffsetResult);


    GetVehicleGainPatternOffsetResult::GetVehicleGainPatternOffsetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetVehicleGainPatternOffsetResult::GetVehicleGainPatternOffsetResult(const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName)
      : CommandResult(CmdName, TargetId)
    {

      setBand(band);
      setOffset(offset);
      setAntennaName(antennaName);
    }

    GetVehicleGainPatternOffsetResult::GetVehicleGainPatternOffsetResult(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setBand(band);
      setOffset(offset);
      setAntennaName(antennaName);
    }


    GetVehicleGainPatternOffsetResultPtr GetVehicleGainPatternOffsetResult::create(const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName)
    {
      return std::make_shared<GetVehicleGainPatternOffsetResult>(band, offset, antennaName);
    }

    GetVehicleGainPatternOffsetResultPtr GetVehicleGainPatternOffsetResult::create(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName)
    {
      return std::make_shared<GetVehicleGainPatternOffsetResult>(relatedCommand, band, offset, antennaName);
    }

    GetVehicleGainPatternOffsetResultPtr GetVehicleGainPatternOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleGainPatternOffsetResult>(ptr);
    }

    bool GetVehicleGainPatternOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<double>::is_valid(m_values["Offset"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string GetVehicleGainPatternOffsetResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleGainPatternOffsetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "Offset", "AntennaName"}; 
      return names; 
    }


    Sdx::GNSSBand GetVehicleGainPatternOffsetResult::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetVehicleGainPatternOffsetResult::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleGainPatternOffsetResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetVehicleGainPatternOffsetResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetVehicleGainPatternOffsetResult::antennaName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void GetVehicleGainPatternOffsetResult::setAntennaName(const std::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<std::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
