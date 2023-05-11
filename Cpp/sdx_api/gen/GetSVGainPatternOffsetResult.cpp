
#include "gen/GetSVGainPatternOffsetResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVGainPatternOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVGainPatternOffsetResult::CmdName = "GetSVGainPatternOffsetResult";
    const char* const GetSVGainPatternOffsetResult::Documentation = "Result of GetSVGainPatternOffset.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSVGainPatternOffsetResult);


    GetSVGainPatternOffsetResult::GetSVGainPatternOffsetResult()
      : CommandResult(CmdName)
    {}

    GetSVGainPatternOffsetResult::GetSVGainPatternOffsetResult(const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
      : CommandResult(CmdName)
    {

      setBand(band);
      setSystem(system);
      setOffset(offset);
      setAntennaName(antennaName);
    }

    GetSVGainPatternOffsetResult::GetSVGainPatternOffsetResult(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
      : CommandResult(CmdName, relatedCommand)
    {

      setBand(band);
      setSystem(system);
      setOffset(offset);
      setAntennaName(antennaName);
    }


    GetSVGainPatternOffsetResultPtr GetSVGainPatternOffsetResult::create(const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
    {
      return std::make_shared<GetSVGainPatternOffsetResult>(band, system, offset, antennaName);
    }

    GetSVGainPatternOffsetResultPtr GetSVGainPatternOffsetResult::create(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
    {
      return std::make_shared<GetSVGainPatternOffsetResult>(relatedCommand, band, system, offset, antennaName);
    }

    GetSVGainPatternOffsetResultPtr GetSVGainPatternOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVGainPatternOffsetResult>(ptr);
    }

    bool GetSVGainPatternOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<double>::is_valid(m_values["Offset"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string GetSVGainPatternOffsetResult::documentation() const { return Documentation; }


    Sdx::GNSSBand GetSVGainPatternOffsetResult::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetSVGainPatternOffsetResult::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVGainPatternOffsetResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVGainPatternOffsetResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSVGainPatternOffsetResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetSVGainPatternOffsetResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetSVGainPatternOffsetResult::antennaName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void GetSVGainPatternOffsetResult::setAntennaName(const Sdx::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<Sdx::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
