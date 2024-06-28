
#include "GetSVGainPatternOffsetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVGainPatternOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVGainPatternOffsetResult::CmdName = "GetSVGainPatternOffsetResult";
    const char* const GetSVGainPatternOffsetResult::Documentation = "Result of GetSVGainPatternOffset.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ------------------------------------------------------------------------------------\n"
      "Band        GNSSBand        Offset will be apply to this band. (\"L1\", \"L2\", \"L5\", \"E6\" or \"S\")\n"
      "System      string          \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Offset      double          Power offset\n"
      "AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna";
    const char* const GetSVGainPatternOffsetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSVGainPatternOffsetResult);


    GetSVGainPatternOffsetResult::GetSVGainPatternOffsetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSVGainPatternOffsetResult::GetSVGainPatternOffsetResult(const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName)
      : CommandResult(CmdName, TargetId)
    {

      setBand(band);
      setSystem(system);
      setOffset(offset);
      setAntennaName(antennaName);
    }

    GetSVGainPatternOffsetResult::GetSVGainPatternOffsetResult(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setBand(band);
      setSystem(system);
      setOffset(offset);
      setAntennaName(antennaName);
    }


    GetSVGainPatternOffsetResultPtr GetSVGainPatternOffsetResult::create(const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName)
    {
      return std::make_shared<GetSVGainPatternOffsetResult>(band, system, offset, antennaName);
    }

    GetSVGainPatternOffsetResultPtr GetSVGainPatternOffsetResult::create(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string GetSVGainPatternOffsetResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSVGainPatternOffsetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "System", "Offset", "AntennaName"}; 
      return names; 
    }


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



    std::optional<std::string> GetSVGainPatternOffsetResult::antennaName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void GetSVGainPatternOffsetResult::setAntennaName(const std::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<std::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
