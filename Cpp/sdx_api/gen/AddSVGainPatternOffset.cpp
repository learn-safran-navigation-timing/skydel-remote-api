
#include "gen/AddSVGainPatternOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddSVGainPatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddSVGainPatternOffset::CmdName = "AddSVGainPatternOffset";
    const char* const AddSVGainPatternOffset::Documentation = "Add an offset (in dB) for all values of the pattern.";

    REGISTER_COMMAND_FACTORY(AddSVGainPatternOffset);


    AddSVGainPatternOffset::AddSVGainPatternOffset()
      : CommandBase(CmdName)
    {}

    AddSVGainPatternOffset::AddSVGainPatternOffset(const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
      : CommandBase(CmdName)
    {

      setBand(band);
      setSystem(system);
      setOffset(offset);
      setAntennaName(antennaName);
    }

    AddSVGainPatternOffsetPtr AddSVGainPatternOffset::create(const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName)
    {
      return std::make_shared<AddSVGainPatternOffset>(band, system, offset, antennaName);
    }

    AddSVGainPatternOffsetPtr AddSVGainPatternOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<AddSVGainPatternOffset>(ptr);
    }

    bool AddSVGainPatternOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<double>::is_valid(m_values["Offset"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string AddSVGainPatternOffset::documentation() const { return Documentation; }


    int AddSVGainPatternOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::GNSSBand AddSVGainPatternOffset::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void AddSVGainPatternOffset::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string AddSVGainPatternOffset::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void AddSVGainPatternOffset::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double AddSVGainPatternOffset::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void AddSVGainPatternOffset::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> AddSVGainPatternOffset::antennaName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void AddSVGainPatternOffset::setAntennaName(const Sdx::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<Sdx::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
