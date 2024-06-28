
#include "GetVehicleAntennaPhaseOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleAntennaPhaseOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleAntennaPhaseOffset::CmdName = "GetVehicleAntennaPhaseOffset";
    const char* const GetVehicleAntennaPhaseOffset::Documentation = "Get Vehicle phase offset antenna pattern. If no name is specified, the command is aplied to Basic Vehicle Antenna.\n"
      "\n"
      "Name Type            Description\n"
      "---- --------------- --------------------\n"
      "Band GNSSBand        Frequency band\n"
      "Name optional string Vehicle antenna name";
    const char* const GetVehicleAntennaPhaseOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleAntennaPhaseOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleAntennaPhaseOffset);


    GetVehicleAntennaPhaseOffset::GetVehicleAntennaPhaseOffset()
      : CommandBase(CmdName, TargetId)
    {}

    GetVehicleAntennaPhaseOffset::GetVehicleAntennaPhaseOffset(const Sdx::GNSSBand& band, const std::optional<std::string>& name)
      : CommandBase(CmdName, TargetId)
    {

      setBand(band);
      setName(name);
    }

    GetVehicleAntennaPhaseOffsetPtr GetVehicleAntennaPhaseOffset::create(const Sdx::GNSSBand& band, const std::optional<std::string>& name)
    {
      return std::make_shared<GetVehicleAntennaPhaseOffset>(band, name);
    }

    GetVehicleAntennaPhaseOffsetPtr GetVehicleAntennaPhaseOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleAntennaPhaseOffset>(ptr);
    }

    bool GetVehicleAntennaPhaseOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string GetVehicleAntennaPhaseOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleAntennaPhaseOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "Name"}; 
      return names; 
    }


    int GetVehicleAntennaPhaseOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::GNSSBand GetVehicleAntennaPhaseOffset::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetVehicleAntennaPhaseOffset::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetVehicleAntennaPhaseOffset::name() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetVehicleAntennaPhaseOffset::setName(const std::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
