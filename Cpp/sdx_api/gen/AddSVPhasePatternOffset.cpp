
#include "gen/AddSVPhasePatternOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddSVPhasePatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddSVPhasePatternOffset::CmdName = "AddSVPhasePatternOffset";
    const char* const AddSVPhasePatternOffset::Documentation = "Add an offset (in rad) for all values of the phase pattern.";

    REGISTER_COMMAND_FACTORY(AddSVPhasePatternOffset);


    AddSVPhasePatternOffset::AddSVPhasePatternOffset()
      : CommandBase(CmdName)
    {}

    AddSVPhasePatternOffset::AddSVPhasePatternOffset(const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
      : CommandBase(CmdName)
    {

      setBand(band);
      setSystem(system);
      setOffset(offset);
      setAntennaName(antennaName);
    }

    AddSVPhasePatternOffsetPtr AddSVPhasePatternOffset::create(const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string AddSVPhasePatternOffset::documentation() const { return Documentation; }


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



    Sdx::optional<std::string> AddSVPhasePatternOffset::antennaName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void AddSVPhasePatternOffset::setAntennaName(const Sdx::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<Sdx::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
