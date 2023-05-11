
#include "gen/GetVehiclePhasePatternOffsetResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehiclePhasePatternOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehiclePhasePatternOffsetResult::CmdName = "GetVehiclePhasePatternOffsetResult";
    const char* const GetVehiclePhasePatternOffsetResult::Documentation = "Result of GetVehiclePhasePatternOffset.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetVehiclePhasePatternOffsetResult);


    GetVehiclePhasePatternOffsetResult::GetVehiclePhasePatternOffsetResult()
      : CommandResult(CmdName)
    {}

    GetVehiclePhasePatternOffsetResult::GetVehiclePhasePatternOffsetResult(const Sdx::GNSSBand& band, double offset, const Sdx::optional<std::string>& antennaName)
      : CommandResult(CmdName)
    {

      setBand(band);
      setOffset(offset);
      setAntennaName(antennaName);
    }

    GetVehiclePhasePatternOffsetResult::GetVehiclePhasePatternOffsetResult(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, double offset, const Sdx::optional<std::string>& antennaName)
      : CommandResult(CmdName, relatedCommand)
    {

      setBand(band);
      setOffset(offset);
      setAntennaName(antennaName);
    }


    GetVehiclePhasePatternOffsetResultPtr GetVehiclePhasePatternOffsetResult::create(const Sdx::GNSSBand& band, double offset, const Sdx::optional<std::string>& antennaName)
    {
      return std::make_shared<GetVehiclePhasePatternOffsetResult>(band, offset, antennaName);
    }

    GetVehiclePhasePatternOffsetResultPtr GetVehiclePhasePatternOffsetResult::create(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, double offset, const Sdx::optional<std::string>& antennaName)
    {
      return std::make_shared<GetVehiclePhasePatternOffsetResult>(relatedCommand, band, offset, antennaName);
    }

    GetVehiclePhasePatternOffsetResultPtr GetVehiclePhasePatternOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehiclePhasePatternOffsetResult>(ptr);
    }

    bool GetVehiclePhasePatternOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<double>::is_valid(m_values["Offset"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string GetVehiclePhasePatternOffsetResult::documentation() const { return Documentation; }


    Sdx::GNSSBand GetVehiclePhasePatternOffsetResult::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetVehiclePhasePatternOffsetResult::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehiclePhasePatternOffsetResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetVehiclePhasePatternOffsetResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetVehiclePhasePatternOffsetResult::antennaName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void GetVehiclePhasePatternOffsetResult::setAntennaName(const Sdx::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<Sdx::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
