
#include "GetSVPhasePatternOffsetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVPhasePatternOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVPhasePatternOffsetResult::CmdName = "GetSVPhasePatternOffsetResult";
    const char* const GetSVPhasePatternOffsetResult::Documentation = "Result of GetSVPhasePatternOffset.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ------------------------------------------------------------------------------------\n"
      "Band        GNSSBand        Offset will be apply to this band. (\"L1\", \"L2\" or \"L5\")\n"
      "System      string          \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Offset      double          Phase offset (in rad)\n"
      "AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna";
    const char* const GetSVPhasePatternOffsetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSVPhasePatternOffsetResult);


    GetSVPhasePatternOffsetResult::GetSVPhasePatternOffsetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSVPhasePatternOffsetResult::GetSVPhasePatternOffsetResult(const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
      : CommandResult(CmdName, TargetId)
    {

      setBand(band);
      setSystem(system);
      setOffset(offset);
      setAntennaName(antennaName);
    }

    GetSVPhasePatternOffsetResult::GetSVPhasePatternOffsetResult(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetSVPhasePatternOffsetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "System", "Offset", "AntennaName"}; 
      return names; 
    }


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
