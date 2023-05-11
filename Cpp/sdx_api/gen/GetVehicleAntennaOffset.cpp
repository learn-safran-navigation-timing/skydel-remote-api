
#include "gen/GetVehicleAntennaOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleAntennaOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleAntennaOffset::CmdName = "GetVehicleAntennaOffset";
    const char* const GetVehicleAntennaOffset::Documentation = "Get the vehicle antenna offset infos. If no name is specified, the default vehicle antenna is get.";

    REGISTER_COMMAND_FACTORY(GetVehicleAntennaOffset);


    GetVehicleAntennaOffset::GetVehicleAntennaOffset(const Sdx::optional<std::string>& name)
      : CommandBase(CmdName)
    {

      setName(name);
    }

    GetVehicleAntennaOffsetPtr GetVehicleAntennaOffset::create(const Sdx::optional<std::string>& name)
    {
      return std::make_shared<GetVehicleAntennaOffset>(name);
    }

    GetVehicleAntennaOffsetPtr GetVehicleAntennaOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleAntennaOffset>(ptr);
    }

    bool GetVehicleAntennaOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string GetVehicleAntennaOffset::documentation() const { return Documentation; }


    int GetVehicleAntennaOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::optional<std::string> GetVehicleAntennaOffset::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetVehicleAntennaOffset::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
