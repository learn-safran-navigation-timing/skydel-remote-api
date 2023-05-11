
#include "gen/GetSVPhasePatternOffsetResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVPhasePatternOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVPhasePatternOffsetResult::CmdName = "GetSVPhasePatternOffsetResult";
    const char* const GetSVPhasePatternOffsetResult::Documentation = "Result of GetSVPhasePatternOffset.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSVPhasePatternOffsetResult);


    GetSVPhasePatternOffsetResult::GetSVPhasePatternOffsetResult()
      : CommandResult(CmdName)
    {}

    GetSVPhasePatternOffsetResult::GetSVPhasePatternOffsetResult(const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
      : CommandResult(CmdName)
    {

      setBand(band);
      setSystem(system);
      setOffset(offset);
      setAntennaName(antennaName);
    }

    GetSVPhasePatternOffsetResult::GetSVPhasePatternOffsetResult(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
      : CommandResult(CmdName, relatedCommand)
    {

      setBand(band);
      setSystem(system);
      setOffset(offset);
      setAntennaName(antennaName);
    }


    GetSVPhasePatternOffsetResultPtr GetSVPhasePatternOffsetResult::create(const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
    {
      return std::make_shared<GetSVPhasePatternOffsetResult>(band, system, offset, antennaName);
    }

    GetSVPhasePatternOffsetResultPtr GetSVPhasePatternOffsetResult::create(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
    {
      return std::make_shared<GetSVPhasePatternOffsetResult>(relatedCommand, band, system, offset, antennaName);
    }

    GetSVPhasePatternOffsetResultPtr GetSVPhasePatternOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVPhasePatternOffsetResult>(ptr);
    }

    bool GetSVPhasePatternOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<double>::is_valid(m_values["Offset"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string GetSVPhasePatternOffsetResult::documentation() const { return Documentation; }


    Sdx::GNSSBand GetSVPhasePatternOffsetResult::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetSVPhasePatternOffsetResult::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVPhasePatternOffsetResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVPhasePatternOffsetResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSVPhasePatternOffsetResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetSVPhasePatternOffsetResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetSVPhasePatternOffsetResult::antennaName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void GetSVPhasePatternOffsetResult::setAntennaName(const Sdx::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<Sdx::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
