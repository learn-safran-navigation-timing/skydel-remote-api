
#include "gen/AddVehiclePhasePatternOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddVehiclePhasePatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddVehiclePhasePatternOffset::CmdName = "AddVehiclePhasePatternOffset";
    const char* const AddVehiclePhasePatternOffset::Documentation = "Add an offset (in rad) for all values of the phase pattern.";

    REGISTER_COMMAND_FACTORY(AddVehiclePhasePatternOffset);


    AddVehiclePhasePatternOffset::AddVehiclePhasePatternOffset()
      : CommandBase(CmdName)
    {}

    AddVehiclePhasePatternOffset::AddVehiclePhasePatternOffset(const Sdx::GNSSBand& band, double offset, const Sdx::optional<std::string>& antennaName)
      : CommandBase(CmdName)
    {

      setBand(band);
      setOffset(offset);
      setAntennaName(antennaName);
    }

    AddVehiclePhasePatternOffsetPtr AddVehiclePhasePatternOffset::create(const Sdx::GNSSBand& band, double offset, const Sdx::optional<std::string>& antennaName)
    {
      return std::make_shared<AddVehiclePhasePatternOffset>(band, offset, antennaName);
    }

    AddVehiclePhasePatternOffsetPtr AddVehiclePhasePatternOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<AddVehiclePhasePatternOffset>(ptr);
    }

    bool AddVehiclePhasePatternOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<double>::is_valid(m_values["Offset"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string AddVehiclePhasePatternOffset::documentation() const { return Documentation; }


    int AddVehiclePhasePatternOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::GNSSBand AddVehiclePhasePatternOffset::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void AddVehiclePhasePatternOffset::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double AddVehiclePhasePatternOffset::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void AddVehiclePhasePatternOffset::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> AddVehiclePhasePatternOffset::antennaName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void AddVehiclePhasePatternOffset::setAntennaName(const Sdx::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<Sdx::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
