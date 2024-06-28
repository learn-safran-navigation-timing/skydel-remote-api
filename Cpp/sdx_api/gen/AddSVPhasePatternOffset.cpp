
#include "AddSVPhasePatternOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddSVPhasePatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddSVPhasePatternOffset::CmdName = "AddSVPhasePatternOffset";
    const char* const AddSVPhasePatternOffset::Documentation = "Add an offset (in rad) for all values of the phase pattern.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ------------------------------------------------------------------------------------\n"
      "Band        GNSSBand        Offset will be apply to this band. (\"L1\", \"L2\", \"L5\", \"E6\" or \"S\")\n"
      "System      string          \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Offset      double          Phase offset (in rad)\n"
      "AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna";
    const char* const AddSVPhasePatternOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(AddSVPhasePatternOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(AddSVPhasePatternOffset);


    AddSVPhasePatternOffset::AddSVPhasePatternOffset()
      : CommandBase(CmdName, TargetId)
    {}

    AddSVPhasePatternOffset::AddSVPhasePatternOffset(const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName)
      : CommandBase(CmdName, TargetId)
    {

      setBand(band);
      setSystem(system);
      setOffset(offset);
      setAntennaName(antennaName);
    }

    AddSVPhasePatternOffsetPtr AddSVPhasePatternOffset::create(const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName)
    {
      return std::make_shared<AddSVPhasePatternOffset>(band, system, offset, antennaName);
    }

    AddSVPhasePatternOffsetPtr AddSVPhasePatternOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<AddSVPhasePatternOffset>(ptr);
    }

    bool AddSVPhasePatternOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<double>::is_valid(m_values["Offset"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string AddSVPhasePatternOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& AddSVPhasePatternOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "System", "Offset", "AntennaName"}; 
      return names; 
    }


    int AddSVPhasePatternOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::GNSSBand AddSVPhasePatternOffset::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void AddSVPhasePatternOffset::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string AddSVPhasePatternOffset::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void AddSVPhasePatternOffset::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double AddSVPhasePatternOffset::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void AddSVPhasePatternOffset::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> AddSVPhasePatternOffset::antennaName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void AddSVPhasePatternOffset::setAntennaName(const std::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<std::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
